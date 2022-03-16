#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>  
#include <string>  
#include <vector>  
#include <sstream> 
#include <cstring> 
using namespace std;
void sortowanieWstawianie(int n, int *tab)
{
     int pom, j;
     for(int i=1; i<n; i++)
     {
             pom = tab[i];
             j = i-1;
             while(j>=0 && tab[j]>pom) 
             {
                        tab[j+1] = tab[j];
                        --j;
             }
             tab[j+1] = pom;
     }     
}
void sortowanieSzybkie(int *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;
	
	int i = lewy - 1, j = prawy + 1, 
	pivot = tab[(lewy+prawy)/2];
	
	while(1)
	{
		while(pivot>tab[++i]);
		
		while(pivot<tab[--j]);
		
		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	sortowanieSzybkie(tab, lewy, j);
	if(i < prawy)
	sortowanieSzybkie(tab, i, prawy);
}

void sortowanieBabelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++)
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}

int main(){
    string STRING,T;
	int okrazenia=0;
	int ilosc[17]={10,50,100,500,1000,2000,5000,10000,20000,50000,100000,200000,300000,500000,700000,900000,1000000};
	int zmienna = ilosc[16];
	int *liczby = new int[zmienna];
	ifstream infile;
	infile.open ("liczby.txt");
    while(!infile.std::ios::eof())
    {
	    getline(infile,STRING);
	}
	stringstream X(STRING);
	while (getline(X, T, ',')) {    
		liczby[okrazenia]=stoi(T);
		if(okrazenia+1 == zmienna){
			break;
		}
		okrazenia++;
	}
	//sortowanieSzybkie(liczby,0,zmienna);
	//sortowanieBabelkowe(liczby,zmienna);
	//sortowanieWstawianie(zmienna,liczby);
	ofstream zapis("dane.txt");
	for(int x=0; x<zmienna; x++){
		zapis<<liczby[x]<<endl;
	}
	infile.close();
	system ("pause");
	zapis.close();
	delete liczby;
}