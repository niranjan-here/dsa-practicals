#include <iostream>
#include <cstdlib>   
#include <cstring>   

using namespace std;

struct Student {
    int id;
    char name[100];
    float cgpa;
};

int main() {
    Student* students = NULL;  
    int count = 0;             
    char choice;

    do {
        students = (Student*)realloc(students, (count + 1) * sizeof(Student));
        if (!students) {
            cout << "Memory allocation failed.\n";
            return 1;
        }

        cout << "Enter student ID: ";
        cin >> students[count].id;

        cout << "Enter student name: ";
        cin.ignore();  
        cin.getline(students[count].name, 100);

        cout << "Enter CGPA: ";
        cin >> students[count].cgpa;

        count++;

        cout << "Add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nStudent Database:\n";
    for (int i = 0; i < count; ++i) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", CGPA: " << students[i].cgpa << "\n";
    }

    free(students);

    return 0;
}
