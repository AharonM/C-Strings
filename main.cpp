/*
Name: Assignment#7: Vowels and Consonants
Author: Aharon Mishiev
Date: 11/14/2013
Description: This program takes in a user entered
string and counts the number of Vowel,Consonants
or both according to user's choice.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAX_NUM=10;
char vowelArray[MAX_NUM]={'A','a','E','e'
                ,'I','i','O','o','U','u'};

//Prototypes
int countVowels(char *);
int countConsonants(char *);
void menu();



int main()
{
   const int MAX_LENGTH=31;
   char wordChoice[MAX_LENGTH];
   bool not_done = true;
   char choice;
   int length=0;
   ofstream outfile("output.txt");

  cout<<"Enter a word you want to analyze: ";
  cin.getline(wordChoice, MAX_LENGTH);
  outfile<<"You entered: ";
  for(int index = 0; wordChoice[index] != '\0'; index++)
  {
   outfile << wordChoice[index];
  }

  do
  {
   menu();
   cin >> choice;
   switch(choice)
   {
   case 'A':
   case 'a':
      outfile<<"\nThere are "<<countVowels(wordChoice);
      outfile<<" vowels in the word you entered.\n";
      break;

   case 'B':
   case 'b':
      outfile<<"There are "<<countConsonants(wordChoice);
      outfile<<" consonants in the word you entered.\n";
      break;

   case 'C':
   case 'c':
      length=strlen(wordChoice);
     outfile << "There are "<< length;
     outfile <<" vowels and consonants in the word you entered.";
     outfile << endl << endl;
      break;

   case 'D':
   case 'd':
      cout<<"Enter a word you want to analyze: ";
      cin.ignore();
      cin.getline(wordChoice, MAX_LENGTH);
      outfile<<"\nYou entered: ";
   for(int index = 0; wordChoice[index] != '\0'; index++)
      {
         outfile << wordChoice[index]<<endl;
      }
      break;

   case 'E':
   case 'e':
      not_done = false;
      break;

   default:
      outfile << "\n\nError: '"<< choice;
      outfile << "' is an invalid selection-try again\n\n";
      break;
      }
   }
  while (not_done);

outfile.close();                   // close output file
return 0;
}




/* Function countVowels()
* Input:
*  pointer to a C-string
* Process:
*  lineary searches the vowel array to find
*  any vowels in the user entered c-string
* Output:
*  returns the number of vowels
*/


int countVowels(char *wordPtr)
{
   int count=0;
while(*wordPtr != '\0')
   {
   for (int index=0;index<MAX_NUM;index++)
   {
   if(*wordPtr == vowelArray[index] )
   count++;
   }
   wordPtr++;
   }
return count;
}




/* Function countConsonants()
* Input:
*  pointer to a C-string
* Process:
*  subtracts the number of vowels from the total
*  length of the string to get the num of consonants
* Output:
*  returns the number of consonants
*/


int countConsonants(char *wordPtr)
{
   int strSize,numVowel,numConsonant=0;
   strSize = strlen(wordPtr);
   numVowel = countVowels(wordPtr);
   numConsonant = strSize-numVowel;
   return numConsonant;
}




/* Function menu()
* Input:
*  none
* Process:
*  Prints the menu of transaction choices
* Output:
*  Prints the menu of transaction choices
*/


void menu()
{
cout << endl << endl;
cout <<"Select one of the choices:";
cout << "\n\t A) Count the number of vowels in the string";
cout<<"\n\t B) Count the number of consonants in the string";
cout<<"\n\t C) Count both the vowels and consonants in the string";
cout << "\n\t D) Enter another string";
cout << "\n\t E) Exit the program";
cout << endl << "\tEnter your selection: ";
return;
}
