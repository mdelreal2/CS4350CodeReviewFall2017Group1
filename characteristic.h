#pragma once
#include <iostream>

using namespace std;

//function prototype
bool characteristic(char numString[], int& c);

//helper function prototypes
bool isNumber(char numStr[], int len);
bool isDecimal(char numStr[], int len, int& newLen);
int toInt(char numStr[], int len);
int findStringLength(char str[]);
int takeNumToExponent(int num, int exp);

//function to find the characteristic of a float expressed as an array of chars
bool characteristic(char numString[], int& c)
{
	//find length of string
	int len = findStringLength(numString);

	//if all chars are either numbers or a decimal
	if (isNumber(numString, len))
	{
		//check for a decimal
		isDecimal(numString, len, len);

		//convert char array to an int
		c = toInt(numString, len);

		return true;
	}
	else
	{
		return false;
	}
}

//returns false if a char array holds anything other than a number or a decimal
bool isNumber(char numStr[], int len)
{
	//return true by default
	bool retVal = true;

	//step through char array
	for (int i = 0; i < len; i++)
	{
		//if char isn't a number or decimal
		if ((numStr[i] < 48 || numStr[i] > 57) && numStr[i] != '.')
		{
			retVal = false;
			break;
		}
	}

	return retVal;
}

//returns true if the char array has a decimal and passes the length of the array before the decimal into newLen
bool isDecimal(char numStr[], int len, int& newLen)
{
	//return false by default
	bool retVal = false;

	//step through char array
	for (int i = 0; i < len; i++)
	{
		//if char array contains a decimal
		if (numStr[i] == '.')
		{
			//store length of characteristic
			newLen = i;

			retVal = true;
			break;
		}
	}

	return retVal;
}

//turns a char array with a decimal into an int
int toInt(char numStr[], int len)
{
	int result = 0;
	int digit;

	//step through array
	for (int i = 0; i < len; i++)
	{
		//turn char into a digit
		if (numStr[i] == '1')
		{
			digit = 1;
		}
		else if (numStr[i] == '2')
		{
			digit = 2;
		}
		else if (numStr[i] == '3')
		{
			digit = 3;
		}
		else if (numStr[i] == '4')
		{
			digit = 4;
		}
		else if (numStr[i] == '5')
		{
			digit = 5;
		}
		else if (numStr[i] == '6')
		{
			digit = 6;
		}
		else if (numStr[i] == '7')
		{
			digit = 7;
		}
		else if (numStr[i] == '8')
		{
			digit = 8;
		}
		else if (numStr[i] == '9')
		{
			digit = 9;
		}
		else
		{
			digit = 0;
		}

		//add digit to result
		result = result + (digit*takeNumToExponent(10, len - i - 1));
	}

	return result;
}

//finds the length of an array of chars
int findStringLength(char str[])
{
	int len = 0;

	//look through array until ending '\0'
	while (str[len] != '\0')
	{
		len++;
	}

	return len;
}

//multiplies a number by itself a given amount
int takeNumToExponent(int num, int exp)
{
	int result = 1;

	//multiply num by itself exp times
	for (int i = 0; i < exp; i++)
	{
		result = result*num;
	}

	return result;
}