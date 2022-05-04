#include "shopingCart.h"
#include <tuple>
#include <iostream>


double ShoppingCart::amountToFreeRides(double amountSpent, int maxSpend) {
	double difference;
	difference = maxSpend - amountSpent;
       return difference;	
		
}

double ShoppingCart::amountSpent(double ticketPrice, int quantity) {
	return ticketPrice * quantity;
}

std::vector<std::tuple<std::string, double>> ShoppingCart::allMenuItems() {
	std::vector<std::tuple<std::string, double>> vec;
	for (int i=0; i < menu.menuItems.size(); i++) {
		vec.push_back(std::make_tuple(std::get<0>(menu.menuItems[i]), std::get<1>(menu.menuItems[i]) ));
	}
	return vec;
}

double ShoppingCart::getMenuItem(std::string id) {
	for (int i=0; i < menu.menuItems.size(); i++) {
		if (std::get<0>(menu.menuItems[i]) == id) {
			return std::get<1>(menu.menuItems[i]); 
		} else {
			std::cout << "no menu item of that id found";
			return 0;
		}
	}
	return 0;
}



void ShoppingCart::constructMenu(double x, double y, double z){
	std::string adultPrice = "adult";
	std::string YouthPrice = "youth";
	std::string SeniorPrice = "honored";

	menu.menuItems.push_back(std::make_tuple(adultPrice, x));
	menu.menuItems.push_back(std::make_tuple(YouthPrice,y));
	menu.menuItems.push_back(std::make_tuple(SeniorPrice,z));

}
