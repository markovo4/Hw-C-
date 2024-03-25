#include <iostream>
#include <Windows.h>
#include <cwchar>
#include <ctime>
#include <string>
using namespace std;

// Functions
void gotoxy(int x, int y); // Function that moves Console Cursor to the x and y coordinates passed in as arguments to the function.
void drawMap();// Function that draws out Game Play Field, where players can perform actions.
void playerField(HANDLE hconsole, int isPlayer, const int START_X, const int START_Y, const string BORDER_LINE, const int END_Y, const string SEPARATOR_LINE);// Function that draws out Player Field, where player have space to make choices.
int fontSize(int x, int y); // Function that changes Font-size and Font-style.
void initGame(HANDLE hconsole, bool* isInitiated, int* moneyPlayer, int* moneyComputer, int* arrPlayer[], int* arrComp[], string* username); // Function that initiates the game and after first initialization, displays players stats.
void drawDiceFace(HANDLE hConsole, int x, int y, int diceValue); // Function that draws at specific coordinates dice.
void drawLine(HANDLE hConsole, int x, int y, int color, string text); // Function that draws out text at a specific point that was provided.
void drawLine(HANDLE hConsole, COORD position, int color, string text); // Function that draws out text at a specific coordinate that was provided;
inline int randomDice(); // Function that returns a random number in the range of (0 , 5).
inline int randomTrurn(); // Function that defines who is the first one Player/Computer to start moving.
void displayCursor(HANDLE hconsole, bool isDisplay); // Function that Displayes/Hides console cursor.
void fillCoords(COORD arr[], bool isComputer); // Function that fills coordinates, players will move at and defines if it is a Player/Computer based on a bool variable.
void isFullRound(int* index, int* diceSum, int* accum, int* money); // Function that checks if the full round was completed.
void nextTurn(int takeATurn, int* turn, bool* isMove); // Function that checks what turn is it.
void fillPropertyCoords(int* arr, int size); // Function that fills amount of properties owned by each player.
void checkIfbought(HANDLE hconsole, int* accum, int* compProp, int* playProp, int* moneyPlay, int* propPlay, string* username, COORD propertyPoints[], int* moneyComp);
void checkIfbought(HANDLE hconsole, int* accumComp, int* propComp, int* compProp, int* playProp, COORD propertyPoints[], int* moneyComp, string* username, int* moneyPlay);
void buyProperty(HANDLE hconsole, int* accumComp, int* propComp, int* compProp, COORD propertyPoints[], int* moneyComp);
void buyProperty(HANDLE hconsole, int* accum, int* playProp, int* propPlay, int* moneyPlay, string* username, COORD propertyPoints[]);
void isYourCell(HANDLE hconsole, int* userProp, int* accumUser, int* moneyUserOne, int* moneyUserTwo, string* username, bool isComputer);
void drawStats(HANDLE hconsole, int* userProp, int* userAccum, int color, int x);
void checkStatus(HANDLE hconsole, string* username, int* accumComp, int* compProp, int* playProp, int* accum, int color, bool isComputer);
void endOfTheGame(HANDLE hconsole, int* moneyPlay, int* moneyComp, bool* isRun);


int main() {
    srand(time(0));
    system("title Monopoly");

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    string userName;

    bool isRunning = true;
    bool isMoving = true;
    bool isInitiated = false;

    int turn = randomTrurn();
    int diceTotal = 0;
    int diceTotalComp = 0;
    int accumulator = 0;
    int accumulatorComp = 0;
    int propertyPosition = 40;
    int moneyPlayer = 1500;
    int moneyComputer = 1500;
    int propertyPlayer = 0;
    int propertyComputer = 0;

    // Constants
    const int WIDTH_PLAYER_FIELD = 82;
    const int HIEGHT_PLAYER_FIELD = 55;
    const int PLAYER_COORDS = 40;
    const int START_X = 155;
    const int START_Y = 0;
    const int END_Y = 55;
    const string BORDER_LINE = "##                                      #                                       ##";
    const string SEPARATOR_LINE = "##------------------------------------------------------------------------------##";

    COORD pointsPlayer[PLAYER_COORDS];
    COORD pointsComputer[PLAYER_COORDS];
    COORD propertyPoints[PLAYER_COORDS] = {
            {4, 2}, {20, 4}, {33, 2}, {48, 4}, {62, 4}, {74, 2}, {90, 4}, {103, 4}, {117, 2}, {131, 4},  {143, 2},
            {144, 9}, {144, 14}, {144, 17}, {144, 24}, {144, 27}, {144, 32}, {144, 39}, {144, 42}, {144, 49}, {144, 52},
            {131, 54}, {117, 52}, {103, 54}, {89, 52}, {74, 52}, {62, 54}, {46, 52}, { 34, 54}, {20, 54}, {4, 52},
            {5, 49},  {5, 42}, {5, 39}, {5, 34},  {5, 27}, {5, 24},  {5, 17}, {5, 14}, {5, 9}
    };
    int* playerProperty = new int[propertyPosition];
    int* computerProperty = new int[propertyPosition];

    fillPropertyCoords(playerProperty, propertyPosition);
    fillPropertyCoords(computerProperty, propertyPosition);
    fillCoords(pointsPlayer, false);
    fillCoords(pointsComputer, true);

    initGame(h, &isInitiated, &moneyPlayer, &moneyComputer, &playerProperty, &computerProperty, &userName);
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

        playerField(h, turn, START_X, START_Y, BORDER_LINE, END_Y, SEPARATOR_LINE);
        initGame(h, &isInitiated, &moneyPlayer, &moneyComputer, &playerProperty, &computerProperty, &userName);

        if (turn == 1) {
            drawLine(h, pointsPlayer[diceTotal - 1], 10, " ");

        }
        else if (turn == 0) {
            drawLine(h, pointsComputer[diceTotalComp - 1], 12, " ");
        }

        if (isMoving) {
            if (turn == 1) {
                diceTotal += (diceOne + 1) + (diceTwo + 1);
                for (int i = accumulator; i < diceTotal; i++) {
                    isFullRound(&i, &diceTotal, &accumulator, &moneyPlayer);
                    drawLine(h, pointsPlayer[i], 10, "@");
                    Sleep(300);
                    drawLine(h, pointsPlayer[i], 10, " ");
                }
                drawLine(h, pointsPlayer[diceTotal - 1], 10, "@");

                accumulator = diceTotal;
                isMoving = false;
                checkIfbought(h, &accumulator, computerProperty, playerProperty, &moneyPlayer, &propertyPlayer, &userName, propertyPoints, &moneyComputer);
            }
            else if (turn == 0) {

                diceTotalComp += (diceOne + 1) + (diceTwo + 1);

                for (int i = accumulatorComp; i < diceTotalComp; i++) {

                    isFullRound(&i, &diceTotalComp, &accumulatorComp, &moneyComputer);
                    drawLine(h, pointsComputer[i], 12, "#");
                    Sleep(300);
                    drawLine(h, pointsComputer[i], 12, " ");
                }
                drawLine(h, pointsComputer[diceTotalComp - 1], 12, "#");
                accumulatorComp = diceTotalComp;
                isMoving = false;
                checkIfbought(h, &accumulatorComp, &propertyComputer, computerProperty, playerProperty, propertyPoints, &moneyComputer, &userName, &moneyPlayer);
            }
        }
        if (!isMoving) {
            int takeATurn = 0;
            if (turn == 0) {
                checkStatus(h, &userName, &accumulatorComp, computerProperty, playerProperty, &accumulator, 12, true);
                drawLine(h, 200, 3, 10, "TO THROW DICE: PRESS [1]");
                nextTurn(takeATurn, &turn, &isMoving);
            }
            else if (turn == 1) {
                checkStatus(h, &userName, &accumulatorComp, computerProperty, playerProperty, &accumulator, 10, false);
                drawLine(h, 200, 5, 10, "TO PASS THE TURN: PRESS [1]");
                nextTurn(takeATurn, &turn, &isMoving);
            }
        }
        endOfTheGame(h, &moneyPlayer, &moneyComputer, &isRunning);
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

void playerField(HANDLE hconsole, int isPlayer, const int START_X, const int START_Y, const string BORDER_LINE, const int END_Y, const string SEPARATOR_LINE){
    int color = isPlayer? 10: 12;

    drawLine(hconsole, START_X, START_Y, color, "##################################################################################\n");
    for (int y = START_Y + 1; y < END_Y; ++y) {
        drawLine(hconsole, START_X, y, color, (BORDER_LINE + "\n"));
        if (y == 24 || y == 40) {
            drawLine(hconsole, START_X, y, color, (SEPARATOR_LINE + "\n"));
        }
    }
    drawLine(hconsole, START_X, END_Y, color, "##################################################################################\n");
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

void initGame(HANDLE hconsole, bool* isInitiated, int* moneyPlayer, int* moneyComputer, int* arrPlayer[], int* arrComp[], string* username) {
    int game;
    if (!*isInitiated) {
        displayCursor(hconsole, false);
        SetConsoleTextAttribute(hconsole, 6);
        fontSize(15, 35);
        drawLine(hconsole, 48, 2, 14, "W E L C O M E  TO  M O N O P O L Y");
        drawLine(hconsole, 53, 4, 14, "Would you like to play?");
        drawLine(hconsole, 54, 6, 14, "PRESS  [1]-Yes [0]-No\n");
        cin >> game;
        if (game == 0) {
            system("CLS");
            drawLine(hconsole, 56, 10, 14, "You Exited the Game!\n\n\n\n\n\n");
            system("pause");
        }
        else {
            drawLine(hconsole, 51, 8, 14, "PLEASE ENTER YOUR USER_NAME: ");
            displayCursor(hconsole, true);
            drawLine(hconsole, 59, 10, 14, "__________");
            gotoxy(59, 10);
            cin >> *username;
            fontSize( 0, 17.5);
            displayCursor(hconsole, false);
            system("CLS");
            system("mode con cols=250 lines=60");
            drawMap();
        }
        *isInitiated = true;
    }
    else if (*isInitiated) {
        string computer = "COMPUTER";
        drawLine(hconsole, 197, 41, 10, (*username + " MONEY:  " + '$' + to_string(*moneyPlayer)));
        drawLine(hconsole, 197, 1, 10, *username + ":");
        drawLine(hconsole, 197, 42, 10, (*username + " PROPERTIES:  " + to_string(*arrPlayer[0])));
        drawLine(hconsole, 197, 25, 10, "STATUS:");
        drawLine(hconsole, 158, 1, 12, computer + ":");
        drawLine(hconsole, 158, 41, 12, (computer + " MONEY:  " + '$' + to_string(*moneyComputer)));
        drawLine(hconsole, 158, 42, 12, (computer + " PROPERTIES:  " + to_string(*arrComp[0])));
        drawLine(hconsole, 158, 25, 12, "STATUS:");
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

inline int randomTrurn() { return rand() % 2; }

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

void isFullRound(int* index, int* diceSum, int* accum, int* money) {
    if (*index == 40) {
        *diceSum = *diceSum - *index;
        *accum = 0;
        *index = 0;
        *money += 500;
    }
}

void nextTurn(int takeATurn, int* turn, bool* isMove) {
    *turn ? gotoxy(200, 6) : gotoxy(200, 4);
    cin >> takeATurn;
    *turn = *turn == 0 ? 1 : 0;
    if (takeATurn == 1) {
        *isMove = true;
    }
}

void fillPropertyCoords(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void checkIfbought(HANDLE hconsole, int* accum, int* compProp, int* playProp, int* moneyPlay, int* propPlay, string* username, COORD propertyPoints[], int* moneyComp) {
    const int SIZE = 22;
    int propertyBuy;
    int properts[SIZE] = { 1, 3, 4, 6, 7, 9, 11, 12, 14, 17, 19, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 39 };
    for (int i = 0; i < SIZE; i++) {
        if (*accum == properts[i]) {
            if (!compProp[*accum] && playProp[*accum] != 3 && *moneyPlay >= (200 * (playProp[*accum] + 1))) {
                drawStats(hconsole, playProp, accum, 10, 200);
                drawLine(hconsole, 197, 3, 10, "WOULD YOU LIKE TO BUY THIS PROPERTY ?\n");
                gotoxy(197, 4);
                cin >> propertyBuy;
                if (propertyBuy) {
                    buyProperty(hconsole, accum, playProp, propPlay, moneyPlay, username, propertyPoints);
                }
            }
        }
    }
    isYourCell(hconsole, compProp, accum, moneyComp, moneyPlay, username, false);
}

void checkIfbought(HANDLE hconsole, int* accumComp, int* propComp, int* compProp, int* playProp, COORD propertyPoints[], int* moneyComp, string* username, int* moneyPlay) {
    const int SIZE = 22;
    int properts[SIZE] = { 1, 3, 4, 6, 7, 9, 11, 12, 14, 17, 19, 21, 23, 26, 28, 29, 31, 33, 34, 36, 38, 39 };
    for (int i = 0; i < SIZE; i++) {
        if (*accumComp == properts[i]) {
            if (!playProp[*accumComp] && compProp[*accumComp] != 3 && *moneyComp >= (200 * (compProp[*accumComp] + 1))) {
                drawStats(hconsole, compProp, accumComp, 12, 161);
                buyProperty(hconsole, accumComp, propComp, compProp, propertyPoints, moneyComp);
            }
        }
    }
    isYourCell(hconsole, playProp, accumComp, moneyPlay, moneyComp, username, true);
}

void buyProperty(HANDLE hconsole, int* accum, int* playProp, int* propPlay, int* moneyPlay, string* username, COORD propertyPoints[]) {
    *propPlay = 0;
    (*propPlay)++;
    playProp[0] += *propPlay;
    playProp[*accum] += *propPlay;
    drawLine(hconsole, { 197, 41 }, 10, *username + " MONEY:  " + '$' + to_string(*moneyPlay) + "   - $" + to_string(200 * playProp[*accum]));
    *moneyPlay -= (200 * playProp[*accum]);

    SetConsoleCursorPosition(hconsole, propertyPoints[*accum]);
    for (int i = 0; i < playProp[*accum]; i++) {
        SetConsoleTextAttribute(hconsole, ( 10 + playProp[*accum]));
        cout << "$";
    }
}

void buyProperty(HANDLE hconsole, int* accumComp, int* propComp, int* compProp, COORD propertyPoints[], int* moneyComp) {
    string computer = "COMPUTER";
    *propComp = 0;
    (*propComp)++;
    compProp[0] += *propComp;
    compProp[*accumComp] += *propComp;
    drawLine(hconsole, { 158, 41 }, 12, computer + " MONEY:  " + '$' + to_string(*moneyComp) + "   - $" + to_string(200 * compProp[*accumComp]));
    *moneyComp -= (200 * compProp[*accumComp]);

    SetConsoleCursorPosition(hconsole, propertyPoints[*accumComp]);
    for (int i = 0; i < compProp[*accumComp]; i++) {
        SetConsoleTextAttribute(hconsole, (5 + compProp[*accumComp]));
        cout << "$";
    }
}

void isYourCell(HANDLE hconsole, int* userProp, int* accumUser, int* moneyUserOne, int* moneyUserTwo, string* username, bool isComputer) {
    string computer = "COMPUTER";
    char sign = isComputer ? '-' : '+';
    char sign2 = !isComputer ? '-' : '+';
    if (userProp[*accumUser] == 1) {
        *moneyUserOne += 100;
        *moneyUserTwo -= 100;
        drawLine(hconsole, 158, 41, 12, computer + " MONEY:  " + '$' + to_string(*moneyUserOne) + "   " + sign + " $100");
        drawLine(hconsole, 197, 41, 10, *username + " MONEY:  " + '$' + to_string(*moneyUserTwo) + "   " + sign2 + " $100");

    }
    else if (userProp[*accumUser] == 2) {
        *moneyUserOne += 150;
        *moneyUserTwo -= 150;
        drawLine(hconsole, 158, 41, 12, computer + " MONEY:  " + '$' + to_string(*moneyUserOne) + "   " + sign + " $150");
        drawLine(hconsole, 197, 41, 10, *username + " MONEY:  " + '$' + to_string(*moneyUserTwo) + "   " + sign2 + " $150");

    }
    else if (userProp[*accumUser] == 3) {
        *moneyUserOne += 250;
        *moneyUserTwo -= 250;
        drawLine(hconsole, 158, 41, 12, computer + " MONEY:  " + '$' + to_string(*moneyUserOne) + "   " + sign + " $250");
        drawLine(hconsole, 197, 41, 10, *username + " MONEY:  " + '$' + to_string(*moneyUserTwo) + "   " + sign2 + " $250");
    }
}

void drawStats(HANDLE hconsole, int* userProp, int* userAccum, int color, int x) {
    if (userProp[*userAccum] == 0) {
        drawLine(hconsole, x, 26, color, "PROPERTY CLASS: NONE");
        drawLine(hconsole, x, 27, color, "PRICE: $200");
        drawLine(hconsole, x, 28, color, "CAN BE BOUGHT ?: YES");
    }
    else if (userProp[*userAccum] == 1) {
        drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOUSE");
        drawLine(hconsole, x, 27, color, "PRICE: $400");
        drawLine(hconsole, x, 28, color, "RENTAL PRICE: $100");
        drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: YES");
    }
    else if (userProp[*userAccum] == 2) {
        drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOSTEL");
        drawLine(hconsole, x, 27, color, "PRICE: $600");
        drawLine(hconsole, x, 28, color, "RENTAL PRICE: $150");
        drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: YES");
    }
}

void checkStatus(HANDLE hconsole, string* username, int* accumComp, int* compProp, int* playProp, int* accum, int color, bool isComputer) {

    int x = isComputer ? 161 : 200;
    if (isComputer) {
        if (compProp[*accumComp] == 0) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: NONE");
            drawLine(hconsole, x, 27, color, "CAN BE BOUGHT ?: NO");
        }
        else if (compProp[*accumComp] == 3) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOTEL");
            drawLine(hconsole, x, 27, color, "RENTAL PRICE: $250");
            drawLine(hconsole, x, 28, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && playProp[*accum] == 1) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOUSE");
            drawLine(hconsole, x, 27, color, "OWNED BY: " + *username);
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $100");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && playProp[*accum] == 2) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOSTEL");
            drawLine(hconsole, x, 27, color, "OWNED BY: " + *username);
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $150");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && playProp[*accum] == 3) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOTEL");
            drawLine(hconsole, x, 27, color, "OWNED BY: " + *username);
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $250");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
    }
    else if (!isComputer) {
        if (playProp[*accum] == 0) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: NONE");
            drawLine(hconsole, x, 27, color, "CAN BE BOUGHT ?: NO");
        }
        else if (playProp[*accum] == 3) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOTEL");
            drawLine(hconsole, x, 27, color, "RENTAL PRICE: $250");
            drawLine(hconsole, x, 28, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && compProp[*accumComp] == 1) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOUSE");
            drawLine(hconsole, x, 27, color, "OWNED BY: COMPUTER");
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $100");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && compProp[*accumComp] == 2) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOSTEL");
            drawLine(hconsole, x, 27, color, "OWNED BY: COMPUTER");
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $150");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
        else if (accumComp == accum && compProp[*accumComp] == 3) {
            drawLine(hconsole, x, 26, color, "PROPERTY CLASS: HOTEL");
            drawLine(hconsole, x, 27, color, "OWNED BY: COMPUTER");
            drawLine(hconsole, x, 28, color, "RENTAL PRICE: $250");
            drawLine(hconsole, x, 29, color, "CAN BE BOUGHT ?: NO");
        }
    }
}

void endOfTheGame(HANDLE hconsole, int* moneyPlay, int* moneyComp, bool* isRun) {
    if (*moneyPlay < 0) {
        system("CLS");
        drawLine(hconsole, 110, 17, 12, "G A M E   O V E R !");
        gotoxy(100, 60);
        *isRun = false;
    }
    else if (*moneyComp < 0) {
        system("CLS");
        drawLine(hconsole, 110, 17, 10, "Y O U   W I N !");
        gotoxy(100, 60);
        *isRun = false;
    }
}