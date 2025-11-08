#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

/*
 * ============================================================================
 * CLASS: Employee
 * ============================================================================
 * Purpose: Manages employee information for TechSolutions company
 * 
 * Features:
 * - Constructor with initializer list
 * - Copy constructor (deep copy)
 * - Const functions for data display
 * - Static members and functions
 * - Dynamic memory management
 * - This pointer usage
 * ============================================================================
 */

class Employee {
private:
    // Data members
    string name;
    int employeeID;
    double* salary;  // Pointer for demonstrating deep copy
    
    // Static member: Tracks total number of employees
    static int totalEmployees;
    
    // Const member: Company name (constant for all employees)
    static const string companyName;

public:
    // ========================================================================
    // CONSTRUCTOR with initializer list
    // ========================================================================
    Employee(string empName, int empID, double empSalary);
    
    // ========================================================================
    // COPY CONSTRUCTOR (Deep Copy)
    // ========================================================================
    Employee(const Employee& other);
    
    // ========================================================================
    // DESTRUCTOR
    // ========================================================================
    ~Employee();
    
    // ========================================================================
    // CONST FUNCTIONS (Cannot modify data members)
    // ========================================================================
    void displayInfo() const;
    double getSalary() const;
    
    // ========================================================================
    // SETTER FUNCTIONS (Demonstrate 'this' pointer)
    // ========================================================================
    void setName(string name);
    void setEmployeeID(int employeeID);
    void setSalary(double salary);
    
    // ========================================================================
    // STATIC FUNCTION (Access static members)
    // ========================================================================
    static int getTotalEmployees();
    static string getCompanyName();
    
    // ========================================================================
    // OBJECT HANDLING FUNCTIONS
    // ========================================================================
    // Function that accepts object as parameter
    void compareWith(Employee emp) const;
    
    // Function that returns an object
    Employee createCopy() const;
    
    // Function to demonstrate shallow vs deep copy
    void modifySalary(double newSalary);
};

#endif