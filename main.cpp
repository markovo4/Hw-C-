#include <iostream>

using namespace std;

// Program 1
void outputFunc(int, int);

int main() {
    int number = 0;
    int helper = 1;
    cin >> number;
    outputFunc(number, helper);
}

void outputFunc(int n, int helper){
    if(helper != n + 1){
        cout << helper << " ";
        ++helper;
        outputFunc(n, helper);
    }
}

// Program 2
void outputFunc2(int, int);

int main() {
    int number = 0;
    int helper = 0;
    cin >> number;
    cin >> helper;
    outputFunc2(number, helper);
}

void outputFunc2(int a, int b) {
    if (a == b) {
        cout << a << " ";
        return;
    }

    if (a > b) {
        cout << b << " ";
        outputFunc2(a, b + 1);
    } else {
        cout << b << " ";
        outputFunc2(a, b - 1);
    }
}

// Program 3
string isSquareRootOfTwo(int);

int main(){
    int number = 0;

    cin >> number;
    cout << isSquareRootOfTwo(number);
}

string isSquareRootOfTwo(int n){
    if(n == 2){
        return "Yes";
    } else if(n < 2){
        return "No";
    } else{
        return isSquareRootOfTwo(n/2);
    }
}

// Program 4
int sumOfDigits(int);

int main(){

    int number;

    cin >> number;
    cout << sumOfDigits(number);
}

int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

// Program 5
void sumOfDigits(int);

int main(){
    int number;

    cin >> number;
    sumOfDigits(number);
}

void sumOfDigits(int n) {
    if (n > 10) {
        cout << (n % 10) << " ";
        sumOfDigits(n / 10);
    } else if(n < 10){
        cout << n;
    }
}

// Program 6
void sumOfDigits(int);

int main(){
    int number;
    cin >> number;
    sumOfDigits(number);
}

void sumOfDigits(int n) {
    if (n < 10) {
        cout << n << " ";
    } else {
        sumOfDigits(n / 10);
        cout << n % 10 << " ";
    }
}

// Program 7
int sumOfDigits(int, int);

int main(){
    int number;
    int coefficient;
    cin >> number;
    cin >> coefficient;
    cout << sumOfDigits(number, coefficient);
}

int sumOfDigits(int n, int coefficient) {
    if (n > 10) {
        return (n % 10)*coefficient + sumOfDigits(n / 10, coefficient / 10);
    } else if(n < 10){
        return (n % 10)*coefficient;
    }
    return 0;
}

// Program 8
bool isPalindrome(string, int, int);
bool isPalindrome(string);

int main() {
    string word;
    cin >> word;

    if (isPalindrome(word)) {
        cout <<"Palindrome" << "\n";
    } else {
        cout << "Not a Palindrome" << "\n";
    }
    return 0;
}

bool isPalindrome(string word, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (word[start] == word[end]) {
        return isPalindrome(word, start + 1, end - 1);
    } else {
        return false;
    }
}

bool isPalindrome(string word) {
    int length = word.length();
    return isPalindrome(word, 0, length - 1);
}

// Program 10
int fib(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib(n - 1, b, a + b);
}

int main()
{
    int n = 0;
    cin >> n;
    cout << fib(n, 0, 1);
    return 0;
}

// Program 11
int powOf(int, int);

int main(){
    cout << powOf(10, 3);
}

int powOf(int number, int pow){
    if(pow == 0){
        return 1;
    }else{
        return number * powOf(number, pow -1);
    }
}

// Program 12
int sumInBetween(int, int, int);

int main(){
    cout << sumInBetween(2, 10, 0);
}

int sumInBetween(int start, int end, int sum){
    if(start != end){
        sum += start;
        start++;
        return sumInBetween(start, end, sum);
    }
    return sum + end;
}
