#include <cstdlib>
#include <ctime>
// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
//thay doi kich thuoc cốnle
//void resizeConsole(int width, int height)
//{
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, width, height, TRUE);
//}
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}
// Thiết lập chế độ hiển thị, có fullscreen hay không
BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

// Đặt chế độ FullScreen
void setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

// Thoát khỏi fullscreen
void exitFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
// tắt con trỏ
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
// Ham tao so ngau nghien
void Random(int &soCanDat, int khoangGiaTri)
{
	srand(time(0));
	soCanDat = rand() % khoangGiaTri + 2;
}
void setthucan(toadothucan *tdthucan, toadoran *toado) {
	bool a = true;
	while (a) {
		for (int b = 0; b < sodot; b++) {
			Random(tdthucan->X, 38);
			Random(tdthucan->Y, 28);
			if (tdthucan->X == toado[b].x&&tdthucan->Y == toado[b].y||tdthucan->X==10&&tdthucan->Y==8 || tdthucan->X == 10 && tdthucan->Y == 9 || tdthucan->X == 10 && tdthucan->Y == 10 || tdthucan->X == 10 && tdthucan->Y == 22 || tdthucan->X == 10 && tdthucan->Y == 21 || tdthucan->X == 10 && tdthucan->Y == 20 || tdthucan->X == 30 && tdthucan->Y == 8 || tdthucan->X == 30 && tdthucan->Y == 9 || tdthucan->X == 30 && tdthucan->Y == 10 || tdthucan->X == 30 && tdthucan->Y == 22 || tdthucan->X == 30 && tdthucan->Y == 21 || tdthucan->X == 30 && tdthucan->Y == 20 || tdthucan->X == 22 && tdthucan->Y == 7 || tdthucan->X == 21 && tdthucan->Y == 7 || tdthucan->X == 20 && tdthucan->Y == 7 || tdthucan->X == 19 && tdthucan->Y == 7 || tdthucan->X == 22 && tdthucan->Y == 23 || tdthucan->X == 21 && tdthucan->Y == 23 || tdthucan->X == 20 && tdthucan->Y == 23 || tdthucan->X == 19 && tdthucan->Y == 23) {
				Random(tdthucan->X, 38);
				Random(tdthucan->Y, 28);
			}
			else { a = false; }
		}
	}
}
void setthucan2(toadothucan2 *tdspc, toadoran *toado) {
	bool a = true;
	while (a) {
		for (int b = 0; b < sodot; b++) {
			Random(tdthucan->X, 38);
			Random(tdthucan->Y, 28);
			if (tdspc->X == toado[b].x&&tdspc->Y == toado[b].y || tdspc->X == 10 && tdspc->Y == 8 || tdspc->X == 10 && tdspc->Y == 9 || tdspc->X == 10 && tdspc->Y == 10 || tdspc->X == 10 && tdspc->Y == 22 || tdspc->X == 10 && tdspc->Y == 21 || tdspc->X == 10 && tdspc->Y == 20 || tdspc->X == 30 && tdspc->Y == 8 || tdspc->X == 30 && tdspc->Y == 9 || tdspc->X == 30 && tdspc->Y == 10 || tdspc->X == 30 && tdspc->Y == 22 || tdspc->X == 30 && tdspc->Y == 21 || tdspc->X == 30 && tdspc->Y == 20 || tdspc->X == 22 && tdspc->Y == 7 || tdspc->X == 21 && tdspc->Y == 7 || tdspc->X == 20 && tdspc->Y == 7 || tdspc->X == 19 && tdspc->Y == 7 || tdspc->X == 22 && tdspc->Y == 23 || tdspc->X == 21 && tdspc->Y == 23 || tdspc->X == 20 && tdspc->Y == 23 || tdspc->X == 19 && tdspc->Y == 23) {
				Random(tdspc->X, 38);
				Random(tdspc->Y, 28);
			}
			else { a = false; }
		}
	}
}
void antd(int sodotcongthem, toadoran *toado, int toadothucanx, int toadothucany) {
	if (toadothucanx == toado->x &&toadothucany == toado->y) {
		if (tdspct == false) {
			setthucan(tdthucan, toado);
		}
		else {
			setthucan2(tdspc, toado);
		}
		sodot += sodotcongthem;
		diem += sodotcongthem;
	}
}
