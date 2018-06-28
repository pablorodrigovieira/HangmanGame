#include"gameH.h"
#include"userChoicesH.h"
//--Game--

//loadTextFile: import word list from a text file
void Game::loadTextFile()
{
	ifstream listOfWords;
	listOfWords.open("listOfWords.txt");

	//get first line of the file which will be the number of words that has into the file
	listOfWords >> numberOfWords;

	wordsArray = new string[numberOfWords];

	//file up the array with the words that are in the text file
	for(int index = 0; index < numberOfWords; index++)
	{
		listOfWords >> wordsArray[index];
	}

}

//raffleWord: raffle a word from the list
string Game::raffleWord()
{
	//get random number 
	srand(time(NULL));
	numberRaffled = rand()%numberOfWords;
		
	//get secretWord according to the number that has been raffled and return it
	secretWord = wordsArray[numberRaffled];
	return secretWord;
}

//copyWordToPointer: copy word raffled to a pointer
void Game::copyWordToPointer()
{
	PtrWord = new string;
	*PtrWord = secretWord;
}

//convertWordToUdenrlines: convert the word raffled to underlines and return the secretWord
string Game::convertWordToUdenrlines()
{
	for(int index = 0; index < secretWord.length(); index++)
	{
		secretWord[index] = '_';
	}
	return secretWord;
}

//printWordRaffled
void Game::printWordRaffled()
{
	//print word raffled after converted with spaces between the underlines _ _ _ _ _ _ _
	cout << "\n\t\t\t\t\tW O R D: ";
	for(int index = 0;index < secretWord.length(); index++)
	{
		cout << secretWord[index] << " ";
	}
}

//gameScreen: the game function
void Game::gameScreen()
{
	char lettersGuessed[sizeOfAlphabet] = " "; //array variable to hold the letters guessed
	countWrongGuesses = 0; 
	countLettersGuessed = 0; 
	continuePlaying = true; 
	isLooping = true;

	//keep looping until the user win or lose
	while(isLooping)
	{
		//clean the screen, print banner, hanger, word raffled _ _ _ , letters guessed and chances left
		system("cls");
		bannerScreen();
		printHanger(countWrongGuesses);
		printWordRaffled();
		printLettersGuessed(lettersGuessed);
		cout << "\n\n\t\t\t\t\t" << secretWord.length() << " Letters! " << "\tChances Left: " << 4 - countWrongGuesses << endl;
		
		//if user get 4 wrong letters - LOST
		//show lose screen and ask user if want continue
		if(countWrongGuesses==4)
		{
			loseScreen();
			continuePlaying = !getUserAnswerExitGame();
			isLooping = false;
		}
		//if the user found the secret word
		//show win screen and ask user if want continue
		else if(wordCompleted())
		{
			winScreen();			
			continuePlaying = !getUserAnswerExitGame();
			isLooping = false;
		}

		//otherwise ask user to enter a letter
		else
		{
			cout << "\n\t\t\t\t\t\tEnter a letter: ";
			cin >> userLetter;
			
			//convert to lowercase
			userLetter = tolower(userLetter);
		
			//check into the function checkLetterGuessed, passing as argument user input and letters already guessed
			//if return true, letter has been guessed already
			if(checkLetterGuessed(userLetter, lettersGuessed))
			{
				cout << "\n\t\t\t\t\tLetter guessed already! Try again." << endl;
				system("pause");
			}
			
			else
			{
				//otherwise pass letter into the array that holds all letters guessed  and increment counter of letters guessed
				lettersGuessed[countLettersGuessed] = userLetter;
				countLettersGuessed++;
			
				//check letter guessed with the secret word, if find the letter entered
				//use the function replaceLetter(userInput) to replace the underline
				if(checkLetterGuessed(userLetter, *PtrWord))
				{
					replaceLetter(userLetter);
				}

				//otherwise show to user the message: wrong letter. and Increment the counter wrong guesses
				else
				{
					cout << "\n\t\t\t\t\t    Wrong Letter! Try again." << endl;
					countWrongGuesses++;
					system("pause");
				}
			}
		}
	}

}

//printHanger: print hanger during the game
void Game::printHanger(int countWrongLetters)
{
	//depending the number of wrong guesses print the hanger and hanged guy
	switch(countWrongLetters)
	{
			case 0:
				cout << "\n\t\t\t\t\t\t\t_______" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|     " <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t\t|     " <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t     -------------" <<endl;

			break;
		case 1:
				cout << "\n\t\t\t\t\t\t\t_______" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|     @" <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t\t|     " <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t     -------------" <<endl;

			break;
		case 2:
				cout << "\n\t\t\t\t\t\t\t_______" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|     @" <<endl;
				cout << "\t\t\t\t\t\t\t|    /|\\" <<endl;
				cout << "\t\t\t\t\t\t\t|     " <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t     -------------" <<endl;
			break;
		case 3:
				cout << "\n\t\t\t\t\t\t\t_______" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|     @" <<endl;
				cout << "\t\t\t\t\t\t\t|    /|\\" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|    " <<endl;
				cout << "\t\t\t\t\t\t     -------------" <<endl;
			break;
		case 4:
				cout << "\n\t\t\t\t\t\t\t_______" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|     @" <<endl;
				cout << "\t\t\t\t\t\t\t|    /|\\" <<endl;
				cout << "\t\t\t\t\t\t\t|     |" <<endl;
				cout << "\t\t\t\t\t\t\t|    / \\" <<endl;
				cout << "\t\t\t\t\t\t     -------------" <<endl;
			break;
	}

}

//printLettersGuessed: print letters guessed
void Game::printLettersGuessed(char lettersGuessed[sizeOfAlphabet])
{
	//function that print letters guessed, helping the user to remember the letters that has been guessed
	cout << "\n\n\t\t\t\t\t\tLetters Guessed: ";
	for(int index = 0;index < strlen(lettersGuessed); index++)
	{
		cout << lettersGuessed[index] << " ";
	}

}
//checkLetterGuessed: check if letter was guessed  before
bool Game::checkLetterGuessed(char letter, string vector)
{
	//check each position of the string, in order to find out if the letter has been guessed already.
	//if found it, return true(FOUND!) otherwise return false
	for(int index = 0; index < vector.length(); index++)
	{
		if(letter == vector[index])
		{
			return true;
		}
	}
	return false;
}

//replaceLetter: replace letter if found it into the secret word
void Game::replaceLetter(char letter)
{
	//check each position the the pointer to replace with letter guessed if it has been found
	for(int index = 0; index < PtrWord->length(); index++)
	{
		if((*PtrWord)[index] == letter)
		{
			letter = toupper(letter);
			secretWord[index] = letter;
		}
		letter = tolower(letter);
	}
}

//wordCompleted: check if the word has been found
bool Game::wordCompleted()
{
	//function that check if the word has been discovered
	//if still have any '_' empty space, return false
	//otherwise return true
	for(int index = 0; index < secretWord.length();index ++)
	{
		if(secretWord[index] == '_')
			return false;
	}
	return true;
}

//destructor
Game::~Game()
{
	//delete the pointers
	delete PtrWord;
	delete [] wordsArray;
}