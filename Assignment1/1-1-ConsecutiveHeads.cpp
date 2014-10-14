/*
	* File: ConsecutiveHeads.cpp
	* --------------------------
	* This file is the starter project for the coin-flipping problem.
	*LOGIC:
	* set flag=0, count=0
	* while flag < 3:
	* 	count++
	* 	x=tossCoin()
	* 	if  x == head:
	* 		flag++
	* 	else:
	* 		flag=0
	* print "it took"+count+"flips to get 3 consecutive heads"
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"

#define HEADS 1
#define TAILS 0

using namespace std;

int main() {
   // [TODO: fill in the code]
   int flag=0;
   int count=0;
   while (flag<3){
	   count++;
	   if (randomInteger(0,99)%2 == HEADS){
		   cout << HEADS << endl;
		   flag++;
	   }
	   else{
		   cout << TAILS << endl;
		   flag=0;
	   }
   }; //end of while loop
   
   cout << "It took " << count << " flips to get 3 successive heads" << endl;
   return 0;
}
