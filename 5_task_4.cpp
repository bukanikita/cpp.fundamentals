#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int investment = 100;
	double money_of_Daphne = static_cast<double> (investment), money_of_Cleo = static_cast<double> (investment);
	double percent_of_Daphne = 0.1, percent_of_Cleo = 0.05;
	int year = 0;

	do 
	{
		money_of_Daphne += percent_of_Daphne * static_cast<double> (investment);
		money_of_Cleo += percent_of_Cleo * static_cast<double> (money_of_Cleo);
		year++;
		cout << "After year " << year << ":\n";
		cout << "Daphne's sum is: " << money_of_Daphne << endl;
		cout << "Cleo's sum is: " << money_of_Cleo << endl;
	} while (money_of_Daphne > money_of_Cleo);

	cout << "After " << year << " years sum of Cleo's sum is bigger than Daphne's sum\n";
	
	cin.get();
	cin.get();

	return 0;
}