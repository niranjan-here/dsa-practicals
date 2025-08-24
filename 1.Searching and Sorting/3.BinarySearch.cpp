#include <bits/stdc++.h>
using namespace std;

struct StudentDetails {
	int id;
	char name[50];
	float cgpa;

};

void binarySearch(StudentDetails student[], int target, int size){
	int left = 0;
	int right = size - 1;
	
	while(left <= right){
		int mid;
		mid = ((right - left) + left)/2;

		if (student[mid].id == target){
			cout << "ID: " << student[mid].id << endl;
			cout << "Name: " << student[mid].name << endl;
			cout << "CGPA: " << student[mid].cgpa << endl;
			return;
		}
		else if (student[mid].id < target){
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "Student Details Not Found" << endl;
}

int main(){
	int studentNumber;
	cout << "How many students data do you want to enter: ";
	cin >> studentNumber;
	StudentDetails* student = new StudentDetails[studentNumber];
	
	
	for(int i = 0; i < studentNumber; i++){
		cout << "\nEnter details for student " << i+1 << endl;
		
		cout << "Enter ID: ";
		cin >> student[i].id;
		cout << "Enter Name: ";
		cin.ignore();
		cin.getline(student[i].name, 50);
		cout << "Enter CGPA: ";
		cin >> student[i].cgpa;
	}
	
	int target;
	cout << "\nEnter Student ID to search: ";
	cin >> target;
	
	binarySearch(student, target, studentNumber);
	
	delete[] student;
	
	
	return 0;
}
