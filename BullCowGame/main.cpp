#include <iostream>
#include <string>
#include "fBullCowGame.h"


using namespace std;




void PrintIntro();
string GetValidGuess(fBullCowGame BCGame);
void PlayGame(fBullCowGame BCGame);
void PrintBullCowCount(fBullCowCount BullCowCount);
bool AskToPlayAgain();
void PrtintGameSummary(fBullCowGame);


fBullCowGame BCGame;

int main() {
	// Welcome to game
	PrintIntro();
	PlayGame(BCGame);
	
	return 0;

}




//Game content. Plays the game
void PlayGame(fBullCowGame BCGame) {

	bool bPlayAgain = false;
	string Guess = "";

	do {
		BCGame.Reset();
		while (!BCGame.IsGameWon() && BCGame.GetCurrenttry() <= BCGame.GetMaxTries()) {
			Guess = GetValidGuess(BCGame);
			fBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
			PrintBullCowCount(BullCowCount);
		}
		PrtintGameSummary(BCGame);
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
}




// Prints count of Bulls and Cows.
void PrintBullCowCount(fBullCowCount BullCowCount) {
	cout << "Bulls: " << BullCowCount.Bulls << endl;
	cout << "Cows: " << BullCowCount.Cows << endl;
}




//4Prints Game Intro
void PrintIntro() {
	cout << "Welcome to the Bulls and Cows, a fun game" << endl;
	cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	cout << " letter isogram I'm thinking of.\n";
}




// Loop till user inputs valid guess.
string GetValidGuess(fBullCowGame BCGame) {
	string input = "";
	cout << "\nTry " << BCGame.GetCurrenttry() << ".  Enter your guess: ";
	getline(cin, input);

	
	EWordStatus Status = BCGame.CheckGuess(input);
	while (Status != EWordStatus::OK) {
		switch (Status) {
		case EWordStatus::Invalid_Length:
			cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EWordStatus::NoIsogram:
			cout << "Please enter an Isogram, a word with no repeating letters.\n";
			break;
		case EWordStatus::Not_Lowercase:
			cout << "Please enter the word lowercase.\n";
			break;
		}
		cout << "\nTry " << BCGame.GetCurrenttry() << ".  Enter your guess: ";
		getline(cin, input);
		Status = BCGame.CheckGuess(input);
	}
	return input;
}




// Asks user if they would like to play again and Resets game. 
bool AskToPlayAgain() {
	
	cout << "\n\nDo you want to play agian? Answer \"yes\" to play again! ";
	string answer = "";
	getline(cin, answer);
	cout << endl;

	if (answer == "yes" ) {
		BCGame.Reset();
		return true;
	}
	else {
		cout << "Thanks for playing!\n";
		return false;
	}

}




void PrtintGameSummary(fBullCowGame BCGame){
	if (BCGame.IsGameWon()) {
		cout << "\nCongratulations!! You have won the game!\n";
	}
	else {
		cout << "You have run out of tries. Better luck next time!\n";
	}
}