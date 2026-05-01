#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    float marks;
    float attendance;
    float studyHours;
    string grade;

public:

    // Input student data
    void inputData() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks (out of 100): ";
        cin >> marks;

        cout << "Enter attendance percentage: ";
        cin >> attendance;

        cout << "Enter daily study hours: ";
        cin >> studyHours;
    }

    // Predict grade using rules
    void predictGrade() {
        float score = 0;

        // Weightage logic
        score += marks * 0.6;
        score += attendance * 0.2;
        score += studyHours * 5;   // scaled

        // Grade decision
        if (score >= 90)
            grade = "A";
        else if (score >= 75)
            grade = "B";
        else if (score >= 60)
            grade = "C";
        else
            grade = "Fail";
    }

    // Display result
    void display() {
        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Attendance: " << attendance << "%" << endl;
        cout << "Study Hours: " << studyHours << endl;
        cout << "Predicted Grade: " << grade << endl;
    }

    // Save to file
    void saveToFile() {
        ofstream file("students.txt", ios::app);
        file << name << " " << marks << " " << attendance << " "
             << studyHours << " " << grade << endl;
        file.close();
    }
};

int main() {
    Student s;

    cin.ignore();  // to handle getline issue
    s.inputData();
    s.predictGrade();
    s.display();
    s.saveToFile();

    cout << "\nData saved successfully!\n";

    return 0;
}
