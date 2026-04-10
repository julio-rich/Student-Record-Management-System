#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "student.h"
using namespace std;

class System {
    private:
    vector<Student> studentList;
    bool isDuplicate(int id) const;

    public:
    void addStudent();
    void viewStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();
    void sortStudents();

    vector<Student>& getStudentList();
};



#endif // SYSTEM_H