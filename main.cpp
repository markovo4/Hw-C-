#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// Program 1
int main() {

    unsigned int numbers[5] = {1, 2, 3, 4, 5};
    int arrLength = sizeof(numbers)/sizeof(numbers[0]);
    for (int i = 0; i < arrLength; i++){
        cout << numbers[i] << endl;
    }
    cout << endl;

    for (int i = arrLength; i >= 0; i--){
        cout << numbers[i] << endl;
    }
}

// Program 2
int main(){
    int randNumbers[20];
    for(int i = 0; i < 20; i++){
        randNumbers[i] = rand() % 100;
        if(randNumbers[i] % 2){
            cout << randNumbers[i] << " ";
        }
    }
}

// Program 3
int main() {
    srand(time(0));

    int randNumRange[10];
    int min = -20;
    int max = 20;
    int K = max - min + 1;

    for (int i = 0; i <= 10; i++) {
        int r = rand() % K + min;
        randNumRange[i] = r;
    }

    int arrLength = sizeof(randNumRange) / sizeof(randNumRange[0]);
    int sum = 0;
    int count = 0;

    for (int i = 0; i < arrLength; i++) {
        if (randNumRange[i] >= 0) {
            sum += randNumRange[i];
            count++;
        }
    }

    cout << "Mean of positive elements of an array: " << sum / count << endl;
    cout << "Sum of positive elements of an array: " << sum << endl;
    cout << "Length of an array: " << arrLength << endl;
    return 0;
}

// Program 4
bool isPunctuation(char c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

int main(){
    char charArr[100];

    char character;
    int num = 0;

    int letter = 0;
    int number = 0;
    int punctSign = 0;

    srand(time(0));

    int min = 0;
    int max = 100;
    int K = max - min + 1;

    for(int i = 0; i <= 100; i++){
        int r = rand() % K + min;
        num = r;
        character = static_cast<char>(num);
        charArr[i] = character;
        cout << charArr[i] << endl;
    }

    for(int i = 0; i <= 100; i++){
        if(isdigit(charArr[i])){
            number++;
        } else if(isalpha(charArr[i])){
            letter++;
        } else if(isPunctuation(charArr[i])){
            punctSign++;
        }
    }

    cout << "Amount of numbers: " << number <<endl;
    cout << "Amount of letters: " << letter <<endl;
    cout << "Amount of punctuation signs: " << punctSign <<endl;

    return 0;
}

// Program 5
int main(){
    int randNumRange[100];
    int userNum = 0;

    cin >> userNum;

    srand(time(0));
    int min = 0;
    int max = 100;
    int K = max - min + 1;

    int count = 0;
    for(int i = 0; i <= 100; i++){
        int r = rand() % K + min;
        randNumRange[i] = r;
        if(randNumRange[i] == userNum){
            count++;
        }
    }
    cout << "Number of repetitions of a user number in a random array: " << count;

    return 0;
}

// Program 6
int main(){
    int randNumarr[20];

    srand(time(0));
    int min = -10;
    int max = 30;
    int K = max - min + 1;

    bool isNegative = false;

    int count = 0;
    for(int i = 0; i <= 20; i++){
        int r = rand() % K + min;
        randNumarr[i] = r;
        if(!isNegative && randNumarr[i] < 0){
            isNegative = true;
        } else if(isNegative){
            count += randNumarr[i];
        }
    }
    cout << "Sum of elements of an array after the first negative element: " << count << endl;
}


