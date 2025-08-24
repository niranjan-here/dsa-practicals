#include <bits/stdc++.h>
using namespace std;

struct StudentDetails {
    int id;
    char name[50];
    int cgpa;
};

/*
    Bubble Sort Explanation:
    Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.
    After each pass, the largest (or smallest) element "bubbles up" to its correct position.
    
    Example:
    Array: [5, 3, 8, 4]
    Pass 1: Compare (5,3) → swap → [3, 5, 8, 4]
            Compare (5,8) → no swap
            Compare (8,4) → swap → [3, 5, 4, 8]
    Pass 2: Compare (3,5) → no swap
            Compare (5,4) → swap → [3, 4, 5, 8]
            Compare (5,8) → no swap
    Result → [3, 4, 5, 8]
*/

void bubbleSortByName(StudentDetails student[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(student[j].name, student[j + 1].name) > 0) {
                swap(student[j], student[j + 1]);
            }
        }
    }
}

void bubbleSortByCGPA(StudentDetails student[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ascending) {
                if (student[j].cgpa > student[j + 1].cgpa) {
                    swap(student[j], student[j + 1]);
                }
            } else {
                if (student[j].cgpa < student[j + 1].cgpa) {
                    swap(student[j], student[j + 1]);
                }
            }
        }
    }
}

void linearSearch(StudentDetails student[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (student[i].id == target) {
            cout << "ID: " << student[i].id << endl;
            cout << "Name: " << student[i].name << endl;
            cout << "CGPA: " << student[i].cgpa << endl;
            return;
        }
    }
    cout << "Student details not found" << endl;
}

void displayStudents(StudentDetails student[], int size) {
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << student[i].id
             << ", Name: " << student[i].name
             << ", CGPA: " << student[i].cgpa << endl;
    }
}

int main() {
    int studentNumber;
    cout << "Enter number of students to add: ";
    cin >> studentNumber;

    StudentDetails* student = new StudentDetails[studentNumber];

    for (int i = 0; i < studentNumber; i++) {
        cout << "\nEnter the details for student " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> student[i].id;
        cout << "Enter Name: ";
        cin >> student[i].name;
        cout << "Enter CGPA: ";
        cin >> student[i].cgpa;
    }

    int target;
    cout << "\nEnter the student ID to search: ";
    cin >> target;
    linearSearch(student, studentNumber, target);

    // Sorting Options
    cout << "\nSorting Students by Name (Alphabetical):\n";
    bubbleSortByName(student, studentNumber);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Ascending):\n";
    bubbleSortByCGPA(student, studentNumber, true);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Descending):\n";
    bubbleSortByCGPA(student, studentNumber, false);
    displayStudents(student, studentNumber);

    delete[] student;
    return 0;
}
