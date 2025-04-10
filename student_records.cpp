#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

enum GRADES { Freshman, Sophomore, Junior, Senior };

string GRADE_LEVEL;

void student_record(const string& studentFirstNamesUpper,const string& studentLastNamesUpper, GRADES StudentGrades, double StudentGPA) {
    cout << "Student Record:" << endl;
    cout << "Name: " << studentFirstNamesUpper <<" "<<studentLastNamesUpper<< endl;
    cout << "Grade Level: " << GRADE_LEVEL << endl;
    cout << "GPA: " << StudentGPA << endl;
}

int main() {
    int StudentGrade;
    string StudentFirstNames;
    string StudentLastNames;
    GRADES StudentGrades;
    double StudentGPA;
    string studentFirstNamesUpper;
    string studentLastNamesUpper;
    cout << "Enter the student grade level (0=Freshman, 1=Sophomore, 2=Junior, 3=Senior):" << endl;
    cin >> StudentGrade;

    if (StudentGrade >= 0 && StudentGrade <= 3) {
        StudentGrades = static_cast<GRADES>(StudentGrade);
        switch (StudentGrades) {
            case Freshman:
                GRADE_LEVEL = "The student is a Freshman";
                break;
            case Sophomore:
                GRADE_LEVEL = "The student is a Sophomore";
                break;
            case Junior:
                GRADE_LEVEL = "The student is a Junior";
                break;
            case Senior:
                GRADE_LEVEL = "The student is a Senior";
                break;
        }
    } else {
        GRADE_LEVEL = "Invalid grade level";
    }

    cout << "Enter the student First  name: " << endl;
    cin >> StudentFirstNames;
    cout << "Enter the student Last name: " << endl;
    cin >> StudentLastNames;

    cout << "Enter the student GPA: " << endl;
    cin >> StudentGPA;
    if (StudentGPA < 0.0 || StudentGPA > 4.0) {
        cout << "Invalid GPA" << endl;
        return 1;
    }
    //covert gpa to a two decimal system
    StudentGPA = static_cast<double>(StudentGPA * 100 + 0.5) / 100.0;

    // Convert name to uppercase
    studentFirstNamesUpper = StudentFirstNames;
    for (size_t i = 0; i < studentFirstNamesUpper.length(); ++i) {
        studentFirstNamesUpper[i] = toupper(studentFirstNamesUpper[i]);
    }
    // Convert name to uppercase
    studentLastNamesUpper = StudentLastNames;
    for (size_t i = 0; i < studentLastNamesUpper.length(); ++i) {
        studentLastNamesUpper[i] = toupper(studentLastNamesUpper[i]);
    }


student_record(studentFirstNamesUpper,studentLastNamesUpper, StudentGrades, StudentGPA);

    return 0;
}
