//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace std;
//------------------------------

// Implement the class methods
class Rot13 {


  const int rotation{13};
  std::string text;
  std::map<char, int> dict;
  std::map<int, char> dict1;
  bool good;

  public:

  void dicc(){
    dict1[0]= 'z';
    for(int i=1; i<27; i++){
      dict[char(97 + i)] = i;
    }
    for(int i = 1; i <26; i++){
      dict1[i] = char(97 + i);
    }

  }
 //check to seee all letters are capital
  bool is_lower(std::string str){
    unsigned int i=0;
    while(i< str.length()){
      if(str[i]>='a' && str[i]<='z'){
        i++;
      }
      else{
        good = false;

        return good;
        break;
      }
    }
    good = true;
    return good;
  }

  Rot13(std::string msg=""){
    if(is_lower(msg)==true){
      text = msg;
    }
  }; 
    //checks to see is text is empty
    
  bool operator !(){
    if(text == "" || good == false){
      return true;
    }
    else{
      return false;
    }
    }
  //member binary take only one parameter
  void operator >>(std::string &str){
    //std::string holder{""};
    //std::cout<< text;
   // str = text;
    for(unsigned int i=0; i< text.length(); i++){
      if(text[i] == ' '){
        str.push_back(' ');
      }
      else{
        int num = (dict[text[i]] + this->rotation) % 26;
        //text[i] = dict1[num];
        str.push_back(dict1[num]);
      }
    }
   
  }
  
  std::string operator<<(std::string &str){
    //text = this-> text;
    //std::string holder; 
    //str = text;
    for(unsigned int i; i< text.length(); i++){
      //char current = str[i];
      if( text[i] == ' '){
        str.push_back(' ');
      }
      else{
        int num = (dict[text[i]] - rotation + 26) %26;
        str.push_back(dict1[num]);
      }
      
    }
    //str = holder;
    return str;
     
    
  }
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "v1" ) {
        Rot13 cipher;
        REQUIRE( !cipher );
    }
    SECTION( "v2" ) {
        Rot13 cipher{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        REQUIRE( !cipher );
    }
    SECTION( "v3" ) {
        Rot13 cipher{"slkgjskjg  akjf Adkfjd fsdfj"};
        REQUIRE( !cipher );
    }
    SECTION( "v4" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher==false );
    }
    SECTION( "e1" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher ==false);
        std::string secret;
        cipher << secret;
        REQUIRE( secret == "nopqrstuvwxy zabcdefg hijklm" );
    }
    SECTION( "e2" ) {
        Rot13 cipher{"nopqrstuvwxy zabcdefg hijklm"};
        REQUIRE( !!cipher==false );
        std::string msg;
        cipher <<msg;
        REQUIRE( msg == "abcdefghijkl mnopqrst uvwxyz" );
    }
}
//------------------------------
