#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <fstream>
#include <limits.h>

using namespace std;

int maxN(int a, int b, bool& first);
int minN(int a, int b);

class IDonInt//Infintite Double on Int
{
private:
	int* integer;
	int integerLength;
	int* decimal;
	int decimalLength;
	int meaning;
	bool work;


public:
	void Writer();
	void ChangeSign();
	void MoveDotLeft(int toMove);
	int MoveDotRight();
	void Destroyer();

	friend IDonInt operator + (IDonInt first, IDonInt second);
	friend IDonInt operator - (IDonInt first, IDonInt second);
	friend IDonInt operator * (IDonInt first, IDonInt second);
	friend ostream& operator << (ostream& out, IDonInt& c);
	friend bool IsBigger(IDonInt a, IDonInt b);

	IDonInt();
	IDonInt(int a);
	IDonInt(int* integerN, int integerLengthN, int* decimalN, int decimalLengthN, bool workN, int meaningN);
	IDonInt(long int a);
	IDonInt(long long int a);
	IDonInt(char* integerPart, int integerPartLength, char* decimalPart, int decimalPartLength, bool signedN);//false - positive number
	IDonInt(int* integerN, int integerLengthN);
	~IDonInt();

	void operator= (IDonInt toCopy);
	void operator += (IDonInt toAdd);

	int* Getinteger() { return integer; }
	int GetintegerLength() { return integerLength; }
	int* Getdecimal() { return decimal; }
	int GetdecimalLength() { return decimalLength; }
	int Getmeaning() { return meaning; }
	//bool Getwork();
	int const BASE = 1000000;
};

IDonInt operator + (IDonInt first, IDonInt second);
IDonInt operator - (IDonInt first, IDonInt second);
IDonInt operator * (IDonInt first, IDonInt second);
ostream& operator << (ostream& out, IDonInt& c);
bool IsBigger(IDonInt a, IDonInt b);


