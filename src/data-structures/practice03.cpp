#include "practice03.h"
#include "linkedlistdll.h"
#include <functional>

using namespace dll;

void ExecutePractice03()
{
    List<StudentPtr>* students = CreateStudentList();
    PrintStudents(const_cast<const List<StudentPtr>*>(students));  
}

List<StudentPtr>* CreateStudentList()
{
    List<Student*>* list = CreateList<Student*>();
    Add(list, new Student { .id = 123, .fullName = "Nguyen Van A", .gpa = 9.1, .performance = EAcademicPerformance::A });
    Add(list, new Student { .id = 124, .fullName = "Nguyen Van B", .gpa = 8.8, .performance = EAcademicPerformance::A });
    Add(list, new Student { .id = 125, .fullName = "Nguyen Van C", .gpa = 9.1, .performance = EAcademicPerformance::A });
    Add(list, new Student { .id = 126, .fullName = "Nguyen Van D", .gpa = 2.1, .performance = EAcademicPerformance::D });
    Add(list, new Student { .id = 127, .fullName = "Nguyen Van E", .gpa = 9.7, .performance = EAcademicPerformance::A });
    Add(list, new Student { .id = 128, .fullName = "Nguyen Van F", .gpa = 4.1, .performance = EAcademicPerformance::C });
    Add(list, new Student { .id = 129, .fullName = "Nguyen Van G", .gpa = 8.3, .performance = EAcademicPerformance::A });
    Add(list, new Student { .id = 130, .fullName = "Nguyen Van H", .gpa = 7.9, .performance = EAcademicPerformance::B });
    Add(list, new Student { .id = 131, .fullName = "Nguyen Van K", .gpa = 9.0, .performance = EAcademicPerformance::A });
    return list;
}

void PrintStudents(const List<StudentPtr>* list)
{
    std::function<void(StudentPtr)> printFunc = [](StudentPtr student)
    {
        PrintStudent(student);
    };
    Foreach<StudentPtr>(const_cast<List<StudentPtr>*>(list), printFunc);
}