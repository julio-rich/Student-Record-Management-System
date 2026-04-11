#include "fileHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

void FileHandler::loadFromFile(vector<Student>& studentList){
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

void FileHandler::saveToFile(const vector<Student>& studentList){
    ofstream file("students.txt");

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