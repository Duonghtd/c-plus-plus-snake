#include <Windows.h>
#include <iostream>
#include "code.h"
void khoidau(toadoran *toado) {
	song = true;
	system("cls");
	setthucan(tdthucan,toado);
	textcolor(2);
	setran(toado);
	vekhung();
	veran(toado);
	phai = true;
	setthucan2(tdspc,toado);
}
int main() {
	SetWindow(80, 30);
	setFullScreen();
	for (;;) {
		Nocursortype();
		giaodien();
		chon();
		xuatdiemcao();
		controlspeed();
		if (c1 == true || c2 == true) {
			khoidau(toado);
			while(song==true) {
				vekhungdb();
				benphai();
				Nocursortype();
				vekhung();
				thucan(tdthucan,toado);
				if ((int)ti % 10 == 0) {
					thucandb(tdspc);
				}
				antd(toado,tdthucan,tdspc);
				timdiemcao();
				dichuyenran(toado);
				switch (c1) {
				case true: {
					t1(toado);
			
					break;
				}
				case false: {
					t2(toado);
					break;
				}
				}
				canduoi(toado);

				veran(toado);
				xulytocdo(toado);
			}
			system("cls");
		}
	}
	return 0;
}
