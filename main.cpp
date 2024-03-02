#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cmath>

using namespace std;

// Program 1
int cube(int x){
    int cube = x*x*x;
    return cube;
}
int main() {
    int length;
    cin >> length;
    cout << cube(length);
    return 0;
}

// Program  2
int isPrime(int x) {
    string isPrime = "Not prime";
    if (x % 2 == 0 || x % 3 == 0 || x % 7 == 0 || x % 5 == 0 || x % 10 == 0){
        isPrime = "Not Prime\n";
        cout << isPrime;
    } else{
        isPrime = "Prime number\n";
        cout << isPrime;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << isPrime(n);
    return 0;
}

// Program  3
int sum(int numberOne, int numberTwo){
    int sum = 0;
    numberOne++;
    for(int i = numberOne; i < numberTwo; i++){
        sum += i;
    }
    return sum;
}
int main(){
    int number1 = 0;
    int number2 = 0;

    cin >> number1;
    cin >> number2;

    cout << sum(number1, number2);
}

// Program  4
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

long int dateConversion(int day, int month, int year) {
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int days = year * 365 + day;

    for (int i = 1; i < month; ++i) {
        days += daysInMonth[i];
        if (i == 2 && isLeapYear(year)) {
            days++;
        }
    }
    int numLeapYears = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    days += numLeapYears;

    return days;
}

int daysDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    long int days1 = dateConversion(day1, month1, year1);
    long int days2 = dateConversion(day2, month2, year2);
    return days2 - days1;
}

int main() {
    int day1, month1, year1, day2, month2, year2;
    cout << "Please input your first date in the format of (dd mm yyyy): ";
    cin >> day1 >> month1 >> year1;
    cout << "Please input your second date in the format of (dd mm yyyy): ";
    cin >> day2 >> month2 >> year2;

    int dayDiff = daysDifference(day1, month1, year1, day2, month2, year2);
    cout << "Difference in days: " << dayDiff << endl;

    return 0;
}

// Program  5
int mean(int arr[]){
    int sum = 0;
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int arrMean = 0;

    for(int i = 0; i < arrLength; i++){
        sum += arr[i];
    }
    arrMean = sum/arrLength;
    return arrMean;
}

int main(){
    int array[] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 10};

    cout << mean(array);
}

// Program  6
int card(string color, int width, int height, char symbol) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (color == "red") {
                if (y == 0 || x == 0 || x == width - 1 || y == height - 1) {
                    SetConsoleTextAttribute(h, 10);
                    cout << '#';
                } else {
                    SetConsoleTextAttribute(h, 12);
                    cout << symbol;
                }
            } else if (color == "blue") {
                if (y == 0 || x == 0 || x == width - 1 || y == height - 1) {
                    SetConsoleTextAttribute(h, 10);
                    cout << '#';
                } else {
                    SetConsoleTextAttribute(h, 11);
                    cout << symbol;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    string color = "red";
    int width = 10;
    int height = 5;
    char symbol = '@';

    cout << card("red", 10, 10, '@');
}

// Program 7
int dice(int color, int num){
    HANDLE h2 = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (num) {
        case 1:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "#       #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "#   #   #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "#       #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
        case 2:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "# #     #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "#       #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "#     # #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
        case 3:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "# #     #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "#   #   #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "#     # #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
        case 4:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "#       #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
        case 5:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "#   #   #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
        case 6:
            SetConsoleCursorPosition(h2, {15, 2});
            SetConsoleTextAttribute(h2, color);
            cout << "#########";
            SetConsoleCursorPosition(h2, {15, 3});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 4});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 5});
            cout << "# #   # #";
            SetConsoleCursorPosition(h2, {15, 6});
            cout << "#########";
            break;
    }
}
int main(){
    dice(14, 1);
}

// Program 8

double roundToDecimal(double number, int roundToDecimalPoints) {
    double factor = pow(10, roundToDecimalPoints);
    return round(number * factor) / factor;
}

int main(){
    double num = 0;
    int decimalPoints = 0;

    cin >> num;
    cin >> decimalPoints;
    cout << roundToDecimal(num, decimalPoints);
}

