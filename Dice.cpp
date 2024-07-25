//Header files
#include <iomanip>
#include <iostream>
using namespace std;

//Function prototypes 
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int generateRandom();

int main() {

	//Variables
	int humanTotalScore = 0;
	int computerTotalScore = 0;
	char answer;

	cout << "Welcome to the Game of Dice Thrones!" << endl << endl;

	do {

		//Human turn 
		humanTotalScore += humanTurn(humanTotalScore);
		if (humanTotalScore < 100) {
			cout << "Your score in the Game so far is: " << humanTotalScore << endl << endl;
			cout << "Enter c to continue the game. " << endl;
			cin >> answer;
		}

		//Break out of loop if human wins before computer plays it's turn
		if (humanTotalScore >= 100) {
			break;
		}

		//Clear console 
		system("CLS");

		//Computers turn 
		computerTotalScore += computerTurn(computerTotalScore);
		if (computerTotalScore < 100) {
			cout << "The computers score in the Game so far is: " << computerTotalScore << endl << endl;
		}

	} while (humanTotalScore < 100 && computerTotalScore < 100);

	if (humanTotalScore >= 100) {
		cout << "Congratulations! You won!" << endl;
	}
	else {
		cout << "The Computer won, better luck next time!" << endl;
	}
	return 0;
}

//Function that controls humans roll of the dice 
int humanTurn(int humanTotalScore) {

	int roll = 0;
	int roundScore = 0;
	char answer;

	cout << "It's your turn! Enter 'r' to roll." << endl;
	cin >> answer;

	while (tolower(answer) == 'r') {

		roll = generateRandom();
		roundScore += roll;

		//Break out of loop if you roll a 1 or you've scored 50 or more points in a single round 
		if (roll == 1 || roundScore >= 50) {
			break;
		}

		//Game menu 
		cout << "You rolled " << roll << endl;
		cout << "Your score this round is: " << roundScore << endl;
		cout << "If you hold, your total score would be: " << roundScore << endl;
		cout << "Press 'h' to hold or 'r' to roll again." << endl;
		cin >> answer;
	}

	if (roll != 1 && roundScore < 50) {
		cout << "Great job! You scored a total of " << roundScore << " this round!" << endl << endl;
		return roundScore;
	}
	else if (roll != 1 && roundScore >= 50) {
		return 100; //Return winning points if human has scored 50 or more points in a single round 
	}

	roundScore = 0;
	cout << "Sorry, you rolled a " << roll << " and therefore lost this round with score a score of " << roundScore << endl << endl;

	return roundScore;
}

//Function that contols computers roll of the dice 
int computerTurn(int computerTotalScore) {

	int roll = 0;
	int roundScore = 0;
	char answer = 'r';

	cout << "It's the computer's turn!" << endl << endl;

	while (tolower(answer) != 'h') {

		roll = generateRandom();
		roundScore += roll;

		//Break out of loop if computer rolls 1 or the total roundScore is more than 10
		if (roll == 1 || roundScore >= 10) {
			break;
		}

		//Game menu 
		cout << "The computer rolled " << roll << endl;
		cout << "The computers score this round is: " << roundScore << endl;
		cout << "If the comupter holds, it's total score would be: " << roundScore << endl;
		cout << "Press 'h' to hold or 'r' to roll again." << endl;
		cin >> answer;
	}

	if (roll != 1) {
		cout << "The computer ended the round with " << roundScore << endl << endl;
		return roundScore;
	}

	cout << "The computer loses. Enter 'c' to continue. " << endl;
	cin >> answer;

	roundScore = 0;
	return roundScore;
}

//Function that generates random numbers and returns it 
int generateRandom() {

	return rand() % 6 + 1;
}