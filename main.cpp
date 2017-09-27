#include <iostream>

using namespace std;

//function prototypes
char convert(int num);
void addToArray(char num, int counter);
void divide(int c1, int n1, int d1, int c2, int n2, int d2, char answer[], int num);

//decimal array
char answer[100];

int main()
{
	//test inputs
	//divide(3, 3, 4, 1, 1, 2, answer, 100);
	//divide(1, 1, 2, 3, 3, 4, answer, 100);
	//divide(9, 1, 2, 5, 3, 8, answer, 10);
	divide(4, 7, 9, 2, 6, 8, answer, 100);
	
	cout << answer << endl;

	return 0;
}

void divide(int c1, int n1, int d1, int c2, int n2, int d2, char answer[], int length)
{
	int newNumerator1;
	int newNumerator2;
	int finalNumerator;
	int finalDenominator;

	//calculate improper fractions to find the new numerators
	newNumerator1 = (c1 * d1) + n1;
	newNumerator2 = (c2 * d2) + n2;

	//flip second fraction multiply to get final fraction
	finalNumerator = newNumerator1 * d2;
	finalDenominator = d1 * newNumerator2;

	int num = 1;
	int counter = 0;

	//first # 
	num = finalNumerator / finalDenominator;
	addToArray(convert(num), counter);

	++counter;

	//decimal
	addToArray('.', counter);

	++counter;

	int nextNum = num;
	int subNum = finalNumerator; //need a better variable name

	//loop to find the next decimal numbers until the length inputed is reached
	for (int i = 3; i <= length; ++i)
	{
		nextNum = nextNum * finalDenominator;
		nextNum = subNum - nextNum;

		//test to see if the next decimal number is 0 
		if (nextNum == 0)
		{
			break;
			//end array
		}

		nextNum = nextNum * 10;

		//save nextNum to subNum to use in the next calculation
		subNum = nextNum;

		nextNum = nextNum / finalDenominator;

		//add num to array and add 1 to the counter
		addToArray(convert(nextNum), counter);
		++counter;
	}

}

char convert(int num)
{
	char retVal;
	if (num == 1)
	{
		retVal = '1';
	}
	if (num == 2)
	{
		retVal = '2';
	}
	if (num == 3)
	{
		retVal = '3';
	}
	if (num == 4)
	{
		retVal = '4';
	}
	if (num == 5)
	{
		retVal = '5';
	}
	if (num == 6)
	{
		retVal = '6';
	}
	if (num == 7)
	{
		retVal = '7';
	}
	if (num == 8)
	{
		retVal = '8';
	}
	if (num == 9)
	{
		retVal = '9';
	}
	if (num == 0)
	{
		retVal = '0';
	}
	return retVal;
}

void addToArray(char num, int counter)
{
	answer[counter] = num;
}

//bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
//{
//
//}



