#include <iomanip>
#include "bien.h"
#include"ham.h"
void chet() {
	song = false;
	c1 = false;
	c2 = false;
	gotoxy(20, 14);
	textcolor(9);
	cout << "thua";
	gotoxy(20, 15);
	cout << "diem cao la" << ": " << diemcao;
	Sleep(2000);
	sodot = 3;
	diem = 0;
	ti = 0.0;
}
void xoaduoi(toadoran *toado) {
	gotoxy(toado[sodot - 1].x, toado[sodot - 1].y);
	textcolor(0);
		cout << " ";
 }
void veran(toadoran *toado) {
	textcolor(mauran);
	for (int k = 0; k < sodot; k++) {
		gotoxy(toado[k].x, toado[k].y); cout << (char)254;
	}
}
void setran(toadoran *toado) {
	toado[0].x = 12;
	toado[1].x = 11;
	toado[2].x = 10;
	toado[0].y = 20;
	toado[1].y = 20;
	toado[2].y = 20;
}
void vekhung() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == 0 || i == 29 || j == 0 || j == 39) {
				gotoxy(j, i);
				textcolor(119);
				cout << " ";
			}
		}
	}
}
void noiduoi(toadoran *toado) {
	for (int H = sodot; H > 0; H--) {
		toado[H].x = toado[H - 1].x;
		toado[H].y = toado[H - 1].y;
	}
}
void sangtrai(toadoran *toado) {
	noiduoi(toado);
	toado[0].x -= 1;
}
void sangphai(toadoran *toado) {
	noiduoi(toado);
	toado[0].x += 1;
}
void xuongduoi(toadoran *toado) {
	noiduoi(toado);
	toado[0].y += 1;
}
void lentren(toadoran *toado) {
	noiduoi(toado);
	toado[0].y -= 1;

}
void dichuyenran(toadoran *toado) {

	if (GetAsyncKeyState(VK_LEFT) && phai == false) {
		trai = true;
		phai = false;
		tren = false;
		duoi = false;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && trai == false) {
		trai = false;
		phai = true;
		tren = false;
		duoi = false;
	}
	else if (GetAsyncKeyState(VK_UP) && duoi == false) {
		trai = false;
		phai = false;
		tren = true;
		duoi = false;
	}
	else if (GetAsyncKeyState(VK_DOWN) && tren == false) {
		trai = false;
		phai = false;
		tren = false;
		duoi = true;
	}
	xoaduoi(toado);
	if (trai == true && phai == false && tren == false && duoi == false) {
		sangtrai(toado);
		ti += 0.2;
	}
	if (trai == false && phai == true && tren == false && duoi == false) {
		sangphai(toado);
		ti += 0.2;
	}
	if (trai == false && phai == false && tren == true && duoi == false) {
		lentren(toado);
		ti += 0.2;
	}
	if (trai == false && phai == false && tren == false && duoi == true) {
		xuongduoi(toado);
		ti += 0.2;
	}

}
void thucan(toadothucan *tdthucan,toadoran *toado) {
	textcolor(14);
	gotoxy(tdthucan->X, tdthucan->Y); cout << "*";
}
void t1(toadoran *toado){
	
	if (toado[0].x ==0) {
		toado[0].x = 38;
	}
	else if(toado[0].x == 39) {
		toado[0].x = 1;
	}
	else if(toado[0].y == 29) {
		toado[0].y = 1;
	}
	else if(toado[0].y == 0) {
		toado[0].y = 28;
	}
}
void xoachuot() {
	int k = 8;
	while (k <= 14) {
		
		gotoxy(17, k);
		cout << "  ";
		k += 2;
	}
}
void pick() {
	if (toadochuot == 8 && GetAsyncKeyState(VK_RIGHT)) {
		c1 = true; c2 = false; xuatdiemcao1 = false; tocdogameran = false;
	}
	else if (toadochuot == 10 && GetAsyncKeyState(VK_RIGHT)) {
		c2 = true; c1 = false; xuatdiemcao1 = false; tocdogameran = false;
	}
	else 	if (toadochuot == 12 && GetAsyncKeyState(VK_RIGHT)) {
		c1 = false; c2 = false; xuatdiemcao1 = true; tocdogameran = false;
	}
	else 	if (toadochuot == 14 && GetAsyncKeyState(VK_RIGHT)) {
		c1 = false; c2 = false; xuatdiemcao1 = false; tocdogameran = true;
	}
}
void giaodien(){
	gotoxy(15, 5);
	textcolor(13);
	cout << "game ran san moi";
	gotoxy(20, 8);
	textcolor(12);
	cout << "co dien";
	gotoxy(20, 10);
	textcolor(11);
	cout << "hien dai";
	gotoxy(20, 12);
	textcolor(10);
	cout << "diem cao";
	gotoxy(20, 14);
	textcolor(9);
	cout << "muc do";
}
void chon(){
	gotoxy(17, toadochuot);
	textcolor(5);
	cout << "->";
	Sleep(500);
	pick();
	
	if (toadochuot == 8 && GetAsyncKeyState(VK_DOWN)) {
		xoachuot();
		toadochuot += 2;
	}
	else if (toadochuot == 10 && GetAsyncKeyState(VK_DOWN)) {
		xoachuot();
		toadochuot += 2;
	}
	else if (toadochuot == 12 && GetAsyncKeyState(VK_DOWN)) {
		xoachuot();

		toadochuot += 2;
	}
	else if (toadochuot == 14 && GetAsyncKeyState(VK_UP)) {
		xoachuot();
		toadochuot -= 2;
	}
	else if (toadochuot == 12 && GetAsyncKeyState(VK_UP)) {
		xoachuot();
		toadochuot -= 2;
	}
	else if (toadochuot == 10 && GetAsyncKeyState(VK_UP)) {
		xoachuot();
		toadochuot -= 2;
	}
	Sleep(100);
}
void benphai() {
	textcolor(5);
	gotoxy(50, 1);
	cout << "thoi gian da choi : " << setw(3) <<ti << "s";
	gotoxy(50, 4);
	cout << "diem cao la: " << diemcao;
	gotoxy(50, 7);
	cout << "diem hien tai: " << diem;
}
void t2(toadoran *toado) {
	if (toado->x == 0 || toado->x == 39 || toado->y == 0 || toado->y == 29) {
		chet();
	}
}
void canduoi(toadoran *toado) {
	for (int a = 3; a <= sodot; a++) {
		if (toado[0].x == toado[a].x) {

			if (toado[0].y == toado[a].y) {
				chet();
			}
		}
	}
}
void timdiemcao() {
	if(diem>=diemcao){
		diemcao = diem;
	}
}
void xuatdiemcao() {
	if (xuatdiemcao1 == true) {
		system("cls");
		while (xuatdiemcao1 == true) {
			textcolor(8);
			gotoxy(20, 14);
			cout << "diem cao la : " << diemcao;
			gotoxy(1, 29);
			textcolor(9);
			cout << "<- " << "thoat";
			if (GetAsyncKeyState(VK_LEFT)) {
				xuatdiemcao1 = false;
				system("cls");
			}
		}
	}
}
void dieuchinhspeed() {
	gotoxy(19, 5);
	textcolor(3);
	cout << "muc do";
	gotoxy(20, 8);
	textcolor(10);
	cout << "nhanh";
	gotoxy(20, 10);
	textcolor(12);
	cout << "binh thuong";
	gotoxy(20, 12);
	textcolor(11);
	cout << "cham";
}
void pick2() {
	if (toadochuot2 == 8 && GetAsyncKeyState(VK_RIGHT)) {
		spg = 50;
		tocdogameran = false;
	}
	else if (toadochuot2 == 10 && GetAsyncKeyState(VK_RIGHT)) {
		spg = 100;
		tocdogameran = false;
	}
	else if (toadochuot2 == 12 && GetAsyncKeyState(VK_RIGHT)) {
		spg = 150;
		tocdogameran = false;
	}
}
void gamespeedpick() {
	gotoxy(17, toadochuot2);
	textcolor(5);
	cout << "->";
	Sleep(500);
	if (toadochuot2 == 8 && GetAsyncKeyState(VK_DOWN)) {
		xoachuot();
		toadochuot2 += 2;
	}
	else if (toadochuot2 == 10 && GetAsyncKeyState(VK_DOWN)) {
		xoachuot();
		toadochuot2 += 2;
	}
	else if (toadochuot2 == 12 && GetAsyncKeyState(VK_UP)) {
		xoachuot();
		toadochuot2 -= 2;
	}
	else if (toadochuot2 == 10 && GetAsyncKeyState(VK_UP)) {
		xoachuot();
		toadochuot2 -= 2;
	}
	Sleep(100);
}
void controlspeed() {
	if (tocdogameran) {
		system("cls");
		while (tocdogameran) {
			dieuchinhspeed();
			gamespeedpick();
			pick2();
		}
		system("cls");
	}
}
void vekhungdb() {
	//nhanh
	textcolor(17);
	gotoxy(10,8);
	cout << " ";
	gotoxy(10, 9);
	cout << " ";
	gotoxy(10, 10);
	cout << " ";
	gotoxy(10, 22);
	cout << " ";
	gotoxy(10, 21);
	cout << " ";
	gotoxy(10, 20);
	cout << " ";
	gotoxy(30, 8);
	cout << " ";
	gotoxy(30, 9);
	cout << " ";
	gotoxy(30, 10);
	cout << " ";
	gotoxy(30, 22);
	cout << " ";
	gotoxy(30, 21);
	cout << " ";
	gotoxy(30, 20);
	cout << " ";
	// cham
	textcolor(34);
	gotoxy(22, 7);
	cout << " ";
	gotoxy(21, 7);
	cout << " ";
	gotoxy(20, 7);
	cout << " ";
	gotoxy(19, 7);
	cout << " ";
	gotoxy(22, 23);
	cout << " ";
	gotoxy(21, 23);
	cout << " ";
	gotoxy(20, 23);
	cout << " ";
	gotoxy(19, 23);
	cout << " ";
}
void xulytocdocon() {
	if (sp > 0) {
		if (spt == true) {
			Sleep(spg - 40);
		}
		else if (spt == false) {
			Sleep(spg + 50);
		}
	}
	else Sleep(spg);
}
void xulytocdo(toadoran * toado) {
	if (toado[0].x == 10 || toado[0].x == 30) {
		if (toado[0].y == 9 || toado[0].y == 10 || toado[0].y == 8 || toado[0].y == 20 || toado[0].y == 21 || toado[0].y == 22) {
			sp = 10;
			spt= true;

		}
	}
	else if (toado[0].y == 7 || toado[0].y == 23) {
		if (toado[0].x == 22 || toado[0].x == 21 || toado[0].x == 20 || toado[0].x == 19) {
			sp = 10;
			spt = false;
			}
	}
	xulytocdocon();
	if (sp > 0) {
		sp--;
		if (spt == true) {
			mauran = 9;
		}
		else {
			mauran = 10;
		}
	}
	else mauran = 12;
}
void thucandb(toadothucan2 *tdspc) {
	textcolor(54);
	gotoxy(tdspc->X, tdspc->Y); cout << "*";
}
