#include"screensH.h"

//---Screens--

void bannerScreen()
{
	//Print banner HANGMAN
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tCoded by Pablo Vieira" << endl;
	cout << "\t\t\t\t _    _          _   _  _____ __  __          _   _  " <<endl;
	cout << "\t\t\t\t| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |" <<endl;
	cout << "\t\t\t\t| |__| |  /  \\  |  \\| | |  __|      |  /  \\  |  \\| |" <<endl;
	cout << "\t\t\t\t|  __  | / /\\ \\ |     | | |_ | |\\/| | / /\\ \\ |     |" <<endl;
	cout << "\t\t\t\t| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |" <<endl;
	cout << "\t\t\t\t|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|" <<endl;
}


void drawHangManAndMenu()
{
	//Print MENU screen
	cout << "\n" <<endl;
	cout << "\t\t\t\t\t\t      ==============================" <<endl;
	cout << "\t\t\t\t_______\t\t      |            MENU            |" <<endl;
	cout << "\t\t\t\t|     |\t\t      ==============================" <<endl;
	cout << "\t\t\t\t|     @ \t      |     Options:               |" <<endl;
	cout << "\t\t\t\t|    /|\\\t      |                            |" <<endl;
	cout << "\t\t\t\t|     |\t              |   PRESS 1 : INSTRUCTIONS   |" <<endl;
	cout << "\t\t\t\t|    / \\\t      |   PRESS 2 : Start Game     |" <<endl;
	cout << "\t\t\t     -------------\t      |   PRESS 3 : Exit Game      |" <<endl;
	cout << "\t\t\t\t\t\t      |                            |" << endl;
	cout << "\t\t\t\t\t\t      ==============================" <<endl;
}

void instructionsScreen()
{
	//Print Instructions Screen
	cout << "\n\n\t\t============================== I N S T R U C T I O N S ==============================" <<endl;
	cout << "\n\t\t     Hangman its a game in which the player has to find out the word that" <<endl;
	cout << "\n\t\t     has been proposed, with the tip the number of letters that has in the word." << endl;
	cout << "\n\t\t     Every wrong letter, is drawn a part of the body hanged." << endl;
	cout << "\n\t\t     The game ends when the word was found or when the body was completely hanged." << endl;
	cout << "\n\t\t     For each word you can have 4 mistakes." << endl;
	cout << "\n\t\t         Choose a letter from the Keyboard and press Enter. Let's Play? Good Luck!" << endl;
	cout << "\n\t\t=====================================================================================" <<endl;
}

void winScreen()
{
	//Print Win Screen Banner
	cout << "\n\t\t\t\t    ===========================================" << endl;
	cout << "\t\t\t\t         Y O U    W O N! - Congratulations    " << endl;
	cout << "\t\t\t\t    ===========================================" << endl;
}

void loseScreen()
{
	//Print Lose Screen Banner
	cout << "\n\t\t\t\t    ===========================================" << endl;
	cout << "\t\t\t\t                 Y O U    L O S T!             " << endl;
	cout << "\t\t\t\t    ===========================================" << endl;
	cout << "\t\t     =========================== G A M E   O V E R ===========================" <<endl;
}

void exitScreen()
{
	//Print Exit Screen Banner
	cout << "\n\n\t\t=====================================================================================" <<endl;
	cout << "\n\t                                Thank you for playing  H A N G M A N                       " <<endl;
	cout << "\n\t                            Hope that you have had a lot of fun! Bye :-)                      " <<endl;
	cout << "\n\t\t=====================================================================================" <<endl;
}
