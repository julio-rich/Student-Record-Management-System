#include "student.h"
#include <iostream>
#include <string>


using namespace std;
void Student::inputStudent() {
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // To ignore the newline character left in the buffer

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student age: ";
    cin >> age;
    cin.ignore(); // To ignore the newline character left in the buffer

    for (int i = 0; i < 5; i++) {
        cout << "Enter course " << i + 1 << ": ";
        getline(cin, courses[i]);

        cout << "Enter score for course " << i + 1 << ": ";
        cin >> scores[i];
        cin.ignore(); // To ignore the newline character left in the buffer

    }
    average_score = computeAverage();
    assignGrade();

}

void Student::displayStudent() {
    cout << "Student ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Age: " << age << endl;
    for (int i = 0; i < 4; i++) {
        if(i == 0){
            cout << "Student's first course: " << courses[i] << " with score: " << scores[i] << endl;
        } else if(i == 1){
            cout << "Student's second course: " << courses[i] << " with score: " << scores[i] << endl;
        } else if (i == 2){
            cout << "Student's third course: " << courses[i] << " with score: " << scores[i] << endl;
        } else if (i == 3){
            cout << "Student's fourth course: " << courses[i] << " with score: " << scores[i] << endl;
        } else if (i == 4){
            cout << "Student's fifth course: " << courses[i] << " with score: " << scores[i] << endl;
        }
    }
    cout << "Average Score: " << average_score << endl;
    cout << "Grade: " << grade << endl;
}

float Student::computeAverage() {
    float sum = 0;

    for (int i = 0; i < 4; i++) {
        sum += scores[i];
    }
    float average_score = sum / 4;
    return average_score;
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

int getId(int id) {
    return id;
}

string getName(string& name) {
    return name;
}
