#ifndef YILANOYUNU_H
#define YILANOYUNU_H
#include <iostream>
#include <vector>
using namespace std;

struct Konum
{
	int x;
	int y;
};

class YilanOyunu
{
	private:
		
		
		
		char** map;
		Konum konum;
		int alan;
		int yilan_boyu;
		Konum* kuyruk;
		void mapolustur();
	public:
		
		int ms;
		int t;
		int f;
		YilanOyunu();
		YilanOyunu(int);
		void yb_arttir();
		char ilerle(char);
		void test();
		void display();
		void yon_belirle();
		bool oyun(char);
		void asd();
		void yem();
		void kuyruk_ayar();
		void kuyruga_ekle();
		void kuyruktan_sil();
};

#endif
