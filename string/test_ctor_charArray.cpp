// Chris Grimes
// cs 23001
// test.cpp for String ctor char Array

#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
  {
  //Setup

  //Test
  char a[]="abc";
  String test(a);

  //Verify
  std::cout<<"abc=="<<test<<std::endl;
  assert(test==a);
  
  }
   {
  //Setup

  //Test
  char a[]="Hello";
  String test(a);

  //Verify
  std::cout<<"Hello=="<<test<<std::endl;
  assert(test==a);
  
   }
 {
  //Setup

  //Test
  char a[]="Hello World";
  String test(a);

  //Verify
  std::cout<<"Hello World=="<<test<<std::endl;
  assert(test==a);
  
 }
 {
  //Setup

  //Test
  char a[]="Hold on Loosely";
  String test(a);

  //Verify
  std::cout<<"Hold on Loosely=="<<test<<std::endl;
  assert(test==a);
  
 }
 {
  //Setup

  //Test
  char a[]="Help, I need somebody!!!";
  String test(a);

  //Verify
  std::cout<<a<<"=="<<test<<std::endl;
  assert(test==a);
  std::cout<<"Done testing char array ctor"<<std::endl;
 }
}
