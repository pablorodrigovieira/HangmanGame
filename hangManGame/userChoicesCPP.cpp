#include"userChoicesH.h"

// ------ USER CHOICES --- function that get user menu choice 
void getUserChoice()
{
	//variable to hold userInputMenu choice
	string userInputMenu = "0";

	//loop while user enter anything different of 3
	while(userInputMenu != "3")
	{
		//print banner and hangman screens and ask user to choose an option
		bannerScreen(); 
		drawHangManAndMenu(); 
		cout << "\n\n\t\t\tPlease choose an option: ";
		cin >> userInputMenu;
		system("cls");

		//if user has choosen 1 show instructions and ask if user want continue in the game
		if(userInputMenu == "1")
		{
			bannerScreen();
			instructionsScreen();
			if(getUserAnswerExitGame())
				userInputMenu = "3";
		}

		//if user has choosen 2 instantiate a newGame of type Game
		else if(userInputMenu == "2")
		{
				Game newGame;
				newGame.loadTextFile();
				newGame.raffleWord();
				newGame.copyWordToPointer();
				newGame.convertWordToUdenrlines();
				newGame.gameScreen();
				if(newGame.continuePlaying == false)
					userInputMenu = "3";
 		}
		
		////if user has choosen 3 show banner screen and exit the game
		if(userInputMenu == "3")
		{
			bannerScreen();
			exitScreen();		
		}
		else
			userInputMenu = "0";
	}
}

// ------ USER CHOICES --- function that get user awnser about exit the game
bool getUserAnswerExitGame()
{
	//variable to hold user awnser if want continue or not
	string userAnswer = "x";

	//loop while user enter any information different than y or n
	while((userAnswer != "y")&&(userAnswer != "n"))
	{
		//clear the buffer
		cin.clear(); 
		cin.ignore(INT_MAX,'\n'); 
		//get user input and check if == y clean the screen and return false
		//which will go to the function getUserChoice() to show the menu options again
		try{
			cout << "\n\t\t\t\tWould you like to continue (y - yes | n - no)? ";
			cin  >> userAnswer;

				if(userAnswer == "y")
				{
					system("cls");
					return false;
				}
				else if(userAnswer == "n")
				{
					system("cls");
					return true;
				}
				else
					throw 0;

		}catch(...){
			cout << "\n\t\t\t\t\tERROR: Wrong option! Try again." <<endl;
		}
		
	}
	return false;
}