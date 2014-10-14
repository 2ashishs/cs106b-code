/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * LOGIC:
 * intToString(n):
 * 	if (n < 0):
 * 		return "-"+intToString(-n)
 * 	if (n<10):
 * 		return string(n)
 * 	else:
 * 		return intToString(n/10)+string(n%10)
 * 
 * stringToInt(str):
 * 	if str.length() == 1:
 * 		return int(str[0])
 * 	else:
 * 		return int(str[0]) * pow(10,str.length()-1) + stringToInt(str[1:])
 * 
 */

#include <iostream>
#include <string>
#include <cmath>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Function prototypes */
string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {
   // [TODO: fill in the code]
   int n = getInteger("Integer n = ");
   cout << "Converting n from integer to string: " << intToString(n) << endl;
   string str = getLine("String of integers str: ");
   cout << "Converting str to integer: " << stringToInt(str) << endl;
   
   return 0;
}

/* Function definition */
string intToString(int n){
	if (n < 0){ //-ve number case
		return string("-")+intToString(-n);
	}
	else if (n < 10){ //single digit number case
		return string()+char('0'+n);
	}
	else{ //2 or more digits number case
		return intToString(n/10)+char('0'+n%10);
	}
}

int stringToInt(string str){
	if (str[0]=='-'){ //-ve number case
		return -1*stringToInt(str.substr(1));
	}
	else if (str.length() == 1){ //single digit case
		return int(str[0]-'0');
	}
	else{ //2 or more digit case
		return int(str[0]-'0')*int(pow(10,str.length()-1))+stringToInt(str.substr(1));
	}
}
