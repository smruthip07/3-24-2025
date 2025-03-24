//
// Created by smrut on 2/23/2025.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <vector>
#include <fstream>

class Image {
public:
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    std::vector<unsigned char> binaryToChar;
    std::vector<std::vector<unsigned char>> pixelData;

    Image(std::ifstream& file);
    std::vector<std::vector<unsigned char>> getPixelData();

};

#endif //IMAGE_H