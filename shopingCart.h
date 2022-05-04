#include<tuple>
#include <string>
#include<vector>




struct Menu {
	std::vector<std::tuple<std::string, double>> menuItems;  
};

class ShoppingCart {

	private:
		Menu menu;
		double total;

	public:
		//construct a menu
		//present a menu
		//update a UI 
		//keep track of inventory/user spend
		void constructMenu(double x, double y, double z);
		std::vector<std::tuple<std::string, double>> allMenuItems();

		double currentTotal = 0;
		int maxSpend;
		double getMenuItem(std::string);
		double amountToFreeRides(double amountSpent, int maxSpend);
		double amountSpent(double ticketPrice, int quantity); 

};

