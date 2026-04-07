#ifndef STUDENT_H
#define STUDENT_H

class student {
    private:
    int id;
    string name;
    int age;
    char courses[3][50]; // Assuming a student can take up to 3 courses
    float scores[3]; // Scores corresponding to the courses
    float average_score;
    char grade;

    public:
    void inputStudent(int& id, string& name, int& age, char courses[3][50], float scores[3]);
    void displayStudent(int& id, string& name, int& age, char courses[3][50], float scores[3], float average_score, char grade);
    float computeAverage(float scores[3]);
    void assignGrade(int id, string& name, float average_score, char &grade);
    int getId(int id);
    string getName( string& name);
};
#endif // STUDENT_H