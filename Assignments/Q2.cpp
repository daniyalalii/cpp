#include <iostream>
using namespace std;

struct Course
{
    string code;
    int credits;
    Course *prerequisites;
    Course *corerequisite;
    Course *next;
    bool isPrinted;
    bool isVisited;
};

Course *CreateCourse(string code, int credits)
{
    Course *c = new Course;
    c->code = code;
    c->credits = credits;
    c->prerequisites = nullptr;
    c->corerequisite = nullptr;
    c->next = nullptr;
    c->isPrinted = false;
    c->isVisited = false;
    return c;
}

bool PrintCoursePlan(Course *c, int step = 0)
{
    if (!c)
        return true;

    if (c->isVisited)
    {
        cout << "⚠️ Error: Cycle detected involving " << c->code << "!" << endl;
        return false;
    }

    if (c->isPrinted)
        return true;

    c->isVisited = true;

    if (c->prerequisites && c->prerequisites->code.empty())
    {
        cout << "❌ Error: " << c->code << " requires a prerequisite course that is not offered." << endl;
        return false;
    }

    if (c->corerequisite && c->corerequisite->code.empty())
    {
        cout << "❌ Error: " << c->code << " has a corequisite course that is not offered." << endl;
        return false;
    }

    if (c->prerequisites)
    {
        if (!PrintCoursePlan(c->prerequisites, step))
            return false;
    }

    if (step == 0)
        cout << "The student begins with ";
    else
        cout << "Next, the student takes ";

    cout << c->code << " (" << c->credits << " credits). ";

    if (c->prerequisites)
        cout << "It requires " << c->prerequisites->code << " beforehand. ";

    if (c->corerequisite)
        cout << "It must be taken alongside " << c->corerequisite->code << ". ";

    cout << endl;

    c->isPrinted = true;

    if (c->corerequisite)
    {
        if (!PrintCoursePlan(c->corerequisite, step + 1))
            return false;
    }

    c->isVisited = false;
    return true;
}

int main()
{
    Course *CS101 = CreateCourse("CS101- Programming Fundamentals", 3);
    Course *CS102 = CreateCourse("CS102- Object Oriented Programming", 3);
    Course *CS201 = CreateCourse("CS201- Data Structures", 3);
    Course *MT101 = CreateCourse("MT101 - Calculus I", 3);
    Course *PHYS101 = CreateCourse("PHYS101 - Applied Physics", 3);

    CS102->prerequisites = CS101;
    CS201->prerequisites = CS102;
    PHYS101->corerequisite = MT101;

    CS101->next = CS102;
    CS102->next = CS201;
    CS201->next = MT101;
    MT101->next = PHYS101;
    cout << "---------------------------------" << endl;
    cout << "Final Course Plan: " << endl;
    Course *temp = CS101;
    while (temp)
    {
        if (!PrintCoursePlan(temp, 0))
            return 0;
        temp = temp->next;
    }

    cout << "Registration Completed" << endl;
    delete CS101;
    delete CS201;
    delete CS102;
    delete MT101;
    delete PHYS101;
    return 0;
}