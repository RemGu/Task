#include "IDonInt.h"


int maxN(int a, int b, bool& first)
{
	if (a > b)
	{
		first = true;
		return a;
	}
	else
	{
		first = false;
		return b;
	}
}

int minN(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

IDonInt::IDonInt()
{
	integer = nullptr;
	decimal = nullptr;
	integerLength = 0;
	decimalLength = 0;
	work = true;
	meaning = 0;
}

IDonInt::IDonInt(int* integerN, int integerLengthN, int* decimalN, int decimalLengthN, bool workN, int meaningN)
{
	integer = integerN;
	integerLength = integerLengthN;
	decimal = decimalN;
	decimalLength = decimalLengthN;
	work = workN;
	meaning = meaningN;
}

IDonInt::IDonInt(int* integerN, int integerLengthN)
{
	integer = (int*)calloc(integerLengthN, sizeof(int));
	if (integer == nullptr)
		work = false;
	else
		work = true;
	for (int i = 0; i < integerLengthN; i++)
	{
		integer[i] = integerN[i];
	}
	this->integerLength = integerLengthN;
	decimal = (int*)calloc(1, sizeof(int));
	decimalLength = 1;
	if (decimal == nullptr)
		work = false;
	else
		work = true;
	decimal[0] = 0;
	meaning = integerLengthN * 6;
}
//IntToLongMath
IDonInt::IDonInt(int a)
{
	meaning = 0;
	int check = a;
	while (check)
	{
		check /= 10;
		meaning++;
	}
	//Number is positive
	if (a < BASE && a >= 0)
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a;
	}
	else if (a > 0)
	{
		integer = (int*)calloc(2, sizeof(int));
		integerLength = 2;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a % BASE;
		integer[1] = a / BASE;
	}

	//Number is negative
	if (a > -1 * BASE && a < 0)
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a;
	}
	else if (a < 0)
	{
		integer = (int*)calloc(2, sizeof(int));
		integerLength = 2;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = -1 * (a % BASE);
		integer[1] = a / BASE;
	}

	//Decimal
	decimal = (int*)calloc(1, sizeof(int));
	decimalLength = 1;
	if (decimal == nullptr || !work)
		work = false;
	else
		work = true;
	decimal[0] = 0;
}

//LongToLongMath
IDonInt::IDonInt(long int a)
{
	long int check = a;
	meaning = 0;
	while (check)
	{
		check /= 10;
		meaning++;
	}
	//Number is positive
	if (a < BASE && a >= 0)
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a;
	}
	else if (a > 0)
	{
		integer = (int*)calloc(2, sizeof(int));
		integerLength = 2;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a % BASE;
		integer[1] = a / BASE;
	}

	//Number is negative
	if (a > -1 * BASE && a < 0)
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = a;
	}
	else if (a < 0)
	{
		integer = (int*)calloc(2, sizeof(int));
		integerLength = 2;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = -1 * (a % BASE);
		integer[1] = a / BASE;
	}

	//Decimal
	decimal = (int*)calloc(1, sizeof(int));
	decimalLength = 1;
	if (decimal == nullptr || !work)
		work = false;
	else
		work = true;
	decimal[0] = 0;
}

//Long long to long math
IDonInt::IDonInt(long long int a)
{
	long long int check = a;
	int pBASE = BASE;
	meaning = 0;
	while (check)
	{
		check /= 10;
		meaning++;
	}
	//Number is positive
	if (a < ((long long int)(pBASE)) && a >= ((long long int)(0)))
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = ((int)(a));
	}
	else if (a > ((long long int)(0)))
	{
		if (a < ((long long int)(pBASE)) * ((long long int)(pBASE)))
		{
			integer = (int*)calloc(2, sizeof(int));
			integerLength = 2;
			if (integer == nullptr)
				work = false;
			else
				work = true;
			long long int conv = a % ((long long int)(pBASE));
			integer[0] = ((int)(conv));
			conv = a / ((long long int)(pBASE));
			integer[1] = ((int)(conv));
		}
		else
		{
			integer = (int*)calloc(3, sizeof(int));
			integerLength = 3;
			if (integer == nullptr)
				work = false;
			else
				work = true;
			long long int conv = a % ((long long int)(pBASE));
			long long int npBASE = ((long long int)(pBASE));
			integer[0] = ((int)(conv));
			conv = (a / npBASE) % npBASE;
			integer[1] = ((int)(conv));
			conv = (a / npBASE) / npBASE;
			integer[2] = ((int)(conv));
		}
	}

	int nBASE = -1 * BASE;
	//Number is negative
	if (a > ((long long int)(nBASE)) && a < ((long long int)(0)))
	{
		integer = (int*)calloc(1, sizeof(int));
		integerLength = 1;
		if (integer == nullptr)
			work = false;
		else
			work = true;
		integer[0] = ((int)(a));
	}
	else if (a < 0)
	{
		if (a > -1 * (long long int)BASE * (long long int)BASE)
		{
			integer = (int*)calloc(2, sizeof(int));
			integerLength = 2;
			if (integer == nullptr)
				work = false;
			else
				work = true;
			long long int npBASE = ((long long int)(pBASE));
			long long int conv = ((long long int)(-1)) * a % ((long long int)(pBASE));
			integer[0] = ((int)(conv));
			conv = a / npBASE;
			integer[1] = ((int)(conv));
		}
		else
		{
			integer = (int*)calloc(3, sizeof(int));
			integerLength = 3;
			if (integer == nullptr)
				work = false;
			else
				work = true;
			long long int npBASE = ((long long int)(pBASE));
			long long int conv = ((long long int)(-1)) * a % ((long long int)(pBASE));
			integer[0] = ((int)(conv));
			conv = ((long long int)(-1)) * ((a / npBASE) % npBASE);
			integer[1] = ((int)(conv));
			conv = (a / npBASE) / npBASE;
			integer[2] = ((int)(conv));
		}
	}

	//Decimal
	decimal = (int*)calloc(1, sizeof(int));
	decimalLength = 1;
	if (decimal == nullptr || !work)
		work = false;
	else
		work = true;
	decimal[0] = 0;
}

//String from one number, already splitted
IDonInt::IDonInt(char* integerPart, int integerPartLength, char* decimalPart, int decimalPartLength, bool signedN)
{
	meaning = integerPartLength + decimalPartLength;
	integerLength = integerPartLength / 6;
	if (integerPartLength % 6)
		integerLength++;
	decimalLength = decimalPartLength / 6;
	if (decimalPartLength % 6)
		decimalLength++;
	integer = (int*)calloc(integerLength, sizeof(int));
	if (integer == nullptr)
		work = false;
	else
		work = true;
	decimal = (int*)calloc(decimalLength, sizeof(int));
	if (decimal == nullptr || !work)
		work = false;
	else
		work = true;
	char* num = (char*)calloc(6, sizeof(char));
	if (num == nullptr)
	{
		cout << "Couldn't give some memory for transforming " << endl;
		work = false;
	}

	//IntegerPart
	int counter = 0;
	int i = integerPartLength - 1;
	while (i >= 0)
	{
		if (i >= 6)
		{
			for (int j = 6 - 1; j >= 0; j--)
			{
				num[j] = integerPart[i];
				i--;
			}
		}
		else if (i >= 0)
		{
			for (int j = 0; j < 6; j++)
			{
				num[j] = '0';
			}
			int cycleEnd = 6 - i - 1;
			for (int j = 6 - 1; j >= cycleEnd; j--)
			{
				j = j;
				num[j] = integerPart[i];
				i--;
			}
		}
		stringstream number(num, ios_base::in | ios_base::out);
		number >> integer[counter];
		if (number.fail())
		{
			work = false;
			cout << "Couldn't read a number" << endl;
		}
		counter++;
	}

	//Decimal part
	counter = 0;
	i = decimalPartLength - 1;
	for (int j = 0; j < 6; j++)
	{
		num[j] = '0';
	}
	while (i >= 0)
	{
		if ((i == decimalPartLength - 1) && (decimalPartLength % 6))
		{
			for (int j = (decimalPartLength % 6) - 1; j >= 0; j--)
			{
				num[j] = decimalPart[i];
				i--;
			}
		}
		else
		{
			if (i > 0)
			{
				for (int j = 6 - 1; j >= 0; j--)
				{
					num[j] = decimalPart[i];
					i--;
				}
			}
		}
		stringstream number(num, ios_base::in | ios_base::out);
		number >> decimal[counter];
		if (number.fail())
		{
			work = false;
			cout << "Couldn't read a number" << endl;
		}
		counter++;
		if (counter == decimalLength)
			break;
	}
	//free(num);
	num = nullptr;
	if (signedN)
	{
		integer[integerLength - 1] *= -1;
	}
}

IDonInt::~IDonInt()
{

}

void IDonInt::ChangeSign()
{
	integer[integerLength - 1] *= -1;
}

bool IsBigger(IDonInt a, IDonInt b)
{
	bool goToDec = true;//IntegerPart
	if (a.integerLength != b.integerLength)
	{
		if (a.integerLength > b.integerLength)
		{
			goToDec = false;
			return true;
		}
		else
		{
			goToDec = false;
			return false;
		}
	}
	else
	{
		for (int i = a.integerLength - 1; i >= 0; i--)
		{
			if (a.integer[i] != b.integer[i])
			{
				if (a.integer[i] > b.integer[i])
				{
					goToDec = false;
					return true;
				}
				else
				{
					goToDec = false;
					return false;
				}
			}
		}
	}
	if (goToDec)//Decimal part
	{
		bool firstDec;
		int shortest = minN(a.decimalLength, b.decimalLength);
		int longest = maxN(a.decimalLength, b.decimalLength, firstDec);
		if (firstDec)
		{
			for (int i = longest - 1; i >= longest - shortest; i--)
			{
				if (a.decimal[i] != b.decimal[i - (longest - shortest)])
				{
					if (a.decimal[i] > b.decimal[i - (longest - shortest)])
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			if (longest - shortest)
			{
				return true;
			}
		}
		else
		{
			for (int i = longest - 1; i >= longest - shortest; i--)
			{
				if (b.decimal[i] != a.decimal[i - (longest - shortest)])
				{
					if (b.decimal[i] > a.decimal[i - (longest - shortest)])
					{
						return false;
					}
					else
					{
						return true;
					}
				}
			}
			if (longest - shortest)
			{
				return false;
			}
		}
	}
	return true;
}

void IDonInt::Writer()//Not always works
{
	int counter = meaning;
	int tenPoint = 0;
	if (work)
	{
		for (int i = integerLength - 1; i >= 0; i--)//Integer Part
		{
			int divider = BASE / 10;
			if (counter >= 6)
			{
				if (i == integerLength - 1)
				{
					cout << integer[i];
					int check = integer[i];
					while (check)
					{
						check /= 10;
						counter--;
					}
				}
				else
				{
					for (int j = 0; j < 6; j++)
					{
						int toPrint = (integer[i] / divider) % 10;
						cout << toPrint;
						divider /= 10;
						counter--;
					}
				}
			}
			else
			{
				if (integerLength > 1)
				{
					if (i != integerLength - 1)
					{
						int divider = BASE / 10;
						int saver = counter;
						for (int j = 0; j < saver; j++)
						{
							int toPrint = (integer[i] / divider) % 10;
							cout << toPrint;
							counter--;
							tenPoint = (i) * 6 + 6 - j + 1;
						}
						cout << "*10^" << tenPoint;
						counter = 0;
						break;
					}
				}
				else
				{
					int check = integer[0];
					int digNum = 0;
					while (check)
					{
						check /= 10;
						digNum++;
					}
					int divider = (int)pow(10, digNum - 1);
					for (int j = 0; j < digNum; j++)
					{
						int toPrint;
						if (divider)
							toPrint = (integer[0] / divider) % 10;
						else
							toPrint = integer[0] % 10;
						cout << toPrint;
						counter--;
						divider /= 10;
					}
				}
				if (meaning == 0)
				{
					cout << 0;
				}
			}
		}

		if (counter > 0)//Decimal Part
		{
			cout << ".";
			for (int i = decimalLength - 1; i >= 0; i--)
			{
				int divider = BASE / 10;
				if (counter >= 6)
				{
					for (int j = 0; j < 6; j++)
					{
						int toPrint = (decimal[i] / divider) % 10;
						cout << toPrint;
						divider /= 10;
					}
					counter -= 6;
				}
				else
				{
					for (int j = 0; j < counter; j++)
					{
						int toPrint = (decimal[i] / divider) % 10;
						cout << toPrint;
						divider /= 10;
					}
				}
			}
		}
	}
	else
	{
		cout << "This number is broken [ " << integer << " " << integerLength << " " << decimal << " " << decimalLength << " ]";
	}
}

void IDonInt::MoveDotLeft(int toMove)//Add check
{
	int newDecimalLength = decimalLength + toMove;
	int* decimalTimed = (int*)calloc(newDecimalLength, sizeof(int));
	if (!decimalTimed)
		work = false;

	int newIntegerLength = integerLength - toMove;
	int* integerTimed = (int*)calloc(newIntegerLength, sizeof(int));
	if (!integerTimed)
		work = false;

	for (int i = 0; i < decimalLength; i++)//1234567
	{
		decimalTimed[i] = decimal[i];
	}
	for (int i = decimalLength; i < newDecimalLength; i++)
	{
		decimalTimed[i] = integer[i - decimalLength];
	}
	for (int i = 0; i < newIntegerLength; i++)
	{
		integerTimed[i] = integer[i + toMove];
	}

	free(integer);
	free(decimal);
	integer = integerTimed;
	decimal = decimalTimed;
	decimalLength = newDecimalLength;
	integerLength = newIntegerLength;
}

int IDonInt::MoveDotRight()
{
	if (decimalLength > 1 && decimal[decimalLength - 1])
	{
		int newDecimalLength = 1;
		int toMove = decimalLength;

		int* decimalTimed = (int*)calloc(newDecimalLength, sizeof(int));
		int newIntegerLength = integerLength + toMove;
		int* integerTimed = (int*)calloc(newIntegerLength, sizeof(int));

		for (int i = 0; i < toMove; i++)
		{
			integerTimed[i] = decimal[i + decimalLength - toMove];
		}
		for (int i = toMove; i < newIntegerLength; i++)
		{
			integerTimed[i] = integer[i - toMove];
		}
		decimalTimed[0] = 0;

		free(integer);
		free(decimal);
		integer = integerTimed;
		decimal = decimalTimed;
		decimalLength = newDecimalLength;
		integerLength = newIntegerLength;
		return toMove;
	}
	return 0;
}

void IDonInt::Destroyer()
{
	if (integer) free(integer);
	if (decimal) free(decimal);
}

void IDonInt::operator= (IDonInt toCopy)
{
	//free(integer);
	//free(decimal);
	bool workN = true;

	int* integerN = (int*)calloc(toCopy.GetintegerLength(), sizeof(int));
	if (!integerN)
		workN = false;
	int integerLengthN = toCopy.GetintegerLength();
	for (int i = 0; i < toCopy.GetintegerLength(); i++)
	{
		integerN[i] = (toCopy.Getinteger())[i];
	}

	int decimalLengthN = toCopy.GetdecimalLength();
	int* decimalN = (int*)calloc(decimalLengthN, sizeof(int));
	if (!decimalN)
		workN = false;
	for (int i = 0; i < decimalLengthN; i++)
	{
		decimalN[i] = (toCopy.Getdecimal())[i];
	}
	int meaningN = toCopy.Getmeaning();
	if (integer) free(integer);
	if (decimal) free(decimal);

	integer = integerN;
	integerLength = integerLengthN;
	decimal = decimalN;
	decimalLength = decimalLengthN;
	work = workN;
	meaning = meaningN;
}

ostream& operator << (ostream& out, IDonInt& c)
{
	int counter = c.meaning;
	int tenPoint = 0;
	if (c.work)
	{
		for (int i = c.integerLength - 1; i >= 0; i--)//Integer Part
		{
			int divider = c.BASE / 10;
			if (counter >= 6)
			{
				if (i == c.integerLength - 1)
				{
					out << c.integer[i];
					int check = c.integer[i];
					while (check)
					{
						check /= 10;
						counter--;
					}
				}
				else
				{
					for (int j = 0; j < 6; j++)
					{
						int toPrint = (c.integer[i] / divider) % 10;
						out << toPrint;
						divider /= 10;
						counter--;
					}
				}
			}
			else
			{
				if (c.integerLength > 1)
				{
					if (i != c.integerLength - 1)
					{
						int divider = c.BASE / 10;
						int saver = counter;
						for (int j = 0; j < saver; j++)
						{
							int toPrint = (c.integer[i] / divider) % 10;
							out << toPrint;
							counter--;
							tenPoint = (i) * 6 + 6 - j + 1;
						}
						out << "*10^" << tenPoint;
						counter = 0;
						break;
					}
				}
				else
				{
					int check = c.integer[0];
					int digNum = 0;
					while (check)
					{
						check /= 10;
						digNum++;
					}
					int divider = (int)pow(10, digNum - 1);
					for (int j = 0; j < digNum; j++)
					{
						int toPrint;
						if (divider)
							toPrint = (c.integer[0] / divider) % 10;
						else
							toPrint = c.integer[0] % 10;
						out << toPrint;
						counter--;
						divider /= 10;
					}
				}
				if (c.meaning == 0 && c.integer[c.integerLength - 1] == 0)
				{
					out << 0;
				}
			}
		}

		if (counter > 0)//Decimal Part
		{
			out << ".";
			for (int i = c.decimalLength - 1; i >= 0; i--)
			{
				int divider = c.BASE / 10;
				if (counter >= 6)
				{
					for (int j = 0; j < 6; j++)
					{
						int toPrint = (c.decimal[i] / divider) % 10;
						out << toPrint;
						divider /= 10;
					}
					counter -= 6;
				}
				else
				{
					for (int j = 0; j < counter; j++)
					{
						int toPrint = (c.decimal[i] / divider) % 10;
						out << toPrint;
						divider /= 10;
					}
				}
			}
		}
	}
	else
	{
		out << "This number is broken [ " << c.integer << " " << c.integerLength << " " << c.decimal << " " << c.decimalLength << " ]";
	}
	return out;
}


void IDonInt::operator += (IDonInt toAdd)
{
	IDonInt sum = *this + toAdd;
	integerLength = sum.integerLength;
	decimalLength = sum.decimalLength;
	meaning = sum.meaning;
	integer = (int*)calloc(integerLength, sizeof(int));
	if (integer == nullptr)
		work = false;
	else
		work = true;
	for (int i = 0; i < integerLength; i++)
	{
		integer[i] = sum.integer[i];
	}
	decimal = (int*)calloc(decimalLength, sizeof(int));
	if (decimal == nullptr || !work)
		work = false;
	else
		work = true;
	for (int i = 0; i < decimalLength; i++)
	{
		decimal[i] = sum.decimal[i];
	}
}

IDonInt operator + (IDonInt first, IDonInt second)
{
	int* sumInteger = nullptr;
	int sumIntegerLength = 0;
	int* sumDecimal = nullptr;
	int sumDecimalLength = 0;
	bool sumWork = false;
	bool signedN = false;
	int sumMeaning;
	long long int signChecker = (long long int)first.integer[first.integerLength - 1] * (long long int)second.integer[second.integerLength - 1];
	int c = 0;

	//Summator
	if (signChecker >= 0)
	{
		if (first.integer[first.integerLength - 1] < 0)
		{
			first.ChangeSign();
			second.ChangeSign();
			signedN = true;
		}
		bool firstDec;
		bool firstInt;
		int adder = 0;
		int decimalLongest = maxN(first.decimalLength, second.decimalLength, firstDec);
		int decimalShortest = minN(first.decimalLength, second.decimalLength);
		int integerLongest = maxN(first.integerLength, second.integerLength, firstInt);
		int integerShortest = minN(first.integerLength, second.integerLength);
		sumDecimalLength = decimalLongest;
		sumDecimal = (int*)calloc(sumDecimalLength, sizeof(int));
		if (sumDecimal == nullptr)
		{
			sumWork = false;
		}
		else
		{
			sumWork = true;
		}
		sumIntegerLength = integerLongest + 1;
		sumInteger = (int*)calloc(sumIntegerLength, sizeof(int));
		if (sumInteger == nullptr || !sumWork)
		{
			sumWork = false;
		}
		else
		{
			sumWork = true;
		}


		if (firstDec)//DecimalPart
		{
			for (int i = 0; i < (decimalLongest - decimalShortest); i++)
			{
				sumDecimal[i] = first.decimal[i];
			}

			for (int i = decimalLongest - decimalShortest; i < decimalLongest; i++)
			{
				sumDecimal[i] = first.decimal[i] + second.decimal[i - (decimalLongest - decimalShortest)] + adder;
				if (sumDecimal[i] >= first.BASE)
				{
					sumDecimal[i] -= first.BASE;
					adder = 1;
				}
			}
		}
		else
		{
			for (int i = 0; i < (decimalLongest - decimalShortest); i++)
			{
				sumDecimal[i] = second.decimal[i];
			}

			for (int i = decimalLongest - decimalShortest; i < decimalLongest; i++)
			{
				sumDecimal[i] = second.decimal[i] + first.decimal[i - (decimalLongest - decimalShortest)] + adder;
				if (sumDecimal[i] >= first.BASE)
				{
					sumDecimal[i] -= first.BASE;
					adder = 1;
				}
				else
				{
					adder = 0;
				}
			}
		}

		if (firstInt)//IntegerPart
		{
			sumMeaning = first.meaning;
			for (int i = 0; i < integerShortest; i++)
			{
				sumInteger[i] = first.integer[i] + second.integer[i] + adder;
				if (sumInteger[i] >= first.BASE)
				{
					sumInteger[i] -= first.BASE;
					adder = 1;
				}
				else
				{
					adder = 0;
				}
			}
			for (int i = integerShortest; i < integerLongest; i++)
			{
				sumInteger[i] = first.integer[i] + adder;
				if (sumInteger[i] >= first.BASE)
				{
					sumInteger[i] -= first.BASE;
					adder = 1;
				}
				else
				{
					adder = 0;
				}
			}
		}
		else
		{
			sumMeaning = second.meaning;
			for (int i = 0; i < integerShortest; i++)
			{
				sumInteger[i] = first.integer[i] + second.integer[i] + adder;
				if (sumInteger[i] >= first.BASE)
				{
					sumInteger[i] -= first.BASE;
					adder = 1;
				}
				else
				{
					adder = 0;
				}
			}
			for (int i = integerShortest; i < integerLongest; i++)
			{
				sumInteger[i] = second.integer[i] + adder;
				if (sumInteger[i] >= first.BASE)
				{
					sumInteger[i] -= first.BASE;
					adder = 1;
				}
				else
				{
					adder = 0;
				}
			}
		}

		if (adder)//Adder Part
		{
			sumInteger[sumIntegerLength - 1] = 1;
		}
		else
		{
			sumIntegerLength -= 1;
			int* timed = (int*)calloc(sumIntegerLength, sizeof(int));
			if (timed == nullptr)
			{
				sumWork = false;
			}
			for (int i = 0; i < sumIntegerLength; i++)
			{
				timed[i] = sumInteger[i];
			}
			free(sumInteger);
			sumInteger = timed;
		}

		if (signedN)
		{
			sumInteger[sumIntegerLength - 1] *= -1;
			first.ChangeSign();
			second.ChangeSign();
		}
		return IDonInt(sumInteger, sumIntegerLength, sumDecimal, sumDecimalLength, sumWork, sumMeaning);
	}

	//Subtraction as summator
	if (first.integer[first.integerLength - 1] > 0 && second.integer[second.integerLength - 1] < 0)
	{
		second.ChangeSign();
		IDonInt result = first - second;
		second.ChangeSign();
		return result;
	}
	if (first.integer[first.integerLength - 1] < 0 && second.integer[second.integerLength - 1] > 0)
	{
		first.ChangeSign();
		IDonInt result = second - first;
		first.ChangeSign();
		return result;
	}
	//return IDonInt(0);
}

IDonInt operator - (IDonInt first, IDonInt second)
{
	//Summing as substraction
	if ((first.integer[first.integerLength - 1] > 0) && (second.integer[second.integerLength - 1] < 0))
	{
		second.ChangeSign();
		IDonInt result = first + second;
		second.ChangeSign();
		return result;
	}
	if ((first.integer[first.integerLength - 1] < 0) && (second.integer[second.integerLength - 1] > 0))
	{
		second.ChangeSign();
		IDonInt result = first + second;
		second.ChangeSign();
		return result;
	}

	//Substraction
	long long int signCheck = ((long long int)(first.integer[first.integerLength - 1])) * ((long long int)(second.integer[second.integerLength - 1]));
	if (signCheck > 0)
	{
		//Block of names
		bool signedN = false, firstDec, firstInt;
		int deleter = 0;
		int* sumInteger = nullptr;
		int sumIntegerLength = 0;
		int* sumDecimal = nullptr;
		int sumDecimalLength = 0;
		bool sumWork = false;
		int sumMeaning;
		int decimalLongest = maxN(first.decimalLength, second.decimalLength, firstDec);
		int decimalShortest = minN(first.decimalLength, second.decimalLength);
		int integerLongest = maxN(first.integerLength, second.integerLength, firstInt);
		int integerShortest = minN(first.integerLength, second.integerLength);
		sumDecimalLength = decimalLongest;
		sumDecimal = (int*)calloc(sumDecimalLength, sizeof(int));
		if (sumDecimal == nullptr)
		{
			sumWork = false;
		}
		else
		{
			sumWork = true;
		}
		sumIntegerLength = integerLongest;
		sumInteger = (int*)calloc(sumIntegerLength, sizeof(int));
		if (sumInteger == nullptr || !sumWork)
		{
			sumWork = false;
		}
		else
		{
			sumWork = true;
		}

		//Counting
		if (first.integer[first.integerLength - 1] < 0)
		{
			signedN = true;
		}

		if (signedN)
		{
			first.ChangeSign();
			second.ChangeSign();
		}

		bool firstNum = IsBigger(first, second);
		if (firstNum)
		{
			sumMeaning = first.meaning;
			for (int i = 0; i < decimalLongest; i++)//Decimal Part
			{
				if (first.decimalLength >= second.decimalLength)
				{
					if (i >= decimalLongest - decimalShortest)
					{
						sumDecimal[i] = first.decimal[i] - second.decimal[i - (decimalLongest - decimalShortest)] - deleter;
					}
					else
					{
						sumDecimal[i] = first.decimal[i] - deleter;
					}
				}
				else
				{
					if (i < decimalLongest - decimalShortest)
					{
						sumDecimal[i] = 0 - second.decimal[i] - deleter;
					}
					else
					{
						sumDecimal[i] = first.decimal[i - (decimalLongest - decimalShortest)] - second.decimal[i] - deleter;
					}
				}

				if (sumDecimal[i] < 0)
				{
					sumDecimal[i] += first.BASE;
					deleter = 1;
				}
				else
				{
					deleter = 0;
				}

			}
			//Integer Part
			for (int i = 0; i < first.integerLength; i++)
			{
				if (i < second.integerLength)
				{
					sumInteger[i] = first.integer[i] - second.integer[i] - deleter;
					if (sumInteger[i] < 0)
					{
						sumInteger[i] += first.BASE;
						deleter = 1;
					}
					else
					{
						deleter = 0;
					}
				}
				else
				{
					sumInteger[i] = first.integer[i] - deleter;
					if (sumInteger[i] < 0)
					{
						sumInteger[i] += first.BASE;
						deleter = 1;
					}
					else
					{
						deleter = 0;
					}
				}
			}
			int counter = sumIntegerLength;
			int i = sumIntegerLength - 1;
			while (!sumInteger[i] && i >= 0)
			{
				counter--;
				i--;
			}
			if (counter < 1)
			{
				counter = 1;
			}
			if (counter < sumIntegerLength)
			{
				sumIntegerLength = counter;
				int* timed = (int*)calloc(sumIntegerLength, sizeof(int));
				if (timed == nullptr)
				{
					sumWork = false;
				}
				for (i = 0; i < sumIntegerLength; i++)
				{
					timed[i] = sumInteger[i];
				}
				free(sumInteger);
				sumInteger = timed;
			}
			if (signedN)
			{
				first.ChangeSign();
				second.ChangeSign();
				sumInteger[sumIntegerLength - 1] *= -1;
			}
			return IDonInt(sumInteger, sumIntegerLength, sumDecimal, sumDecimalLength, sumWork, sumMeaning);
		}
		else
		{
			sumMeaning = second.meaning;
			for (int i = 0; i < decimalLongest; i++)//Decimal Part
			{
				if (second.decimalLength >= first.decimalLength)
				{
					if (i >= decimalLongest - decimalShortest)
					{
						sumDecimal[i] = second.decimal[i] - first.decimal[i - (decimalLongest - decimalShortest)] - deleter;
					}
					else
					{
						sumDecimal[i] = second.decimal[i] - deleter;
					}
				}
				else
				{
					if (i < decimalLongest - decimalShortest)
					{
						sumDecimal[i] = 0 - first.decimal[i] - deleter;
					}
					else
					{
						sumDecimal[i] = second.decimal[i - (decimalLongest - decimalShortest)] - first.decimal[i] - deleter;
					}
				}
				if (sumDecimal[i] < 0)
				{
					sumDecimal[i] += first.BASE;
					deleter = 1;
				}
				else
				{
					deleter = 0;
				}

			}
			//Integer Part
			for (int i = 0; i < second.integerLength; i++)
			{
				if (i < first.integerLength)
				{
					sumInteger[i] = second.integer[i] - first.integer[i] - deleter;
					if (sumInteger[i] < 0)
					{
						sumInteger[i] += first.BASE;
						deleter = 1;
					}
					else
					{
						deleter = 0;
					}
				}
				else
				{
					sumInteger[i] = second.integer[i] - deleter;
					if (sumInteger[i] < 0)
					{
						sumInteger[i] += first.BASE;
						deleter = 1;
					}
					else
					{
						deleter = 0;
					}
				}
			}
			int counter = sumIntegerLength;
			int i = sumIntegerLength - 1;
			while (!sumInteger[i])
			{
				counter--;
				i--;
			}
			if (counter < sumIntegerLength)
			{
				sumIntegerLength = counter;
				int* timed = (int*)calloc(sumIntegerLength, sizeof(int));
				if (timed == nullptr)
				{
					sumWork = false;
				}
				for (i = 0; i < sumIntegerLength; i++)
				{
					timed[i] = sumInteger[i];
				}
				free(sumInteger);
				sumInteger = timed;
			}
			if (signedN)
			{
				first.ChangeSign();
				second.ChangeSign();
			}
			else
			{
				sumInteger[sumIntegerLength - 1] *= -1;
			}
			return IDonInt(sumInteger, sumIntegerLength, sumDecimal, sumDecimalLength, sumWork, sumMeaning);
		}
	}
	//return IDonInt(0);
}

IDonInt operator * (IDonInt firstN, IDonInt secondN)
{
	IDonInt multiplication(0);
	IDonInt first(0);
	IDonInt second(0);
	first = firstN;
	second = secondN;
	long long int firstBASE = first.BASE;
	int movedFirst = 0;
	int movedSecond = 0;
	int movedResult = 0;
	long long int adder = 0;
	bool firstLength;
	int* multInt = (int*)calloc(1, sizeof(int));
	multInt[0] = 0;
	int multIntLength = 1;
	bool signedN = false;
	bool signedF = false;
	bool signedS = false;
	bool add = false;
	bool mWork = true;
	int lengthS = 0;
	long long dig;
	int sumItr;
	int* toSum;
	int toSumLength;
	movedFirst = first.MoveDotRight();
	movedSecond = second.MoveDotRight();
	movedResult = movedFirst + movedSecond;

	int longest = maxN(first.integerLength, second.integerLength, firstLength);
	int shortest = minN(first.integerLength, second.integerLength);
	long long int checkSign = ((long long int)(first.integer[first.integerLength - 1])) * ((long long int)(second.integer[second.integerLength - 1]));
	if (checkSign < 0)
	{
		signedN = true;
	}
	if (first.integer[first.integerLength - 1] < 0)
	{
		signedF = true;
		first.ChangeSign();
	}
	if (second.integer[second.integerLength - 1] < 0)
	{
		signedS = true;
		second.ChangeSign();
	}
	int lengthCounter = longest;

	for (int i = 0; i < shortest; i++)
	{
		sumItr = 0;
		lengthCounter++;
		toSum = (int*)calloc(lengthCounter + 1, sizeof(int));
		if (toSum == nullptr || !mWork)
			mWork = false;
		else
			mWork = true;
		for (int j = 0; j < longest; j++)
		{
			if (i > 0 && j == 0)
			{
				for (int k = 0; k < lengthCounter - longest - 1; k++)
				{
					toSum[k] = 0;
					sumItr++;
				}
			}
			if (firstLength)
			{
				dig = ((long long int)(second.integer[i])) * ((long long int)(first.integer[j])) + adder;
			}
			else
			{
				dig = ((long long int)(second.integer[j])) * ((long long int)(first.integer[i])) + adder;
			}
			{
				if (dig > firstBASE)
				{
					toSum[sumItr] = ((int)(dig % firstBASE));
					adder = (dig / firstBASE);
					sumItr++;
				}
				else
				{
					toSum[sumItr] = (int)dig;
					adder = ((long long int)(0));
					sumItr++;
				}
			}
		}
		if (adder)
		{
			toSum[sumItr] = adder;
			adder = 0;
		}
		else
		{
			toSum[sumItr] = 0;
		}

		for (int j = lengthCounter; j >= 0; j--)
		{
			if (toSum[j])
			{
				lengthS = j + 1;
				break;
			}
		}
		int* sumT = (int*)calloc(lengthS, sizeof(int));
		for (int j = 0; j < lengthS; j++)
			sumT[j] = toSum[j];
		free(toSum);
		toSum = sumT;
		IDonInt toAdd(toSum, lengthS);
		multiplication += toAdd;
		free(toSum);
		toAdd.Destroyer();
	}

	first.MoveDotLeft(movedFirst);
	second.MoveDotLeft(movedSecond);
	multiplication.MoveDotLeft(movedResult);
	if (signedF)
	{
		first.ChangeSign();
	}
	if (signedS)
	{
		second.ChangeSign();
	}
	//IDonInt multiplication(multInt, multIntLength);
	free(multInt);
	if (signedN)
	{
		multiplication.ChangeSign();
	}
	multiplication.meaning = first.meaning + second.meaning;
	first.Destroyer();
	second.Destroyer();
	return multiplication;
}

