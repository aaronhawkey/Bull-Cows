#include "fBullCowGame.h"
#include <map>
#include <string>



// Constructor for fBullCowGame Type.
fBullCowGame::fBullCowGame() {
	Reset();
}




// Resets fBullCowGame values.
void fBullCowGame::Reset(){
	MyCurrentTry = 1;
	MyMaxTries = 4;
	HIDDEN_WORD = "ant";
	bGameWon = false;
}




// Gets the maximum amount of tries.
int fBullCowGame::GetMaxTries() const{
	return MyMaxTries;
}




// Gets the user's current try.
int fBullCowGame::GetCurrenttry() const{
	return MyCurrentTry;
}




// Reterns the length of the hidden word.
int fBullCowGame::GetHiddenWordLength() const
{
	return HIDDEN_WORD.length();
}




// Checks to see if the game has been won.
bool fBullCowGame::IsGameWon() const{
	return bGameWon;
}




// Checks the users guess to see if valid. Returns EWordStatus.
EWordStatus fBullCowGame::CheckGuess(std::string Guess) const{
	if (!IsIsogram(Guess)) {
		return EWordStatus::NoIsogram;
	}
	else if (false) {
		return EWordStatus::Not_Lowercase;

	}
	else if (GetHiddenWordLength() != Guess.length()){
		return EWordStatus::Invalid_Length;
	}
	else {
		return EWordStatus::OK;
	}
}




// Submits the guess to the game. Returns a count of Bulls and Cows
fBullCowCount fBullCowGame::SubmitValidGuess(std::string Guess){

	MyCurrentTry++;
	fBullCowCount BullCowCount;
	 
	for (int i = 0; i < GetHiddenWordLength(); i++) {
		// The loop header could cuase problems later
		for (int j = 0; j < GetHiddenWordLength(); j++) {
			if (HIDDEN_WORD[i] == Guess[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bGameWon = true;
	}
	else if (BullCowCount.Bulls != GetHiddenWordLength()){
		bGameWon = false;
	}
	return BullCowCount;
}




// 
bool fBullCowGame::IsIsogram(std::string) const
{
	return true;
}

