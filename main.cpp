#include <iostream>
#include "yilan.h"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void yon_belirle(char* yonp)
{
	while(1)
	{
		char p =getch();
		if(p=='w'||p=='a'||p=='s'||p=='d')
		*yonp=p;
		
		
	}
}

int main() {
	system("color 0a");
	cout<<"Yilan oyunu\nLutfen zorluk seciniz(1-10): ";
	int z=0;
	cin>>z;
	int ms=250/z;
	cout<<"Baslamak icin herhangi bir tusa basin";
	getch();
	char yon='d';
	char* yonp=&yon;
	YilanOyunu game(25);
	game.test();
	thread t2(yon_belirle,yonp);
	t2.detach();
	while(game.oyun(yon))
	{
		
		
		game.display();
		this_thread::sleep_for(chrono::milliseconds(ms));
		system("cls");
	
	}
	
	
	return 0;
}
