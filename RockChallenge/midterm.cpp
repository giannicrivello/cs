
/********************************************************************
# Author:           Gianni Crivello
#Contact:           gianni.crivello@pcc.edu
# Lab:              
# Date:             05/12/2022
# Description:     A program that is used to decipher a winner of a rock
                   collection contest.

# Input:           userName<string> rocksCollected<int>            
# Output:          formatted string deciphering the winner and average 
                   amount of rocks collected
# Sources:         N/A 
#******************************************************************************/
#include<iostream>
#include<string>
#include<iomanip>
#define NUM_PLAYERS 3

using namespace std;

int main(int argc, char* args[]) {
	
	//declaration of players
	string player1;
	string player2;
	string player3;

	//declaration of rocks collected
	int rocksForPlayer1;
	int rocksForPlayer2;
	int rocksForPlayer3;
	cout << endl;
	cout << endl;
	cout << "WELCOME TO THE ROCK CHAMPIONSHIPS" << endl;
	cout << endl;
	cout << endl;
	
	//Displays
	cout << "Enter player 1 name: " << endl;
	getline(cin, player1);

	cout << "How many rocks did " << player1 << " collect? " << endl;
	
	cin >> rocksForPlayer1;
	if (rocksForPlayer1 < 0){
			cout << "invalid amount entered setting amount to 0 " << endl;
			rocksForPlayer1 = 0;
	}
	cout << "Enter player 2 name: " << endl;
	cin.ignore();
	getline(cin, player2);
	cout << "How many rocks did " << player2 << " collect? " << endl;
	cin >> rocksForPlayer2;
	if (rocksForPlayer2 < 0){
			cout << "invalid amount entered setting amount to 0 " << endl;
			rocksForPlayer2 = 0;
	}
	cout << "Enter player 3 name: " << endl;
	cin.ignore();
	getline(cin, player3);
	cout << "How many rocks did " << player3 << " collect? " << endl;
	cin >> rocksForPlayer3;
	if (rocksForPlayer3 < 0){
			cout << "invalid amount entered setting amount to 0 " << endl;
			rocksForPlayer3 = 0;
	}

	//logic to calculate winner:w

	string first;
	string second;
	string third;

	//case of no tie
	if(rocksForPlayer1 != rocksForPlayer2 && rocksForPlayer2 != rocksForPlayer3 && rocksForPlayer1 != rocksForPlayer3) {		
		//player1 wins, player2 second, player3 third
		if(rocksForPlayer1 > rocksForPlayer2 && rocksForPlayer1 > rocksForPlayer3 && rocksForPlayer2 > rocksForPlayer3){

			first = player1;
			second = player2;
			third = player3;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;
        }else if(rocksForPlayer1 > rocksForPlayer2 && rocksForPlayer1 > rocksForPlayer3 && rocksForPlayer2 < rocksForPlayer3){
			//player 1 wins, player 3 second, player2 third
			first = player1;
			second = player3;
			third = player2;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;

		} else if (rocksForPlayer1 < rocksForPlayer2 && rocksForPlayer1 > rocksForPlayer3 && rocksForPlayer2 > rocksForPlayer3){
			//player 2 wins, player 1 in second, player 3 in third
			first = player2;
			second = player1;
			third = player3;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;
		} else if (rocksForPlayer1 < rocksForPlayer2 && rocksForPlayer1 < rocksForPlayer3 && rocksForPlayer2 > rocksForPlayer3){
			//2 3 1
			first = player2;
			second = player3;
			third = player1;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;
		} else if (rocksForPlayer1 > rocksForPlayer2 && rocksForPlayer1 < rocksForPlayer3 && rocksForPlayer2 < rocksForPlayer3){
			//312
			first = player3;
			second = player1;
			third = player2;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;

		} else if (rocksForPlayer1 < rocksForPlayer2 && rocksForPlayer1 < rocksForPlayer3 && rocksForPlayer2 < rocksForPlayer3){
			//321
            first = player3;
			second = player2;
			third = player1;
			cout << first << " is in first place!" << endl;
			cout << second << " is in second place." << endl;
			cout << third << " is in third place... womp womp" << endl;
		} else {
			cout << "do nothing";
		}
		// cout << "the average number of rocks collected by our players is " << (rocksForPlayer1+rocksForPlayer2+rocksForPlayer3) / static_cast<double>(NUM_PLAYERS) << endl;
    }else{
		//case of tie
		
		//handle case of tie for first
		//player1 & player2 are in first
		if (rocksForPlayer1 == rocksForPlayer2 && rocksForPlayer1 > rocksForPlayer3) {
			cout << player1 << " & " << player2 << " are tied for first " << player3 << " is in second." << endl;
			return 0;
		}
		//player1 & player3 are in first
		if (rocksForPlayer1 == rocksForPlayer3 && rocksForPlayer1 > rocksForPlayer2) {
			cout << player1 << " & " << player3 << " are tied for first " << player2 << " is in second." << endl;
			return 0;
		}
		//player2 & player3 are in first
		if(rocksForPlayer2 == rocksForPlayer3 && rocksForPlayer2 > rocksForPlayer1){
			cout << player2 << " & " << player3 << " are tied for first " << player1 << " is in second." << endl;
			return 0;
		}
        //case of tie for second

		//player1 & player2 are in second
		if (rocksForPlayer1 == rocksForPlayer2 && rocksForPlayer1 < rocksForPlayer3) {
			cout << player1 << " & " << player2 << " are tied for second " << player3 << " is in first." << endl;
			return 0;
		}
		//player1 & player3 are in second
		if (rocksForPlayer1 == rocksForPlayer3 && rocksForPlayer1 < rocksForPlayer2) {
			cout << player1 << " & " << player3 << " are tied for second " << player2 << " is in first." << endl;
			return 0;
		}
		//player2 & player3 are in second
		if(rocksForPlayer2 == rocksForPlayer3 && rocksForPlayer2 < rocksForPlayer1){
			cout << player2 << " & " << player3 << " are tied for second " << player1 << " is in first." << endl;
			return 0;
		}
		if(rocksForPlayer2 == rocksForPlayer3 && rocksForPlayer2 == rocksForPlayer1){
			cout << "EVERYONE IS TIED....YAY" << endl;
			return 0;
		}
    }
	cout << setprecision(2);
	double average = (rocksForPlayer1+rocksForPlayer2+rocksForPlayer3) / static_cast<double>(NUM_PLAYERS);
	cout << "the average number of rocks collected by our players is " << average << endl;
	cout << "Thanks and come again! Goodbye" << endl;
}