#include <bits/stdc++.h>
using namespace std;

struct StudentDetails {
	int id;
	char name[5];
	int cgpa;
};

void linearSearch(StudentDetails student[], int size, int target){
	for (int i = 0; i < size; i++){
		if (student[i].id == target){
			cout << "ID: " << student[i].id << endl;
			cout << "Name: " << student[i].name << endl;
			cout << "CGPA: " << student[i].cgpa << endl;
			return;
		}
	}
	
	cout << "Student details not found";
}

int main(){
	int studentNumber;
	cout << "Enter number of students to add: ";
	cin >> studentNumber;
	
	StudentDetails* student = new StudentDetails[studentNumber];
	
	for (int i = 0; i < studentNumber; i++){
		cout << "\nEnter the details for student " << i+1 << endl;
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
	
	delete[] student;
	
	return 0;
	
	
	
}
