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

        static Texture* Create(const wstring& Name, UINT Width, UINT Height);

        Texture();
        ~Texture();

        virtual HRESULT Load(const wstring& _Path) override;

        UINT GetWidth() { return MWidth; }
        void SetWidth(UINT _MWidth) { MWidth = _MWidth; }
        UINT GetHeight() { return MHeight; }
        void SetHeight(UINT _MHeight) { MHeight = _MHeight; }
        HDC GetHdc() { return MHdc; }
        E_TextureType GetTextureType() { return Type; }
        Gdiplus::Image* GetImage() { return MImg; }
        bool IsAlpha() { return bAlpha; }

    private:
        bool bAlpha;
        E_TextureType Type;
        Gdiplus::Image* MImg;
        HBITMAP MBitmap;
        HDC MHdc;

        UINT MWidth;
        UINT MHeight;
    };
}