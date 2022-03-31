#include <stdio.h>
#include <fstream>
#include <time.h>
#include <string>
#include <algorithm>
#include <iostream>  
#include <string>  
#include <vector>  
#include <sstream>
#include <cstring> 

using namespace std;
void printTab(int *tab, int n);
int*  findMinAndMax(int* tab, int n);


void counting_sort(int *tab, int n, int yMin, int yMax) {

	int* counters = new int[yMax - yMin + 1];

	//Wstawiamy początkowe wartości liczników
	for (int x = 0; x < (yMax - yMin + 1); x++)
	{
		counters[x] = 0;
	}

	for (int x = 0; x < n; x++)
	{
		//Zliczamy ilość wystąpień poszczególnych elementów
		counters[tab[x] - yMin]++;
	}

	//Zapisujemy elementy w ilości podyktowanej przez liczniki
	//w tablicy docelowej
	int lastIndex = 0;
	for (int x = 0; x < (yMax - yMin + 1); x++)
	{
		int y;
		for (y = lastIndex; y < counters[x] + lastIndex; y++)
		{
			tab[y] = x + yMin;
		}
		lastIndex = y;
	}
}

int main() {
	int n;
    string STRING,T,odpowiedz,sortowanie;
	int okrazenia=0;
	int ilosc[17]={10,50,100,500,1000,2000,5000,10000,20000,50000,100000,200000,300000,500000,700000,900000,1000000};
	cout << "Choose how many variables do you want to sort"<<endl;
	int zmienna; //= ilosc[9];
	cin >> zmienna;
	int *liczby = new int[zmienna];
	ifstream infile;
	infile.open ("liczby.txt");
    while(!infile.std::ios::eof())
    {
	    getline(infile,STRING);
	}
	stringstream X(STRING);
	while (getline(X, T, ',')) {    
		liczby[okrazenia]=atoi(T.c_str());
		if(okrazenia+1 == zmienna){
			break;
		}
		okrazenia++;
	}

	int* minAndMax = findMinAndMax(liczby, zmienna);
	counting_sort(liczby, zmienna, minAndMax[0], minAndMax[1]);
    cout << "Do you want to save sorted data ?"<<endl;
	cin >> odpowiedz;
	if(odpowiedz == "yes"){
		ofstream zapis("dane2.txt");
		for(int x=0; x<zmienna; x++){
			zapis<<liczby[x]<<endl;
		}
		zapis.close();
	}
	infile.close();

	delete[] liczby;
	delete[] minAndMax;
	system("pause");
	return 0;

}

void printTab(int *tab, int n) {
	cout << endl << "\t| ";
	for (int x = 0; x < n; x++) {
		cout << tab[x] << " | ";
	}
	cout << endl << endl;
}

//Funkcja do wyszukiwania największej i 
//najmniejszej wartości w tablicy
int*  findMinAndMax(int* tab, int n)
{
	int* minAndMax = new int[2];
	minAndMax[0] = tab[0];
	minAndMax[1] = tab[0];

	for (int x = 0; x < n; x++)
	{
		if (tab[x] < minAndMax[0])
		{
			minAndMax[0] = tab[x];
		}
		if (tab[x] > minAndMax[1])
		{
			minAndMax[1] = tab[x];
		}
	}

	return minAndMax;
}