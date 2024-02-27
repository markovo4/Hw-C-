#include <iostream>
#include <ctime>

using namespace std;

// Program 1
int randomStart() {
    int min = 0;
    int max = 20;
    int K = max - min + 1;
    int r = rand() % K + min;
    return r;
}
const int height = 5;
const int width = 6;

int main() {
    srand(time(0));

    int arr[height][width];
    int sum = 0;
    int mean = 0;
    int max = -10000;
    int min = 10000;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[y][x] = randomStart();
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << arr[y][x] << "\t";
            sum += arr[y][x];
        }
        cout << endl;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (arr[x][y] > max) {
                max = arr[x][y];
            } else if (arr[x][y] < min) {
                min = arr[x][y];
            }
        }
    }
    mean = sum / (sizeof(arr[height][width] / sizeof(arr[0][0])));

    cout << "Min: " << min << endl << "Max: " << max << "\n\n";
    cout << "Mean: " << mean << endl << "Sum: " << sum;
}

// Program 2
int randomStart() {
    int min = 0;
    int max = 20;
    int K = max - min + 1;
    int r = rand() % K + min;
    return r;
}

const int height = 5;
const int width = 5;

int main() {
    srand(time(0));

    int arr[height][width];
    int sumMainDiag = 0;
    int sumSubDiag = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[y][x] = randomStart();
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if(x == y){
                sumMainDiag += arr[x][y];
            } else if(x + y == height - 1){
                sumSubDiag += arr[x][y];
            }
        }
    }
    cout << "Sum Main Diagonal: " << sumMainDiag << endl << "Sum Sub Diagonal: " << sumSubDiag;
}

// Program 3
int randomStart() {
    int min = -10;
    int max = 10;
    int K = max - min + 1;
    int r = rand() % K + min;
    return r;
}

const int height = 5;
const int width = 5;

int main() {
    srand(time(0));
    int arr[height][width];
    int negElements = 0;
    int posElements = 0;
    int zeroElements = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[y][x] = randomStart();
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if(arr[x][y] < 0){
                negElements++;
            } else if(arr[x][y] > 0){
                posElements++;
            } else if (arr[x][y] == 0){
                zeroElements++;
            }
        }
    }
    cout << "Positive elements: " << posElements << endl << "Negative elements: " << negElements << endl<< "Zero elements: "<< zeroElements;
}

// Program 4
int randomStart() {
    int min = 0;
    int max = 20;
    int K = max - min + 1;
    int r = rand() % K + min;
    return r;
}

const int height = 5;
const int width = 5;

int main() {
    srand(time(0));
    int arr[height][width];
    int xSums[width] = {0};
    int ySums[height] = {0};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[y][x] = randomStart();
            xSums[x] += arr[y][x];
            ySums[y] += arr[y][x];
            cout << arr[y][x] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < height; i++) {
        cout << "ySum"<< i << ": " << ySums[i] << "\n";
    }
    cout << "\n";
    for (int i = 0; i < width; i++) {
        cout << "xSum"<< i << ": " << xSums[i] << "\n";

    }
}

// Program 5

const int height = 5;
const int width = 5;

int main() {
    int arr[height][width];
    int column = 0;
    int row = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[y][x] = column + row;
            column += 10;
            cout << arr[y][x] << "\t";
        }
        column = 0;
        row++;
        cout << endl;
    }
}

// Program 6

const int HEIGHT = 6;
const int WIDTH = 6;

int main(){
    int arr[HEIGHT][WIDTH];
    int number = 0;

    for(int y = 0; y < HEIGHT; y++ ){
        number++;
        for(int x = 0; x < WIDTH; x++ ){
            arr[y][x] = number;
            cout << arr[y][x] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < HEIGHT - 1; i++) {
        if (arr[i][0] % 2 != 0) {
            swap(arr[i], arr[i + 1]);
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            cout << arr[y][x] << "\t";
        }
        cout << endl;
    }
    return 0;
}