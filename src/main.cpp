#include "student.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    student std;
    int id;
    string name;
    int age;
    char courses[3][50];
    float scores[3];
    float average_score;
    char grade;

    std.inputStudent(id, name, age, courses, scores);
    average_score = std.computeAverage(scores);
    std.assignGrade(id, name, average_score, grade);
    std.displayStudent(id, name, age, courses, scores, average_score, grade);
}