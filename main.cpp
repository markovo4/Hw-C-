#include <iostream>
#include <cmath>

using namespace std;

// Program 1
int main() {
    int firstNum;
    int secondNum;
    int thirdNum;
    int elementQuantity;
    int sum;
    int average;

    cout << "Please input three numbers:\n";
    cin >> firstNum;
    cin >> secondNum;
    cin >> thirdNum;

    int numbers[3] = {firstNum, secondNum, thirdNum};

    elementQuantity = sizeof(numbers)/sizeof(numbers[0]);
    sum = firstNum + secondNum + thirdNum;
    average = sum/elementQuantity;

    cout << average;
}

// Program 2
int main(){
    float a;
    float b;
    float x;

    cout << "Please input variables for a linear expression ax + b = 0:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    x = ( b * (-1) ) / a;
    cout << x;
}

// Program 3
int power(int number, int degree){
    int result = pow(number, degree);
    return result;
}

int main(){
    int number;
    int degree;

    cout << "Input number = ";
    cin >> number;
    cout << "\nInput degree = ";
    cin >> degree;
    cout << power(number,degree);
};

// Program 4
int sphereSA(int radius, float PI) {
    int result = 4 * PI * pow(radius, 2);
    return result;
}

int main() {
    const float PI = 2 * acos(0.0);
    int radius;

    cout << "Please input the radius of a sphere";
    cin >> radius;
    cout << sphereSA(radius, PI);
}

// Program 5
int uahToUsd(int uah) {
    int result = uah / 38;
    return result;
}

int uahToEur(int uah) {
    int result = uah / 40;
    return result;
}

int uahToBitcoin(int uah) {
    int result = uah / 2000000;
    return result;
}

int main() {
    int uah;

    cout << "Input amount of uah you would like to convert to usd, eur, bitcoin\n";
    cin >> uah;
    cout << "\nUAH to USD: ";
    cout << uahToUsd(uah);
    cout << "\nUAH to EUR: ";
    cout << uahToEur(uah);
    cout << "\nUAH to BITCOIN: ";
    cout << uahToBitcoin(uah);
}

// Program 6
int kmToNauticalMile(int km) {
    int result = km / 0.539957;
    return result;
}

int kmToMile(int km) {
    int result = km / 0.621371;
    return result;
}

int main() {
    int km;

    cout << "Input distance in kilometers that you would like to convert to nautical miles, miles\n";
    cin >> km;
    cout << "\nKM to Nautical Miles: ";
    cout << kmToNauticalMile(km);
    cout << "\nKM to Miles: ";
    cout << kmToMile(km);
}

// Program 7
int percentagePart(float whole, float part){
    float result = (part/whole)*100;
    return result;
}

int main(){
    float whole;
    float part;
    cout << "Input whole:\n";
    cin >> whole;
    cout << "\nInput part: ";
    cin >> part;
    cout << "\nPercentage P of your number: ";
    cout << percentagePart(whole, part);
}

// Program 8
float celciusToFarenheit(float degree) {
    float result = (degree * 9 / 5) + 32;
    return result;
}

float celciusToKelvin(float degree) {
    float result = degree + 273.15;
    return result;
}

float celciusToReaumur(float degree) {
    float result = degree * 0.8;
    return result;
}

float celciusToDelisle(float degree) {
    float result = (100 - degree) * 3 / 2;
    return result;
}

int main() {
    float degree;

    cout << "Input degrees in Celcius:\n";
    cin >> degree;
    cout << "\nCelcius to Kelvin: ";
    cout << celciusToKelvin(degree);
    cout << "\nCelcius to Reaumur: ";
    cout << celciusToReaumur(degree);
    cout << "\nCelcius to Delisle: ";
    cout << celciusToDelisle(degree);
    cout << "\nCelcius to Farenheit: ";
    cout << celciusToFarenheit(degree);
}


// Program 9
int main() {
    int a = 10;
    int b = 20;

    int c = a;
    a = b;
    b = c;

    cout << a << '\n';
    cout << b << '\n' << '\n';
    swap(a, b);
    cout << a << '\n';
    cout << b;
}

