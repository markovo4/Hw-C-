#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int iterationSum = 0;
    int switchSum = 0;

    srand(time(0));
    rand();

    const int size = 10;
    int ar[size];

    // before sorting
    for (int i = 0; i < size; i++)
    {
        ar[i] = rand() % 1000;
        cout << ar[i] << "\t";
    }

    ///////////////////////////////////////////////

//     bubble sorting
    for (int pr = 0; pr < size; pr++){
        iterationSum++;
        for (int k = size - 1; k > 0; k--){
            iterationSum++;
            if (ar[k - 1] > ar[k]){
                switchSum++;
                int temp = ar[k];
                ar[k] = ar[k - 1];
                ar[k - 1] = temp;
            }
        }
    }

    /////////////////////////////////////////////////

    cout << "\n\n";
    // after sorting
    for (int current : ar)
        cout << current << "\t";

    cout << "\n\n";
    cout << "Sum of all iterations: " << iterationSum << endl;
    cout << "Sum of all swaps: " << switchSum << endl;




    // optimized bubble sorting
    int swapped = 0;
    for (int i = 0; i < size - 1; i++){
        iterationSum++;
        for (int j = 0; j < size - i - 1; j++) {
//            iterationSum++;
            if (ar[j] > ar[j + 1]) {
                switchSum++;
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }


    cout << "\n\n";
    // after sorting
    for (int current : ar)
        cout << current << "\t";

    cout << "\n\n";
    cout << "Sum of all iterations: " << iterationSum << endl;
    cout << "Sum of all swaps: " << switchSum << endl;
}
