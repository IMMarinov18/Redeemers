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

void ShowAllOrders(ORDER* orders, int& size)
{
	 
	cout << "\nList of all the orders: \n";
	cout << "Choose an order by its number.\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << " " << i + 1 << orders[i].Food<< " , " << orders[i].Name << " , " << orders[i].Address << " , " << orders[i].Specification << " , " << orders[i].price << " - ";
		if (orders[i].bought)
		{
			cout << "bought  " << endl;
		}
		else
		{
			cout << "free  " << endl;
		}

	}
}


void EnterOrderDetails(ORDER* orders, int& size)
{
	cout << "OK, now enter your game data in this order:\n Name; Address; Specification; price " << endl;
	string food, name, address, specification;
	float  price;
	cin  >> food >> name >> address >> specification >> price;
	if (Create(orders, size, food , name, address, specification, price))
	{
		cout << "Successfully purchased! " << endl;
	}
	else
	{
		cout << "Sorry, you don't have enough money!" << endl << "Try adding some more! " << endl;
	}

}

bool MainMenu(ORDER* orders, int& size)
{
	int index = 1;
	cout << "\nList: \n 1.Add money to your wallet.\n 2.See your balance.\n 3.Make an order. \n 4.Go to the cart . \n 5.Return an order. \n 6.Quit \n\n";


	int n;
	cin >> n;
	switch (n)
	{
		{
	case 1:
	{
		int newMoney;
		cout << "How much money do you want to add?" << endl << "Add:";
		cin >> newMoney;
		wallet = newMoney + wallet;
		cout << "Money added!" << endl << endl;
	}
	case 2:
	{
		cout << "Your balance is " << wallet << "$ !" << endl;
		return true;
	}
	case 3:
	{
		EnterOrderDetails(orders, size);
		return true;
	}


	case 4:
	{
		ShowAllOrders(orders, size);
		return true;
	}
	case 5:
	{
		cout << "Choose what you wish to return:";
		ShowAllOrders(orders, size);
		RemoveOrder(orders, size, index);
		return true;
	}
	case 6:
	{
		return false;
	}
	default:
	{
		cout << "Error. Please enter again." << endl;
		return true;
	}

		}
	}
}



void Greetings()
{
	string hello = "Hello!\nWelcome to !\nChoose an option from the main menu down below. \n\n";
	cout << hello;
}

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
