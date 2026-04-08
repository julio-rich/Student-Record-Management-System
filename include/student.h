#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

class Student {
    private:
    int id;
    string name;
    int age;
    vector <string> courses; // Assuming a student can take more than 3 courses, using vector to store course names
    vector <float> scores; // Scores corresponding to the courses
    float average_score;
    char grade;

    public:
    void inputStudent();
    void displayStudent();
    float computeAverage();
    void assignGrade();

    int getId();
    string getName();

    void setName(string newName);
    void setAge(int newAge);
    void setCourses(vector<string> newCourses);
    void setScores(vector<float> newScores);

    void updateName();
    void updateCoursesAndScores();
    void updateAllInformation();

    int getAge();
    vector<string> getCourses();
    vector<float> getScores();

    void setId(int newId);
    void setAge(int newAge);
};
#endif // STUDENT_H