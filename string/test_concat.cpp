// Chris Grimes
// cs 23001
// test.cpp String concatenation

#include<iostream>
#include<cassert>
#include"string.hpp"

int main(){
  {
    //Setup

    //Test
    char a[]="a";
    char b[]="b";
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<rhs<<"+"<<lhs<<std::endl;
    result= rhs+lhs;
    assert(result==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b[]="b";
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<rhs<<"+"<<b<<std::endl;
    result= rhs+b;
    assert(result==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b='b';
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<rhs<<"+"<<b<<std::endl;
    result= rhs+b;
    assert(result==tmp);
  }
 {
    //Setup

    //Test
    char a[]="a";
    char b[]="b";
    char c[]="ba";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<b<<"+"<<rhs<<std::endl;
    result= b+rhs;
    assert(result==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b='b';
    char c[]="ba";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<b<<"+"<<rhs<<std::endl;
    result= b+rhs;
    assert(result==tmp);
  }




  {
    //Setup

    //Test
    char a[]="a";
    char b[]="bc";
    char c[]="abc";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    result= rhs+lhs;
    assert(result==tmp);
  }

  {
    //Setup

    //Test
    char a[]="I love ";
    char b[]="you!!";
    char c[]="I love you!!";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    result= rhs+lhs;
    assert(result==tmp);
  }

  {
    //Setup

    //Test
    char a[]="Good morning the worm";
    char b[]=", your honor";
    char c[]="Good morning the worm, your honor";
    String rhs(a);
    String lhs(b);
    String tmp(c);
    String result;    

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    result= rhs+lhs;
    assert(result==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b[]="b";
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    rhs+=lhs;
    assert(rhs==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b[]="b";
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<rhs<<"+"<<b<<std::endl;
    rhs+=b;
    assert(rhs==tmp);
  }
  {
    //Setup

    //Test
    char a[]="a";
    char b='b';
    char c[]="ab";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<rhs<<"+"<<b<<std::endl;
    rhs+=b;
    assert(rhs==tmp);
  }
  {
    //Setup

    //Test
    char a[]="Help,";
    char b[]=" me";
    char c[]="Help, me";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    rhs+=lhs;
    assert(rhs==tmp);
  }
  {
    //Setup

    //Test
    char a[]="I've got a ";
    char b[]="ticket to the moon";
    char c[]="I've got a ticket to the moon";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    rhs+=lhs;
    assert(rhs==tmp);
  }
  {
    //Setup

    //Test
    char a[]="I've got a really expensive ";
    char b[]="ticket to the moon";
    char c[]="I've got a really expensive ticket to the moon";
    String rhs(a);
    String lhs(b);
    String tmp(c);
        

    //Verify
    std::cout<<a<<"+"<<b<<std::endl;
    rhs+=lhs;
    assert(rhs==tmp);
  }

  std::cout<<"Done testing concatenation + and +="<<std::endl;
}
