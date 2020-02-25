// keygen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//unsigned int means that int can only be positive. So we don't have to sorry about negative numbers
// Using starcraft keygen model
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h> 
#include "src/keygen/checker.hpp"

#define KEYLEN 19 //This will make the key length of our generator 20 digits
unsigned int verifyKey(unsigned int *digit);
unsigned int* generateKey();

int main (void)
{
	checker head;

	// Private functions. Need to do later
	unsigned int* genkey = generateKey();
	unsigned int f = verifyKey(genkey);
	char strkey[KEYLEN + 2];

	printf("Your key: ");
	// Go through every digit place holder
	for (unsigned int i = 0; i < KEYLEN + 1; ++i)
		// Print every integer of of Key Length
		//printf("%d", genkey[i]);
		//Converts integers to string
		itoa(genkey[i], strkey + i, 10); 

	// Print string for testing
	//printf("%s", strkey);
	//printf("\n");
	//// Verification of key
	//printf("%d should be %d\n", genkey[KEYLEN],f);

	head.isCorrect(strkey);
	
	return 0;
}

// verifyKey: the created key is sent to this function to go through every variable. The last digit should be equal to the last digit of the key
unsigned int verifyKey(unsigned int *digit) {
	unsigned int  y, lastDigit;
	y = 3;
	for (unsigned int i = 0; i < KEYLEN; i++)
	{
		// Add up the XOR of this math and it should return the last digit of the key to verify
		y += (2 * y) ^ digit[i];
	}
	lastDigit = y % 10;
	return lastDigit;
}

// Create actual key
unsigned int* generateKey() {
	unsigned int x;
	unsigned int* genkey;
	x = 3;
	genkey = reinterpret_cast<unsigned int*>(malloc((KEYLEN+1)*sizeof(unsigned int)));
	srand(time(NULL));
	for (unsigned int i = 0; i < KEYLEN; ++i) {
		unsigned int random;
		random = rand() % 10;
		x += (2 * x) ^ random;
		genkey[i] = random;
	}
	genkey[KEYLEN] = x % 10;
	
	return genkey;
}
