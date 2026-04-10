#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include "student.h"
using namespace std;

class FileHandler {
    public:
    static void saveToFile(const vector<Student>& studentList);
    static void loadFromFile(vector<Student>& studentList);
};

#endif