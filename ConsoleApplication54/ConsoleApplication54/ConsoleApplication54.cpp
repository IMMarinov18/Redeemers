// ConsoleApplication54.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct ORDER {
	string Food;
	string Address;
	string Name;
	string Specification;
	float price;
	bool bought;
};
//data
/*******************/
int index = 1;
float wallet = 0;
bool Create(ORDER* orders, int& size, string food, string address, string name, string specification, float price)
{
	if (size > 100)
	{
		return false;
	}
	orders[size].Address = address;
	orders[size].Food = food;
	orders[size].Name = name;
	orders[size].Specification = specification;
	orders[size++].price = price;
	if (wallet >= price)
	{
		wallet = wallet - price;
		return true;

	}
	else
	{
		for (int i = index; i <= size; i++)
		{
			orders[i] = orders[i + 1];
		}
		size--;
		return false;

	}
}




void RemoveOrder(ORDER* orders, int& size, int index)
{
	cout << "Choose which order you want to remove from the cart(write the number of the order) \n\n";
	cin >> index;
	for (int i = index; i <= size; i++)
	{
		orders[i] = orders[i + 1];
	}
	size--;
	
	

}
/*******************/

//presentation
/*******************/




int main()
{
	ORDER orders[500];
	string quit = "OK, bye! Have a nice day\n";
	int size = 0;
	Greetings();
	while (MainMenu(orders, size));
	cout << quit;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
