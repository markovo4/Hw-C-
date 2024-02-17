#include <iostream>

using namespace std;

// File 2, Program 1
float calculateTime(float distance, float velocity){
    float time = distance / velocity;
    return time;
}

int main() {
    float distance;
    float velocity;

    cout << "Input distance in km and velocity in km/h";
    cout << "\ndistance = ";
    cin >> distance;
    cout << "\nvelocity = ";
    cin >> velocity;

    cout << "\nTime in hours = ";
    cout << calculateTime(distance, velocity);

    cout << "\nTime in minutes = ";
    cout << calculateTime(distance, velocity) * 60;

    cout << "\nTime in seconds = ";
    cout << calculateTime(distance, velocity) * 3600;
}

// File 2, Program 2
int wholeSum(int firstNumber, int secondNumber){
    int result = (int) firstNumber + (int) secondNumber;
    return result;
}

int main() {
    float firstNumber;
    float secondNumber;

    cin >> firstNumber;
    cin >> secondNumber;

    float fractionalSum = firstNumber + secondNumber;

    cout << fractionalSum << "\n";

    cout << wholeSum(firstNumber, secondNumber);
}

// File 2, Program 3
int uahAmount(float money) {
    return money;
}

float uahCoins(int func, float money) {
    float result = (money - (float) func) * 100;
    return result;
}

int main() {
    float money;

    cin >> money;

    cout << uahAmount(money) << " UAH\n";
    cout << (int) uahCoins(uahAmount(money), money) << " coins";
}

// File 3, Program 1
int middleDigit(int number){
    int secondDigit = (number % 100)/10;
    return secondDigit;
}

int main(){
    int firstNumber;
    int secondNumber;

    cin >> firstNumber;
    cin >> secondNumber;

    cout << middleDigit(firstNumber) + middleDigit(secondNumber);
}

// File 3, Program 2
int sumOneAndThree(int number) {
    int firstDigit = number / 1000;
    int thirdDigit = ((number % 1000) % 100) / 10;
    int result = firstDigit + thirdDigit;
    return result;
}

int diffTwoAndFour(int number) {
    int secondDigit = (number % 1000) / 100;
    int fourthDigit = ((number % 1000) % 100) % 10;
    int result = secondDigit - fourthDigit;
    return result;
}

int main() {
    int number;

    cin >> number;
    cout << "Sum one and three = ";
    cout << sumOneAndThree(number);

    cout << "\nDifference between two and four = ";
    cout << diffTwoAndFour(number);
}

// File 3, Program 3
int twoDigit(int number) {
    int firstDigit = number / 100;
    int thirdDigit = (number % 100) % 10;
    int result = (firstDigit * 10) + (thirdDigit);
    return result;
}

int main() {
    int number;

    cin >> number;
    cout << "Two digits = ";
    cout << twoDigit(number);
}

// File 4, Program 1
string checkEven(int num){
    string result;
        if(num % 2 == 0){
            result = "Even";
        }
        else{
            result = "Odd";
        }
    return result;
}

int main(){
    int number;

    cin >> number;

    cout << checkEven(number);

}

// File 4, Program 2
string customMin(int firstNum, int secondNum, int thirdNum){
    string result;
    if(firstNum < secondNum){
        if(firstNum < thirdNum){
            result = "First number is the min.";
        }
    }

    else if(thirdNum < firstNum) {
        if (thirdNum < secondNum) {
            result = "Third number is the min.";
        }
    }

    if(firstNum > secondNum){
        if(thirdNum > secondNum){
            result = "Second number is the min.";
        }
    }

    return result;
}

//int main(){
    int numberOne;
    int numberTwo;
    int numberThree;

    cin >> numberOne;
    cin >> numberTwo;
    cin >> numberThree;

    cout << customMin(numberOne, numberTwo, numberThree);
}

// File 4, Program 3
string customMin(int num) {
    string result;
    if (num < 0) {
        result = "Negative number";
    } else if (num > 0) {
        result = "Positive number";
    } else {
        result = "Equals zero";
    }
    return result;
}

int main() {
    int number;

    cin >> number;
    cout << customMin(number);
}

// File 5, Program 2
string isDecimalNum(float num){
    string result;
    if(num != (int) num){
        result = "Has decimals";
    }
    else{
        result = "It is an integer";
    }
    return result;
}

int main(){
    float number;

    cin >> number;
    cout << isDecimalNum(number);
}

// File 5, Program 3
string dayOfTheWeek(int num) {
    switch (num) {
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 7:
            return "Sunday";
        default:
            return "Error";
    }
}

string dayOfTheWeekIf(int num) {
    if (num == 1) {
        return "Monday";
    } else if (num == 2) {
        return "Tuesday";
    } else if (num == 3) {
        return "Wednesday";
    } else if (num == 4) {
        return "Thursday";
    } else if (num == 5) {
        return "Friday";
    } else if (num == 6) {
        return "Saturday";
    } else if (num == 7) {
        return "Sunday";
    } else {
        return "Error";
    }
}

int main() {
    int number;

    cin >> number;
    cout << dayOfTheWeekIf(number) << "\n";
    cout << dayOfTheWeek(number);
}

// File 5, Program 11
string weather(int num) {
    string result;
    if (num < 0) {
        result = "Today is freezing. \nTomorrow is "
                 "freezing with wind speed of "
                 "99999999099999999999km/h "
                 "Precipitations: meteorite rain. Black Sea temperature will be -99990999999999999999 degrees celsius.";
    } else if (num > 0 && num <= 10) {
        result = "Today is cold. \nTomorrow is "
                 "cold with wind speed of "
                 "99999999099999999999km/h "
                 "Precipitations: planet collapse. Black Sea temperature will be 15 million degrees celsius.";
    } else if (num >= 11 && num <= 18) {
        result = "Today is warm. \nTomorrow is "
                 "warm with wind speed of "
                 "0km/h "
                 "Precipitations: none. Black Sea temperature will be 10 degrees celsius.";
    } else if (num > 19) {
        result = "Today is Hot. \nTomorrow is "
                 "Hot with wind speed of "
                 "900km/h "
                 "Precipitations: none. Black Sea will be evaporated.";
    }
    return result;
}

int main() {
    int temperature;

    cin >> temperature;
    cout << weather(temperature);
}



