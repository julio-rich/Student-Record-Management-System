#include "student.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// FUNCTION DECLARATIONS
void AddStudent(vector<Student>& studentList);
void viewStudents(const vector<Student>& studentList);
void searchStudent(const vector<Student>& studentList);
void updateStudent(vector<Student>& studentList);
void deleteStudent(vector<Student>& studentList);

int main(){
    vector<Student> studentList;
    loadFromFile(studentList);
    int choice;

    do {
        cout << "-----Student Record Management System-----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Sort Students" << endl;
        cout << "7. Exit(save)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddStudent(studentList);
                break;
            case 2:
                viewStudents(studentList);
                break;
            case 3:
                searchStudent(studentList);
                break;
            case 4:
                updateStudent(studentList);
                break;
            case 5:
                deleteStudent(studentList);
                break;
            case 6:
                saveToFile(studentList);
                break;
            case 7:
                saveToFile(studentList);
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}



// FUNCTION ADD STUDENTS
void AddStudent(vector<Student>& studentList){
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

bool Student::isDuplicate(vector<Student>& studentList, int id){
    for (const auto& student : studentList) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
}

// FUNCTION VIEW STUDENTS
void viewStudents(const vector<Student>& studentList){
    if(studentList.empty()){
        cout << "No students to display." << endl;
        return;
    }
    for (const auto& student : studentList) {
        student.displayStudent();
    }
}

//FUNCTION SEARCH STUDENTS
void searchStudent(const vector<Student>& studentList){
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
void deleteStudent(vector<Student>& studentList){
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

void saveToFile(const vector<Student>& studentList){
    osdtream file("students.txt");

    if(!file){
        cout << "Error opening file." << endl;
        return;
    }

    for(const auto& student : studentList){
        file << student.getId() << endl;
        file << student.getName() << endl;
        file << student.getAge() << endl;

        vector<string> courses = student.getCourses();
        vector<float> scores = student.getScores();

        file << courses.size() << endl;

        for(int i = 0; i < courses.size(); i++){
            file << courses[i] << endl;
            file << scores[i] << endl;
        }
    }

    file.close();
    cout << "Student data saved to file successfully!" << endl;
}

void loadFromFile(vector<Student>& studentList){
    ifstream file("Students.txt");

    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }
    
    while(true) {
        Student student;
        int id, age, numCourses;

        if (!(file >> id)) break;
        file.ignore(); // To ignore the newline character after reading id

        string name;
        getline(file, name);

        file >> age;
        file >> numCourses;
        file.ignore(); // To ignore the newline character after reading numCourses

        vector<string> courses;
        vector<float> scores;

        for(int i = 0; i < numCourses; i++){
            string course;
            float score;

            getline(file, course);
            file >> score;
            file.ignore(); // To ignore the newline character after reading score

            courses.push_back(course);
            scores.push_back(score);
        }
        student.setId(id);
        student.setName(name);
        student.setAge(age);
        student.setCourses(courses);
        student.setScores(scores);
        student.computeAverage();
        student.assignGrade();
        studentList.push_back(student);
    }
    file.close();
    cout << "Student data loaded from file successfully!" << endl;
}

void sortStudents(vector<Student>& studentList){
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