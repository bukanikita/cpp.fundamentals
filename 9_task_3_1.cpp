#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#pragma pack(push,1)
struct chaff
{
	char dross[20];
	int slag;
};
#pragma pack(pop)

char buffer[2*sizeof(chaff)];

int main() 
{
	const char *info[2] = {"First variable", "Second variable"};
	const int number_of_ch = 2;
	chaff *ch = new (buffer) chaff[number_of_ch];

	cout << "Address of buffer: " << &buffer << endl;
	for (int i = 0; i < number_of_ch; ++i)
	{
		strncpy_s(ch[i].dross, 20, info[i], 20);
		ch[i].slag = i;
		cout << "Adress of " << i+1 << " element " << &ch[i] << endl
			 << "And values in it: \n"
			 << "Dross: " << ch[i].dross << endl
			 << "Slag: " << ch[i].slag << endl;
	}

	cin.get();
	cin.get();

	return 0;
}