#include <iostream>
#include <Windows.h>

using namespace std;
// Program 1
void SetCursor(short x, short y, short color){
    COORD pos = { x, y };
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, pos);
    SetConsoleTextAttribute(h, color);
    cout << "@";
}

int main() {
    short x;
    short y;
    short color;

    cin >> x;
    cin >> y;
    cin >> color;

    SetCursor(x, y, color);
}


// Program 2
char Line(short x, char symbol, short color, bool verticalOrHorizontal) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    if (verticalOrHorizontal) {
        for (int i = 0; i < x; i++) {
            cout << symbol;
        }
    } else if (!verticalOrHorizontal) {
        for (int i = 0; i < x; i++) {
            cout << symbol << endl;
        }
    }
}
int main() {
    short x = 10;
    short color = 12;
    char symbol = '@';
    bool verticalOrHorizontal = true;

    Line(x, symbol, color, verticalOrHorizontal);
}

// Program 3

char Rectangle(short x, short y, char symbol, char fill) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if(i == 0 || j == 0 || i == y - 1 || j == x - 1){
                cout << symbol;
            } else{
                cout << fill;
            }
        }
        cout << endl;
    }
}

int main() {
    short x = 20;
    short y = 30;
    char symbol = '@';
    char fill = '.';
    Rectangle( x,  y,  symbol,  fill);
}
