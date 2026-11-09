
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Subject
{
    string name;
    double grade;
    double credit;
};

struct Semester
{
    vector<Subject> subjects;
    double sgpa;
};

int main()
{
    int totalSemesters;

    double overallCredits = 0;
    double overallGradePoints = 0;

    vector<Semester> semesters;

    cout << "====================================\n";
    cout << "          CGPA CALCULATOR\n";
    cout << "====================================\n";

    cout << "\nEnter number of completed semesters: ";
    cin >> totalSemesters;

    if (totalSemesters <= 0)
    {
        cout << "Invalid number of semesters!\n";
        return 0;
    }

    for (int i = 0; i < totalSemesters; i++)
    {
        Semester sem;
        int courses;

        double totalCredits = 0;
        double totalGradePoints = 0;

        cout << "\n========== SEMESTER "
             << i + 1 << " ==========\n";

        cout << "Enter number of courses: ";
        cin >> courses;

        if (courses <= 0)
        {
            cout << "Invalid number of courses!\n";
            return 0;
        }

        for (int j = 0; j < courses; j++)
        {
            Subject sub;

            cout << "\nCourse " << j + 1 << endl;

            cout << "Enter course name: ";
            cin >> ws;
            getline(cin, sub.name);

            cout << "Enter grade points (0-10): ";
            cin >> sub.grade;

            cout << "Enter credit hours: ";
            cin >> sub.credit;

            if (sub.grade < 0 || sub.grade > 10 ||
                sub.credit <= 0)
            {
                cout << "Invalid grade or credit!\n";
                return 0;
            }

            totalCredits += sub.credit;

            totalGradePoints +=
                sub.grade * sub.credit;

            sem.subjects.push_back(sub);
        }

        sem.sgpa = totalGradePoints / totalCredits;

        overallCredits += totalCredits;
        overallGradePoints += totalGradePoints;

        semesters.push_back(sem);

        cout << fixed << setprecision(2);

        cout << "\nSemester " << i + 1
             << " GPA: " << sem.sgpa << endl;
    }

    double cgpa = overallGradePoints / overallCredits;

    cout << "\n\n====================================\n";
    cout << "           FINAL RESULT\n";
    cout << "====================================\n";

    for (int i = 0; i < totalSemesters; i++)
    {
        cout << "\nSemester " << i + 1 << endl;

        cout << left << setw(20) << "Course"
             << setw(15) << "Grade"
             << setw(15) << "Credits" << endl;

        cout << "------------------------------------\n";

        for (int j = 0;
             j < semesters[i].subjects.size(); j++)
        {
            Subject sub = semesters[i].subjects[j];

            cout << left << setw(20) << sub.name
                 << setw(15) << sub.grade
                 << setw(15) << sub.credit << endl;
        }

        cout << "Semester GPA: "
             << semesters[i].sgpa << endl;
    }

    cout << "\nTotal Credits: " << overallCredits;

    cout << "\nTotal Grade Points: "
         << overallGradePoints;

    cout << "\n\nOverall CGPA: " << cgpa;

    cout << "\n====================================\n";

    return 0;
}