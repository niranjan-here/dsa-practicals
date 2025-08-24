#include <bits/stdc++.h>
using namespace std;

struct StudentDetails {
    int id;
    char name[50];
    int cgpa;
};

/*
    Selection Sort Explanation:
    Selection sort repeatedly finds the minimum (or maximum) element from the unsorted part
    and puts it at the beginning. 
    
    Example:
    Array: [5, 3, 8, 4]
    Pass 1: Smallest is 3 → Swap with 5 → [3, 5, 8, 4]
    Pass 2: Smallest is 4 → Swap with 5 → [3, 4, 8, 5]
    Pass 3: Smallest is 5 → Swap with 8 → [3, 4, 5, 8]
    Sorted Result → [3, 4, 5, 8]
*/

void selectionSortByName(StudentDetails student[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(student[j].name, student[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        swap(student[i], student[minIndex]);
    }
}

void selectionSortByCGPA(StudentDetails student[], int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        int index = i;
        for (int j = i + 1; j < size; j++) {
            if (ascending) {
                if (student[j].cgpa < student[index].cgpa) {
                    index = j;
                }
            } else {
                if (student[j].cgpa > student[index].cgpa) {
                    index = j;
                }
            }
        }
        swap(student[i], student[index]);
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
    selectionSortByName(student, studentNumber);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Ascending):\n";
    selectionSortByCGPA(student, studentNumber, true);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Descending):\n";
    selectionSortByCGPA(student, studentNumber, false);
    displayStudents(student, studentNumber);

    delete[] student;
    return 0;
}
