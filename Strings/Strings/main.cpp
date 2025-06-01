#include <stdio.h>
#include <stdlib.h>
#include <string>

// How to initialize a char array.
void intializeCharArray()
{
	char a1[5];
	char a2[5] = { 'A', 'B', 'C', 'D', 'E' };
	char a3[] = { 'A', 'B', 'C', 'D', 'E' };
	char a4[5] = { 65,66,67,68,69 };
}

// How to initialize a string.
void intializeReadAndWriteString()
{
	char name1[10] = { 'J', 'o', 'h', 'n', '\0' };
	char name2[] = { 'J', 'o', 'h', 'n', '\0' };
	char name3[] = "John";

	char name4[10];
	// Read John.
	// scanf_s("%s", name4);
	// scanf("%s", name4);
	// scanf_s("%s", name4, (unsigned)_countof(name4));
	scanf_s("%s", name4, 10);
	printf("%s", name4);

	// Read John Doe.
	char name5[10];
	fgets(name5, sizeof(name5), stdin);
	// name4[strcspn(name4, "\n")] = '\0';  // Optional: strip newline
	puts(name4);
}

// Print the length of a string
void lengthOfString()
{
	char str[] = "welcome";
	int strIndx;
	for (strIndx = 0; str[strIndx] != '\0'; ++strIndx)
	{
		// Do nothing as we want to get the length of the array based on index.
	}
	printf("Length of a given string is: %d", strIndx);
}

// Change the case of a given string
// ASCII codes for chars A: 65, a: 97, B: 66, b: 98
// Difference in the ASCII codes for given char from case to case is 32.
void changingCaseOfString()
{
	char str[] = "welcom6783332%*^&T*e";
	
	// As the alphabates are integer ASCII codes.
	int strIndx = 0;
	for (; strIndx < str[strIndx] != '\0'; strIndx++)
	{
		// Condition for checking if the character being processed is capial or lower case char.
		// Handle other chars like int, or special characters these should be unchanged.
		if ((int)str[strIndx] >= 97 && str[strIndx] <= 122)
		{
			str[strIndx] = str[strIndx] - 32;
		}
		else if ((int)str[strIndx] >= 65 && str[strIndx] <= 90)
		{
			str[strIndx] = str[strIndx] + 32;
		}

		// Alternate way using ternary operator.
		// This does not check for the special chars only a-z and A-Z characters are processed.
		// str[strIndx] = (int)str[strIndx] >= 97 ? str[strIndx] - 32 : str[strIndx] + 32;
	}
	printf("The updated case of the string is: %s", str);
}

// Count number of words and vowels present in a string.
void countNumOfWordsAndVowelsInStr()
{
	char str[] = " ";
	int strIndx = 0;
	int wordsInStr = 0;
	int vowelsInStr = 0;
	int lettersInStr = 0;
	int consonentsInStr = 0;
	for (strIndx = 0; str[strIndx] != '\0'; strIndx++)
	{
		if (str[strIndx] == ' ')
		{
			wordsInStr++;
		}
		// else if (str[strIndx] == 'a' || str[strIndx] == 'e' || str[strIndx] == 'i' || str[strIndx] == 'o' || str[strIndx] == 'u'
		// 	|| str[strIndx] == 'A' || str[strIndx] == 'E' || str[strIndx] == 'I' || str[strIndx] == 'O' || str[strIndx] == 'U')
		else if (strchr("aeiouAEIOU", str[strIndx])) // Using string.h functions
		{
			vowelsInStr++;
			lettersInStr++;
		}
		else if (str[strIndx] >= 65 && str[strIndx] <= 90 || str[strIndx] >= 97 && str[strIndx] <= 122)
		{
			lettersInStr++;
			consonentsInStr++;
		}
		else
		{
			lettersInStr++;
		}
	}
	printf("The number of words, letters, consonents and vowels in a string are %d, %d, %d and %d respectively.", wordsInStr, lettersInStr, consonentsInStr, vowelsInStr);
}

// Count number of words and vowels present in a string.
// This method demostrates the way to cound the words, consonents, vowels, and no. of letters in a string.
void countNumOfWordsAndVowelsInStr1()
{
	char str[] = "How are you?";
	int strIndx = 0;
	int wordsInStr = 0;
	int vowelsInStr = 0;
	int lettersInStr = 0;
	int consonentsInStr = 0;
	int inWord = 0; // 0 = not in word, 1 = in word

	for (strIndx = 0; str[strIndx] != '\0'; strIndx++)
	{
		char ch = str[strIndx];

		// Count vowels
		if (strchr("aeiouAEIOU", ch))
		{
			vowelsInStr++;
			lettersInStr++;
		}
		// Count consonants (alphabetic but not vowels)
		else if (isalpha(ch))
		{
			consonentsInStr++;
			lettersInStr++;
		}
		// Any special character other than the space is considered as letter.
		else if (!isspace(ch))
		{
			lettersInStr++;
		}

		// Word detection: if we hit an alpha character and we’re not in a word yet
		if (isalpha(ch))
		{
			if (!inWord)
			{
				inWord = 1;
				wordsInStr++;
			}
		}
		else
		{
			inWord = 0; // reset when outside word
		}
	}
	printf("The number of words, letters, consonents and vowels in a string are %d, %d, %d and %d respectively.\n",
		wordsInStr, lettersInStr, consonentsInStr, vowelsInStr);
}

// Count number of words and vowels present in a string.
// This method demostrates the way to cound the words, consonents, vowels, and no. of letters in a string.
void countNumOfWordsAndVowelsInStr2()
{
	char str[] = "How are you?";
	int strIndx = 0;
	int wordsInStr = 0;
	int vowelsInStr = 0;
	int lettersInStr = 0;
	int consonentsInStr = 0;
	int inWord = 0; // 0 = not in word, 1 = in word


	for (strIndx = 0; str[strIndx] != '\0'; strIndx++)
	{
		char ch = str[strIndx];

		// Check if character is a letter (A-Z or a-z)
		int isAlpha = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');

		// Count vowels
		if (strchr("aeiouAEIOU", ch))
		{
			vowelsInStr++;
			lettersInStr++;
		}
		// Count consonants (alphabetic but not vowels)
		else if (isAlpha)
		{
			consonentsInStr++;
			lettersInStr++;
		}
		// Any special character other than the space is considered as letter.
		else if (ch != ' ')
		{
			lettersInStr++;
		}

		// Word detection: if we hit an alpha character and we’re not in a word yet
		if (isAlpha)
		{
			if (!inWord)
			{
				inWord = 1;
				wordsInStr++;
			}
		}
		else
		{
			inWord = 0; // reset when outside word
		}
	}
	printf("The number of words, letters, consonents and vowels in a string are %d, %d, %d and %d respectively.\n",
		wordsInStr, lettersInStr, consonentsInStr, vowelsInStr);
}

// Validate a string
// Validate the string which should only contain a alphanumeric value, containing any special chars will make it invalid.
bool validateString()
{
	char str1[] = "MyRi089";
	// char str2[] = "MyRi08&#9";

	for (int strIndx = 0; str1[strIndx] != '\0'; strIndx++)
	{
		char ch = str1[strIndx];
		int isAplhaNum = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= 48 && ch <= 57);

		if (!isAplhaNum)
		{
			printf("The string provided is invalid.\n");
			return false;
		}
	}
	printf("The string provided is valid.\n");
	return true;
}

void reversingString()
{
	char a[] = "Welcome";
	char* b1 = (char*)malloc(strlen(a) * sizeof(char));

	int bIndx = 0;
	int aIndx = strlen(a) - 1;
	for ( ; aIndx >= 0; --aIndx, ++bIndx)
	{
		b1[bIndx] = a[aIndx];
	}

	// Add a string delimeter.
	b1[bIndx] = '\0';
	printf("The reveresed string of Welcome is %s", b1);
}

void reversingString1()
{
	char a[] = "Welcome";
	
	int bIndx = 0;
	int aIndx = strlen(a) - 1;
	for (; bIndx < aIndx; --aIndx, ++bIndx)
	{
		int temp = a[bIndx];
		a[bIndx] = a[aIndx];
		a[aIndx] = temp;
	}

	printf("The reveresed string of Welcome is %s", a);
}

bool comparingString()
{
	char str1[] = "Pointer";
	char str2[] = "Pointen";

	if (strlen(str1) != strlen(str2))
	{
		printf("The two strings provided are not equal.");
		return false;
	}
	for (int strIndx = 0; str1[strIndx] != '\0'; ++strIndx)
	{
		if (str1[strIndx] != str2[strIndx])
		{
			printf("The two strings provided are not equal.\n");
			if (str1[strIndx] < str2[strIndx])
			{
				printf("%s is smaller than %s.\n", str1, str2);
				return false;
			}
			printf("%s is greater than %s.\n", str1, str2);
			return false;
		}
	}
	printf("The two strings provided are equal.\n");
	return true;
}

bool palindrome()
{
	char str1[] = "{{{}}}";
	for (int strIndx1 = 0, strIndx2 = strlen(str1) - 1; strIndx1 < strIndx2; ++strIndx1, --strIndx2)
	{
		if( str1[strIndx1] != str1[strIndx2] )
		{
			printf("Given string is not a palindrome.\n");
			return false;
		}
	}
	printf("Given string is a palindrome.\n");
	return true;
}

bool hasBalancedCurlyBraces()
{
	char str1[] = "{{{}3}}";
	// if (strlen(str1) % 2 != 0)
	// {
	// 	  printf("Given string does not has balanced curly braces.\n");
	// 	  return false;
	// }

	int curlyBracesCount = 0;
	for (int strIndx1 = 0; str1[strIndx1] != '\0'; ++strIndx1)
	{
		if (str1[strIndx1] == '{')
		{
			curlyBracesCount++;
		}
		else if (str1[strIndx1] == '}')
		{
			curlyBracesCount--;
		}
	}
	if (curlyBracesCount == 0)
	{
		printf("Given string do have balanced curly braces.\n");
	}
	else
	{
		printf("Given string do not have balanced curly braces.\n");
		return false;
	}
	return true;
}

// 1. We can compare the letters with all other letters in a string.
// 2. Using an HashTable for counting.
// 3. Using bits.
bool isDuplicateCharInString1()
{
	char str1[] = "asdfghjuak";
	for (int strIndx = 0; strIndx < strlen(str1); ++strIndx)
	{
		int auxIndx = strIndx + 1;
		for ( ; auxIndx < strlen(str1); ++auxIndx)
		{
			if (str1[strIndx] == str1[auxIndx])
			{
				printf("There is a duplicate character found in a string.\n");
				return true;
			}
		}
	}
	printf("There is no duplicate character found in a string.\n");
	return false;
}

// Using an HashTable for counting.
// Consider we always have a string of small case letters.
bool isDuplicateCharInString2()
{
	// We know the values for the small case ASCII codes start from a: 97, z:122
	// Let's calculate the length of alphabets as we know 26.
	// so for holding all the characters from a-z we need an array of a[25]
	char str1[] = "asdfghjuk";
	int hashArr[26] = { 0 };

	for (int strIndx = 0; str1[strIndx] != '\0'; ++strIndx)
	{
		if (hashArr[122 - (int)str1[strIndx]] == 0)
		{
			hashArr[122 - (int)str1[strIndx]] = (int)str1[strIndx];
		}
		else
		{
			printf("There is a duplicate character found in a string.\n");
			return true;
		}
	}
	printf("There is no duplicate character found in a string.\n");
	return false;
}

// Using Bits.
// Consider we always have a string of small case letters.
// We should know the concepts of Left Shift, Right Shift, Bits ORing (Merging), Bits ANDing (Masking).
bool isDuplicateCharInString3()
{
	// As we need space of 26 to check all the possible characters, we can use 26 bits.
	// Bits can be in the multiple of 8bits in our case. So let's take 32 bits. i.e. 4 bytes.
	// 4 bytes of space is consumed by integer, or long integer.
	char str1[] = "sdfgahjuk";
	int h = 0;
	int x = 0;
	// We know the values for the small case ASCII codes start from a: 97, z:122

	for (int strIndx = 0; str1[strIndx] != '\0'; ++strIndx)
	{
		x = 1;
		x = x << str1[strIndx] - 97;

		// Perform masking using bitwise AND to check if the bit is turned on already to check duplicates.
		if (!(h & x))
		{
			// Perform merging using bitwise OR
			h = x | h;
		}
		else
		{
			printf("The value %c in the string is duplicated.\n", str1[strIndx]);
			return true;
		}
	}
	printf("There are no duplicate values in the string.\n");
	return false;
}

bool isAnagram()
{
	char a[] = "listen";
	char b[] = "silent";

	if (strlen(a) != strlen(b))
	{
		printf("Given strings %s, and %s are not anagrams.", a, b);
		return false;
	}
	int hashArr[26] = { 0 };
	for (int aIndx = 0; a[aIndx] != '\0'; ++aIndx)
	{
		hashArr[122 - (int)a[aIndx]]++;
	}
	for (int bIndx = 0; b[bIndx] != '\0'; ++bIndx)
	{
		hashArr[122 - (int)b[bIndx]]--;
		if (hashArr[122 - (int)b[bIndx]] < 0)
		{
			printf("Given strings %s, and %s are not anagrams.", a, b);
			return false;
		}
	}
	printf("Given strings %s, and %s are anagrams.", a, b);
	return true;
}

// A string permutation is a rearrangement of the characters in a string,
// creating a new sequence while using all the original characters
// e.g. ABC => ABC, ACB, CAB, CBA, BAC, BCA => n!
// Solution can be achieved by State Space Tree, recursion and Backtracking.

//                    [ABC]
//          +-----------|-----------+
//          |           |           |
//          A           B           C
//         / \         / \         / \
//        B   C       A   C       A   B
//       /     \     /     \     /     \
//      C       B   C       A   B       A
//     ABC    ACB  BAC     BCA CAB     CBA

void permulationOfString(int k)
{
	char str[8] = "ABCDEFG";
	static int a[10] = {};
	static char res[10];
	int i;
	if (str[k] == '\0')
	{
		res[k] = 0;
		printf("%s\n", res);
	}
	else
	{
		for (int indx = 0; str[indx] != '\0'; ++indx)
		{
			if (a[indx] == 0)
			{
				res[k] = str[indx];
				a[indx] = 1;
				permulationOfString(k + 1);
				a[indx] = 0;
			}
		}
	}
}

int main()
{
	// intializeCharArray();
	// intializeReadAndWriteString();
	// lengthOfString();
	// changingCaseOfString();
	// countNumOfWordsAndVowelsInStr();
	// countNumOfWordsAndVowelsInStr1();
	// countNumOfWordsAndVowelsInStr2();
	// validateString();
	// reversingString();
	// reversingString1();
	// comparingString();
	// palindrome();
	// hasBalancedCurlyBraces();
	// isDuplicateCharInString1();
    // isDuplicateCharInString2();
	// isDuplicateCharInString3();
	// isAnagram();
	permulationOfString(0);
	return 0;
}