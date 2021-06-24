// ------------------------------------------------------------------------------------------
// Name: Neina Cichon
// Abstract: String Manipulation
// Date: 2020-10-10
// ------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes – built-in libraries of functions
// --------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------
const long lngARRAY_SIZE = 100;

// --------------------------------------------------------------------------------
// User Defined Types (UDT)
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
int StringLength(char strBuffer[]);
void PrintString(char strBuffer[]);
void CopyString(char strDestination[], char strSource[]);
int FindLetterIndexSensitive(char strSource[], char chrLetterToFind);
int FindLetterIndexInsensitive(char strSource[], char chrLetterToFind);
void AppendString(char strDestination[], char strSource[]);
void ReverseCopyString(char strDestination[], char strSource[]);
void AllCapsStringCopy(char strDestination[], char strSource[]);
void CopyStringAtIndex(char strDestination, char strSource, int intStartIndex, int intLength);
int CountWords(char strSource[]);
void PrintEnterprise();

// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------
void main()
{

	int intLength = 0;
	char strSource[100] = "Space... The Final  Frontier!";
	char strDestination[100];
	int intIndexSensitive = 0;
	int intIndexInsensitive = 0;
	int intWordCount = 0;

	//Problem #1: String Length
	printf("--Problem #1: String Length--\n");
	intLength = StringLength(strSource);
	printf("The length is %d", intLength);

	//Problem #2: Copy Source String
	printf("\n\n--Problem #2: Copy Source String--\n");
	printf("The Source String: ");
	PrintString(strSource);
	CopyString(strDestination, strSource);
	printf("\nThe Destination String: ");
	PrintString(strDestination);

	//Problem #3: Find Index of Letter - Case Sensitive
	printf("\n\n--Problem #3: Find Index of Letter - Case Sensitive--\n");
	intIndexSensitive = FindLetterIndexSensitive(strSource, 'i');
	printf("The Index of the letter is: %d \n", intIndexSensitive);

	//Problem #4: Find Index of Letter - Case Insensitive
	printf("\n\n--Problem #4: Find Index of Letter - Case Insensitive--\n");
	intIndexInsensitive = FindLetterIndexInsensitive(strSource, 'I');
	printf("The Index of the letter is: %d \n", intIndexInsensitive);

	//Problem #5: Add Source String to the End of Destination String 
	printf("\n\n--Problem #5: Add Source String to the End of Destination String--\n");
	printf("The Appended String: ");
	AppendString(strDestination, strSource);
	PrintString(strDestination);
	printf("\n");

	//Problem #6: Copy Source String to Destination String in Reverse
	printf("\n\n--Problem #6: Copy Source String to Destination String in Reverse--\n");
	printf("The Source String: ");
	PrintString(strSource);
	ReverseCopyString(strDestination, strSource);
	printf("\nThe Destination String: ");
	PrintString(strDestination);
	printf("\n");

	//Problem #7: Copy Source string to Destination String as all Uppercase
	printf("\n\n--Problem #7: Copy Source string to Destination String as all Uppercase--\n");
	printf("The Source String: ");
	PrintString(strSource);
	AllCapsStringCopy(strDestination, strSource);
	printf("\nThe Destination String: ");
	PrintString(strDestination);
	printf("\n");

	//Problem #8: Copy Source string to Destination String starting at index x
	printf("\n\n--Problem  #8: Copy Source string to Destination String starting at index 5--\n");
	printf("The Source String: ");
	CopyStringAtIndex(strDestination, strSource, 5, intLength);
	printf("\nThe Destination String: ");
	PrintString(strDestination);
	printf("\n");


	//Problem #9: Count Words in String
	printf("\n\n--Problem #9: Count Words in String--\n");
	printf("The Source String: ");
	PrintString(strSource);
	intWordCount = CountWords(strSource);
	printf("\nWord Count: %d\n\n", intWordCount);


	PrintEnterprise();
	system("pause");
}

// --------------------------------------------------------------------------------
// Name: StringLength
// Abstract: Get Length Of String
// --------------------------------------------------------------------------------
int StringLength(char strSource[])
{
	int intIndex = 0;

	while (strSource[intIndex] != 0)
	{
		intIndex += 1;

	}
	return intIndex;

}


// --------------------------------------------------------------------------------
// Name: PrintLength
// Abstract: Print a String
// --------------------------------------------------------------------------------
void PrintString(char strBuffer[])
{
	int intIndex = 0;

	while (strBuffer[intIndex] != 0)
	{
		printf("%c", strBuffer[intIndex]);
		intIndex += 1;
	}

}


// --------------------------------------------------------------------------------
// Name: CopyString
// Abstract: Copy Source String to Destination String Variable
// --------------------------------------------------------------------------------
void CopyString(char strDestination[], char strSource[])
{
	int intIndex = 0;

	while (strSource[intIndex] != 0)
	{
		strDestination[intIndex] = strSource[intIndex];
		intIndex += 1;
	}
	//terminate
	strDestination[intIndex] = 0;
} 


// --------------------------------------------------------------------------------
// Name: FindLetterIndexSensitive
// Abstract: Find a Letter in String (Case Sensitive)
// --------------------------------------------------------------------------------
int FindLetterIndexSensitive(char strSource[], char chrLetterToFind)
{
	int intLetterToFindIndex = -1;
	int intIndex = 0;

	while (strSource[intIndex] != 0)
	{

		if (strSource[intIndex] == chrLetterToFind)
		{
			intLetterToFindIndex = intIndex;
			break;
		}
		intIndex += 1;
	}
	return intLetterToFindIndex;
}


// --------------------------------------------------------------------------------
// Name: FindLetterIndexInsensitive
// Abstract: Find a Letter in String (Case Insensitive)
// --------------------------------------------------------------------------------
int FindLetterIndexInsensitive(char strSource[], char chrLetterToFind)
{
	int intLetterToFindIndex = -1;
	int intIndex = 0;
	char chrTempChar = '0';

	if (chrLetterToFind >= 'a' && chrLetterToFind <= 'z')
	{
		chrLetterToFind -= 32;
	}

	while (strSource[intIndex] != 0)
	{
		if (strSource[intIndex] >= 'a' && strSource[intIndex] <= 'z')
		{
			chrTempChar = strSource[intIndex] - 32;
		}
		else
		{
			chrTempChar = strSource[intIndex];
		}

		if (chrTempChar == chrLetterToFind)
		{
			intLetterToFindIndex = intIndex;
			break;
		}
		intIndex += 1;
	}
	return intLetterToFindIndex;
}



// --------------------------------------------------------------------------------
// Name: AppendString
// Abstract: Add Source String to the end of Destination String
// --------------------------------------------------------------------------------
void AppendString(char strDestination[], char strSource[])
{
	int intIndexDestination = 0;
	int intIndexSource = 0;
	int intIndex = 0;
	int intIndexTotal = 0;

	//get destination string length
	while (strDestination[intIndexDestination] != 0)
	{
		intIndexDestination += 1;
	}

	//get source string length
	while (strSource[intIndexSource] != 0)
	{
		intIndexSource += 1;
	}

	intIndexTotal = intIndexDestination + 1;

	//terminate
	strDestination[intIndexTotal] = 0;

	//add second string beginning at length index
	for (intIndex = 0; intIndex < intIndexTotal; intIndex += 1, intIndexDestination += 1)
	{
		strDestination[intIndexDestination] = strSource[intIndex];
	}

	//terminate
	strDestination[intIndexDestination] = 0;

}



// --------------------------------------------------------------------------------
// Name: ReverseCopyString
// Abstract: Copy Source String to Destination String in Reverse Order (ABC -> CBA)
// --------------------------------------------------------------------------------
void ReverseCopyString(char strDestination[], char strSource[])
{
	int intIndex = 0;
	int intIndexSource = 0;
	int intIndexGoal = 0;

	//get source string length
	while (strSource[intIndexSource] != 0)
	{
		intIndexSource += 1;
	}
	intIndexSource -= 1;
	intIndexGoal = intIndexSource + 1;

	for (intIndex = 0; intIndex < intIndexGoal; intIndex += 1, intIndexSource -= 1)
	{
		strDestination[intIndex] = strSource[intIndexSource];
	}

	//terminate
	strDestination[intIndex] = 0;
}


// --------------------------------------------------------------------------------
// Name: AllCapsStringCopy
// Abstract: Copy Source String to Destination String in ALL CAPS
// --------------------------------------------------------------------------------
void AllCapsStringCopy(char strDestination[], char strSource[])
{
	int intIndex = 0;

	while (strSource[intIndex] != 0)
	{
		if (strSource[intIndex] >= 'a' && strSource[intIndex] <= 'z')
		{
			strDestination[intIndex] = strSource[intIndex] - 32;
		}
		else
		{
			strDestination[intIndex] = strSource[intIndex];
		}

		intIndex += 1;
	}
	//terminate
	strDestination[intIndex] = 0;
}


// --------------------------------------------------------------------------------
// Name: CopyStringAtIndex
// Abstract: Copy Source String to Destination String beginning at X index
// --------------------------------------------------------------------------------
void CopyStringAtIndex(char strDestination[], char strSource[], int intStartIndex, int intLength)
{
	int intIndex = 0;


	for (intIndex = 0; intIndex < intLength; intIndex += 1, intStartIndex += 1 )
	{
		strDestination[intIndex] = strSource[intStartIndex];
	}

	//terminate
	strDestination[intIndex] = 0;
}


// --------------------------------------------------------------------------------
// Name: CountWords
// Abstract: Count Words In String
// --------------------------------------------------------------------------------
int CountWords(char strSource[])
{
	int intIndex = 0;
	int intWordCount = 0;

	while (strSource[intIndex] != 0)
	{
		if (strSource[intIndex] > 'A' && strSource[intIndex] < 'Z')
		{
			if (strSource[intIndex + 1] == ' ' || strSource[intIndex + 1] == '!' || strSource[intIndex + 1] == '.' || strSource[intIndex + 1] == '?' || strSource[intIndex + 1] == '"' || strSource[intIndex + 1] == ',' || strSource[intIndex + 1] == ';' || strSource[intIndex + 1] == ':')
			{
				intWordCount += 1;
			}
		}
		else if (strSource[intIndex] > 'a' && strSource[intIndex] < 'z')
		{
			if (strSource[intIndex + 1] == ' ' || strSource[intIndex + 1] == '!' || strSource[intIndex + 1] == '.' || strSource[intIndex + 1] == '?' || strSource[intIndex + 1] == '"' || strSource[intIndex + 1] == ',' || strSource[intIndex + 1] == ';' || strSource[intIndex + 1] == ':' || strSource[intIndex + 1] == 0)
			{
				intWordCount += 1;
			}
		}
		intIndex += 1;
	}

	return intWordCount;
}


// --------------------------------------------------------------------------------
// Name: PrintEnterprise
// Abstract: Prints ASCII art of enterprise
// --------------------------------------------------------------------------------
void PrintEnterprise()
{
	printf("\n\n");
	printf(" ___________________        ____....-----....____\n");
	printf("(________________||_)   ==============================\n");
	printf("    ______%c   %c_______.--'.  `---..._____...---'\n", 92, 92);
	printf("    `-------..__            `,/\n");
	printf("                `-._ -  -  - |\n");
	printf("                    `-------'\n");
	printf("\n\n");
}