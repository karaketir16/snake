#include <iostream>
#include <conio.h>
#include "yilan.h"
#include <cstdlib>
#include <ctime>
using namespace std;

YilanOyunu::YilanOyunu()
{
	alan=10;
	map= new char*[alan];
	for(int b=0;b<alan;b++)
	{
		map[b]= new char[alan];
	}
	mapolustur();
}

YilanOyunu::YilanOyunu(int a)
{
	t=0;
	f=0;
	alan =a;
	kuyruk=new Konum[alan*alan];
	
	for(int f=0;f<alan*alan;f++)
	{
		kuyruk[f].x=0;
		kuyruk[f].y=0;
	}
	
	
	map= new char*[alan];
	for(int b=0;b<alan;b++)
	{
		map[b]= new char[alan];
	}
	mapolustur();
	
	konum.x=konum.y=a/2;
	kuyruga_ekle();
	yilan_boyu=2;
	
	

}
void YilanOyunu::test()
{
	display();
}
void YilanOyunu::mapolustur()
{
	for(int a=0;a<alan;a++)
	{
		for(int b=0;b<alan;b++)
		{
			
			map[a][b]=' ';
			
		}
	}
	for(int a=0;a<alan;a++)
	{
		for(int b=0;b<alan;b++)
		{
			
			if(a==0)
			{
				map[a][b]='X';
			}
			
			if(b==0)
			{
				map[a][b]='X';
			}
			if(a==(alan-1))
			{
				map[a][b]='X';
			}
			if(b==(alan-1))
			{
				map[a][b]='X';
			}
			
			
			
		}
	}
	yem();
}
void YilanOyunu::display()
{
	for(int y=alan-1;y>=0;y--)
	{
		for(int x=0;x<alan;x++)
		{
			cout<<map[x][y];
		}
		cout<<endl;
	}

	
}
void YilanOyunu::asd()
{
	while(1)
	{
		//cout<<yon;
	}
}

char YilanOyunu::ilerle(char yon)
{
	
	
	if(yon=='w')
	{
		konum.y++;
		char ch=map[konum.x][konum.y];
		map[konum.x][konum.y]='#';
		kuyruga_ekle();
		return ch;
	}
	if(yon=='a')
	{
		konum.x--;
		char ch=map[konum.x][konum.y];
		map[konum.x][konum.y]='#';
		kuyruga_ekle();
		return ch;
	}
	if(yon=='s')
	{
		konum.y--;
		char ch=map[konum.x][konum.y];
		map[konum.x][konum.y]='#';
		kuyruga_ekle();
		return ch;
	}
	if(yon=='d')
	{
		konum.x++;
		char ch=map[konum.x][konum.y];
		map[konum.x][konum.y]='#';
		kuyruga_ekle();
		return ch;
	}
	
	
}
bool YilanOyunu::oyun(char yon)
{
	char ch=ilerle(yon);
	if(ch=='X'||ch=='#')
	{
		return 0;
	}
	if(ch=='a')
	{
		yilan_boyu++;
		yem();
		return 1;
	}
	kuyruktan_sil();
	return 1;
}
void YilanOyunu::yem()
{
	int x,y;
	srand(time(NULL));
	do
	{
		x=rand()%alan;
		y=rand()%alan;
	}while(map[x][y]!=' ');
	
	map[x][y]='a';
}
void YilanOyunu::kuyruga_ekle()
{
	
	
	
	kuyruk[t].x=konum.x;
	kuyruk[t].y=konum.y;
	t++;
}

void YilanOyunu::kuyruktan_sil()
{
	
	
		map[kuyruk[f].x][kuyruk[f].y]=' ';
		f++;
		for(int o=1;o<t;o++)
		{
			kuyruk[o-1].x=kuyruk[o].x;
			kuyruk[o-1].y=kuyruk[o].y;
		}
		f--;
		t--;
}

