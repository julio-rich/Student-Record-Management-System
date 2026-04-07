#include "student.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void AddStudent(vector<Student>& studentList, int id){
    Student NewStd;
    NewStd.inputStudent();

    if(NewStd.getId()== id){
        cout << "Student with ID " << id << " already exists. Please enter a unique ID." << endl;
        return;
    }
    studentList.push_back(NewStd);
    cout << "Student added successfully!" << endl;
}

void isDuplicate(vector<Student>& studentList, int id){
    for (const auto& student : studentList) {
        if (student.getId() == id) {
            cout << "Student with ID " << id << " already exists. Please enter a unique ID." << endl;
            return;
        }
    }
}

int main(){
    vector<Student> studentList;

    return 0;
}