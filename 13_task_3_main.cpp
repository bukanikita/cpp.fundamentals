#include "13_task_3_dma.h"

const int DMA = 4;

int main()
{
	abstractDMA *dma[DMA];
	std::string temp;
	int rating;
	char kind;

	for (int i = 0; i < DMA; i++)
	{
		cout << "Enter dma's label: ";
		getline(cin,temp);
		cout << "Enter dma's rating: ";
		cin >> rating;
		cout << "Enter 1 for baseDMA, 2 for lackDMA and 3 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout <<"Enter either 1, 2 or 3: ";
		if (kind == '1')
		{
			dma[i] = new baseDMA(temp.c_str(), rating);
			while (cin.get() != '\n')
				continue;
		}
		else if (kind == '2')
		{
			cin.get();
			std::string temp_col;
			cout << "Enter dma's color: ";
			getline(cin,temp_col);
			dma[i] = new lacksDMA(temp_col.c_str(), temp.c_str(), rating);
		}
		else
		{
			cin.get();
			std::string temp_style;
			cout << "Enter dma's style: ";
			getline(cin,temp_style);
			dma[i] = new hasDMA(temp_style.c_str(), temp.c_str(), rating);
		}
	}
	cout << endl;
	for (int i = 0; i < DMA; i++)
	{
		dma[i]->View();
		cout << endl;
	}

	for (int i = 0; i < DMA; i++)
	{
		delete dma[i];  // free memory
	}
	cout << "Done.\n";           

	cin.get();
	cin.get();

	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

