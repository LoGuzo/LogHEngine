#include "LogHTexture.h"
#include "LogHApplication.h"

extern LogH::Application App;

namespace LogH::Graphics
{
	Texture::Texture()
		:Resource(Enums::E_ResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
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