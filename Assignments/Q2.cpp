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
    bool isRegistered;
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
    c->isRegistered = false;
    return c;
}

bool PrintCoursePlan(Course *c, int step = 0)
{
    if (!c)
        return true;

    if (c->isVisited)
    {
        cout << "Error: Cycle detected involving " << c->code << endl;
        return false;
    }

    if (c->isPrinted)
        return true;

    c->isVisited = true;

    if (c->prerequisites && c->prerequisites->code.empty())
    {
        cout << "Error: " << c->code << " requires a prerequisite course that is not offered." << endl;
        return false;
    }

    if (c->corerequisite && c->corerequisite->code.empty())
    {
        cout << "Error: " << c->code << " has a corequisite course that is not offered." << endl;
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

    cout << c->code << " (" << c->credits << " credits)";

    if (c->prerequisites)
        cout << "It requires " << c->prerequisites->code << " beforehand";

    if (c->corerequisite)
        cout << "It must be taken alongside " << c->corerequisite->code;

    cout << endl;

    c->isPrinted = true;
    c->isRegistered = true;

    if (c->corerequisite)
    {
        if (!PrintCoursePlan(c->corerequisite, step + 1))
            return false;
    }

    c->isVisited = false;
    return true;
}

void ShowCourses()
{
    cout << "Available Courses:" << endl;
    cout << "1. CS101- Programming Fundamentals (3 credits)" << endl;
    cout << "2. CS102- Object Oriented Programming (3 credits)" << endl;
    cout << "3. CS201- Data Structures (3 credits)" << endl;
    cout << "4. MT101 - Calculus I (3 credits)" << endl;
    cout << "5. PHYS101 - Applied Physics (3 credits)" << endl;
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

    int choice;
    string input;

    do
    {
        cout << "===== COURSE REGISTRATION MENU =====" << endl;
        cout << "1. View all courses" << endl;
        cout << "2. Register for a course" << endl;
        cout << "3. Print full registered course plan" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            ShowCourses();
        }
        else if (choice == 2)
        {
            ShowCourses();
            cout << "Enter the course ID: ";
            cin >> input;

            Course *selectedCourse = nullptr;
            if (input == "CS101")
                selectedCourse = CS101;
            else if (input == "CS102")
                selectedCourse = CS102;
            else if (input == "CS201")
                selectedCourse = CS201;
            else if (input == "MT101")
                selectedCourse = MT101;
            else if (input == "PHYS101")
                selectedCourse = PHYS101;
            else
            {
                cout << "Invalid course code entered." << endl;
                continue;
            }

            if (selectedCourse == CS102)
            {
                char pfPassed;
                cout << "Have you passed CS101? (y/n): ";
                cin >> pfPassed;
                if (pfPassed == 'y' || pfPassed == 'Y')
                {
                    cout << "Registering Object Oriented Programming (CS102)..." << endl;
                    selectedCourse->isRegistered = true;
                    cout << selectedCourse->code << " registered successfully." << endl;
                }
                else
                {
                    cout << "You cannot register for CS102 until CS101 is passed." << endl;
                    cout << "Registering CS101 instead..." << endl;
                    PrintCoursePlan(CS101, 0);
                }
            }
            else if (selectedCourse == CS201)
            {
                char oopPassed;
                cout << "Have you passed CS102? (y/n): ";
                cin >> oopPassed;
                if (oopPassed == 'y' || oopPassed == 'Y')
                {
                    cout << "Registering Data Structures (CS201)..." << endl;
                    selectedCourse->isRegistered = true;
                    cout << selectedCourse->code << " registered successfully." << endl;
                }
                else
                {
                    cout << "You cannot register for CS201 until CS102 is passed." << endl;
                    cout << "Registering CS102 instead..." << endl;
                    PrintCoursePlan(CS102, 0);
                }
            }

            else if (selectedCourse == PHYS101)
            {
                char calculusRegistered;
                cout << "Are you registering for MT101 alongside PHYS101? (y/n): ";
                cin >> calculusRegistered;
                if (calculusRegistered == 'y' || calculusRegistered == 'Y')
                    PrintCoursePlan(PHYS101, 0);
                else
                    cout << "You must register for MT101 alongside PHYS101." << endl;
            }
            else
            {
                PrintCoursePlan(selectedCourse, 0);
            }
        }
        else if (choice == 3)
        {
            cout << "Your Registered Courses:" << endl;
            Course *temp = CS101;
            while (temp)
            {
                if (temp->isRegistered)
                    cout << temp->code << " (" << temp->credits << " credits)" << endl;
                temp = temp->next;
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 4);

    delete CS101;
    delete CS201;
    delete CS102;
    delete MT101;
    delete PHYS101;

    return 0;
}