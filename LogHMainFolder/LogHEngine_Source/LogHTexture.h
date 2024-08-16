#pragma once
#include "LogHResource.h"

namespace LogH :: Graphics
{
    class Texture : public Resource
    {
    public:
        enum class E_TextureType
        {
            Bmp,
            Png,
            None,
        };

        Texture();
        ~Texture();

        virtual HRESULT Load(const wstring& _Path) override;

        UINT GetWidth() { return MWidth; }
        UINT GetHeight() { return MHeight; }
        HDC GetHdc() { return MHdc; }
        E_TextureType GetTextureType() { return Type; }
        Gdiplus::Image* GetImage() { return MImg; }

    private:
        E_TextureType Type;
        Gdiplus::Image* MImg;
        HBITMAP MBitmap;
        HDC MHdc;

        UINT MWidth;
        UINT MHeight;
    };
}