#include <iostream>
#include <algorithm>    // random_shuffle
#include <vector>       // vector
#include <ctime>        // time
#include <cstdlib>      // rand, std::srand
#include <Windows.h>    //fot the timer
#include <string>
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
		if (food == "burger")
		{
			wallet = wallet - 3.5;
			return true;
		}
		if (food == "pizza")
		{
			wallet = wallet - 10;
			return true;
		}
		if (food == "rice")
		{
			wallet = wallet - 2.5;
			return true;
		}
		if (food == "ice cream")
		{
			wallet = wallet - 1.5;
			return true;
		}
		if (food == "spaghetti")
		{
			wallet = wallet - 3;
			return true;
		}

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
	cout<<endl << "Choose which order you want to remove from the cart(write the number of the order): ";
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
	cout << endl;
	cout << "\nList of all the orders: \n";
	cout << endl;
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



string mixUp(string scrambleWord)//built in function to randomly shuffle character is a string
{

	random_shuffle(scrambleWord.begin(), scrambleWord.end());


	return scrambleWord;

}

int timer(int min, int sec)
{
	Sleep(1000);
	while (min >= 1)
	{
		cout << "\rTime remaining to your delivery: " << min << " min" << flush;
		Sleep(/*300000*/1000);   //направено е нарочно така и минутите текат толкова бързо, за да не се чака при проверка на програмата.
		//Ако искате наистина 5 мин разкументирайте "300000" и махнете "1000"
		min--;
	}
	if (min == 0)
	{
		while (sec >= 1)
		{
			cout << "\rTime remaining to your delivery: " << sec << " sec" << flush;
			Sleep(1000);
			sec--;
		}
	}
	if (sec == 0)
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Your delivery is down, go and get it!" << endl;
		cout << endl;
		return false;
	}
}

int GameOfWords(ORDER* orders, int& size, int count, string guessWord, string scrambleWord, int& points, int inThistimePoints, string gameWords[25])
{
	string name, food, address, specification;
	float  price = 0;

	string answearForTheGame;

	for (int i = 0; i < 25; i++)
	{

		//scrambleWord = gameWords[i];
		// mixUp(scrambleWord);

		scrambleWord = mixUp(gameWords[i]);

		cout << endl;

		cout << "Guess the word: ";

		cout << scrambleWord << endl;

		cout << "Enter your answear: ";

		cin >> guessWord;


		while (count != 4 && guessWord != gameWords[i])
		{


			count++;
			if (count == 4)
			{
				cout << endl<<"You lose, too many tries" << endl;


				cout << "-----------------------------------------------------------------" << endl;
				cout <<endl<< "The mystery word is-->>" << gameWords[i] << endl;
				cout << endl;
				cout << "-----------------------------------------------------------------" << endl;

				cout << endl<< "Your delivery will be there after: " << endl;



				return points;
				return 0;



			}
			else
			{
				cout <<endl<< "Wrong word, try again " << endl;
				cin >> guessWord;
			}
		}

		if (i >= 8)
		{
			cout << "Level 2:" << endl;
			inThistimePoints = 3;
		}

		if (i >= 12)
		{
			cout << "Level 3:" << endl;
			inThistimePoints = 5;
		}

		if (i >= 14)
		{
			cout << "Level 4:" << endl;
			inThistimePoints = 8;
		}

		if (i >= 20)
		{
			cout << "Level 5, now it will be hard than you think:" << endl;
			inThistimePoints = 15;
		}
		if (i == 25)
		{


			cout << "Your delivery will be there after: " << endl;
			return points;
			return 0;

		}

		if (gameWords[i] == guessWord)
		{
			cout << endl<< "Your answear is correct, good job!" << endl;

			inThistimePoints++;

			points = points + inThistimePoints;

			inThistimePoints = 0;

		}



	}

}


void EnterOrderDetails(ORDER* orders, int& size, int min, int sec, int& points)
{

	int count = 1;

	string guessWord;

	string scrambleWord;



	int inThistimePoints = 0;

	string gameWords[25] = { /*1*/"blue",/*2*/"ticket",/*3*/"exercise",/*4*/"orange",/*5*/"atom",/*6*/"chemistry",/*7*/"broadcast",/*8*/"carelessly",
		/*9*/"demonstrate",/*10*/"generously",/*11*/"household",/*12*/"distinguish",/*13*/"embarrassment",/*14*/"independence",/*15*/"exhibitionism",
		/*16*/"psychotomimetic",/*17*/"trichotillomania",/*18*/"omphaloskepsis",/*19*/"myrmecophilous",/*20*/"xenotransplantation",
		/*21*/	"antidisestablishmentarianism",/*22*/"honorificabilitudinitatibus",/*23*/"supercalifragilisticexpialidocious",
		/*24*/"Pneumonoultramicroscopicsilicovolcanoconiosis" };//they start from zero so you need to "-" 1 if you use these index


	string name, food, address, specification;
	float  price;
	string answearForTheGame;
	cout << endl<< "OK, now enter your data for this order:" << endl;
	cout << endl;
	cout << "Enter name:"; cin >> name; cout << endl;

	cout << "You can pick of this option:" << endl;
	cout << endl;
	cout << "burger - 3.50 $" << " " << "|" << " " << "pizza - 10$" << " " << "|" << " " << "rice - 2.5$" << " " << "|" << " " << "ice cream - 1.5$"
		<< " " << "|" << " " << "spaghetti - 3$" << endl;
	cout << endl;

	cout << "Enter food: "; cin >> food; cout << endl;
	cout << "Enter address: "; cin >> address; cout << endl;
	cout << "Enter specification: "; cin >> specification; cout << endl;
	cout << "Enter the price of the product: "; cin >> price; cout << endl;
	cout << endl;
	cout << "Do you wanna play a game while we processes your order ?" << endl;
	cout << endl << "Write ""yes / no"" to answear: ";  cin >> answearForTheGame;
	if (answearForTheGame == "yes")
	{
		cout << endl;
		cout << "|-------------------------------------------------------------------------|" << endl;
		cout << "|          So this is a game where you need to guess the word             |" << endl;
		cout << "|          which letters are shuffled. In this game there are levels      |" << endl;
		cout << "|          In every level you can win points                              | " << endl;
		cout<<"|                                                                         |" << endl;
		cout << "|                                            Good Luck :)                 |" << endl;
		cout << "|-------------------------------------------------------------------------|" << endl;

		GameOfWords(orders, size, count, guessWord, scrambleWord, points, inThistimePoints, gameWords);
		Create(orders, size, name, food, address, specification, price);
		timer(min, sec);

	}
	else
	{
		timer(min, sec);

		if (Create(orders, size, name, food, address, specification, price))
		{
			cout << "Successfully purchased! " << endl;


		}
		else
		{
			cout << "Sorry, you don't have enough money!" << "Try adding some more! " << endl;

		}
	}
}


void walletMoney(float& money)
{
	cin >> money;   //scrambleWord = mixUp(gameWords[i]);
}

void transferingPointsToMoney(int& pointsYouWant, int& points, float& newMoney)
{
	string name, food, address, specification;
	float  price = 0;
	

	cout << endl;
		cout << "        You can entered of this options:" << endl;
		cout<<"-------------------------------------------------------------------------------------" << endl;
		cout << "          20 points = 1$   |  40 points = 2$  |  60 points = 3$"<< endl;
		cout << "          80 points = 1$   |  100 points = 3$ |  120 points = 4$" << endl;
		cout << "          140 points = 5$  |  160 points = 6$ |  180 points = 7$" << endl;
		cout << "                           | 200 points = 10$ |" << endl;  
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout<<endl << "Enter your points, you want to transfer: ";
		cin >> pointsYouWant;
		if (pointsYouWant >= 20 and points >= pointsYouWant and pointsYouWant <= 200)
		{
			points = points - pointsYouWant;
			if (pointsYouWant == 20)
			{
				newMoney = newMoney + 1;
			}
			if (pointsYouWant == 40)
			{
				newMoney = newMoney + 2;
			}
			if (pointsYouWant == 60)
			{
				newMoney = newMoney + 3;
			}
			if (pointsYouWant == 80)
			{
				newMoney = newMoney + 4;
			}
			if (pointsYouWant == 100)
			{
				newMoney = newMoney + 5;
			}
			if (pointsYouWant == 120)
			{
				newMoney = newMoney + 6;
			}
			if (pointsYouWant == 140)
			{
				newMoney = newMoney + 7;
			}
			if (pointsYouWant == 160)
			{
				newMoney = newMoney + 8;
			}
			if (pointsYouWant == 180)
			{
				newMoney = newMoney + 9;
			}
			if (pointsYouWant == 200)
			{
				newMoney = newMoney + 10;
			}
		}
		else
		{
			cout << endl;
			cout << "Your entered points are too low or too high, please follow the table fot inserting points!" << endl;
		}
	
}

void displayHowManyPoints(int& points)
{
	cout<<endl << "This is how much points you have:" << " ";
	cout << points << endl;

}
bool MainMenu(ORDER* orders, int& size, string name, string food, string address, string specification, float price, int min, int sec, int& pointsYouWant, int& points, float& newMoney,float &money)
{
	int index = 1;
	cout << "\nList: \n 1.Add money to your wallet.\n 2.See your balance.\n 3.Make an order. \n 4.Go to the cart . \n 5.Return an order.\n 6.View your points. \n 7.Transfer points. \n 8.Quit \n\n";


	int n;
	cin >> n;
	switch (n)
	{
		{
	case 1:
	{

		cout << "How much money do you want to add?" << endl << "Add: " ;
		walletMoney(money);

		wallet = money + wallet;
		wallet = wallet + newMoney;
		
			cout << "Money added!" << endl << endl;
		
		
	}
	case 2:
	{
		
			wallet = wallet + newMoney;
			cout << endl << "Your balance is " << wallet << "$ !" << endl;
			return true;
		
		
	}
	case 3:
	{
		
		EnterOrderDetails(orders, size, min, sec, points);
		//if (Create(orders, size, name, food, address, specification, price))
		return true;
	}


	case 4:
	{
		ShowAllOrders(orders, size);
		return true;
	}
	case 5:
	{
		cout << endl;
		cout << "Choose what you wish to return:"<<endl;
		ShowAllOrders(orders, size);
		RemoveOrder(orders, size, index);
		return true;
	}
	case 6:
	{
		displayHowManyPoints(points);
		return true;
	}
	case 7:
	{
		transferingPointsToMoney(pointsYouWant, points, newMoney);
		return true;
	}
	case 8:
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
	float money ;
	int pointsYouWant;
	int points = 0;
	float newMoney = 0;
	string name, food, address, specification;
	float price = 0;
	int min = 5;
	int sec = 10;//тук трябва да са 60 попринцип,защото след минутите започват секундите и се почва от 60, но отново за да е по-бързо тук ще е 10
	ORDER orders[500];
	string quit = "OK, bye! Have a nice day\n";
	int size = 0;
	Greetings();
	while (MainMenu(orders, size, name, food, address, specification, price, min, sec, pointsYouWant, points, newMoney, money));
	cout << quit;
}

