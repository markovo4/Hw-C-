#include <iostream>

using namespace std;

// Program 1
int main() {
    int number = 5;
    int* pNumber1 = &number;
    int** pNumber2 = &pNumber1;
    int*** pNumber3 = &pNumber2;
    int**** pNumber4 = &pNumber3;
    int***** pNumber5 = &pNumber4;

    cout << &pNumber1 << endl;
    cout << &pNumber2 << endl;
    cout << &pNumber3 << endl;
    cout << &pNumber4 << endl;
    cout << &pNumber5 << endl;

    cout << endl;

    cout << &pNumber5 << endl;
    cout << &pNumber5 - 4 << endl;
    cout << &pNumber5 - 8 << endl;
    cout << &pNumber5 - 12 << endl;
    cout << &pNumber5 - 16 << endl;

}

// Program 2

void AllocateMemory(int** ar, int count);
void RandomFillArray(int* ar, int count);
void PrintArray(int* ar, int count);
void AddAtTheEnd(int** ar, int& count);
void DeleteLastElement(int** ar);

int main() {
    int count = 10;
    static int* pCount = &count;
    int* arr = nullptr;
    AllocateMemory(&arr, count);
    RandomFillArray(arr, count);
    AddAtTheEnd(&arr, count);
    DeleteLastElement(&arr);
    DeleteLastElement(&arr);
    AddAtTheEnd(&arr, count);
    AddAtTheEnd(&arr, count);
    AddAtTheEnd(&arr, count);
    PrintArray(arr, count);
    delete[] arr;
}

void AllocateMemory(int** ar, int count) {
    (*ar) = new int[count]();
    cout << "Memory allocated" << endl;
}

void RandomFillArray(int* ar, int count) {
    for (int i = 0; i < count; i++) {
        ar[i] = rand() % 10;
    }
    cout << "Memory Filled" << endl;
}

void PrintArray(int* ar, int count) {
    for (int i = 0; i < count; i++) {
        cout << ar[i] << endl;
    }
}

void AddAtTheEnd(int** ar, int& count) {
    int* temp = new int[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = (*ar)[i];
    }
    temp[count] = rand() % 10;
    count++;

    delete[] * ar;

    *ar = temp;
}


void DeleteLastElement(int** ar) {
    if (*ar != nullptr) {
        int* temp = *ar;

        int size = 0;
        while (temp[size] >= 0) {
            ++size;
        }

        if (size > 0) {
            int* pSize = &size;
            int* newArray = new int[*pSize - 1];


            for (int i = 0; i < *pSize - 1; ++i) {
                newArray[i] = temp[i];
            }

            delete[] temp;
            *ar = newArray;
        }
    }
}

