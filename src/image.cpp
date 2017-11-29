#include "image.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void CreateGradient(Image32 Image)
{
    srand((u32)time(NULL));
    RGBA StartColor = {u8(rand() % 0x100), u8(rand() % 0x100), u8(rand() % 0x100), 0};//{255-101, 255-152, 255-203, 0x00};
    RGBA EndColor = {u8(rand() % 0x100), u8(rand() % 0x100), u8(rand() % 0x100), 0};//{101, 152, 203, 0x00};
    //printf("R: %02X, G: %02X, B: %02X, A: %02X\n", StartColor.R, StartColor.G, StartColor.B, StartColor.A);
    //printf("R: %02X, G: %02X, B: %02X, A: %02X\n", EndColor.R, EndColor.G, EndColor.B, EndColor.A);

    for (uint r = 0; r < Image.Height; r++)
    {
        for (uint c = 0; c < Image.Width; c++)
        {
            /*
            u32 RedValue = u32(0xFF * r / Image.Height);
            u32 GreenValue = u32(0xFF * c / Image.Width) << 8;
            u32 BlueValue =
                u32(0xFF * (r * Image.Height + c) / (Image.Height * Image.Width)) << 16;
            u32 RGBValue = RedValue | GreenValue | BlueValue;
            printf("%08x : %08x : %08x := %08x\n", RedValue, GreenValue, BlueValue, RGBValue);
            */
            /*
            u32 RGBValue = StartColor + u32(DiffColor *
                (r * Image.Width + c) / (Image.Width * Image.Height) / 2.0f);
            */
            float PercentGradient = float(r+c+1)/float(Image.Height+Image.Width);
            float StartWeight = 1.0f - PercentGradient;
            float EndWeight = PercentGradient;
            //printf("SW: %.2f, EW: %.2f\n", StartWeight, EndWeight);
            RGBA PixelColor = {};
            PixelColor.R = u8((StartColor.R*StartWeight + EndColor.R*EndWeight));
            PixelColor.G = u8((StartColor.G*StartWeight + EndColor.G*EndWeight));
            PixelColor.B = u8((StartColor.B*StartWeight + EndColor.B*EndWeight));
            PixelColor.A = u8(0x00);
            //printf("R: %02X, G: %02X, B: %02X, A: %02X\n", PixelColor.R, PixelColor.G, PixelColor.B, PixelColor.A);
            Image.Pixels[r * Image.Width + c] = PixelColor;
        }
    }
}
