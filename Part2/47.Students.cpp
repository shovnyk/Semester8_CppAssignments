/* 
    Create a structure containing studentname, rollno, marks.
    Now create an array of structure of 10 students.
    Now find the highest marks and the name of the student who got it.
    Take a string from user and print each word in reversed way. 
    The entire string will not be reversed in this process.
*/

#include <iostream>
#include <string>

using namespace std;

struct Student
{
   string name;
   long int rollno;
   float marks;
};

const int NUM_STUDENTS = 2;

void input(Student* s, int number)
{
    cout << "Student " << number << endl;
    cout << "\tEnter name: ";          cin >> s->name;
    cout << "\tEnter roll number: ";   cin >> s->rollno;
    cout << "\tEnter marks: ";         cin >> s->marks;
    cout << endl;
}

// void printStudents(Student s[], int numStudents)
// {
//     for (int i = 0; i < numStudents; i++) {
//         cout << "Student " << i << endl;
//         cout << "\tName: " << s[i].name << endl;
//         cout << "\tRoll: " << s[i].rollno << endl;
//         cout << "\tMarks: " << s[i].marks << endl;
//     }
//     cout << endl;
// }

Student highestMarks(Student s[], int numStudents)
{
    Student max = s[0];
    for (int i = 1; i < numStudents; i++) {
        if (max.marks < s[i].marks) {
            max = s[i];
        }
    }
    return max;
}

int main()
{
    Student s[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++)
        input(&s[i], i+1);

    Student topper = highestMarks(s, NUM_STUDENTS);
    cout << topper.name << " scored the highest marks." << endl;
}
