#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100;

char getLetterGrade(int grade) {
    if (grade >= 90) return 'A';
    else if (grade >= 80) return 'B';
    else if (grade >= 70) return 'C';
    else if (grade >= 60) return 'D';
    else return 'F';
}

void sortGrades(string names[], int grades[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool condition = ascending ? grades[j] > grades[j + 1] : grades[j] < grades[j + 1];
            if (condition) {
                swap(grades[j], grades[j + 1]);
                swap(names[j], names[j + 1]);
            }
        }
    }
}

int searchStudent(string names[], int n, string target) {
    for (int i = 0; i < n; i++) {
        if (names[i] == target) {
            return i;
        }
    }
    return -1;
}

void calculateStats(int grades[], int n, double &average, int &highest, int &lowest) {
    int sum = 0;
    highest = grades[0];
    lowest = grades[0];
    for (int i = 0; i < n; i++) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }
    average = static_cast<double>(sum) / n;
}

int main() {
    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS];
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter student name: ";
        cin >> ws;
        getline(cin, names[i]);
        cout << "Enter " << names[i] << "'s grade: ";
        cin >> grades[i];
    }

    char sortChoice;
    cout << "\nSort grades in ascending (A) or descending (D) order? ";
    cin >> sortChoice;
    bool ascending = (sortChoice == 'A' || sortChoice == 'a');
    sortGrades(names, grades, numStudents, ascending);

    cout << "\nSorted Grades:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << names[i] << ": " << grades[i] << " (" << getLetterGrade(grades[i]) << ")\n";
    }

    string searchName;
    cout << "\nEnter student name to search: ";
    cin >> ws;
    getline(cin, searchName);
    int index = searchStudent(names, numStudents, searchName);
    if (index != -1) {
        cout << names[index] << "'s grade: " << grades[index]
             << " (" << getLetterGrade(grades[index]) << ")\n";
    } else {
        cout << "Student not found.\n";
    }

    char editChoice;
    cout << "\nWould you like to edit a student's grade? (Y/N): ";
    cin >> editChoice;
    if (editChoice == 'Y' || editChoice == 'y') {
        string editName;
        cout << "Enter student name to edit: ";
        cin >> ws;
        getline(cin, editName);
        int editIndex = searchStudent(names, numStudents, editName);
        if (editIndex != -1) {
            cout << "Enter new grade for " << names[editIndex] << ": ";
            cin >> grades[editIndex];
            cout << "Grade updated.\n";
        } else {
            cout << "Student not found.\n";
        }
    }

    double average;
    int highest, lowest;
    calculateStats(grades, numStudents, average, highest, lowest);

    cout << fixed << setprecision(2);
    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;

    return 0;
}
