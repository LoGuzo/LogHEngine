#include "LogHTexture.h"
#include "LogHApplication.h"
#include "LogHResourceManager.h"

extern LogH::Application App;

namespace LogH::Graphics
{
	Texture* Texture::Create(const wstring& Name, UINT Width, UINT Height)
	{
		Texture* Image = ResourceManager::Find<Texture>(Name);
		if (Image)
			return Image;

		Image = new Texture();
		Image->SetName(Name);
		Image->SetWidth(Width);
		Image->SetHeight(Height);

		HDC Hdc = App.GetHdc();
		HWND Hwnd = App.GetHwnd();

		Image->MBitmap = CreateCompatibleBitmap(Hdc, Width, Height);
		Image->MHdc = CreateCompatibleDC(Hdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(Image->MHdc, Image->MBitmap);
		DeleteObject(oldBitMap);

		ResourceManager::Insert(Name, Image);

		return Image;
	}

	Texture::Texture()
		:Resource(Enums::E_ResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
		SAFE_DELETE(MImg);
	}

	HRESULT Texture::Load(const wstring& _Path)
	{
		wstring ext = _Path.substr(_Path.find_last_of(L".") + 1);
		//bmp
		if (ext == L"bmp")
		{
			Type = E_TextureType::Bmp;
			MBitmap = (HBITMAP)LoadImageW(nullptr, _Path.c_str(), IMAGE_BITMAP, 
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			
			if (!MBitmap)
				return S_FALSE;

			BITMAP info = {};
			GetObject(MBitmap, sizeof(BITMAP), &info);

			MWidth = info.bmWidth;
			MHeight = info.bmHeight;

			HDC MainHdc = App.GetHdc();
			MHdc = CreateCompatibleDC(MainHdc);

			HBITMAP oldBitMap = (HBITMAP)SelectObject(MHdc, MBitmap);
			DeleteObject(oldBitMap);
		}
		//png
		else if (ext == L"png")
		{
			Type = E_TextureType::Png;
			MImg = Gdiplus::Image::FromFile(_Path.c_str());

			if (!MImg)
				return S_FALSE;

			MWidth = MImg->GetWidth();
			MHeight = MImg->GetHeight();
		}
		return S_OK;
	}
}