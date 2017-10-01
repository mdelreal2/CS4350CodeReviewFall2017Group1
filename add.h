#pragma once

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
int determineDifferenceInPower(int& n1, int& d1, int& n2, int& d2);
void reverseArrayIntoResultArray(char arrayToReverse[], char resultArray[], int counter, bool isMantisa);

using namespace std;

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	//hold the value of the differenceInPower between the highest order denominator and lowest order denominator
	int differenceInPower = determineDifferenceInPower(n1, d1, n2, d2);

	//if determineDifferenceInPower sets the return value to 0, send a return value of false
	if (differenceInPower == 0)
	{
		return false;
	}

	//setting gcd (greatest common denominator) to use as it can be read in person more easily than d1 or d2
	int gcd = d1;

	//add the numerators together
	int newNumerator = n1 + n2;

	//store the newNumerator as having a wholeInteger and a decimal remainder
	int wholeInteger = newNumerator / gcd;
	int remainder = newNumerator % gcd;

	//add the characteristics of 1 and 2 and the value of the wholeInteger to get the value of the number to the left of the decimal
	int leftOfDecimal = c1 + c2 + wholeInteger;
	int rightOfDecimal = remainder;

	//creating an array to store the values of the converted numbers
	char* tempArray = new char[len];

	//setting up to convert the integer into the result array of characters
	int leftOfDecimalCounter = 0;

	int testNumber = leftOfDecimal;

	//loop through until the testNumber cannot be used anymore
	while (testNumber > 0)
	{
		//set the tempArray using the counter iterator with the last digit of testNumber converted to an ascii value
		tempArray[leftOfDecimalCounter] = testNumber % 10 + '0';
		//remove the last digit from the number by dividing testNumber by 10
		testNumber = testNumber / 10;
		leftOfDecimalCounter++;
	}

	//after obtaining the result from the conversion, the numbers will be reversed and need to be swapped.
	reverseArrayIntoResultArray(tempArray, result, leftOfDecimalCounter, false);

	//delete the array used to assist with the setting of result
	delete[] tempArray;

	//use the same tempArray pointer to create a new array 
	tempArray = new char[len];

	//take care of the right of the decimal now
	testNumber = rightOfDecimal;
	int rightOfDecimalCounter = 0;

	//loop through until the testNumber cannot be used anymore
	while (testNumber > 0)
	{
		//get the last digit from testNumber and convert it into an ascii value and place it into tempArray
		tempArray[rightOfDecimalCounter] = testNumber % 10 + '0';
		//remove the last digit from the number by dividing testNumber by 10
		testNumber = testNumber / 10;
		rightOfDecimalCounter++;
		leftOfDecimalCounter++;
	}

	//place the reversed contents of the array into result
	reverseArrayIntoResultArray(tempArray, result, leftOfDecimalCounter, true);

	return true;
}
int determineDifferenceInPower(int & n1, int & d1, int & n2, int & d2)
{
	int differenceInPower = 0;

	//check first to see that neither denominator is a 0, otherwise dividing by 0 would crash the program 
	if (d1 == 0 || d2 == 0)
	{
		//differenceInPower is already set to 0
	}

	////find whichever denominator has a higher order and fall into the right if statement
	else if (d1 < d2)
	{
		//set differenceInPower
		differenceInPower = d2 / d1;
		//set the new numerator of n1 to accomodate the differenceInPower
		n1 = n1 * differenceInPower;
		//set d1 to be the same as d2
		d1 = d2;
	}

	else if (d1 > d2)
	{
		//set the differenceInPower
		differenceInPower = d1 / d2;
		//set the new numerator of n2 to accomodate the differenceInPower
		n2 = n2 * differenceInPower;
		//set d2 to be the same as d1
		d2 = d1;
	}

	//if the denominators are the same, there is no need to manipulate the numerators
	else if (d1 == d2)
	{
		//set the differenceInPower
		differenceInPower = 1;
	}

	return differenceInPower;
}
//takes in an array with backwards elements and an array to place the elements in the right way, 
//a counter to iterate through the arrays, and a boolean value to increment past a decimal point character
void reverseArrayIntoResultArray(char arrayToReverse[], char resultArray[], int counter, bool isMantisa)
{
	//if working with the mantisa, use this technique
	if (isMantisa)
	{
		int reverseCounter = 0;

		//loop through until the decimal point is found and keep track of the iterations with a counter
		while (resultArray[reverseCounter] != '.')
		{
			reverseCounter++;
		}

		//increment the counter to move past the decimal point
		reverseCounter += 1;

		//set a difference int to signal the amount of characters needing to be swapped
		int difference = counter - reverseCounter;

		while (difference >= 0)
		{
			//place the elements into result Array from arryToReverse from back to front
			resultArray[reverseCounter] = arrayToReverse[difference];
			difference--;
			reverseCounter++;
		}

		//add a null terminator to the next element of resultArray
		resultArray[reverseCounter + 1] = '\0';
	}

	//if it is the characteristic, use this technique
	else if (!isMantisa)
	{
		int reverseCounter = 0;

		//loop through until the counter reaches the end of arrayToReverse
		while (counter > 0)
		{
			//place the elements into resultArray from arrayToReverse from back to front
			resultArray[reverseCounter] = arrayToReverse[counter - 1];
			counter--;
			reverseCounter++;
		}

		//add a decimal point to the next element of resultArray
		resultArray[reverseCounter] = '.';
	}
}
