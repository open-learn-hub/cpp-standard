#include "stack.h"
#include "student.h"
#include "practice04.h"
#include <functional>
#include <iostream>

void ExecutePractice04()
{
    Stack<StudentPtr>* students = CreateStudentStack();
    std::cout << "Initial student list by stack" << std::endl;
    PrintStudents(students);

    std::cout << "Pop twice " << std::endl;
    Pop(students);
    Pop(students);

    std::cout << "Peek " << std::endl;
    PrintStudent(Peek<StudentPtr>(students));

    std::cout << "The current stack content" << std::endl;
    PrintStudents(students);
}

void PrintStudents(const StackPtr<StudentPtr> students)
{
    std::function<void(StudentPtr)> printFuct = [](StudentPtr student)
    {
        PrintStudent(student);
    };

    Foreach(students, printFuct);
}

Stack<StudentPtr>* CreateStudentStack()
{
    StackPtr<Student*> stack = CreateStack<Student*>();
    Push(stack, new Student { .id = 123, .fullName = "Nguyen Van A", .gpa = 9.1, .performance = EAcademicPerformance::A });
    Push(stack, new Student { .id = 124, .fullName = "Nguyen Van B", .gpa = 8.8, .performance = EAcademicPerformance::A });
    Push(stack, new Student { .id = 125, .fullName = "Nguyen Van C", .gpa = 9.1, .performance = EAcademicPerformance::A });
    Push(stack, new Student { .id = 126, .fullName = "Nguyen Van D", .gpa = 2.1, .performance = EAcademicPerformance::D });
    Push(stack, new Student { .id = 127, .fullName = "Nguyen Van E", .gpa = 9.7, .performance = EAcademicPerformance::A });
    Push(stack, new Student { .id = 128, .fullName = "Nguyen Van F", .gpa = 4.1, .performance = EAcademicPerformance::C });
    Push(stack, new Student { .id = 129, .fullName = "Nguyen Van G", .gpa = 8.3, .performance = EAcademicPerformance::A });
    Push(stack, new Student { .id = 130, .fullName = "Nguyen Van H", .gpa = 7.9, .performance = EAcademicPerformance::B });
    Push(stack, new Student { .id = 131, .fullName = "Nguyen Van K", .gpa = 9.0, .performance = EAcademicPerformance::A });
    return stack;
}
