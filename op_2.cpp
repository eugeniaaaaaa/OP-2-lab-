#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void check_open(ifstream &f)
{								//if file wasn`t opened -> exit
	if (!f)
	{
		cout << "File isn't open. ";
		system("pause");
		exit(1);
	}
}
int main()
{
	ifstream file("premier_league1.csv");
	
}