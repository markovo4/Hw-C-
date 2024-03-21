#include <iostream>

using namespace std;

void addRowAtTheEnd(int**& arr, int &rows, int columns);
void removeRowAtTheEnd(int**& arr, int& rows, int columns);
void removeColumnAtTheEnd(int**& arr, int rows, int& columns);
void AddColumnAtTheEnd(int**& arr, int rows, int& columns);

int main() {
    int rows = 5;
    int columns = 5;
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {

        arr[i] = new int[columns];

        for (int j = 0; j < columns; j++) {

            arr[i][j] = 1;
        }
    }

    addRowAtTheEnd(arr, rows, columns);
    removeRowAtTheEnd(arr, rows, columns);
    removeRowAtTheEnd(arr, rows, columns);
    removeRowAtTheEnd(arr, rows, columns);
    removeRowAtTheEnd(arr, rows, columns);
    addRowAtTheEnd(arr, rows, columns);
    addRowAtTheEnd(arr, rows, columns);
    AddColumnAtTheEnd(arr, rows, columns);
    removeColumnAtTheEnd(arr, rows, columns);
    removeColumnAtTheEnd(arr, rows, columns);
    removeColumnAtTheEnd(arr, rows, columns);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void addRowAtTheEnd(int**& arr, int &rows, int columns) {
    rows++;

    int** temp = new int* [rows];

    for (int i = 0; i < rows - 1; i++) {

        temp[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            temp[i][j] = arr[i][j];
        }

        delete[] arr[i];
    }

    temp[rows - 1] = new int[columns];

    for (int j = 0; j < columns; j++) {
        temp[rows - 1][j] = 0;
    }

    delete[] arr;
    arr = temp;
}

void removeRowAtTheEnd(int**& arr, int& rows, int columns) {
    rows--;

    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++) {

        temp[i] = new int[columns];

        for (int j = 0; j < columns; j++) {
            temp[i][j] = arr[i][j];
        }

        delete[] arr[i];
    }

    delete[] arr;

    arr = temp;
}

void AddColumnAtTheEnd(int**& arr, int rows, int& columns) {
    columns++;
    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++) {
        temp[i] = new int[columns];

        for (int j = 0; j < columns; j++) {
            temp[i][j] = arr[i][j];
        }
        delete[] arr[i];
    }

    delete[] arr;
    for (int i = 0; i < rows; i++) {
        temp[i][columns - 1] = 0;
    }
    arr = temp;
}

void removeColumnAtTheEnd(int**& arr, int rows, int& columns) {
    columns--;

    int** temp = new int* [rows];

    for (int i = 0; i < rows; i++) {
        temp[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            temp[i][j] = arr[i][j];
        }
        delete[] arr[i];
    }

    delete[] arr;

    arr = temp;
}