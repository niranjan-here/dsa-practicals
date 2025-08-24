#include <bits/stdc++.h>
using namespace std;

struct StudentDetails {
    int id;
    char name[50];
    int cgpa;
};

/*
    Insertion Sort Explanation:
    Insertion sort builds the final sorted array one element at a time.
    It takes each new element and inserts it into its correct position 
    among the already sorted elements.
    
    Example:
    [5, 3, 8, 4]
    Step 1: [5]
    Step 2: Insert 3 → [3, 5]
    Step 3: Insert 8 → [3, 5, 8]
    Step 4: Insert 4 → [3, 4, 5, 8]
    Result → [3, 4, 5, 8]
*/

void insertionSortByName(StudentDetails student[], int size) {
    for (int i = 1; i < size; i++) {
        StudentDetails key = student[i];
        int j = i - 1;
        while (j >= 0 && strcmp(student[j].name, key.name) > 0) {
            student[j + 1] = student[j];
            j--;
        }
        student[j + 1] = key;
    }
}

void insertionSortByCGPA(StudentDetails student[], int size, bool ascending) {
    for (int i = 1; i < size; i++) {
        StudentDetails key = student[i];
        int j = i - 1;
        if (ascending) {
            while (j >= 0 && student[j].cgpa > key.cgpa) {
                student[j + 1] = student[j];
                j--;
            }
        } else {
            while (j >= 0 && student[j].cgpa < key.cgpa) {
                student[j + 1] = student[j];
                j--;
            }
        }
        student[j + 1] = key;
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
    insertionSortByName(student, studentNumber);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Ascending):\n";
    insertionSortByCGPA(student, studentNumber, true);
    displayStudents(student, studentNumber);

    cout << "\nSorting Students by CGPA (Descending):\n";
    insertionSortByCGPA(student, studentNumber, false);
    displayStudents(student, studentNumber);

    delete[] student;
    return 0;
}
