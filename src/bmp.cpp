#include "bmp.h"
#include "image.h"

#include <stdio.h>

internal void
WriteBMP(char *String, Image32 Image)
{
    u32 PixelsBytes = sizeof(u32)*Image.PixelCount;

    BMPHeader BMP;// = {};
    BMP.Type = 0x4D42;
    BMP.SizeBytes = sizeof(BMP) + PixelsBytes;
    BMP.Reserved1 = 0;
    BMP.Reserved2 = 0;
    BMP.OffsetBytes = sizeof(BMP);
    BMP.StructSize = sizeof(BMP) - 14;
    BMP.Width = (s32)Image.Width;
    BMP.Height = -(s32)Image.Height;
    BMP.Planes = 1;
    BMP.BitCount = 32;
    BMP.Compression = 0;
    BMP.SizeImage = PixelsBytes;
    BMP.XPerMeter = 0;
    BMP.YPerMeter = 0;
    BMP.ColorsUsed = 0;
    BMP.ColorsImportant = 0;

#if 0
    FILE *RefFile = nullptr;
    fopen_s(&RefFile, "img/ref.bmp", "rb");
    BMPHeader RefBMP = {};
    if (RefFile != nullptr)
    {
        fread(&RefBMP, sizeof(RefBMP), 1, RefFile);
        fclose(RefFile);
    }
    else
    {
        printf("Error: Cannot open file \"%s\"\n", "../img/ref.bmp");
    }
#endif

    FILE *BMPFile = nullptr;
    fopen_s(&BMPFile, String, "wb");
    if (BMPFile != nullptr)
    {
        fwrite(&BMP, sizeof(BMP), 1, BMPFile);
        fwrite(Image.Pixels, Image.PixelBytes, 1, BMPFile);
        fclose(BMPFile);
    } else
    {
        printf("ERROR: Cannot open file \"%s\"\n", String);
    }
}
