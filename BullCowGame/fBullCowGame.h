#pragma once
#include <string>


struct fBullCowCount {
	int Bulls = 0;
	int Cows = 0;

};



enum class EWordStatus {
	OK,
	NoIsogram,
	Invalid_Length,
	Not_Lowercase
};

class fBullCowGame {

public:
	fBullCowGame();
	void Reset();
	
	int GetMaxTries() const;
	int GetCurrenttry() const;
	int GetHiddenWordLength() const;
	
	bool IsGameWon() const;
	EWordStatus CheckGuess(std::string) const;
	fBullCowCount SubmitValidGuess(std::string Guess);

private:
	int MyCurrentTry;
	int MyMaxTries;
	std::string HIDDEN_WORD;
	bool bGameWon;
	
	bool IsIsogram(std::string) const;
};