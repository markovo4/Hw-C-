#include <iostream>
using namespace std;

int main() {
    double x = 1.15;
    double y = 10.1;
    double* ptrX = &x;
    double* ptrY = &y;
    double result = ptrY - ptrX;
    size_t distance = (&x - &y) * sizeof(double);

    cout << result << endl;
    cout << distance << endl;
}