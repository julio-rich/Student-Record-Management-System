#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;

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
    // core functions
    void inputStudent();
    void displayStudent() const;
    float computeAverage();
    void assignGrade();

    // getters and setters
    int getId() const;
    string getName() const;
    float getAverage() const;
    int getAge() const;
    vector<string> getCourses () const;
    vector<float> getScores() const;

    void setId(int newId);
    void setName(string newName);
    void setAge(int newAge);
    void setCourses(vector<string> newCourses);
    void setScores(vector<float> newScores);

    // update functions
    void updateName();
    void updateAge();
    void updateCoursesAndScores();
    void updateAllInformation();

    


    
};
#endif // STUDENT_H