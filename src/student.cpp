#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// FUNCTION INPUT STUDENT

void Student::inputStudent() {
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // To ignore the newline character left in the buffer

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student age: ";
    cin >> age;
    cin.ignore(); // To ignore the newline character left in the buffer

    courses.clear();
    scores.clear();

    for (int i = 0; i < 3; i++) {
        string course;
        float score;
        
        cout << "Enter course " << i + 1 << ": ";
        getline(cin, course);

        cout << "Enter score for course " << i + 1 << ": ";
        cin >> score;
        cin.ignore(); // To ignore the newline character left in the buffer

        courses.push_back(course);
        scores.push_back(score);

    }
    average_score = computeAverage();
    assignGrade();

}

// FUNCTION DISPLAY STUDENT

void Student::displayStudent()const{
    cout << "Student ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Age: " << age << endl;
    for (int i = 0; i < courses.size(); i++) {
        cout << "Course: " << courses[i] << ", Score: " << scores[i] << endl;
    }
    cout << "Average Score: " << average_score << endl;
    cout << "Grade: " << grade << endl;
}

// FUNCTION COMPUTE AVERAGE

float Student::computeAverage() {
    if (scores.empty()) {
        return 0;
    }
    float sum = 0;

    for (int i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }

    average_score = sum / scores.size();
    return average_score;
}


int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

// FUNCTION ASSIGN GRADE

void Student::assignGrade() {
    if (average_score >= 90) {
        grade = 'A';
    } else if (average_score >= 80) {
        grade = 'B';
    } else if (average_score >= 70) {
        grade = 'C';
    } else if (average_score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
}

// FUNCTION UPDATE NAME

void Student::updateName() {
    cin.ignore(); 
    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Name updated successfully!" << endl;
}

// FUNCTION UPDATE AGE
void Student::updateAge() {
    cout << "Enter new age: ";
    cin >> age;
    cin.ignore(); 
    cout << "Age updated successfully!" << endl;
}

// FUNCTION UPDATE COURSES AND SCORES

void Student::updateCoursesAndScores() {
    courses.clear();
    scores.clear();

    for (int i = 0; i < 3; i++) {
        string course;
        float score;

        cout << "Enter new course " << i + 1 << ": ";
        getline(cin, course);

        cout << "Enter new score for course " << i + 1 << ": ";
        cin >> score;
        cin.ignore(1000, '\n');

        courses.push_back(course);
        scores.push_back(score);

    }

    average_score = computeAverage();
    assignGrade();
    cout << "Courses and scores updated successfully!" << endl;
}

// FUNCTION UPDATE ALL INFORMATION

void Student::updateAllInformation() {
    cout << "Enter the updated name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, name);

    cout << "Enter the updated age: ";
    cin >> age;
    cin.ignore(); // To ignore the newline character left in the buffer

    courses.clear();
    scores.clear();

    for (int i = 0; i < 3; i++) {
        string course;
        float score;

        cout << "Enter the updated course " << i + 1 << ": ";
        getline(cin, course);

        cout << "Enter the updated score for course " << i + 1 << ": ";
        cin >> score;
        cin.ignore(); // To ignore the newline character left in the buffer

        courses.push_back(course);
        scores.push_back(score);

    }
    average_score = computeAverage();
    assignGrade();
    cout << "All information updated successfully!" << endl;
}


int Student::getAge() const {
    return age;
}

vector<string> Student::getCourses() const {
    return courses;
}

vector<float> Student::getScores() const {
    return scores;
}

void Student::setId(int newId) {
    id = newId;
}

void Student::setName(string newName) {
    name = newName;
}

void Student::setAge(int newAge) {
    age = newAge;
}
void Student::setCourses(vector<string> newCourses) {
    courses = newCourses;
}

void Student::setScores(vector<float> newScores) {
    scores = newScores;
}

float Student::getAverage() const{
    return average_score;
}