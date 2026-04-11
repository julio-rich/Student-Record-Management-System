#include "system.h"
#include <iostream>
#include <algorithm>
using namespace std;


// FUNCTION ADD STUDENTS
void System::addStudent(){
    Student NewStd;
    NewStd.inputStudent();

    int id = NewStd.getId();

    if (isDuplicate(id)){
        cout << "A student with this ID already exists. Please try again." << endl;
        return;
    }

    studentList.push_back(NewStd);
    cout << "Student added successfully!" << endl;
}

// FUNCTION CHECK DUPLICATE ID

bool System::isDuplicate(int id) const{
    for (const auto& student : studentList) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
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
    cin >> choice;
    if(choice == 1){
        cout << "Enter the ID of the student to search: ";
        int id;
        cin >> id;
        for (const auto& student : studentList) {
            if (student.getId() == id) {
                student.displayStudent();
                return;
            }
        }
    }else if(choice == 2){
        cin.ignore();
        cout << "Enter the name of the student to search: ";
        string name;       
        getline(cin, name);
        for (const auto& student : studentList) {
            if (student.getName() == name) {
                student.displayStudent();
                return; 
            }
        }
    }
    cout <<"Student not found \n";
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
            cout << "2. Update Age" << endl;
            cout << "3. Update Courses and Scores" << endl;
            cout << "4. Update all information" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            cin.ignore(); 

            if (choice == 1){
                cout << "Enter the updated name: ";
                student.updateName();
            } else if (choice == 2){
                cout << "Enter the updated age: ";
                student.updateAge();
            } else if (choice == 3){
                cout << "Enter the updated courses and scores: ";
                student.updateCoursesAndScores();
            } else if (choice == 4){
                student.updateAllInformation();
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
    int id;
    cin >> id;
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->getId() == id) {
            studentList.erase(it);
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

void System::showStatistics()const {
    if (studentList.empty()){
        cout << "No students to calculate statistics." << endl;
        return;
    }
    const Student* highest = &studentList[0];
    const Student* lowest = &studentList[0];
    float totalAverage = 0;

    for(const auto& student : studentList){
        if (student.getAverage() > highest->getAverage()){
            highest = &student;
        }
        if (student.getAverage() < lowest->getAverage()){
            lowest = &student;
        }
        totalAverage += student.getAverage();   

    }

    float classAverage = totalAverage / studentList.size(); 

    cout << "\n-----STATISTICS DASHBOARD-----\n" << endl;
    
    cout << "\nTop Student: \n";
    highest->displayStudent();

    cout << "\nLowest Student:\n";
    lowest->displayStudent();

    cout << "\nClass Average: " << classAverage <<endl;

}

vector<Student>& System::getStudentList(){
    return studentList;
}