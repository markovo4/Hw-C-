#include <iostream>
#include <Windows.h>
#include <cwchar>
#include <ctime>
using namespace std;

// Functions
void gotoxy(int x, int y); // Function that moves Console Cursor to the x and y coordinates passed in as arguments to the function.
void drawMap();// Function that draws out Game Play Field, where players can perform actions.
void playerField(HANDLE hconsole, int isPlayer); // Function that draws out Player Field, where player have space to make choices.
int fontSize(int x, int y); // Function that changes Font-size and Font-style.
void initGame(HANDLE hconsole); // Function that initiates the game.
void drawDiceFace(HANDLE hConsole, int x, int y, int diceValue); // Function that draws at specific coordinates dice.
void drawLine(HANDLE hConsole, int x, int y, int color, string text); // Function that draws out text at a specific point that was provided.
void drawLine(HANDLE hConsole, COORD position, int color, string text); // Function that draws out text at a specific coordinate that was provided;
inline int randomDice(); // Function that returns a random number in the range of (0 , 5).
inline int randomTrurn(); // Function that defines who is the first one Player/Computer to start moving.
void displayCursor(HANDLE hconsole, bool isDisplay); // Function that Displayes/Hides console cursor.
void fillCoords(COORD arr[], bool isComputer); // Function that fills coordinates, players will move at and defines if it is a Player/Computer based on a bool variable.
void isFullRound(int* index, int* diceSum, int* accum); // Function that checks if the full round was completed.
void nextTurn(int takeATurn, int* turn, bool* isMove); // Function that checks what turn is it.

// Constants
const int WIDTH_PLAYER_FIELD = 82;
const int HIEGHT_PLAYER_FIELD = 55;
const int PLAYER_COORDS = 40;


int main() {
    srand(time(0));
    system("title Monopoly");

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    bool isRunning = true;
    bool isMoving = true;
    int turn = randomTrurn();
    int diceTotal = 0;
    int diceTotalComp = 0;

    int accumulator = 0;
    int accumulatorComp = 0;

    initGame(h);

    COORD pointsPlayer[PLAYER_COORDS];
    COORD pointsComputer[PLAYER_COORDS];

    fillCoords(pointsPlayer, false);
    fillCoords(pointsComputer, true);

    drawLine(h, 6, 2, 10, "@");
    drawLine(h, 6, 3, 12, "#");

    while (isRunning) {

        if (turn == 0) {
            drawLine(h, 6, 3, 12, " ");
        }
        else if (turn == 1) {
            drawLine(h, 6, 2, 10, " ");
            drawLine(h, pointsPlayer[diceTotal - 1], 10, " ");
        }

        int diceOne = randomDice();
        int diceTwo = randomDice();

        drawDiceFace(h, 30, 19, diceOne);
        drawDiceFace(h, 95, 19, diceTwo);

        playerField(h, turn);

        if (turn == 1) {
            SetConsoleTextAttribute(h, 10);
            drawLine(h, pointsPlayer[diceTotal - 1], 10, " ");

        }
        else if (turn == 0) {
            SetConsoleTextAttribute(h, 12);
            drawLine(h, pointsComputer[diceTotalComp - 1], 12, " ");
        }

        if (isMoving) {
            if (turn == 1) {
                diceTotal += (diceOne + 1) + (diceTwo + 1);
                for (int i = accumulator; i < diceTotal; i++) {
                    isFullRound(&i, &diceTotal, &accumulator);
                    drawLine(h, pointsPlayer[i], 10, "@");
                    Sleep(300);
                    drawLine(h, pointsPlayer[i], 10, " ");
                }
                drawLine(h, pointsPlayer[diceTotal - 1], 10, "@");

                accumulator = diceTotal;
                isMoving = false;
            }
            else if (turn == 0) {
                diceTotalComp += (diceOne + 1) + (diceTwo + 1);
                for (int i = accumulatorComp; i < diceTotalComp; i++) {
                    isFullRound(&i, &diceTotalComp, &accumulatorComp);
                    drawLine(h, pointsComputer[i], 12, "#");
                    Sleep(300);
                    drawLine(h, pointsComputer[i], 12, " ");
                }
                drawLine(h, pointsComputer[diceTotalComp - 1], 12, "#");
                accumulatorComp = diceTotalComp;
                isMoving = false;
            }
        }
        if (!isMoving) {
            int takeATurn = 0;
            if (turn == 0) {
                drawLine(h, 200, 3, 10, "TO THROW DICE: PRESS [1]");
                nextTurn(takeATurn, &turn, &isMoving);
            }
            else if (turn == 1) {
                drawLine(h, 200, 5, 10, "TO PASS THE TURN: PRESS [1]");
                nextTurn(takeATurn, &turn, &isMoving);
            }
        }
    }
}

void displayCursor(HANDLE hconsole, bool isDisplay) {
    CONSOLE_CURSOR_INFO cci = { 100, isDisplay };
    SetConsoleCursorInfo(hconsole, &cci);
}

void drawMap() {
    char map[] =
            "#########################################################################################################################################################\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #     ---     #             #     ---     #     ---     #             #     ---    #     ---     #             #     ---    #             #\n"
            "#########################################################################################################################################################\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #     ---     #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #     ---     #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #     ---     #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #             #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #     ---     #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "###############                                                                                                                           ###############\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#             #                                                                                                                           #             #\n"
            "#    ---      #                                                                                                                           #     ---     #\n"
            "#########################################################################################################################################################\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #             #             #             #             #             #            #             #             #            #             #\n"
            "#             #     ---     #     ---     #             #     ---     #             #            #     ---     #             #     ---    #             #\n"
            "#########################################################################################################################################################\n";
    cout << map;
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void playerField(HANDLE hconsole ,int isPlayer) {
    if (isPlayer) {
        SetConsoleTextAttribute(hconsole, 10);
    }
    else if (!isPlayer) {
        SetConsoleTextAttribute(hconsole, 12);
    }
    const int startX = 155;
    const int startY = 0;
    const int endY = 55;
    const string borderLine = "##                                      #                                       ##";
    const string separatorLine = "##------------------------------------------------------------------------------##";

    gotoxy(startX, startY);
    cout << "##################################################################################\n";

    for (int y = startY + 1; y < endY; ++y) {
        gotoxy(startX, y);
        cout << borderLine << "\n";
        if (y == 24 || y == 40) {
            gotoxy(startX, y);
            cout << separatorLine << '\n';
        }
    }

    gotoxy(startX, endY);
    cout << "##################################################################################\n";
}

int fontSize(int x, int y) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = x; // Width of each character in the font
    cfi.dwFontSize.Y = y; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font

    if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi)) {
        std::cerr << "Error: SetCurrentConsoleFontEx failed." << std::endl;
        return 1;
    }
}

void initGame(HANDLE hconsole) {
    int game;
    static string userName;
    displayCursor(hconsole, false);
    SetConsoleTextAttribute(hconsole, 6);
    fontSize(15, 35);
    gotoxy(48, 2);
    cout << "W E L C O M E  TO  M O N O P O L Y";
    gotoxy(53, 4);
    cout << "Would you like to play?";
    gotoxy(54, 6);
    cout << "PRESS  [1]-Yes [0]-No\n";
    cin >> game;
    if (game == 0) {
        system("CLS");
        gotoxy(56, 10);
        cout << "You Exited the Game!" << endl;
    }
    else {
        gotoxy(51, 8);
        cout << "PLEASE ENTER YOUR USER_NAME: ";
        displayCursor(hconsole, true);
        gotoxy(59, 10);
        cout << "__________";
        gotoxy(59, 10);
        cin >> userName;
        fontSize( 0, 17.5);
        displayCursor(hconsole, false);
        system("CLS");
        system("mode con cols=250 lines=60");
        drawMap();
    }
}

void drawDiceFace(HANDLE hConsole,int x, int y, int diceValue) {
    const char* allDiceFaces[6][15] = {
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##           #           ##\n",
                    "##          ###          ##\n",
                    "##           #           ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##    ###                ##\n",
                    "##    ###                ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                ###    ##\n",
                    "##                ###    ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##    ###                ##\n",
                    "##    ###                ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##           #           ##\n",
                    "##          ###          ##\n",
                    "##           #           ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                ###    ##\n",
                    "##                ###    ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##           #           ##\n",
                    "##          ###          ##\n",
                    "##           #           ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
            {
                    "###########################\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##     #           #     ##\n",
                    "##    ###         ###    ##\n",
                    "##     #           #     ##\n",
                    "##                       ##\n",
                    "##                       ##\n",
                    "##    ###         ###    ##\n",
                    "##    ###         ###    ##\n",
                    "##                       ##\n",
                    "###########################\n"
            },
    };

    const WORD diceColors[6] = { 10, 11, 12, 13, 14, 15 };

    for (int j = 0, m = y; j < 15; j++, m++) {
        drawLine(hConsole, x, m, diceValue + 1, allDiceFaces[diceValue][j]);
    }
}

void drawLine(HANDLE hConsole, int x, int y, int color, string text) {
    COORD position;
    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(hConsole, position);
    SetConsoleTextAttribute(hConsole, color);
    cout << text;
}

void drawLine(HANDLE hConsole, COORD position, int color, string text) {
    SetConsoleCursorPosition(hConsole, position);
    SetConsoleTextAttribute(hConsole, color);
    cout << text;
}

inline int randomDice() { return rand() % 6; }

inline int randomTrurn() { return rand() % 1; }

void fillCoords(COORD arr[], bool isComputer) {
    int startPointX = 6;
    int index = 0;
    int startPointY = isComputer ? 3 : 2;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 10; x++) {

            if (y == 0) {
                startPointX += 14;
            }
            else if (y == 1) {
                startPointY += 5;
            }
            else if (y == 2) {
                startPointX -= 14;
            }
            else if (y == 3) {
                startPointY -= 5;
            }
            arr[index].X = startPointX;
            arr[index].Y = startPointY;
            index++;
        }
    }
}

void isFullRound(int* index, int* diceSum, int* accum) {
    if (*index == 40) {
        *diceSum = *diceSum - *index;
        *accum = 0;
        *index = 0;
    }
}

void nextTurn(int takeATurn, int* turn, bool* isMove) {
    *turn ? gotoxy(200, 6) : gotoxy(200, 4);
    cin >> takeATurn;
    if (*turn == 1) {
        *turn = 0;
    }
    else if (*turn == 0) {
        *turn = 1;
    }
    if (takeATurn == 1) {
        *isMove = true;
    }
}