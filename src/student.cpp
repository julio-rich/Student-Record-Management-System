#include "student.h"
#include <iostream>
#include <string>


using namespace std;

void inputStudent(int& id, string& name, int& age, char courses[3][50], float scores[3]) {
    cout << "Enter student ID: \n";
    cin >> id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter student name: \n";
    getline(cin, name);
    cout << "Enter student age: \n";
    cin >> age;
    cin.ignore(); // Clear the input buffer
    for (int i = 0; i < 3; i++) {
        if (i == 1){
            cout << "Enter the first course name: \n";
        } else if (i == 2){
            cout << "Enter the second course name: \n";
        } else {
            cout << "Enter the third course name: \n";
        }
        cin.getline(courses[i], 50);
    }
    cin.ignore(); // Clear the input buffer
    for (int i = 0; i < 3; i++) {
        if (i == 1){
            cout << "Enter the first course score: \n";
        } else if (i == 2){
            cout << "Enter the second course score: \n";
        } else {
            cout << "Enter the third course score: \n";
        }
        cin >> scores[i];
        cin.ignore(); // To ignore the newline character left in the buffer

    }
    cin.ignore(); // Clear the input buffer


}

void displayStudent(int& id, string& name, int& age, char courses[3][50], float scores[3], float average_score, char grade) {
    cout << "Student ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Age: " << age << endl;
    for (int i = 0; i < 3; i++) {
        if(i == 1){
            cout << "Student's first course: " << courses[i] << " with score: " << scores[i] << endl;
        } else if(i == 2){
            cout << "Student's second course: " << courses[i] << " with score: " << scores[i] << endl;
        } else {
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

float computeAverage(float scores[3]) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += scores[i];
    }
    float average_score = sum / 3;
    return average_score;
}

void assignGrade(int id, string& name, float average_score, char &grade) {
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
