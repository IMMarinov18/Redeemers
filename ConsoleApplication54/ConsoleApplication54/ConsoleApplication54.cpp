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
bool Create(ORDER* orders, int& size, string name, string food, string address, string specification, float price)
{
	if (size > 100)
	{
		return false;
	}
	orders[size].Name = name;
	orders[size].Food = food;
	orders[size].Address = address;
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
	wallet = wallet + orders[index - 1].price;
	for (int i = index; i <= size; i++)
	{
		orders[i] = orders[i + 1];
	}

	size--;
	cout << "Successfully deleted!" << endl;
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
		if (size >= 1)
		{
			cout << " " << i + 1 << ": " << orders[i].Name << " , " << orders[i].Food << " , " << orders[i].Address << " , " << orders[i].Specification << " , " << orders[i].price << " - ";
			if (orders[i].bought)
			{
				cout << "bought  " << endl;
			}
			else
			{
				cout << "free  " << endl;
			}
		}
		else if (size == 0)
		{
			cout << "There are not any orders in your cart!" << endl;
		}
	}
}


void EnterOrderDetails(ORDER* orders, int& size)
{
	string name, food, address, specification;
	float  price;
	cout << "OK, now enter your data for this order:" << endl;
	cout << "Enter name:"; cin >> name; cout << endl;
	cout << "Enter food:"; cin >> food; cout << endl;
	cout << "Enter address:"; cin >> address; cout << endl;
	cout << "Enter specification:"; cin >> specification; cout << endl;
	cout << "Enter price:"; cin >> price; cout << endl;



	if (Create(orders, size, name, food, address, specification, price))
	{
		cout << "Successfully purchased! " << endl;
	}
	else
	{
		cout << "Sorry, you don't have enough money!" << "Try adding some more! " << endl;
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
	string hello = "Hello!\nWelcome to our online shop!\nChoose an option from the main menu down below. \n\n";
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
