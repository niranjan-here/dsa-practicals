#include <iostream>
using namespace std;
struct Student {
    int id;
    char name[50];
    float cgpa;
};
int main() {
    int n;
    cout << "How many students do you want to add? ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin.ignore(); // clear newline from buffer
        cin.getline(students[i].name, 50);
        cout << "CGPA: ";
        cin >> students[i].cgpa;
    }
    // Display all student details
    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", CGPA: " << students[i].cgpa << endl;
    }
    // Free the allocated memory
    delete[] students;
    return 0;
}
