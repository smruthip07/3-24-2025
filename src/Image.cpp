//
// Created by smrut on 2/23/2025.
//


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "Image.h"


Image::Image(std::ifstream& file){

    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    binaryToChar.resize(fileSize);
    file.read(reinterpret_cast<char*>(binaryToChar.data()), fileSize);


    idLength = binaryToChar[0];
    colorMapType = binaryToChar[1];
    dataTypeCode = binaryToChar[2];
    colorMapOrigin = binaryToChar[3]|(binaryToChar[4]<<8);
    colorMapLength = binaryToChar[5]|(binaryToChar[6]<<8);
    colorMapDepth = binaryToChar[7];
    xOrigin = binaryToChar[8]|(binaryToChar[9]<<8);
    yOrigin = binaryToChar[10]|(binaryToChar[11]<<8);
    width = binaryToChar[12]|(binaryToChar[13]<<8);
    height = binaryToChar[14]|(binaryToChar[15]<<8);
    bitsPerPixel = binaryToChar[16];
    imageDescriptor = binaryToChar[17];

    for(int i = 18; i < binaryToChar.size(); i+=3){
        pixelData.push_back({binaryToChar[i], binaryToChar[i+1], binaryToChar[i+2]});
    }
}


std::vector<std::vector<unsigned char>> Image::getPixelData(){
    return pixelData;
}

// ./project1.out ./src/output/part1.tga .input/layer1.tga .input/pattern1.tga Multiply
