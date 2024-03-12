#include <iostream>
#include <Windows.h>
using namespace std;

void pow(double* X, double* Y);

int main() {
    double A;
    double B;
    pow(3, 3);
    cin >> A;
    cin >> B;
    pow(&A, &B);
    cout << "A: " << A;
}

void pow(double* X, double* Y) {
    double result = 1.0;
    for (int i = 0; i < *Y; i++) {
        result *= *X;
    }
    *X = result;
}