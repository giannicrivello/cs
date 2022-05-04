#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "shopingCart.h"


#define MAX_ADULT_SPEND 100
#define MAX_YOUTH_SPEND 28
#define MAX_HONORED_SPEND 28


#define ADULT_TICKET_PRICE 5.25
#define HONORED_TICKET_PRICE 2.50
#define YOUTH_PRICE 3.25

void handleAddingToCart(ShoppingCart cart, int numTickets, double priceOfTicket) {
	//take current total += numTickets* priceofTicket
	cart.currentTotal += (numTickets * priceOfTicket);
	double amountToFreeRides = cart.amountToFreeRides(cart.currentTotal, MAX_ADULT_SPEND);
	if (amountToFreeRides > 0) {
		//handle recusive call
			std::cout << "if you spend " << amountToFreeRides << " more dollars, you get free rides for the month." << std::endl;
			std::cout << std::endl;
			std::cout << "your current balance is " << std::setw(10) << cart.currentTotal<<std::endl;

			std::cout << "would yo like to continue?(Y/N)" << std::endl;
			
			char choice;
			std::cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return;
			} else if (choice == 'Y' || choice == 'y') {
				std::cout << "Great!, how much would you like to buy? " << std::endl;
				int numTickets;
				std::cin >> numTickets;
				handleAddingToCart(cart, numTickets, priceOfTicket);
			}
	}else if (amountToFreeRides == 0) {
		std::cout << "great! you've earned free rides for the month!" << std::endl;
	}else if (amountToFreeRides < 0) {
		std::cout << "you have reached max spend, we are refunding you " << amountToFreeRides << " and you have also earned a token for free rides for the month" << std::endl; 
	} else {
		std::cout << "Something went wrong";
	}
}
void handleChoice(std::string item, int maxSpend) {

		//init cart
		ShoppingCart cart;
		//construct menu
		cart.constructMenu(ADULT_TICKET_PRICE, YOUTH_PRICE, HONORED_TICKET_PRICE);
		std::cout << "Hello and welcome to HopPass! " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Ticket Pricing: " <<std::endl;
		std::cout << std::endl;
		std::cout << "=============================" <<std::endl;
		std::cout << std::endl;
		// std::cout << std::endl;
		std::cout << "Our Current ticket pricing ----->" << std::endl;
		std::vector<std::tuple<std::string, double>> menuItemsList = cart.allMenuItems();
		for (int i=0; i < menuItemsList.size(); i++) {
			
			std::cout << std::get<1>(menuItemsList[i]) << std::setw(10) << std::get<0>(menuItemsList[i]) << std::endl;

		}
		std::cout << "You selected [" << item << "] is this correct?" <<std::endl;
		char correctCheck;
		std::cin >> correctCheck;
		if (correctCheck == 'Y' || 'y') {
			std::cout << "Great! Glad we got that taken care of..." << std::endl;
			std::cout << "Note that we are having a special this year, if you buy over " << maxSpend << " you get free tickets for the year!" <<std::endl;
			std:: cout << "===========" <<std::endl;
			std::cout << "your current balance is " << std::setw(10) << cart.currentTotal << std::endl;
			std::cout << "How many tickets would you like to buy?" << std::endl;
			int numTickets;
			std::cin >> numTickets;
		//amount spent
		cart.currentTotal = cart.amountSpent(cart.getMenuItem(item), numTickets);

		//amount to free tickets
		double amountToFreeRides = cart.amountToFreeRides(cart.currentTotal, maxSpend);

		if (amountToFreeRides > 0) {
			std::cout << "your current balance is " << std::setw(10) << cart.currentTotal<<std::endl;
			std::cout <<std::endl;
			//handle recusive call
			std::cout << "if you spend " << amountToFreeRides << " more dollars, you get free rides for the month." << std::endl;

			std::cout << "would yo like to continue?(Y/N)" << std::endl;
			char choice;
			std::cin >> choice;
			if (choice == 'N' || choice == 'n') {
				return;
			} else if (choice == 'Y' || choice == 'y') {
				std::cout << "Great!, how much would you like to buy? " << std::endl;
				int numTickets;
				std::cin >> numTickets;
				handleAddingToCart(cart, numTickets, cart.getMenuItem(item));
			}

		}else if (amountToFreeRides == 0) {
			std::cout << "great! you've earned free rides for the month!" << std::endl;
			std::cout << std::endl;
		} else if (amountToFreeRides < 0) {
			std::cout << "you have reached max spend, we are refunding you " << amountToFreeRides << " and you have also earned a token for free rides for the month" << std::endl; 
		}

		} else {
			//todo: put a wrapper menu
			return;
		} 
}



void hopPassMenu(char a) {
	std::cout << "entered into pass menu" << std::endl;
	
	if (a == 'A' || a == 'a') {
		handleChoice("adult", MAX_ADULT_SPEND);
		return;

	}
	if (a == 'Y' || a == 'y') {
		handleChoice("youth", MAX_YOUTH_SPEND);
		return;
	}
	if (a == 'H' || a == 'h') {
		handleChoice("honored", MAX_HONORED_SPEND);
		return;
	} 
	else {
		std::cout << "please enter a valid choice (A=adult, Y=youth, H=honored, Q=quit)" << std::endl;
		char a;
		std::cin >> a;
		if (a == 'Q' || a == 'q'){		
			return;
		} else if (a == 'A' || a == 'a' || a == 'Y' || a == 'y' || a == 'H' || a == 'h') {
			hopPassMenu(a);
		} else {
			std::cout << "Stop trying to break my program!";
		}
	}
}
// int wrapperMenu() {
// 	std::cout <<  "Please enter valid choice" << std::endl;
// 	char choice;
// 	std::cin >> choice;

// 	if (choice == 'Q' || choice == 'q') {
// 		std::cout << "Hope to see you again!";
// 		return 0;
// 	} else {
// 		hopPassMenu(choice);
// 		std::cout << "Thank you for riding the hopPass system" << std::endl;
// 		return 0;
// 	}
// }
	
int main() {
	std::cout << "WELCOME to hopPass, the most hoppiest pass train thing you will ever ride" <<std::endl;
	std::cout << std::endl;
	std::cout << "please choose a valid option:" << std::endl;
	std::cout << std::endl;
    std::cout << "=============================" << std::endl;
	std::cout << "A" << std::setw(10) << "Adult" <<std::endl;
	std::cout << "Y" << std::setw(10) << "Youth" <<std::endl;
	std::cout << "H" << std::setw(10) << "Honor" <<std::endl;
	std::cout << "Q" << std::setw(10) << "Quit Program" <<std::endl;

	char choice;
	std::cin >> choice;

	if (choice == 'Q' || choice == 'q') {
		std::cout << "Hope to see you again!";
		return 0;
	} else {
		hopPassMenu(choice);
		std::cout << "Thank you for riding the hopPass system" << std::endl;
		return 0;
	}
}

