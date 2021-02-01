//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"
////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    std::vector<String> vec = s.split(' ');
    if(vec.size()!= 10){
      host= "";
      date= Date();
      time= Time();
      request= "";
      status= "";
      number_of_bytes= 0;
    }
    else{
      host= vec[0];
      std::vector<String> vecTime= vec[3].split(':');
      std::vector<String> vecDate= vecTime[0].split('/');
      date= Date(vecDate[0], vecDate[1], vecDate[2]);
      time= Time(vecTime[1], vecTime[2], vecTime[3]);    
      request= vec[5].substr(1,(vec[5].length())-1);
      request+= " "; 
      request+= vec[6];
      request+= " ";
      request+= vec[7].substr(0,(vec[7].length())-2);
      status= vec[8];
      if(vec[9]== "-")
        number_of_bytes=0;
      else{
        for(int i=(vec[9].length()-1); i>=0; --i){
          if(i==((vec[9].length())-1)){
            number_of_bytes= (vec[9][i]-'0'); 
            //std::cout<<vec[9][i]<<" "<<number_of_bytes<<std::endl;
          }
          else if(i==((vec[9].length())-2)){
            number_of_bytes=number_of_bytes+ ((vec[9][i]-'0')*10); 
            //std::cout<<vec[9][i]<<" "<<number_of_bytes<<std::endl;
          }
	  else if(i==((vec[9].length())-3)){
            number_of_bytes=number_of_bytes+ ((vec[9][i]-'0')*100); 
            //std::cout<<vec[9][i]<<" "<<number_of_bytes<<std::endl;
          }
          else if(i==((vec[9].length())-4)){
            number_of_bytes=number_of_bytes+ ((vec[9][i]-'0')*1000); 
            //std::cout<<vec[9][i]<<" "<<number_of_bytes<<std::endl;
          }
          else if(i==((vec[9].length())-5)){
	    number_of_bytes=number_of_bytes+ ((vec[9][i]-'0')*10000);
            //std::cout<<vec[9][i]<<" "<<number_of_bytes<<std::endl;
          }
        }
      }
    }
}

Time::Time(String hr, String min, String sec){
  hour= (hr[0]-'0')*10;
  hour= hour+ (hr[1]-'0');
  minute= (min[0]-'0')*10; 
  minute= minute+ (min[1]-'0');
  second= (sec[0]-'0')*10;
  second= second+ (sec[1]-'0');
}

Date::Date(String d, String m, String yr){
  day= d.substr(1,2);
  month= m;
  year= (yr[0]-'0')*1000;
  year= year+((yr[1]-'0')*100);
  year= year+((yr[2]-'0')*10);
  year= year+((yr[3]-'0')*1);    
}
////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    String tmp;
    char x;
    while(!in.eof()){
      //std::cout<<"first while loop"<<std::endl;
      while(x!='\n'){
        //std::cout<<"second while loop"<<std::endl;
        tmp+=String(x);
	//std::cout<<tmp<<std::endl;
        in.get(x);
      }
      if(x=='\n'){
        in.get(x);
        //std::cout<<"creating a logentry"<<std::endl;
        LogEntry a(tmp);
        tmp="";
        //std::cout<<"adding entry to vec"<<std::endl;
        result.push_back(a);
      }   
    }
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& vec) {
  for(std::vector<LogEntry>::size_type i =0; i<= vec.size()-1;++i)
    out<<vec[i]<<std::endl;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& vec) {
  for(std::vector<LogEntry>::size_type i =0; i<= vec.size()-1;++i)
    out<<vec[i].getHost()<<std::endl;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& vec){
  int result=0;
  for(std::vector<LogEntry>::size_type i =0; i<= vec.size()-1;++i)
    result+= vec[i].getBytes();
  return result;
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log){
  out<<log.host<<" "<<log.date<<" "<<log.time<<" "<<log.request<<" "<<log.status<<" "
  <<log.number_of_bytes;
  return out;
}
std::ostream& operator<<(std::ostream& out, const Date& rhs){
  out<<rhs.day<<" "<<rhs.month<<" "<<rhs.year;
  return out;
}
std::ostream& operator<<(std::ostream& out, const Time& rhs){
  if(rhs.hour>9)
    out<<rhs.hour;
  else
    out<<"0"<<rhs.hour;
  if(rhs.minute>9)
    out<<" "<<rhs.minute;
  else
    out<<" 0"<<rhs.minute;
  if(rhs.second>9)
    out<<" "<<rhs.second;
  else
    out<<" 0"<<rhs.second;
  return out;
}
String LogEntry::getHost() const{
  return host;
}
int LogEntry::getBytes() const{
  return number_of_bytes;
}
