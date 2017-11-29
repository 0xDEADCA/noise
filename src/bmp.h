#ifndef BMP_H
#define BMP_H

#include "types.h"

#pragma pack(push, 1)
struct BMPHeader
{
    // File Header
    u16 Type; // Always Ascii BM
    u32 SizeBytes; // Size (bytes) of file
    u16 Reserved1; // 0
    u16 Reserved2; // 0
    u32 OffsetBytes; // Offset (bytes) to actual pixel data
    // Info Header
    u32 StructSize; // Size (bytes) of InfoHeader
    s32 Width;
    s32 Height; // NOTE(chris): If positive, pixel data is bottom to top
    u16 Planes; // Must be 1
    u16 BitCount; // Bits-per-pixel (0, 1, 4, 8, 16, 24, 32)
    u32 Compression; // *Should* be 0
    u32 SizeImage; // Only used if Compression is weird (not 0)
    s32 XPerMeter; // Horizontal resolution
    s32 YPerMeter; // Vertical resolution
    u32 ColorsUsed; // 0 for our purposes
    u32 ColorsImportant; // 0 for our purposes
};
#pragma pack(pop)

#endif
