// Chris Grimes
// CS 23001
// Project 2 string.cpp

#include"string.hpp"

String::String(){
  stringSize=1; // changes stringSize to 1
  str= new char[stringSize]; // makes str point at a new char array in heap
  str[0]=0; // assigns null terminator to first index
}

String::String(char x){
  stringSize=2; // changes stringSize to 2
  str= new char[stringSize]; // points str at dynamically allocated char array in heap
  str[0]=x; // assigns the argument to first index
  str[1]=0; // assigns null terminator to last element is said array
}

String::String(const char x[]){
  int i=0; // creates a loop var to count elements present in char array
  while(x[i]!=0)
     ++i; // loop that increment loop var while searching for null terminator
  stringSize=i+1; // changes stringSize to match the number of elements in char array
  str= new char[stringSize]; // creates a char array in heap and points str at it
  int j=0;
  while(x[j]!=0){ // fill String with char array
    str[j]=x[j];
    ++j;
  }
  str[j]=0; // puts null terminator in last index
}

String::String(const String& rhs){
  stringSize= rhs.stringSize; // stringSize changed to match rhs
  str= new char[stringSize]; // creates a dynamicall allocated array and points str at it
  for(int i=0;i<stringSize; ++i) // fills str with rhs.str
    str[i]=rhs.str[i];
}

String::~String(){
  delete[] str; // deallocates dynamic array
}

void String::swap(String& rhs){
  char *tmp=str; //creates a temp pointer and assigns rhs.str to it
  str=rhs.str; // str points to what rhs.str used to point to prior to function call
  rhs.str=tmp; //rhs.str points to str
  int temp=stringSize; //creates a temp int and assigns rhs.stringSize to it
  stringSize=rhs.stringSize; // stringSize is now equivalent to what rhs.stringSize used to equal prior to function call
  rhs.stringSize=temp; // rhs.stringSize is assigned the value stored in stringSize
}

String& String::operator=(String rhs){
  swap(rhs);
  return *this;
}

char& String::operator[] (int x){
  return str[x]; // returns the char at index x
}

char String::operator[] (int x) const{
  return str[x]; // returns the char at index x
}

int String::capacity() const{
  return stringSize-1; // returns capacity of str
}

int String::length() const{
  int i =0;
  while(str[i]!=0) // searches for null terminator
    ++i;
  return i; // returns the index the null terminator is in
}

String String::operator+ (const String &rhs) const{
  String result(str); // creates the return string
  int strLength= result.length(); // finds length of lhs
  int newLength= strLength+rhs.length()+1; // finds the length the result needs to be
  result.resetCapacity(newLength); // resizes the result
  int i=0;
  for(; (rhs[i]!=0)||((strLength+i)<result.stringSize);++i)
    result.str[(strLength)+i]=rhs[i]; // concatenates rhs to result
  result.str[(strLength)+i]=0; // fills null terminator
  return result;
}

String& String::operator+=(const String &rhs){
  int strLength= length(); //finds length of rhs
  int newLength= strLength+rhs.length()+1; //finds the length results needs to be
  resetCapacity(newLength); // resizes lhs
  int i=0;
  for(; (rhs[i]!=0);++i)
    str[(strLength)+i]=rhs[i]; // concatenates rhs to lhs
  str[(strLength)+i]=0;
  return *this; // returns lhs
}

bool String::operator== (const String &rhs) const{
  int i=0;
  while((str[i]!=0) && (str[i]==rhs.str[i]))++i; // goes through index until there is a difference
  return (str[i]==rhs.str[i]); // checks equality at the first index that is different
}

bool String::operator< (const String &rhs) const{
  int i=0;
  while((str[i]!=0) && (rhs.str[i]!=0) && (str[i]==rhs.str[i]))++i; // searches index for the first difference
  return str[i]<rhs.str[i]; // checks the first different index 
}

String String::substr(int start, int end) const{
  String sub;
  for(int i=start; i<= end;++i) // fills sub with the desired indexs
    sub+= str[i];
  return sub;
}

int String::findch(int start, char x) const{
  int i=start;
  while((str[i]!=x)&&(str[i]!=0)) // searches indexs starting with i for desired char
    ++i;
  if(str[i]==0) // returns -1 if char not found
    i=-1;
  return i;
}

int String::findstr(int start, const String &target)const{
  char first= target[0]; //creates a char == the first element of target
  int begin=findch(start, first),result= -1; // searches str for the first element of target
  while((begin<=length())&&(begin> -1)){
    int j= begin; //used to loop through str index
    int i=0; // used to loop through target index
    if(str[j]==target.str[i]){
      int tmp= j; // saves potiential return value
      while(str[j]==target.str[i]){
        if(str[j]==target.str[(target.length()-1)]){
          result=tmp; // assigns potiential return value to actual return value
          ++i;
          ++j;
        }
        else{ // continues to loop through index
	  ++i;
          ++j;
        }
      }
      if(result!=-1) // if a result was found exits loop
        break;
      else if(str[j]!=target.str[i]) // if result has yet to be found searches str again starting at 1+(the last position that == target[0]
         begin= findch((begin+1), first);
    }
  }
  return result;
}

std::istream& operator>>(std::istream& in, String& rhs){
  char buf[256];
  if(!in.eof()){ // checks for end of file; if not fills buf with read char
      in>>buf;
      rhs=String(buf);// assigns buf to rhs
  }
  else{
    rhs=String();// fills rhs with empty string
  }
  return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
  for(int i=0; i<rhs.stringSize;++i)
    out<<rhs.str[i];// outputs rhs
  return out;
}

String::String(int x){
  stringSize=x+1; // changes stringSize to the correct length
  str= new char[stringSize]; // assigns the str pointer to char array
  str[0]=0;
}

String::String(int x, const char rhs[]){
  stringSize=x+1; // changes stringSizze to the correct length
  str= new char[stringSize]; // assigns str pointer to char array
  int j=0;
  while(rhs[j]!=0) ++j; // finds the length of rhs
  int i=0;
  for(; (i<stringSize)||(i<j); ++i)
    str[i]=rhs[i]; // fills String with rhs contents
  str[i]=0; // fills null terminator
}

void String::resetCapacity(int x){
  int smaller= stringSize;
  if(smaller>x) smaller=x; // compare to check for smaller length
  stringSize=x;
  char *tmp= new char[stringSize];
  for(int i=0; i<smaller; ++i)
    tmp[i]=str[i]; // fills tmp with str values
  delete[] str; // deallocates str
  str=tmp; // assigns str to tmp
}

std::vector<String> String::split(char a) const{
  std::vector<String> v1; // declares the return vector
  int i=findch(0,a), j=0; // finds the first element that contains the target char
  while((i<length())&&(i>=0)){
    String tmp= substr(j,(i-1)); //creates a substring 
    v1.push_back(tmp); // puts substring into the vector
    ++i; // increments the point at which the next findch will begins its search
    j=i; // sets the start location of findch to the element at which the next search will begin
    i=findch(i,a); // finds the next element that said char is in
  }
  if(i==-1){
   String tmp=substr(j,length()-1);
   v1.push_back(tmp);  
  }
  return v1;
}

//overloading the operator +
String operator+(const char lhs[], const String& rhs){
  return String(lhs)+rhs;
}

String operator+(char lhs, const String& rhs){
  return String(lhs)+rhs;
}

/*String operator+(const String& lhs, const char rhs[]){
  return lhs+String(rhs);
}

String operator+(const String& lhs, char rhs){
  return lhs+String(rhs);
  }*/

//overloading the operator ==
bool operator==(const char lhs[], const String& rhs){
  return String(lhs)==rhs;
}

bool operator==(char lhs, const String& rhs){
  return String(lhs)==rhs;
}

/*bool operator==(const String& lhs, const char rhs[]){
  return lhs==String(rhs);
}

bool operator==(const String& lhs, char rhs){
  return lhs==String(rhs);
  }*/

//overloading the operator <
bool operator<(const char lhs[], const String& rhs){
  return String(lhs)<rhs;
}

bool operator<(char lhs, const String& rhs){
  return String(lhs)<rhs;
}

/*bool operator<(const String& lhs, const char rhs[]){
  return lhs<String(rhs);
}

bool operator<(const String& lhs, char rhs){
  return lhs<String(rhs);
}

//overloading the operator<=
bool operator<=(const char lhs[], const String& rhs){
  return ((String(lhs)<rhs)||(String(lhs)==rhs));
}

bool operator<=(char lhs, const String& rhs){
  return ((String(lhs)<rhs)||(String(lhs)==rhs));
}

bool operator<=(const String& lhs, const char rhs[]){
  return ((lhs<String(rhs))||(lhs==String(rhs)));
}

bool operator<=(const String& lhs, char rhs){
  return ((lhs<String(rhs))||(lhs==String(rhs)));
}

//overloading the operator !=
bool operator!=(const char lhs[], const String& rhs){
  return (!(String(lhs)==rhs));
}

bool operator!=(char lhs, const String& rhs){
  return (!(String(lhs)==rhs));
}

bool operator!=(const String& lhs, const char rhs[]){
  return (!(lhs==String(rhs)));
}

bool operator!=(const String& lhs, char rhs){
  return (!(lhs==String(rhs)));
}

//overloading the operator >=
bool operator>=(const char lhs[], const String& rhs){
  return (!(String(lhs)<rhs));
}

bool operator>=(char lhs, const String& rhs){
  return (!(String(lhs)<rhs));
}

bool operator>=(const String& lhs, const char rhs[]){
  return (!(lhs<String(rhs)));
}

bool operator>=(const String& lhs, char rhs){
  return (!(lhs<String(rhs)));
}

//overloading the operator >
bool operator>(const char lhs[], const String& rhs){
  return ((!(String(lhs)<rhs))&&(!(String(lhs)==rhs)));
}

bool operator>(char lhs, const String& rhs){
  return ((!(String(lhs)<rhs))&&(!(String(lhs)==rhs)));
}

bool operator>(const String& lhs, const char rhs[]){
  return ((!(lhs<String(rhs)))&&(!(lhs==String(rhs))));
}

bool operator> (const String& lhs, char rhs){
  return ((!(lhs<String(rhs)))&&(!(lhs==String(rhs))));
  }*/

//overloading the boolean operators
bool operator<=(const String& lhs, const String& rhs){
  return ((lhs<rhs)||(lhs==rhs));
}

bool operator!=(const String& lhs, const String& rhs){
  return (!(lhs==rhs));
}

bool operator>=(const String& lhs, const String& rhs){
  return (!(lhs<rhs));
}

bool operator>(const String& lhs, const String& rhs){
  return ((!(lhs<rhs))&&(!(lhs==rhs)));
}
