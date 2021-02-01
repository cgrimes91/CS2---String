// Chris Grimes
// cs 23001
// test.cpp String constructor for chars

#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){

  //Setup

  //Test
  char a='a';
  String test(a);

  //Verify
  std::cout<<"a=="<<test<<std::endl;
  assert(test==a);

  std::cout<<"Done testing ctor char"<<std::endl;

}
