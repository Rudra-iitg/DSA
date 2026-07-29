#include <iostream>
#include <string>
using namespace std;

// ============================================
// BASE CLASS (Parent)
// ============================================
class Person {
protected:                    // Protected: Accessible by derived classes
    string name;
    int age;

public:
    // Constructor
    Person(string n = "", int a = 0) {
        name = n;
        age = a;
        cout << ">>> Person constructor called" << endl;
    }

    // Method of Base class
    void speak() {
        cout << name << " says: Hello!" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// ============================================
// DERIVED CLASS (Child) - Single Inheritance
// ============================================
class Student : public Person {   // <-- INHERITS from Person
private:
    int rollNo;
    string grade;

public:
    // Constructor (calls Person constructor)
    Student(string n, int a, int r, string g) : Person(n, a) {
        rollNo = r;
        grade = g;
        cout << ">>> Student constructor called" << endl;
    }

    // New method specific to Student
    void study() {
        cout << name << " is studying hard!" << endl;
    }

    // Override base class method
    void display() {
        Person::display();  // Call base class display
        cout << ", Roll No: " << rollNo << ", Grade: " << grade << endl;
    }
};

// ============================================
// ANOTHER DERIVED CLASS
// ============================================
class Teacher : public Person {   // <-- INHERITS from Person
private:
    string subject;
    double salary;

public:
    Teacher(string n, int a, string sub, double sal) : Person(n, a) {
        subject = sub;
        salary = sal;
        cout << ">>> Teacher constructor called" << endl;
    }

    void teach() {
        cout << name << " teaches " << subject << endl;
    }

    void display() {
        Person::display();
        cout << ", Subject: " << subject << ", Salary: $" << salary << endl;
    }
};

// ============================================
// MULTILEVEL INHERITANCE EXAMPLE
// ============================================
class GradStudent : public Student {  // Inherits from Student
private:
    string researchTopic;

public:
    GradStudent(string n, int a, int r, string g, string topic) 
        : Student(n, a, r, g) {
        researchTopic = topic;
        cout << ">>> GradStudent constructor called" << endl;
    }

    void doResearch() {
        cout << name << " is researching: " << researchTopic << endl;
    }
};

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    cout << "=== Creating Student Object ===" << endl;
    Student s1("Alice", 20, 101, "A");
    s1.display();      // Calls Student's display (overridden)
    s1.speak();        // Inherited from Person
    s1.study();        // Student's own method

    cout << "\n=== Creating Teacher Object ===" << endl;
    Teacher t1("Bob", 45, "Math", 50000);
    t1.display();
    t1.speak();        // Inherited from Person
    t1.teach();        // Teacher's own method

    cout << "\n=== Creating GradStudent Object (Multilevel) ===" << endl;
    GradStudent g1("Charlie", 25, 201, "A+", "AI");
    g1.display();      // Inherited from Student
    g1.speak();        // Inherited from Person (via Student)
    g1.study();        // Inherited from Student
    g1.doResearch();   // GradStudent's own method

    cout << "\n=== Access Modes Summary ===" << endl;
    /*
    ┌─────────────┬────────────────┬────────────────┬────────────────┐
    │ Base Class  │ Public Inherit │ Private Inherit│ Protected Inherit│
    ├─────────────┼────────────────┼────────────────┼────────────────┤
    │ public      │ public         │ private        │ protected      │
    │ protected   │ protected      │ private        │ protected      │
    │ private     │ NOT ACCESSIBLE │ NOT ACCESSIBLE │ NOT ACCESSIBLE │
    └─────────────┴────────────────┴────────────────┴────────────────┘
    */

    return 0;
}