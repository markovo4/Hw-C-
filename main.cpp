#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

// File 1 Program 1
int evenNumbers(){
    for (int i = 0; i <= 100; i++){
        if(i % 2 == 0){
            cout << i << ' ';
        }
    }
    return 0;
}
int main() {
    evenNumbers();
    return 0;
}

// File 1 Program 4
int factorial(int number){
    if(number == 0){
        return 1;
    } else{
        return number * factorial(number - 1);
    }
}

int main(){
    int num;

    cin >> num;
    cout << factorial(num);
}

// File 1 Program 7
int wholeDiv(int num){
    for(int i = 1; i < num; i++){
        if(num % i == 0){
            cout << i << ' ';
        }
    }
    return 0;
}
int main(){
    int number;

    cin >> number;
    cout << wholeDiv(number);
}

// File 2 Program 15
int main() {
    int repeat;
    cin >> repeat;
    string marker = "##############";
    for (int y = 0; y <= repeat; y++) {
        for (int x = 0; x <= repeat; x++) {
            if (x == 0) {
                cout << '\n';
            }
            else if (x == y) {
                cout << marker;
            }
            else {
                cout << ' ';
            }
        }
    }
    return 0;
}

// File 2 Program 2
int main() {
    for (int i = 1; i <= 10; i++) {

        for (int j = 1; j <= 10; j++) {

            cout << setw(4) << i * j << "   ";

            if (i == 1) {
                cout << "";
            }
        }
        cout << endl;
    }
}

// File 2 Program 4
int main(){
    int m;
    int n;

    cin >> m;
    cin >> n;
    for(int y = 0; y <= m; y++){
        for(int x = 0; x <= n; x++){
            if(x == 0){
                cout << "\n" << "#";
            } else if(y == 0 || x == n || y == m){
                cout << "#";
            } else{
                cout << ".";
            }
        }
    }
    return 0;
}




















































































//int randFunc() {
//    static bool initialized = false;
//    if (!initialized) {
//        srand(time(0));
//        initialized = true;
//    }
//    int min = -100;
//    int max = 100;
//    int K = max - min + 1;
//    int r = rand() % K + min;
//    return r;
//}
//
//int arrRandNum(int array[], int size) {
//    for (int i = 0; i < size; i++) {
//        array[i] = randFunc();
//    }
//}
////
////float evenNum(int func){
////    float sum;
////    for(int i = 0; i <= 100; i++){
////        if (func % 2 == 0){
////            sum++;
////        }
////    }
////    return sum;
////}
////
////float oddNum(int func){
////    float sum;
////    for(int i = 0; i <= 100; i++){
////        if (func % 2 != 0){
////            sum++;
////        }
////    }
////    return sum;
////}
////
////float positiveNum(float func){
////    float sum;
////    for(int i = 0; i <= 100; i++){
////        if (func > 0){
////            sum++;
////        }
////    }
////    return sum;
////}
////
////float negativeNum(float func){
////    float sum;
////    for(int i = 0; i <= 100; i++){
////        if (func < 0){
////            sum++;
////        }
////    }
////    return sum;
////}
////
////float zeroNum(float func){
////    float sum;
////    for(int i = 0; i <= 100; i++){
////        if (func == 0){
////            sum++;
////        }
////    }
////    return sum;
////}
//
//int main() {
//    int arr[100];
//    arrRandNum(arr, 100);
//    for (int i = 0; i < 100; i++) {
//        cout << arr[i] << ' ';
//    }
//}

