#include "Employee.h"

// ============================================================================
// STATIC MEMBER INITIALIZATION
// ============================================================================
int Employee::totalEmployees = 0;
const string Employee::companyName = "TechSolutions";

// ============================================================================
// CONSTRUCTOR with Initializer List
// ============================================================================
// Purpose: Initialize employee data and allocate dynamic memory for salary
Employee::Employee(string empName, int empID, double empSalary) 
    : name(empName), employeeID(empID) {
    
    // Dynamic memory allocation for salary
    salary = new double;
    *salary = empSalary;
    
    // Increment total employee count
    totalEmployees++;
    
    cout << "✓ Constructor called: Employee created - " << name << endl;
}

// ============================================================================
// COPY CONSTRUCTOR (DEEP COPY)
// ============================================================================
// Purpose: Create a new employee by copying another (with separate memory)
Employee::Employee(const Employee& other) 
    : name(other.name), employeeID(other.employeeID) {
    
    // Deep copy: Allocate new memory and copy the value
    salary = new double;
    *salary = *(other.salary);
    
    totalEmployees++;
    
    cout << "✓ Copy Constructor called: Deep copy created for " << name << endl;
}

// ============================================================================
// DESTRUCTOR
// ============================================================================
// Purpose: Release dynamically allocated memory
Employee::~Employee() {
    delete salary;
    totalEmployees--;
    cout << "✗ Destructor called: Employee removed - " << name << endl;
}

// ============================================================================
// CONST FUNCTION: Display employee information
// ============================================================================
// Note: 'const' ensures this function won't modify any data members
void Employee::displayInfo() const {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "  Company: " << companyName << endl;
    cout << "  Employee Name: " << name << endl;
    cout << "  Employee ID: " << employeeID << endl;
    cout << "  Salary: $" << *salary << endl;
    cout << "╚══════════════════════════════════════╝\n";
}

// ============================================================================
// CONST FUNCTION: Get salary
// ============================================================================
double Employee::getSalary() const {
    return *salary;
}

// ============================================================================
// SETTER with 'this' POINTER
// ============================================================================
// Purpose: Distinguish between parameter 'name' and member variable 'name'
void Employee::setName(string name) {
    this->name = name;  // 'this' pointer differentiates parameter from member
}

void Employee::setEmployeeID(int employeeID) {
    this->employeeID = employeeID;  // Using 'this' pointer
}

void Employee::setSalary(double salary) {
    *(this->salary) = salary;  // Using 'this' pointer with dynamic memory
}

// ============================================================================
// STATIC FUNCTION: Get total number of employees
// ============================================================================
int Employee::getTotalEmployees() {
    return totalEmployees;
}

// ============================================================================
// STATIC FUNCTION: Get company name
// ============================================================================
string Employee::getCompanyName() {
    return companyName;
}

// ============================================================================
// OBJECT HANDLING: Passing object as function argument
// ============================================================================
void Employee::compareWith(Employee emp) const {
    cout << "\n→ Comparing salaries...\n";
    if (*salary > *emp.salary) {
        cout << name << " earns more than " << emp.name << endl;
    } else if (*salary < *emp.salary) {
        cout << emp.name << " earns more than " << name << endl;
    } else {
        cout << "Both employees earn the same salary.\n";
    }
}

// ============================================================================
// OBJECT HANDLING: Returning an object from function
// ============================================================================
Employee Employee::createCopy() const {
    cout << "\n→ Creating a copy using copy constructor...\n";
    return Employee(*this);  // Returns a copy of current object
}

// ============================================================================
// FUNCTION: Modify salary (for demonstrating shallow vs deep copy)
// ============================================================================
void Employee::modifySalary(double newSalary) {
    *salary = newSalary;
    cout << "→ Salary modified to: $" << *salary << " for " << name << endl;
}