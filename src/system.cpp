#include "system.h"
#include <iostream>
#include <algorithm>
using namespace std;


// FUNCTION ADD STUDENTS
void System::addStudent(){
    Student NewStd;
    NewStd.inputStudent();

    int id = NewStd.getId();

    for(const auto& student : studentList){
        if(student.getId() == id){
            cout << "Error: Student with ID " << id << " already exists. Please enter a unique ID." << endl;
            return;
        }
    }
    studentList.push_back(NewStd);
    cout << "Student added successfully!" << endl;
}

// FUNCTION VIEW STUDENTS
void System::viewStudents()const {
    if(studentList.empty()){
        cout << "No students to display." << endl;
        return;
    }
    for (const auto& student : studentList) {
        student.displayStudent();
    }
}

//FUNCTION SEARCH STUDENTS
void System::searchStudent()const {
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
void System::updateStudent(){
    cout << "-----Updating student information-----" << endl;

    cout << "Enter the ID of the student to update: ";
    int id;
    cin >> id;

    for (int i = 0; i < studentList.size(); i++){
        if (studentList[i].getId()== id){
             Student &student = studentList[i];

            cout << "1. Update Name" << endl;
            cout << "2. Update Courses and Scores" << endl;
            cout << "3. Update both " << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            cin.ignore(); 

            if (choice == 1){
                student.upadateName();
                cout << "Name updated successfully!" << endl;
            } else if (choice == 2){
                student.updateCoursesAndScores();
                cout << "Courses and scores updated successfully!" << endl;
            } else if (choice == 3){
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
void System::deleteStudent(){
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
    cout << "Student with ID " << id << " not found." << endl;
}

// FUNCTION SORT STUDENTS
void System::sortStudents(){
    cout << "-----Sorting students-----" << endl;
    cout << "1. Sort by Name" << endl;
    cout << "2. Sort by Average Score" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice ==1){
        sort(studentList.begin(), studentList.end(),
    [](const Student& a, const Student& b){
        return a.getName() < b.getName();
    });
    } else if (choice == 2) {
        sort (studentList.begin(), studentList.end(),
    [](const Student& a, const Student& b) {
        return a.getAverage() > b.getAverage();
    });
    } else {
        cout << "Invalid choice. Returning to main menu." << endl;
        return;
    }
    
}