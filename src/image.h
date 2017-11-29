#ifndef IMAGE_H
#define IMAGE_H

#include "types.h"

struct RGBA
{
    u8 R;
    u8 G;
    u8 B;
    u8 A;

    operator u32()
    {
        return u32((A << 24) | (B << 16) | (G << 8) | (R << 0));
    }
};

struct RGB
{
    u8 R;
    u8 G;
    u8 B;
};

struct Image32
{
    u32 Width;
    u32 Height;
    u32 PixelCount;
    u32 PixelBytes;
    RGBA *Pixels;
};

struct Image24
{
    u32 Width;
    u32 Height;
    u32 PixelCount;
    u32 PixelBytes;
    RGB *Pixels;
};

#endif
