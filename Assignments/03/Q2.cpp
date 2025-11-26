#include <iostream>
#include <string>
using namespace std;

// using constant to set the status type
const int FACULTY = 0;
const int STUDENT = 1;
const int ADMIN_STAFF = 2;
const int LECTURE_COURSE = 0;
const int LAB_COURSE = 1;
const int ONLINE_COURSE = 2;
const int SEMINAR = 0;
const int WORKSHOP = 1;
const int EXAMINATION = 2;
const int ANNOUNCEMENT = 3;

// struct for grades
struct Grade
{
    string courseID;
    string grade;
    double marks;

    Grade() {}
    Grade(const string &id, const string &g, double m)
        : courseID(id), grade(g), marks(m) {}
};

// struct for recording attendence
struct AttendanceRecord
{
    string date;
    string courseID;
    bool present; 

    AttendanceRecord() {}
    AttendanceRecord(const string &d, const string &c, bool p)
        : date(d), courseID(c), present(p) {}
};

// struct for recording transaction
struct TransactionRecord
{
    string transactionID;
    string type; // --> for tuition, sal, or scolarship
    double amount;
    string date;
    string description;

    TransactionRecord() {}
    TransactionRecord(const string &id, const string &t, double amt, const string &d, const string &desc)
        : transactionID(id), type(t), amount(amt), date(d), description(desc) {}
};

// struct for recording exam result
struct ExamResult
{
    string studentID;
    string courseID;
    double marks;
    string grade;

    ExamResult() {}
    ExamResult(const string &sID, const string &cID, double m, const string &g)
        : studentID(sID), courseID(cID), marks(m), grade(g) {}
};

// base person class
class Person
{
protected:
    string uniqueID;
    string name;
    string contactInfo;
    int role;

public:
    Person(const string &id, const string &n, const string &contact, int r)
        : uniqueID(id), name(n), contactInfo(contact), role(r) {}

    // getters
    string getID() const { return uniqueID; }
    string getName() const { return name; }
    string getContactInfo() const { return contactInfo; }
    int getRole() const { return role; }

    // setters
    void setContactInfo(const string &contact) { contactInfo = contact; }

    virtual void displayInfo() const
    {
        cout << "ID: " << uniqueID << ", Name: " << name
             << ", Contact: " << contactInfo << ", Role: ";
        switch (role)
        {
        case FACULTY:
            cout << "Faculty";
            break;
        case STUDENT:
            cout << "Student";
            break;
        case ADMIN_STAFF:
            cout << "Administrative Staff";
            break;
        }
        cout << endl;
    }

    virtual void performDuties() = 0;
    virtual ~Person() {}
};

// faculty class
class Faculty : public Person
{
private:
    string coursesTaught[20];
    int coursesCount;
    string officeHours;
    string researchProjects[10];
    int researchCount;
    string publicationRecords[50];
    int publicationsCount;

public:
    Faculty(const string &id, const string &n, const string &contact, const string &hours)
        : Person(id, n, contact, FACULTY), coursesCount(0), officeHours(hours),
          researchCount(0), publicationsCount(0) {}

    void addCourse(const string &course)
    {
        if (coursesCount < 20)
        {
            coursesTaught[coursesCount++] = course;
        }
    }

    void addResearchProject(const string &project)
    {
        if (researchCount < 10)
        {
            researchProjects[researchCount++] = project;
        }
    }

    void addPublication(const string &publication)
    {
        if (publicationsCount < 50)
        {
            publicationRecords[publicationsCount++] = publication;
        }
    }

    void setOfficeHours(const string &hours) { officeHours = hours; }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Office Hours: " << officeHours << endl;
        cout << "Courses Taught (" << coursesCount << "): ";
        for (int i = 0; i < coursesCount; i++)
        {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
        cout << "Research Projects: " << researchCount << endl;
        cout << "Publications: " << publicationsCount << endl;
    }

    void performDuties() override
    {
        cout << "Faculty " << name << " is teaching courses, conducting research, and publishing papers." << endl;
    }
};

// student class
class Student : public Person
{
private:
    string enrolledCourses[15];
    int enrolledCount;
    Grade grades[50];
    int gradesCount;
    bool scholarshipStatus;
    AttendanceRecord attendanceRecords[200];
    int attendanceCount;
    string extracurricularActivities[20];
    int activitiesCount;

public:
    Student(const string &id, const string &n, const string &contact)
        : Person(id, n, contact, STUDENT), enrolledCount(0), gradesCount(0),
          scholarshipStatus(false), attendanceCount(0), activitiesCount(0) {}

    void enrollCourse(const string &courseID)
    {
        if (enrolledCount < 15)
        {
            enrolledCourses[enrolledCount++] = courseID;
        }
    }

    void addGrade(const string &courseID, const string &grade, double marks)
    {
        if (gradesCount < 50)
        {
            grades[gradesCount++] = Grade(courseID, grade, marks);
        }
    }

    void markAttendance(const string &date, const string &courseID, bool present)
    {
        if (attendanceCount < 200)
        {
            attendanceRecords[attendanceCount++] = AttendanceRecord(date, courseID, present);
        }
    }

    void addExtracurricularActivity(const string &activity)
    {
        if (activitiesCount < 20)
        {
            extracurricularActivities[activitiesCount++] = activity;
        }
    }

    void setScholarshipStatus(bool status) { scholarshipStatus = status; }

    double calculateGPA() const
    {
        if (gradesCount == 0)
            return 0.0;
        double total = 0.0;
        for (int i = 0; i < gradesCount; i++)
        {
            total += grades[i].marks;
        }
        return total / gradesCount;
    }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Enrolled Courses: " << enrolledCount << endl;
        cout << "GPA: " << calculateGPA() << endl;
        cout << "Scholarship Status: " << (scholarshipStatus ? "Yes" : "No") << endl;
        cout << "Extracurricular Activities: " << activitiesCount << endl;
    }

    void performDuties() override
    {
        cout << "Student " << name << " is attending classes, studying, and participating in activities." << endl;
    }
};

// admin class
class AdministrativeStaff : public Person
{
private:
    string departmentsManaged[5];
    int deptCount;
    string tasksAssigned[30];
    int tasksCount;
    string workSchedule;
    string eventCoordination[20];
    int eventsCount;

public:
    AdministrativeStaff(const string &id, const string &n, const string &contact, const string &schedule)
        : Person(id, n, contact, ADMIN_STAFF), deptCount(0), tasksCount(0),
          workSchedule(schedule), eventsCount(0) {}

    void addDepartment(const string &dept)
    {
        if (deptCount < 5)
        {
            departmentsManaged[deptCount++] = dept;
        }
    }

    void assignTask(const string &task)
    {
        if (tasksCount < 30)
        {
            tasksAssigned[tasksCount++] = task;
        }
    }

    void addEventCoordination(const string &event)
    {
        if (eventsCount < 20)
        {
            eventCoordination[eventsCount++] = event;
        }
    }

    void setWorkSchedule(const string &schedule) { workSchedule = schedule; }

    void displayInfo() const override
    {
        Person::displayInfo();
        cout << "Work Schedule: " << workSchedule << endl;
        cout << "Departments Managed: " << deptCount << endl;
        cout << "Tasks Assigned: " << tasksCount << endl;
        cout << "Events Coordinated: " << eventsCount << endl;
    }

    void performDuties() override
    {
        cout << "Administrative Staff " << name << " is managing departments and coordinating events." << endl;
    }
};

// base course class
class Course
{
protected:
    string courseID;
    string courseName;
    int credits;
    string enrolledStudents[100];
    int enrolledCount;
    int courseType;

public:
    Course(const string &id, const string &name, int cred, int type)
        : courseID(id), courseName(name), credits(cred), enrolledCount(0), courseType(type) {}

    // getters
    string getCourseID() const { return courseID; }
    string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }
    int getEnrolledCount() const { return enrolledCount; }

    void enrollStudent(const string &studentID)
    {
        if (enrolledCount < 100)
        {
            enrolledStudents[enrolledCount++] = studentID;
        }
    }

    virtual void displayInfo() const
    {
        cout << "Course ID: " << courseID << ", Name: " << courseName
             << ", Credits: " << credits << ", Enrolled: " << enrolledCount << endl;
    }

    virtual void conductClass() = 0;
    virtual string getCourseType() const = 0;
    virtual ~Course() {}
};

// lecture class
class LectureCourse : public Course
{
private:
    string attendancePolicy;
    string lectureHall;

public:
    LectureCourse(const string &id, const string &name, int credits, const string &policy, const string &hall)
        : Course(id, name, credits, LECTURE_COURSE), attendancePolicy(policy), lectureHall(hall) {}

    void setAttendancePolicy(const string &policy) { attendancePolicy = policy; }
    void setLectureHall(const string &hall) { lectureHall = hall; }

    void displayInfo() const override
    {
        Course::displayInfo();
        cout << "Type: Lecture Course, Hall: " << lectureHall
             << ", Attendance Policy: " << attendancePolicy << endl;
    }

    void conductClass() override
    {
        cout << "Conducting lecture for " << courseName << " in " << lectureHall << endl;
    }

    string getCourseType() const override { return "Lecture Course"; }
};

// lab class
class LabCourse : public Course
{
private:
    string labEquipmentList[50];
    int equipmentCount;
    string labRoom;

public:
    LabCourse(const string &id, const string &name, int credits, const string &room)
        : Course(id, name, credits, LAB_COURSE), equipmentCount(0), labRoom(room) {}

    void addEquipment(const string &equipment)
    {
        if (equipmentCount < 50)
        {
            labEquipmentList[equipmentCount++] = equipment;
        }
    }

    void setLabRoom(const string &room) { labRoom = room; }

    void displayInfo() const override
    {
        Course::displayInfo();
        cout << "Type: Lab Course, Lab Room: " << labRoom
             << ", Equipment Count: " << equipmentCount << endl;
    }

    void conductClass() override
    {
        cout << "Conducting lab session for " << courseName << " in " << labRoom << endl;
    }

    string getCourseType() const override { return "Lab Course"; }
};

// online class
class OnlineCourse : public Course
{
private:
    string virtualPlatformLink;
    string recordingLink;
    bool liveSession;

public:
    OnlineCourse(const string &id, const string &name, int credits, const string &platform)
        : Course(id, name, credits, ONLINE_COURSE), virtualPlatformLink(platform), liveSession(false) {}

    void setVirtualPlatformLink(const string &link) { virtualPlatformLink = link; }
    void setRecordingLink(const string &link) { recordingLink = link; }
    void setLiveSession(bool live) { liveSession = live; }

    void displayInfo() const override
    {
        Course::displayInfo();
        cout << "Type: Online Course, Platform: " << virtualPlatformLink
             << ", Live Session: " << (liveSession ? "Yes" : "No") << endl;
    }

    void conductClass() override
    {
        cout << "Conducting online session for " << courseName << " via " << virtualPlatformLink << endl;
    }

    string getCourseType() const override { return "Online Course"; }
};

// event class
class Event
{
private:
    string eventID;
    string eventTitle;
    string eventDate;
    string eventTime;
    string location;
    int eventType;
    string description;
    string targetAudience[100];
    int audienceCount;

public:
    Event(const string &id, const string &title, const string &date, const string &time,
          const string &loc, int type, const string &desc)
        : eventID(id), eventTitle(title), eventDate(date), eventTime(time),
          location(loc), eventType(type), description(desc), audienceCount(0) {}

    void addTargetAudience(const string &audience)
    {
        if (audienceCount < 100)
        {
            targetAudience[audienceCount++] = audience;
        }
    }

    void displayInfo() const
    {
        cout << "Event ID: " << eventID << ", Title: " << eventTitle << endl;
        cout << "Date: " << eventDate << ", Time: " << eventTime << ", Location: " << location << endl;
        cout << "Type: ";
        switch (eventType)
        {
        case SEMINAR:
            cout << "Seminar";
            break;
        case WORKSHOP:
            cout << "Workshop";
            break;
        case EXAMINATION:
            cout << "Examination";
            break;
        case ANNOUNCEMENT:
            cout << "Announcement";
            break;
        }
        cout << endl
             << "Description: " << description << endl;
    }

    void notifyParticipants() const
    {
        cout << "Notifying " << audienceCount << " participants about " << eventTitle << endl;
    }
};

// payment class
class PaymentManager
{
private:
    TransactionRecord transactions[1000];
    int transactionCount;

public:
    PaymentManager() : transactionCount(0) {}

    void recordTransaction(const string &id, const string &type, double amount, const string &date, const string &description)
    {
        if (transactionCount < 1000)
        {
            transactions[transactionCount++] = TransactionRecord(id, type, amount, date, description);
        }
    }

    void displayTransactionHistory() const
    {
        cout << "=== TRANSACTION HISTORY ===" << endl;
        for (int i = 0; i < transactionCount; i++)
        {
            cout << "ID: " << transactions[i].transactionID
                 << ", Type: " << transactions[i].type
                 << ", Amount: $" << transactions[i].amount
                 << ", Date: " << transactions[i].date << endl;
        }
    }

    double calculateTotalRevenue() const
    {
        double total = 0.0;
        for (int i = 0; i < transactionCount; i++)
        {
            if (transactions[i].type == "tuition" || transactions[i].type == "fees")
            {
                total += transactions[i].amount;
            }
        }
        return total;
    }

    double calculateTotalExpenses() const
    {
        double total = 0.0;
        for (int i = 0; i < transactionCount; i++)
        {
            if (transactions[i].type == "salary" || transactions[i].type == "grant" ||
                transactions[i].type == "scholarship")
            {
                total += transactions[i].amount;
            }
        }
        return total;
    }
};

// exam class
class ExaminationManager
{
private:
    string examSchedules[100];
    int scheduleCount;
    ExamResult examResults[500];
    int resultsCount;
    string gradingCriteria[50];
    int criteriaCount;
    string invigilationAssignments[100];
    int assignmentCount;

public:
    ExaminationManager() : scheduleCount(0), resultsCount(0), criteriaCount(0), assignmentCount(0) {}

    void scheduleExam(const string &schedule)
    {
        if (scheduleCount < 100)
        {
            examSchedules[scheduleCount++] = schedule;
        }
    }

    void recordExamResult(const string &studentID, const string &courseID, double marks, const string &grade)
    {
        if (resultsCount < 500)
        {
            examResults[resultsCount++] = ExamResult(studentID, courseID, marks, grade);
        }
    }

    void addGradingCriteria(const string &criteria)
    {
        if (criteriaCount < 50)
        {
            gradingCriteria[criteriaCount++] = criteria;
        }
    }

    void assignInvigilator(const string &assignment)
    {
        if (assignmentCount < 100)
        {
            invigilationAssignments[assignmentCount++] = assignment;
        }
    }

    void displayExamSchedule() const
    {
        cout << "=== EXAM SCHEDULE ===" << endl;
        for (int i = 0; i < scheduleCount; i++)
        {
            cout << examSchedules[i] << endl;
        }
    }

    void displayResults(const string &studentID) const
    {
        cout << "\n=== EXAM RESULTS FOR STUDENT " << studentID << " ===" << endl;
        for (int i = 0; i < resultsCount; i++)
        {
            if (examResults[i].studentID == studentID)
            {
                cout << "Course: " << examResults[i].courseID
                     << ", Marks: " << examResults[i].marks
                     << ", Grade: " << examResults[i].grade << endl;
            }
        }
    }
};

// project research class
class ResearchProject
{
private:
    string projectID;
    string projectTitle;
    string fundingSource;
    string participatingFaculty[20];
    int facultyCount;
    string enrolledStudents[50];
    int studentCount;
    double budget;
    string startDate;
    string endDate;

public:
    ResearchProject(const string &id, const string &title, const string &funding, double b,
                    const string &start, const string &end)
        : projectID(id), projectTitle(title), fundingSource(funding), facultyCount(0),
          studentCount(0), budget(b), startDate(start), endDate(end) {}

    void addFaculty(const string &facultyID)
    {
        if (facultyCount < 20)
        {
            participatingFaculty[facultyCount++] = facultyID;
        }
    }

    void addStudent(const string &studentID)
    {
        if (studentCount < 50)
        {
            enrolledStudents[studentCount++] = studentID;
        }
    }

    void displayInfo() const
    {
        cout << "Project ID: " << projectID << ", Title: " << projectTitle << endl;
        cout << "Funding Source: " << fundingSource << ", Budget: $" << budget << endl;
        cout << "Duration: " << startDate << " to " << endDate << endl;
        cout << "Faculty: " << facultyCount << ", Students: " << studentCount << endl;
    }

    string getProjectID() const { return projectID; }
    string getProjectTitle() const { return projectTitle; }
};

// main class for flex
class FLEX
{
private:
    Person *persons[2000];
    int personCount;
    Course *courses[500];
    int courseCount;
    Event *events[200];
    int eventCount;
    ResearchProject *projects[100];
    int projectCount;
    PaymentManager paymentManager;
    ExaminationManager examManager;

public:
    FLEX() : personCount(0), courseCount(0), eventCount(0), projectCount(0) {}

    // adding person
    void addPerson(Person *person)
    {
        if (personCount < 2000)
        {
            persons[personCount++] = person;
        }
    }
    // adding course
    void addCourse(Course *course)
    {
        if (courseCount < 500)
        {
            courses[courseCount++] = course;
        }
    }
    // adding event
    void addEvent(Event *event)
    {
        if (eventCount < 200)
        {
            events[eventCount++] = event;
        }
    }
    // adding research project
    void addResearchProject(ResearchProject *project)
    {
        if (projectCount < 100)
        {
            projects[projectCount++] = project;
        }
    }

    // displaying all the persons
    void displayAllPersons() const
    {
        cout << "=== ALL PERSONS ===" << endl;
        for (int i = 0; i < personCount; i++)
        {
            persons[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }
    // displaying all the records
    void displayAllCourses() const
    {
        cout << "=== ALL COURSES ===" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            courses[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }
    // displaying all the events
    void displayAllEvents() const
    {
        cout << "=== ALL EVENTS ===" << endl;
        for (int i = 0; i < eventCount; i++)
        {
            events[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }
    // displaying all the research project
    void displayResearchProjects() const
    {
        cout << "=== RESEARCH PROJECTS ===" << endl;
        for (int i = 0; i < projectCount; i++)
        {
            projects[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    // finding person
    Person *findPerson(const string &id) const
    {
        for (int i = 0; i < personCount; i++)
        {
            if (persons[i]->getID() == id)
            {
                return persons[i];
            }
        }
        return nullptr;
    }
    // finding course
    Course *findCourse(const string &id) const
    {
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i]->getCourseID() == id)
            {
                return courses[i];
            }
        }
        return nullptr;
    }

    // enrolling student in course
    void enrollStudentInCourse(const string &studentID, const string &courseID)
    {
        Person *person = findPerson(studentID);
        Course *course = findCourse(courseID);

        if (person && course && person->getRole() == STUDENT)
        {
            Student *student = dynamic_cast<Student *>(person);
            if (student)
            {
                student->enrollCourse(courseID);
                course->enrollStudent(studentID);
                cout << "Student " << studentID << " enrolled in course " << courseID << endl;
            }
        }
        else
        {
            cout << "Enrollment failed. Student or course not found." << endl;
        }
    }

    // recording payment methods
    void recordPayment(const string &id, const string &type, double amount, const string &date, const string &description)
    {
        paymentManager.recordTransaction(id, type, amount, date, description);
    }
    // displaying financial summary
    void displayFinancialSummary() const
    {
        cout << "\n=== FINANCIAL SUMMARY ===" << endl;
        cout << "Total Revenue: $" << paymentManager.calculateTotalRevenue() << endl;
        cout << "Total Expenses: $" << paymentManager.calculateTotalExpenses() << endl;
        cout << "Net Balance: $" << (paymentManager.calculateTotalRevenue() - paymentManager.calculateTotalExpenses()) << endl;
    }

    // scheduling exams
    void scheduleExam(const string &schedule)
    {
        examManager.scheduleExam(schedule);
    }
    // recording exam results
    void recordExamResult(const string &studentID, const string &courseID, double marks, const string &grade)
    {
        examManager.recordExamResult(studentID, courseID, marks, grade);
    }

    // generating system reports
    void generateSystemReport() const
    {
        cout << "=== FLEX UNIVERSITY SYSTEM REPORT ===" << endl;
        cout << "Total Persons: " << personCount << endl;

        int facultyCount = 0, studentCount = 0, adminCount = 0;
        for (int i = 0; i < personCount; i++)
        {
            switch (persons[i]->getRole())
            {
            case FACULTY:
                facultyCount++;
                break;
            case STUDENT:
                studentCount++;
                break;
            case ADMIN_STAFF:
                adminCount++;
                break;
            }
        }

        cout << "Faculty Members: " << facultyCount << endl;
        cout << "Students: " << studentCount << endl;
        cout << "Administrative Staff: " << adminCount << endl;
        cout << "Total Courses: " << courseCount << endl;
        cout << "Total Events: " << eventCount << endl;
        cout << "Research Projects: " << projectCount << endl;
    }
    // destroying person, course, event and project
    ~FLEX()
    {
        for (int i = 0; i < personCount; i++)
            delete persons[i];
        for (int i = 0; i < courseCount; i++)
            delete courses[i];
        for (int i = 0; i < eventCount; i++)
            delete events[i];
        for (int i = 0; i < projectCount; i++)
            delete projects[i];
    }
};

// main menu
void displayMenu()
{
    cout << "=====================================================" << endl;
    cout << "          FLEX UNIVERSITY MANAGEMENT SYSTEM" << endl;
    cout << "=====================================================" << endl;
    cout << "1.  Add Faculty" << endl;
    cout << "2.  Add Student" << endl;
    cout << "3.  Add Administrative Staff" << endl;
    cout << "4.  Add Course" << endl;
    cout << "5.  Add Event" << endl;
    cout << "6.  Add Research Project" << endl;
    cout << "7.  Enroll Student in Course" << endl;
    cout << "8.  Record Payment" << endl;
    cout << "9.  Schedule Exam" << endl;
    cout << "10. Record Exam Result" << endl;
    cout << "11. View All Persons" << endl;
    cout << "12. View All Courses" << endl;
    cout << "13. View All Events" << endl;
    cout << "14. View Research Projects" << endl;
    cout << "15. View Financial Summary" << endl;
    cout << "16. Generate System Report" << endl;
    cout << "0.  Exit System" << endl;
    cout << "=====================================================" << endl;
    cout << "Enter your choice: ";
}

// to add faculty member
void addFacultyInteractive(FLEX &system)
{
    string id, name, contact, hours;
    cout << "=== ADD FACULTY ===" << endl;
    cout << "Enter Faculty ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Contact Info: ";
    getline(cin, contact);
    cout << "Enter Office Hours: ";
    getline(cin, hours);

    system.addPerson(new Faculty(id, name, contact, hours));
    cout << "Faculty added successfully!" << endl;
}
// to add student
void addStudentInteractive(FLEX &system)
{
    string id, name, contact;
    cout << "=== ADD STUDENT ===" << endl;
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Contact Info: ";
    getline(cin, contact);

    system.addPerson(new Student(id, name, contact));
    cout << "Student added successfully!" << endl;
}
// to add course
void addCourseInteractive(FLEX &system)
{
    string id, name;
    int credits, type;
    cout << "=== ADD COURSE ===" << endl;
    cout << "Enter Course ID: ";
    cin >> id;
    cout << "Enter Course Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Credits: ";
    cin >> credits;

    cout << "Select Course Type:" << endl;
    cout << "1. Lecture Course" << endl;
    cout << "2. Lab Course" << endl;
    cout << "3. Online Course" << endl;
    cout << "Enter choice (1-3): ";
    cin >> type;

    switch (type)
    {
    case 1:
    {
        string policy, hall;
        cout << "Enter Attendance Policy: ";
        cin.ignore();
        getline(cin, policy);
        cout << "Enter Lecture Hall: ";
        getline(cin, hall);
        system.addCourse(new LectureCourse(id, name, credits, policy, hall));
        break;
    }
    case 2:
    {
        string room;
        cout << "Enter Lab Room: ";
        cin.ignore();
        getline(cin, room);
        system.addCourse(new LabCourse(id, name, credits, room));
        break;
    }
    case 3:
    {
        string platform;
        cout << "Enter Virtual Platform: ";
        cin.ignore();
        getline(cin, platform);
        system.addCourse(new OnlineCourse(id, name, credits, platform));
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "Course added successfully!" << endl;
}
// main fucntion
int main()
{
    FLEX system;
    int choice;

    cout << "=====================================================" << endl;
    cout << "    WELCOME TO FLEX UNIVERSITY MANAGEMENT SYSTEM" << endl;
    cout << "=====================================================" << endl;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addFacultyInteractive(system);
            break;
        case 2:
            addStudentInteractive(system);
            break;
        case 3:
        {
            string id, name, contact, schedule;
            cout << "=== ADD ADMINISTRATIVE STAFF ===" << endl;
            cout << "Enter Staff ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Contact Info: ";
            getline(cin, contact);
            cout << "Enter Work Schedule: ";
            getline(cin, schedule);
            system.addPerson(new AdministrativeStaff(id, name, contact, schedule));
            cout << "Administrative staff added successfully!" << endl;
            break;
        }
        case 4:
            addCourseInteractive(system);
            break;
        case 5:
        {
            string id, title, date, time, location, description;
            int type;
            cout << "=== ADD EVENT ===" << endl;
            cout << "Enter Event ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Date: ";
            getline(cin, date);
            cout << "Enter Time: ";
            getline(cin, time);
            cout << "Enter Location: ";
            getline(cin, location);
            cout << "Select Event Type (0-Seminar, 1-Workshop, 2-Exam, 3-Announcement): ";
            cin >> type;
            cout << "Enter Description: ";
            cin.ignore();
            getline(cin, description);
            system.addEvent(new Event(id, title, date, time, location, type, description));
            cout << "Event added successfully!" << endl;
            break;
        }
        case 6:
        {
            string id, title, funding, start, end;
            double budget;
            cout << "=== ADD RESEARCH PROJECT ===" << endl;
            cout << "Enter Project ID: ";
            cin >> id;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Funding Source: ";
            getline(cin, funding);
            cout << "Enter Budget: ";
            cin >> budget;
            cout << "Enter Start Date: ";
            cin.ignore();
            getline(cin, start);
            cout << "Enter End Date: ";
            getline(cin, end);
            system.addResearchProject(new ResearchProject(id, title, funding, budget, start, end));
            cout << "Research project added successfully!" << endl;
            break;
        }
        case 7:
        {
            string studentID, courseID;
            cout << "=== ENROLL STUDENT IN COURSE ===" << endl;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            system.enrollStudentInCourse(studentID, courseID);
            break;
        }
        case 8:
        {
            string id, type, date, description;
            double amount;
            cout << "=== RECORD PAYMENT ===" << endl;
            cout << "Enter Transaction ID: ";
            cin >> id;
            cout << "Enter Type (tuition/salary/grant/scholarship): ";
            cin >> type;
            cout << "Enter Amount: ";
            cin >> amount;
            cout << "Enter Date: ";
            cin.ignore();
            getline(cin, date);
            cout << "Enter Description: ";
            getline(cin, description);
            system.recordPayment(id, type, amount, date, description);
            cout << "Payment recorded successfully!" << endl;
            break;
        }
        case 9:
        {
            string schedule;
            cout << "=== SCHEDULE EXAM ===" << endl;
            cout << "Enter Exam Schedule: ";
            cin.ignore();
            getline(cin, schedule);
            system.scheduleExam(schedule);
            cout << "Exam scheduled successfully!" << endl;
            break;
        }
        case 10:
        {
            string studentID, courseID, grade;
            double marks;
            cout << "=== RECORD EXAM RESULT ===" << endl;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            cout << "Enter Marks: ";
            cin >> marks;
            cout << "Enter Grade: ";
            cin >> grade;
            system.recordExamResult(studentID, courseID, marks, grade);
            cout << "Exam result recorded successfully!" << endl;
            break;
        }
        case 11:
            system.displayAllPersons();
            break;
        case 12:
            system.displayAllCourses();
            break;
        case 13:
            system.displayAllEvents();
            break;
        case 14:
            system.displayResearchProjects();
            break;
        case 15:
            system.displayFinancialSummary();
            break;
        case 16:
            system.generateSystemReport();
            break;
        case 0:
            cout << "Thank you for using FLEX University Management System!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 0-16." << endl;
        }

        if (choice != 0)
        {
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}