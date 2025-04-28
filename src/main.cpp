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

std::vector<std::vector<unsigned char>> Multiply(std::vector<std::vector<unsigned char>> img1, const int b, const int g, const int r) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    int blue = img1[i][0]*b;
    int green = img1[i][1]*g;
    int red = img1[i][2]*r;
    if (blue>255) {
      blue = 255;
    }
    if (green>255) {
      green = 255;
    }
    if (red>255) {
      red = 255;
    }
    temp[0] = static_cast<unsigned char>(blue);
    temp[1] = static_cast<unsigned char>(green);
    temp[2] = static_cast<unsigned char>(red);
    img3[i].resize(temp.size());
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
      temp[j] = static_cast<unsigned char> (255 * (1 - ((1 - img1[i][j]/255.0f) * (1 - img2[i][j]/255.0f))));
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
      if (img1[i][j] < img2[i][j]) {
        temp[j] = 0;
      } else {
        temp[j] = img1[i][j] - img2[i][j];
    }
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
      if (temp[j] < 0) {
        temp[j] = 0;
      }
      if (temp[j] > 255) {
        temp[j] = 255;
      }
    }
    img3[i] = temp;
  }
  return img3;
}



std::vector<std::vector<unsigned char>> Addition(std::vector<std::vector<unsigned char>> img1, const int b, const int g, const int r) {
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);
  for (int i = 0; i < img1.size(); i++) {
    temp[0] = img1[i][0] + b;
    temp[1] = img1[i][1] + g;
    temp[2] = img1[i][2] + r;
    if (img1[i][0] + b > 255) {
      temp[0] = 255;
    }
    if (img1[i][1] + g > 255) {
      temp[1] = 255;
    }
    if (img1[i][2] + r > 255) {
      temp[2] = 255;
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
        temp[j] =255 * 2 * (img1[i][j]/255.0f) * (img2[i][j]/255.0f);
      }
      if (img2[i][j]/255.0f > 0.5) {
        temp[j] = 255 * (1 - (2 * (1-img1[i][j]/255.0f) * (1-img2[i][j]/255.0f)));
      }
    }
    img3[i] = temp;
  }
  return img3;
}

std::vector<std::vector<unsigned char>> Seperate(std::vector<std::vector<unsigned char>> img1, std::string color) {
  // std::vector<std::vector<unsigned char>> img3;
  // img3.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);
  int channel;
  if (color == "blue") {
    channel = 0;
  }
  if (color == "green") {
    channel = 1;
  }
  if (color == "red") {
    channel = 2;
  }

  for (int i = 0; i < img1.size(); i++) {
    temp[0] = img1[i][channel];
    temp[1] = img1[i][channel];
    temp[2] = img1[i][channel];
    img1[i] = temp;
  }
  return img1;
}

std::vector<std::vector<unsigned char>> Combine(std::vector<std::vector<unsigned char>> img1, std::vector<std::vector<unsigned char>> img2, std::vector<std::vector<unsigned char>> img3) {
  std::vector<std::vector<unsigned char>> img4;
  img4.resize(img1.size());
  std::vector<unsigned char> temp;
  temp.resize(3);

  for (int i = 0; i < img1.size(); i++) {
    img4[i].resize(3);
    img4[i][0] =  img1[i][0];
    img4[i][1] = img2[i][1];
    img4[i][2] = img3[i][2];
  }
  return img4;
}

std::vector<std::vector<unsigned char>> Rotate(Image img1) {
  int width = img1.width;
  int height = img1.height;
  std::vector<std::vector<unsigned char>> img2 = img1.getPixelData();
  std::vector<std::vector<unsigned char>> img3;
  img3.resize(img2.size());

  for (int i = 0; i < img2.size(); i++) {
    img3[i].resize(3);
    for (int j = 0; j<3; j++) {
      img3[i][j] = img2[img2.size() - 1 - i][j];
    }
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
  //1.
  std::ifstream lay1("untitled14/input/layer1.tga", std::ios::binary);
  std::ifstream pat1("untitled14/input/pattern1.tga", std::ios::binary);
  Image i8(pat1);
  Image i3(lay1);
  std::vector<std::vector<unsigned char>> ans1=Multiply(i3.getPixelData(), i8.getPixelData());
  vecToTga("untitled14/output/part1.tga", ans1, i3);

  //2.
  auto lay2(std::ifstream("input/layer2.tga", std::ios::binary));
  auto car(std::ifstream("input/car.tga", std::ios::binary));
  Image i4(lay2);
  Image i1(car);
  std::vector<std::vector<unsigned char>> ans2=Subtract(i1.getPixelData(), i4.getPixelData());
  vecToTga("output/part2.tga", ans2, i4);

  //3.
  std::ifstream pat2("C:/Users/smrut/CLionProjects/untitled14/input/pattern2.tga", std::ios::binary);
  std::ifstream tex("C:/Users/smrut/CLionProjects/untitled14/input/text.tga", std::ios::binary);
  Image i9(pat2);
  Image i10(tex);
  std::vector<std::vector<unsigned char>> ans31=Multiply(i3.getPixelData(), i9.getPixelData());
  std::vector<std::vector<unsigned char>> ans32= Screen(ans31, i10.getPixelData());
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part3.tga", ans32, i10);

  //4.
  std::ifstream cir("C:/Users/smrut/CLionProjects/untitled14/input/circles.tga", std::ios::binary);
  Image i2(cir);
  std::vector<std::vector<unsigned char>> ans4 = Subtract(Multiply(i4.getPixelData(), i2.getPixelData()), i9.getPixelData());
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part4.tga", ans4, i9);

  //5.
  std::vector<std::vector<unsigned char>> ans5 = Overlay(i3.getPixelData(), i8.getPixelData());
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part5.tga", ans5, i9);

  //6.
  std::vector<std::vector<unsigned char>> ans6 = Addition(i1.getPixelData(), 0, 200, 0);
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part6.tga", ans6, i1);

  //7.

  std::vector<std::vector<unsigned char>> ans7 = Multiply(i1.getPixelData(), 0, 1, 4);
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part7.tga", ans7, i1);

  //8.
  std::vector<std::vector<unsigned char>> ans81 = Seperate(i1.getPixelData(), "red");
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part8_r.tga", ans81, i1);

  std::vector<std::vector<unsigned char>> ans82 = Seperate(i1.getPixelData(), "green");
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part8_g.tga", ans82, i1);

  std::vector<std::vector<unsigned char>> ans83 = Seperate(i1.getPixelData(), "blue");
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part8_b.tga", ans83, i1);

  //9.
  std::ifstream blue("C:/Users/smrut/CLionProjects/untitled14/input/layer_blue.tga", std::ios::binary);
  Image b(blue);
  std::ifstream green("C:/Users/smrut/CLionProjects/untitled14/input/layer_green.tga", std::ios::binary);
  Image g(green);
  std::ifstream red("C:/Users/smrut/CLionProjects/untitled14/input/layer_red.tga", std::ios::binary);
  Image r(red);
  std::vector<std::vector<unsigned char>> ans9 = Combine(b.getPixelData(), g.getPixelData(), r.getPixelData());
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part9.tga", ans9, r);

  //10.
  std::ifstream tex2("C:/Users/smrut/CLionProjects/untitled14/input/text2.tga", std::ios::binary);
  Image i11(tex2);
  std::vector<std::vector<unsigned char>> ans10 = Rotate(i11);
  vecToTga("C:/Users/smrut/CLionProjects/untitled14/output/part10.tga", ans10, i11);

  return 0;
}
