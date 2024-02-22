#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// Program 1
//int main() {
//
//    unsigned int numbers[5] = {1, 2, 3, 4, 5};
//    int arrLength = sizeof(numbers)/sizeof(numbers[0]);
//    for (int i = 0; i < arrLength; i++){
//        cout << numbers[i] << endl;
//    }
//    cout << endl;
//
//    for (int i = arrLength; i >= 0; i--){
//        cout << numbers[i] << endl;
//    }
//}

// Program 2
//int main(){
//    int randNumbers[20];
//    for(int i = 0; i < 20; i++){
//        randNumbers[i] = rand() % 100;
//        if(randNumbers[i] % 2){
//            cout << randNumbers[i] << " ";
//        }
//    }
//}

// Program 3
int main() {
    int randNumRange[10];
    srand(time(0));
    int min = -20;
    int max = 20;
    int K = max - min + 1;
    int r = rand() % K + min;
    for (int i = 0; i <= 10; i++) {
        randNumRange[i] = r;
        cout << randNumRange[i] << "\n";
    }

}
