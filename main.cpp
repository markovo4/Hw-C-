#include <iostream>

using namespace std;


// Program 1
struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

bool isInsideRect(const Point& point, const Rectangle& rect);

int main() {
    Rectangle rect;
    rect.topLeft = { 1, 1 };
    rect.bottomRight = { 5, 5 };

    Point pointOne = { 2, 2 };
    Point pointTwo = { 0, 0 };

    string result;
    result = isInsideRect(pointOne, rect) ? "Point is inside the rectangle." : "Point is inside the rectangle.";
    cout << result << "\n\n\n\n";

    result = isInsideRect(pointTwo, rect) ? "Point is inside the rectangle." : "Point is inside the rectangle.";
    cout << result << "\n\n\n\n";
}

bool isInsideRect(const Point &point, const Rectangle &rect) {
    return (point.x >= rect.topLeft.x && point.x <= rect.bottomRight.x && point.y <= rect.topLeft.y && point.y >= rect.bottomRight.y);
}


// Program 3

struct Student {
    char* name;
    char* lastName;
    char* date;
    char* address;
    char* phoneNumber;
    int* tests;
    int* projects;
    int* exams;
};

void createStudent(Student& student, const char* name, const char* lastName, const char* date, const char* address, const char* phoneNumber);
void freeStudentMemory(Student& student);
void printStudentInfo(const Student& student);

int main() {
    Student student;
    createStudent(student, "Jhon", "Matkovskiy", "12/08/1989", "Somewhere St.", "+1 05-563-5673");

    printStudentInfo(student);

    freeStudentMemory(student);

}

void createStudent(Student& student, const char* name, const char* lastName, const char* date, const char* address, const char* phoneNumber) {

    student.name = new char[strlen(name) + 1];
    strcpy_s(student.name, strlen(name) + 1, name);

    student.lastName = new char[strlen(lastName) + 1];
    strcpy_s(student.lastName, strlen(lastName) + 1, lastName);

    student.date = new char[strlen(date) + 1];
    strcpy_s(student.date, strlen(date) + 1, date);

    student.address = new char[strlen(address) + 1];
    strcpy_s(student.address, strlen(address) + 1, address);

    student.phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy_s(student.phoneNumber, strlen(phoneNumber) + 1, phoneNumber);

    student.tests = new int[5] {100, 80, 20, 46, 90};

    student.projects = new int[5] {98, 99, 97, 90, 96};

    student.exams = new int[5] {70, 80, 65, 46, 78};
}

void freeStudentMemory(Student& student) {
    delete[] student.name;
    delete[] student.lastName;
    delete[] student.date;
    delete[] student.address;
    delete[] student.phoneNumber;
    delete[] student.tests;
    delete[] student.projects;
    delete[] student.exams;
}

void printStudentInfo(const Student& student) {
    cout << student.name << endl << endl;
    cout << student.lastName << endl << endl;
    cout << student.date << endl << endl;
    cout << student.address << endl << endl;
    cout << student.phoneNumber << endl << endl;
    cout << "TESTS: ";
    for (int i = 0; i < 5; i++) {
        if (i != 4) {
            cout << student.tests[i] << "%, ";
        }
        else if (i == 4) {
            cout << student.tests[i] << "% ";
        }
    }
    cout << endl << endl;
    cout << "PROJECTS: ";
    for (int i = 0; i < 5; i++) {
        if (i != 4) {
            cout << student.projects[i] << "%, ";
        }
        else if(i == 4){
            cout << student.projects[i] << "% ";
        }
    }
    cout << endl << endl;
    cout << "EXAMS: ";
    for (int i = 0; i < 5; i++) {
        if (i != 4) {
            cout << student.exams[i] << "%, ";
        }
        else if (i == 4) {
            cout << student.exams[i] << "% ";
        }

    }
    cout << endl << endl;
}
