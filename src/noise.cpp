#include "noise.h"

#include "image.cpp"
#include "bmp.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    Image32 Image = {0};
    Image.Width = 100;
    Image.Height = 100;
    Image.PixelCount = Image.Width * Image.Height;
    Image.PixelBytes = Image.PixelCount * sizeof(RGBA);
    Image.Pixels = (RGBA *)malloc(Image.PixelBytes);
    /*
          NOTE(chris):
              RED       0x00FF0000
              GREEN     0x0000FF00
              BLUE      0x000000FF
    */
    /*
    for (uint i = 0; i < Image.PixelCount; i++)
    {
        if (i / Image.Width < 33)
            Image.Pixels[i] = 0x00FF0000;
        else if (i / Image.Width < 66)
            Image.Pixels[i] = 0x0000FF00;
        else
            Image.Pixels[i] = 0x000000FF;
    }
    */
    CreateDirectoryA("img", nullptr);
    CreateGradient(Image);
    WriteBMP("img/test.bmp", Image);

    return(0);
}
