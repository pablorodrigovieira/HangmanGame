#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<time.h>
#include<ctype.h>
#include"screensH.h"

using namespace std;	

#ifndef GAME
#define GAME

//constant variable to hold sizeOfAlphabet
const int sizeOfAlphabet = 26;

//Class Game
class Game
{
	//attributes of the Class
public:
		string secretWord;
		string *wordsArray;
		string *PtrWord;
		string letters;
		char userLetter;
		int numberRaffled;
		int numberOfWords;
		int countWrongLetters;
		int countWrongGuesses;
		int countLettersGuessed;
		bool continuePlaying;
		bool isLooping;
		
	//behaviours of the Class

//loadTextFile: import word list from a text file
void loadTextFile();
//raffleWord: raffle a word from the list
string raffleWord();
//copyWordToPointer: copy word raffled to a pointer
void copyWordToPointer();
//convertWordToUdenrlines: convert the word raffled to underlines
string convertWordToUdenrlines();
//printWordRaffled
void printWordRaffled();

//gameScreen: the game screen
void gameScreen();
//printHanger: print hanger during the game
void printHanger(int countWrongLetters);

//printLettersGuessed: print letter guessed
void printLettersGuessed(char lettersGuessed[sizeOfAlphabet]);
//checkLetterGuessed: check if letter was guessed  before
bool checkLetterGuessed(char letter, string vector);
//replaceLetter: replace letter if found it into the secret word
void replaceLetter(char letter);
//wordCompleted: check if the word has been found
bool wordCompleted();

//destructor
~Game();

};

#endif