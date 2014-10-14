/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the recursive combinations problem.
 * LOGIC:
 * Cnk(n,k):
 * 	if (n==0 || k==0 || n==k):
 * 		return 1
 * 	else:
 * 		return cnk(n-1,k) + cnk(n-1,k-1)
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

int Cnk(int n,int k){
	if (n==0 || k==0 || n==k){
		return 1;
	}
	else{
		return ( Cnk(n-1,k) + Cnk(n-1,k-1) );
	}
}

//Even smaller implementation
int cnk(int n,int k){
	return (n==0 || k==0 || n==k) ? 1 : (cnk(n-1,k)+cnk(n-1,k-1));
}
int main() {
   // [TODO: fill in the code]
   int n = getInteger("n = ");
   int k = getInteger("k = ");
   cout << "C(" << n << "," << k << ")=" << cnk(n,k) << endl;
   return 0;
}
