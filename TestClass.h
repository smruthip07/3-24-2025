//
// Created by smrut on 3/11/2025.
//

#include <iostream>

#ifndef TESTCLASS_H
#define TESTCLASS_H



class TestClass {
  std::string name;

  public:
    TestClass(std::string name) : name(name) {}
    std::string getName() { return name; }
};



#endif //TESTCLASS_H
