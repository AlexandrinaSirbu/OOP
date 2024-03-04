#include <iostream>
#include "student.h"
#include "global.h"
using namespace std;

int main()
{
    char name1, name2;
    std::cout << "Please student 1, enter your full name: ";
    std::cin >> name1;
    student s1;
    s1.SetName(name1);
    cout << "Student`s name:" << s1.GetName() << "\n";
    s1.SetGradeMath(5.8);
    cout << "Math grade:" << s1.GetGradeMath() << "\n";
    s1.SetGradeEngl(7.2);
    cout << "Engl grade:" << s1.GetGradeEngl() << "\n";
    s1.SetGradeHist(10);
    cout << "Hist grade:" << s1.GetGradeHist() << "\n";
    s1.SetGradeAverage();
    cout << "Average grade:" << s1.GetGradeAverage() << "\n";
    cout << "\n";


    std::cout << "Please student 2, enter your full name: ";
    std::cin >> name2;
    student s2;
    s2.SetName(name2);
    cout << "Student`s name:" << s2.GetName() << "\n";
    s2.SetGradeMath(3.8);
    cout << "Math grade:" << s2.GetGradeMath() << "\n";
    s2.SetGradeEngl(8.2);
    cout << "Engl grade:" << s2.GetGradeEngl() << "\n";
    s2.SetGradeHist(9);
    cout << "Hist grade:" << s2.GetGradeHist() << "\n";
    s2.SetGradeAverage();
    cout << "Average grade:" << s2.GetGradeAverage() << "\n";
    cout << "\n";

    if (CompGradeMath(s1, s2) == 1) cout << s1.GetName() << " is better at math" << "\n"; else cout << s2.GetName() << " is better at math" << "\n";
    if (CompGradeEngl(s1, s2) == 1) cout << s1.GetName() << " is better at english" << "\n"; else cout << s2.GetName() << " is better at english" << "\n";
    if (CompGradeHist(s1, s2) == 1) cout << s1.GetName() << " is better at history" << "\n"; else cout << s2.GetName() << " is better at history" << "\n";
    if (CompGradeAverage(s1, s2) == 1) cout << s1.GetName() << " is better overall" << "\n"; else cout << s2.GetName() << " is better overall" << "\n";
    if (CompName(s1, s2) == 1) cout << s1.GetName() << " comes first in the registry" << "\n"; else cout << s2.GetName() << " comes first in the registry" << "\n";

}