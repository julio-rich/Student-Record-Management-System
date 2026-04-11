#include "student.h"
#include "system.h"
#include "fileHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    System system;
    FileHandler::loadFromFile(system.getStudentList());
    int choice;

    do {
        cout << "-----Student Record Management System-----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Sort Students" << endl;
        cout << "7. Show Statistics" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.viewStudents();
                break;
            case 3:
                system.searchStudent();
                break;
            case 4:
                system.updateStudent();
                break;
            case 5:
                system.deleteStudent();
                break;
            case 6:
                FileHandler::saveToFile(system.getStudentList());
                break;
            case 7:
                system.showStatistics();
                break;
            case 8:
                FileHandler::saveToFile(system.getStudentList());
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    FileHandler::saveToFile(system.getStudentList());
    return 0;
}


















