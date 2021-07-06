#include "IDonInt.h"
#include <iostream>
#include <iomanip>

char* AddChar(char* toAdd, char value, int& length)
{
	length++;
	char* result = (char*)calloc(length, sizeof(char));
	int oldLength = length - 1;
	for (int i = 0; i < oldLength; i++)
	{
		result[i] = toAdd[i];
	}
	result[oldLength] = value;
	free(toAdd);
	return result;
}


ostream& divider(ostream& out)
{
	
		out << "\t";
	return out;
}

int main()
{
	ifstream file("numbers.txt", ios::binary);
	file.unsetf(ios::skipws);
	if (!file.is_open())
	{
		cout << "Ñouldn't open a file" << endl;
	}
	char initial[2] = "0";
	char symbol;
	int counterC = 0, counter = 0;
	char* numInt = nullptr;
	int numIntLength;
	char* numDec = nullptr;
	int numDecLength;
	bool inside = false;
	bool isSigned = false;
	bool decimal = false;
	IDonInt num1(0);
	IDonInt num2(1);
	int consolePosition = 0;
	file.seekg(0, ios_base::beg);
	while (!file.eof())
	{
		file >> symbol;
		if (file.fail() && !file.eof())
		{
			cout << "Couldn't get a symbol";
		}

		if (((symbol >= 48) && (symbol <= 57)) || (symbol == 45))
		{
			if (!inside)
			{
				if (symbol == 45)
				{
					isSigned = true;
				}
				if (symbol >= 48 && symbol <= 57)
				{
					if (!decimal)
					{
						numInt = (char*)calloc(1, sizeof(int));
						if (numInt == nullptr)
							cout << "Memory isn't allocated" << endl;
						numInt[0] = symbol;
						numIntLength = 1;
					}
					else
					{
						numDec = (char*)calloc(1, sizeof(int));
						if (numDec == nullptr)
							cout << "Memory isn't allocated" << endl;
						numDec[0] = symbol;
						numDecLength = 1;
					}
				}
				inside = true;
			}
			else
			{
				if (symbol >= 48 && symbol <= 57)
				{
					if (!decimal)
					{
						numInt = AddChar(numInt, symbol, numIntLength);
					}
					else
					{
						numDec = AddChar(numDec, symbol, numDecLength);
					}
				}
				else
				{

				}
			}
		}
		else
		{
			if (inside)
			{
				if (decimal == false && symbol == 46)
				{
					decimal = true;
					inside = false;
				}
				else
				{
					inside = false;
					decimal = false;

					if (consolePosition < 3)
					{
						IDonInt num(numInt, numIntLength, numDec, numDecLength, false);
						//num.Writer();
						consolePosition += 1;
						cout << num << divider;
						num1 = num;
						//if (num == 0.0 || num1 == 0.0)
							//return 0;

					}
					else
					{
						cout << endl;
						IDonInt num(numInt, numIntLength, numDec, numDecLength, false);
						//num.Writer();

						consolePosition = 1;
						cout << num << divider;
						num2 = num;

					}

					free(numDec);
					free(numInt);

				}
			}
			else
			{
				inside = false;

			}
		}
	}
	cout << "\n";
	IDonInt sum = num1 + num2;
	cout << "Sum of 4th and 6th number is " << sum << endl;
	file.close();
	if (file.is_open())
	{
		cout << "Couldn't close fail";
	}
	cout << endl;
	system("pause");
	return 0;
}
