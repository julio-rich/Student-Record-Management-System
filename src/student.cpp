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

void Student::displayStudent() {
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
    float sum = 0;

    for (int i = 0; i < scores.size; i++) {
        sum += scores[i];
    }
     average_score = sum / scores.size();
    return average_score;
}

// FUNCTION ASSIGN GRADE

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

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
    cout << "Enter new name: "
    getline(cin, name);
    cout << "Name updated successfully!" << endl;
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
        cin.ignore(); // To ignore the newline character left in the buffer

        courses.push_back(course);
        scores.push_back(score);

    }

    average_score = computeAverage();
    assignGrade();
    cout << "Courses and scores updated successfully!" << endl;
}

// FUNCTION UPDATE ALL INFORMATION
void Student::updateAllInformation() {
    cout << "Enter new name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, name);

    cout << "Enter new age: ";
    cin >> age;
    cin.ignore(); // To ignore the newline character left in the buffer

    courses.clear();
    scores.clear();

    for (int i = 0; i < 3; i++) {
        string course;
        float score;

        cout << "Enter new course " << i + 1 << ": ";
        getline(cin, course);

        cout << "Enter new score for course " << i + 1 << ": ";
        cin >> score;
        cin.ignore(); // To ignore the newline character left in the buffer

        courses.push_back(course);
        scores.push_back(score);

    }
}

int Student::getAge() {
    return age;
}

vector<string> Student::getCourses() {
    return courses;
}

vector<float> Student::getScores() {
    return scores;
}

void Student::setId(int newId) {
    id = newId;
}

void Student::setAge(int newAge) {
    age = newAge;
}

float Student::getAverage() {
    return average_score;
}