#include "student.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// FUNCTION ADD STUDENTS
void AddStudent(vector<Student>& studentList){
    Student NewStd;
    NewStd.inputStudent();

    int id = NewStd.getId();

    if(isDuplicate(studentList, id)){
        cout << "Error: Student with ID " << id << " already exists. Please enter a unique ID." << endl;
        return;
    }
    studentList.push_back(NewStd);
    cout << "Student added successfully!" << endl;
}

bool Student::isDuplicate(vector<Student>& studentList, int id){
    for (const auto& student : studentList) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
}

// FUNCTION VIEW STUDENTS
void Student::viewStudents(const vector<Student>& studentList){
    if(studentList.empty()){
        cout << "No students to display." << endl;
        return;
    }
    for (const auto& student : studentList) {
        student.displayStudent();
    }
}

//FUNCTION SEARCH STUDENTS
void Student::searchStudent(const vector<Student>& studentList){
    cout << "-----Searching for students-----" << endl;
    cout << "1. Search by ID: " <<endl;
    cout << "2. Search by Name; " << endl;

    int choice;
    cout << "Enter your choice : " << endl; 
    cin >> choice
    if(choice == 1){
        int id;
        cin >> id;
        for (const auto& student : studentList) {
            if (student.getId() == id) {
                student.displayStudent();
                return;
            }
        }else if(choice == 2){
        cin.ignore();
        string name;       
        cin >> name;
        for (const auto& student : studentList) {
            if (student.getName() == name) {
                student.displayStudent();
                return; 
            }
        }
    }
    cout <<"Student not found \n";
}
}

// FUNCTION UPDATE STUDENTS
void updateStudent(vector<Student>& studentList){
    cout << "-----Updating student information-----" << endl;

    cout << "Enter the ID of the student to update: ";
    int id;
    cin >> id;

    for (int i = 0; i < studentList.size(); i++){
        if (studentList[i].getId()== id){
             Student &student = studentList[i];

            cout << "1. Update Name" << endl;
            cout << "2. Update Age" << endl;
            cout << "3. Update Courses and Scores" << endl;
            cout << "4. Update All Information" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            cin.ignore(); 

            if (choice == 1){
                student.upadateName();
                cout << "Name updated successfully!" << endl;
            } else if (choice == 2){
                student.updateAge();
                cout << "Age updated successfully!" << endl;
            } else if (choice == 3){
                student.updateCoursesAndScores();
                cout << "Courses and scores updated successfully!" << endl;
            } else if (choice == 4){
                student.updateAllInformation();
                cout << "All information updated successfully!" << endl;
            }
            cout << "Student information updated successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
    
}

//FUNCTION DELETE STUDENTS
void Student::deleteStudent(vector<Student>& studentList){
    cout << "-----Deleting a student-----" << endl;
    cout << "Enter the ID of the student to delete:";
    cin >> id;
    for (int i = 0; i < studentList.size(); i++){
        if (studentList[i].getId()==id){
            studentList.erase(studentList.begin() + i);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
}

int main(){
    vector<Student> studentList;

    return 0;
}