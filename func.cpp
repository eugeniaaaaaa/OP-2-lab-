#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void check_open(ifstream &f)
{
  if (!f)
  {
    cout << "Файл не открыт. ";
    system("pause");
    exit(1);
  }
}

void get_result(ifstream &file, int result[])
{

  string str, num;
  getline(file, str);
  int n = stoi(str);
  
  int i = 0;
  while (file)
  {
    result[i] = 0;
    getline(file, str);
    str.erase(0, str.find(';') + 1);
    int arr[20], j = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (isdigit(str[i]))
      {
        num = str[i];
        arr[j] = stoi(num);
        j++;
      }
    }
    for (int k = 0; k < 20 - 1; k = k + 2)
    {
      if (arr[k] > arr[k + 1])
      {
        result[i] = result[i] + 3;
      }
      if (arr[k] == arr[k + 1])
      {
        result[i] = result[i] + 1;
      }
    }
    i++;
  }
  file.close();
}
void calculate_result(int result[])
{
  ifstream file2("premier_league1.csv");
  ofstream file1("result.csv");
  string str;
  getline(file2, str);

  string name, winner;
  int best = result[0];
  getline(file2, str);
  str.erase(str.find(';'), str.find('\0'));
  file1 << str << ";" << result[0] << endl;
  winner = str;
  int i = 1;
  while (file2)
  {
    if (i < 20)
    {
      getline(file2, str);
      str.erase(str.find(';'), str.find('\0'));//оставляем название команды
      file1 << str << ";" << result[i] << endl;
      if (result[i] > best)//если результат предыдущего меньше результата текущего
      {
        best = result[i];
        winner = str;//присваиваем победителю название команды
      }
      i++;
    }
    else break;
  }
  file1 << endl << winner << endl;
  file1.close();

}
int main()
{
  ifstream file("premier_league1.csv");
  string str;
  getline(file, str); 
  int n = stoi(str);
  int *result = new int[n];
  get_result(file, result);

}
