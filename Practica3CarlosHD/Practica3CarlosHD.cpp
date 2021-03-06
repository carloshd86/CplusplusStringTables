// Practica3CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>


/*******/

char * getStringTableElement(const char * const * stringTable, int tableLength, int index);
int getStringTableElementReversed(char * outputBuffer, const char * const * stringTable, int tableLength, int index);

/*******/


/**
Returns the string stored in the index of the table, or a null pointer if it does not exist.

@param stringTable Table of strings.
@param tableLength Length of the table (number of strings contained in the table).
@param index Index of the string that must be returned

@return The pointer to the string stored in the index of the table, or a null pointer if it does not exist.
*/
char * getStringTableElement(const char * const * stringTable, int tableLength, int index)
{
	// The only condition to break is that the table has no length. Otherwise, a null pointer will be returned if the index cannot be accessed.
	assert(tableLength >= 0);

	if (stringTable && tableLength > 0 && index < tableLength)
	{
		if (*(stringTable + index))
		{
			return const_cast<char *>(*(stringTable + index));
		}
		else
		{
			return nullptr;
		}
	}

	return nullptr;
}

/**
Stores in an output buffer the reversed string of the string stored in the index of the table, or a null pointer if it does not exist.

@param outputBuffer The buffer where the reversed string will be stored.
@param stringTable Table of strings.
@param tableLength Length of the table (number of strings contained in the table).
@param index Index of the string that must be returned

@return 0 if the string was not created, 1 otherwise.
*/
int getStringTableElementReversed(char * outputBuffer, const char * const * stringTable, int tableLength, int index)
{
	assert(outputBuffer);

	// Referring to the table, the only condition to break is that it has no length. Otherwise, a null pointer will be returned if the index cannot be accessed.
	assert(tableLength >= 0);

	if (stringTable && tableLength > 0 && index < tableLength)
	{
		char * stringToReverse = getStringTableElement(stringTable, tableLength, index);

		if (stringToReverse)
		{
			// Length of the string.
			unsigned int stringLength = 0;

			// Custom strlen
			while ('\0' != *(stringToReverse + stringLength))
				stringLength++;

			unsigned int i = 0;
			while (i <= ((stringLength - 1) - i))
			{
				*(outputBuffer + i) = *(stringToReverse + ((stringLength - 1) - i));
				*(outputBuffer + ((stringLength - 1) - i)) = *(stringToReverse + i);
				i++;
			}
			*(outputBuffer + stringLength) = '\0';
			return 1;
		}
	}

	return 0;
}


int main()
{
	char * tStrings[] = { "Even", "Odd", "This is a complete sentence", "This is a number 11 and this is another 20937" };
	int tableLength = 4;
	char * buffer = nullptr;
	int reverseResult;

	printf("\nObtaining the strings in table:\n");
	printf("\n%s", getStringTableElement(tStrings, tableLength, 0));
	printf("\n%s", getStringTableElement(tStrings, tableLength, 1));
	printf("\n%s", getStringTableElement(tStrings, tableLength, 2));
	printf("\n%s", getStringTableElement(tStrings, tableLength, 3));
	// Non existing element
	printf("\n%s", getStringTableElement(tStrings, tableLength, 4));



	printf("\n\nObtaining the reversed strings in table:\n");
	buffer = new char[strlen(tStrings[0]) + 1];
	reverseResult = getStringTableElementReversed(buffer, tStrings, tableLength, 0);
	printf("\n Result: %d | %s", reverseResult, buffer);
	delete[]buffer;
	buffer = nullptr;

	buffer = new char[strlen(tStrings[1]) + 1];
	reverseResult = getStringTableElementReversed(buffer, tStrings, tableLength, 1);
	printf("\n Result: %d | %s", reverseResult, buffer);
	delete[]buffer;
	buffer = nullptr;

	buffer = new char[strlen(tStrings[2]) + 1];
	reverseResult = getStringTableElementReversed(buffer, tStrings, tableLength, 2);
	printf("\n Result: %d | %s", reverseResult, buffer);
	delete[]buffer;
	buffer = nullptr;

	buffer = new char[strlen(tStrings[3]) + 1];
	reverseResult = getStringTableElementReversed(buffer, tStrings, tableLength, 3);
	printf("\n Result: %d | %s", reverseResult, buffer);
	delete[]buffer;
	buffer = nullptr;

	// Non existing element
	buffer = new char[2];
	reverseResult = getStringTableElementReversed(buffer, tStrings, tableLength, 4);
	printf("\n Result: %d | %s", reverseResult, buffer);
	delete[]buffer;
	buffer = nullptr;

	printf("\n\n Press Enter to exit");

	getchar();

	return 0;
}

