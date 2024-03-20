#include <iostream>

using namespace std;

// Program 1
int main() {
    const int size = 100;
    char str[size];
    char symbol;
    int counter = 0;

    cout << "Please enter a sentence: ";
    cin.getline(str, size);

    cout << "Please enter a symbol you would like to find: ";
    cin >> symbol;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol) {
            cout << i << ", ";
            counter++;
        }
    }
    cout <<"\n\n";
    cout << symbol << "= " << counter;

}


// Program 2

int main() {
    const int size = 100;
    char str[size];
    int counter = 0;
    int wordCounter = 0;
    int numbersCount = 0;
    int vowelsCount = 0;
    int consonantsCount = 0;
    int otherSymbolsCount = 0;
    int punctuationSymbolsCount = 0;

    char punctuationSymbols[] = { ',', '!', '.', '?', '\0' };
    char consonants[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', '\0' };
    char vowels[] = { 'a', 'e', 'i', 'o', 'u', '\0' };
    char otherSymbols[] = { '@', '#', '$', '%', '^', '&', '*', '(', ')', '[', ']', '{', '}', '+', '=', '-', '_', '\0' };

    cout << "Please enter a sentence: ";
    cin.getline(str, size);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            numbersCount++;
        }

        if (str[i] == ' ') {
            wordCounter++;
        }

        for (int j = 0; vowels[j] != '\0'; j++) {
            if (str[i] == vowels[j]) {
                vowelsCount++;
                break;
            }
        }

        for (int j = 0; consonants[j] != '\0'; j++) {
            if (str[i] == consonants[j]) {
                consonantsCount++;
                break;
            }
        }

        for (int j = 0; otherSymbols[j] != '\0'; j++) {
            if (str[i] == otherSymbols[j]) {
                otherSymbolsCount++;
                break;
            }
        }

        for (int j = 0; punctuationSymbols[j] != '\0'; j++) {
            if (str[i] == punctuationSymbols[j]) {
                punctuationSymbolsCount++;
                break;
            }
        }
        counter++;
    }
    cout << "Word Count: " << (wordCounter) << '\n';
    cout << "Total Count: " << counter << '\n';
    cout << "Numbers Count: " << numbersCount << '\n';
    cout << "Vowels Count: " << vowelsCount << '\n';
    cout << "Consonants Count: " << consonantsCount << '\n';
    cout << "Other Symbols Count: " << otherSymbolsCount << '\n';
    cout << "Punctuation Symbols Count: " << punctuationSymbolsCount << '\n';

    return 0;
}

// Program 3
double aveWordLength(char* sentence);

int main() {
    const int size = 100;
    char sentence[size];

    cout << "Enter a sentence: ";
    cin.getline(sentence, size - 1);

    cout << "Average word length: " << aveWordLength(sentence) << endl;

    return 0;
}

double aveWordLength(char* sentence) {
    double wordCount = 0;
    double totalLength = 0;
    bool inWord = false;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if ((sentence[i]) != ' ') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
            totalLength++;
        }
        else {
            inWord = false;
        }
    }

    return (totalLength) / wordCount;
}

// Program 4
int main() {
    int size = 100;
    char* str = new char[size];

    cin.getline(str, size - 1);

    for (int i = 0; i < (strlen(str) / 2); i++) {
        if (str[i] != str[strlen(str) - i - 1]) {
            return false;
        }
        cout << "Is a palindrome." << endl;
    }
}

// Program 5
int countWordOccurrences(const char* text, const char* word) {
    int count = 0;

    while (*text != '\0') {
        if (*text == *word) {
            const char* tempText = text;
            const char* tempWord = word;

            while (*tempWord != '\0' && *tempText == *tempWord) {
                tempText++;
                tempWord++;
            }

            if (*tempWord == '\0' && *tempText == ' ') {
                count++;
            }
        }
        text++;
    }
    return count;
}

int main() {
    const int size = 100;
    char text[size];
    char word[size];

    cout << "Enter text: ";
    cin.getline(text, size);
    cout << "Enter word to count: ";
    cin >> word;

    int occurrences = countWordOccurrences(text, word);
    cout << "The entered word occurs: " << occurrences << " times in the text.";
}

// Program 6
int isThisWordIncluded(char* text, char** word, int wordCount);

int main() {
    int size = 100;
    char* text = new char[size];
    int wordlength = 20;
    int maxWordCount = 3;
    char** word = new char*[maxWordCount];

    cout << "Enter text: ";
    cin.getline(text, size);

    for (int i = 0; i < maxWordCount; i++) {
        word[i] = new char[wordlength];
    }

    for (int i = 0; i < maxWordCount; i++) {
        cout << "Enter spam text: ";
        cin.getline(word[i], wordlength);
    }

    cout << endl;

    if (isThisWordIncluded(text, *&word, maxWordCount)) {
        cout << "SPAM EMAIL";
    }
    else if (!isThisWordIncluded(text, *&word, maxWordCount)) {
        cout << "IT IS NOT A SPAM EMAIL";
    }

    for (int i = 0; i < maxWordCount; i++) {
        delete[] word[i];
    }
    delete[] word;

}

int isThisWordIncluded(char* text, char** word, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        char* currentWord = word[i];

        for (int j = 0; text[j] != '\0'; j++) {

            int k;
            for (k = 0; *(currentWord + k) != '\0' && tolower(text[j + k]) == tolower(*(currentWord + k)); k++);

            if (*(currentWord + k) == '\0' && (text[j + k] == ' ' || text[j + k] == '\0')) {
                return 1;
            }
        }
    }
    return 0;
}