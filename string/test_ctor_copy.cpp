// chris grimes
// cs 23001
// test.cpp String copy ctor tests

#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
  {
    //Setup
    char a[]="abc";
    String test(a);

    // Test
    String copy(test);

    // Verify
    std::cout<<copy<<"=="<<test<<std::endl;
    assert(test==copy);
  }
  {
    //Setup
    char a[]="When the truth is found";
    String test(a);

    // Test
    String copy(test);

    // Verify
    std::cout<<copy<<"=="<<test<<std::endl;
    assert(test==copy);
  }
  {
    //Setup
    char a[]="to be lies. And all the joy within you dies";
    String test(a);

    // Test
    String copy(test);

    // Verify
    std::cout<<copy<<"=="<<test<<std::endl;
    assert(test==copy);
  }
  {
    //Setup
    char a[]="Don't you want somebody to love";
    String test(a);

    // Test
    String copy(test);

    // Verify
    std::cout<<copy<<"=="<<test<<std::endl;
    assert(test==copy);
  }
  {
    //Setup
    char a[]="Don't you need somebody to love";
    String test(a);

    // Test
    String copy(test);

    // Verify
    std::cout<<copy<<"=="<<test<<std::endl;
    assert(test==copy);
  }
  std::cout<<" finished testing copy constructor"<<std::endl;
}
