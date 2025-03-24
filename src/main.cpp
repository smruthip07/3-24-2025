//
// Created by smrut on 2/23/2025.
//
#include <iostream>
#include <string>
#include <vector>
//#include "main.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <cstdint>


std::vector<std::vector<unsigned char>> Multiply(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2){
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    for (int j = 0; j<3; j++) {
      temp[j] = static_cast<unsigned char>(255 * (img1[i][j]/255.0f) * (img2[i][j]/255.0f));
    }
    img3[i] = temp;
  }
  return img3;
}

std::vector<std::vector<unsigned char>> Screen(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    for (int j = 0; j<3; j++) {
      temp[j] = static_cast<unsigned char>(1 - (255 * (1 - img1[i][j]/255.0f) * (1 - img2[i][j]/255.0f)));
    }
    img3[i] = temp;
  }
  return img3;
}

std::vector<std::vector<unsigned char>> Subtract(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    for (int j = 0; j<3; j++) {
      temp[j] = img1[i][j] - img2[i][j];
    }
    img3[i] = temp;
  }
  return img3;
}

std::vector<std::vector<unsigned char>> Addition(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    for (int j = 0; j<3; j++) {
      temp[j] = img1[i][j] + img2[i][j];
    }
    img3[i] = temp;
  }
  return img3;
}



std::vector<std::vector<unsigned char>> Overlay(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img2.size(); i++) {
    for (int j = 0; j<3; j++) {
      if (img2[i][j]/255.0f <= 0.5) {
        temp[j] = 2 * img1[i][j]/255 * img2[i][j];
      }
      if (img2[i][j]/255.0f > 0.5) {
        temp[j] = 1 - (2 * (1-img1[i][j]/255) * (1-img2[i][j]));
      }
    }
    img3[i] = temp;
  }
  return img3;
}

void vecToTga(const std::string& output, std::vector<std::vector<unsigned char>>& vec, Image& img) {
  std::ofstream file(output, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << output << " for writing." << std::endl;
    return;
  }


  unsigned char header[18] = {0};
  header[0] = img.idLength;
  header[1] = img.colorMapType;
  header[2] = img.dataTypeCode;
  header[3] = img.colorMapOrigin & 0xFF;
  header[4] = (img.colorMapOrigin >> 8) & 0xFF;
  header[5] = img.colorMapLength & 0xFF;
  header[6] = (img.colorMapLength >> 8) & 0xFF;
  header[7] = img.colorMapDepth;
  header[8] = img.xOrigin & 0xFF;
  header[9] = (img.xOrigin >> 8) & 0xFF;
  header[10] = img.yOrigin & 0xFF;
  header[11] = (img.yOrigin >> 8) & 0xFF;
  header[12] = img.width & 0xFF;
  header[13] = (img.width >> 8) & 0xFF;
  header[14] = img.height & 0xFF;
  header[15] = (img.height >> 8) & 0xFF;
  header[16] = img.bitsPerPixel;
  header[17] = img.imageDescriptor;

  file.write(reinterpret_cast<char*>(header), 18);

  for (auto& pixel : vec) {
    file.put(static_cast<char>(pixel[0]));
    file.put(static_cast<char>(pixel[1]));
    file.put(static_cast<char>(pixel[2]));
  }

  file.close();
}


int main() {
  //
  //1.
  std::ifstream lay1("C:/Users/smrut/CLionProjects/untitled14/input/layer1.tga", std::ios::binary);
  std::ifstream pat1("C:/Users/smrut/CLionProjects/untitled14/input/pattern1.tga", std::ios::binary);
  Image i8(pat1);
  Image i3(lay1);
  std::vector<std::vector<unsigned char>> ans1=Multiply(i3.getPixelData(), i8.getPixelData());
  std::ofstream output1("C:/Users/smrut/CLionProjects/untitled14/output/output1.tga", std::ios::binary);
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/output1.tga", ans1, i3);
  std::cout << '\n';
  // //2.
  // auto lay2(std::ifstream("layer2.tga", std::ios::binary));
  // auto car(std::ifstream("car.tga", std::ios::binary));
  // Image i4(lay2);
  // Image i1(car);
  // std::vector<std::vector<unsigned char>> ans2=Multiply(i1.getPixelData(), i4.getPixelData());
  // vecToTga("output2.tga", ans2, i4);
  //
  // //3.
  // std::ifstream pat2("pattern2.tga", std::ios::binary);
  // std::ifstream tex("text.tga", std::ios::binary);
  // Image i9(pat2);
  // Image i10(tex);
  // std::vector<std::vector<unsigned char>> ans31=Multiply(i3.getPixelData(), i9.getPixelData());
  // std::vector<std::vector<unsigned char>> ans32= Screen(ans31, i10.getPixelData());
  // vecToTga("output3.tga", ans32, i9);
  //
  // //4.
  // std::ifstream cir("circle.tga", std::ios::binary);
  // Image i2(cir);
  // std::vector<std::vector<unsigned char>> ans4 = Subtract(i9.getPixelData(), Multiply(i4.getPixelData(), i2.getPixelData()));
  // vecToTga("output/output4.tga", ans4, i9);
  //
  // //5.
  // std::vector<std::vector<unsigned char>> ans5 = Overlay(i3.getPixelData(), i8.getPixelData());
  //
  //
  // //6.
  //
  //
  //

  return 0;
}
