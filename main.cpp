#include "Employee.h"
#include <iostream>
using namespace std;

/*
 * ============================================================================
 * MAIN PROGRAM: TechSolutions Employee Management System
 * ============================================================================
 * Demonstrates:
 * 1. Constructor with initializer list
 * 2. Copy constructor (deep copy)
 * 3. This pointer usage
 * 4. Const and static members
 * 5. Dynamic object allocation
 * 6. Passing objects to functions
 * 7. Returning objects from functions
 * 8. Shallow vs Deep copy difference
 * ============================================================================
 */

void demonstrateShallowVsDeepCopy();

int main() {
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════╗\n";
    cout << "║    TECHSOLUTIONS EMPLOYEE MANAGEMENT SYSTEM               ║\n";
    cout << "║    Assignment 2 - OOP Concepts Demonstration              ║\n";
    cout << "╚═══════════════════════════════════════════════════════════╝\n\n";
    
    // ========================================================================
    // 1. CONSTRUCTOR with INITIALIZER LIST
    // ========================================================================
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "1. CREATING EMPLOYEES (Constructor with Initializer List)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    Employee emp1("Ahmad Ali", 101, 50000.0);
    Employee emp2("Sara Khan", 102, 60000.0);
    Employee emp3("Usman Tariq", 103, 55000.0);
    
    // ========================================================================
    // 2. CONST FUNCTIONS - Display employee information
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "2. DISPLAYING EMPLOYEE INFO (Const Functions)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    emp1.displayInfo();
    emp2.displayInfo();
    emp3.displayInfo();
    
    // ========================================================================
    // 3. STATIC FUNCTION - Show total employees and company name
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "3. STATIC MEMBERS (Company Name & Total Employees)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    cout << "Company Name: " << Employee::getCompanyName() << endl;
    cout << "Total Employees: " << Employee::getTotalEmployees() << endl;
    
    // ========================================================================
    // 4. THIS POINTER - Modify employee data using setters
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "4. USING 'this' POINTER (Setter Functions)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    cout << "→ Updating employee 1's name using 'this' pointer...\n";
    emp1.setName("Ahmad Ali Khan");
    emp1.setSalary(55000.0);
    emp1.displayInfo();
    
    // ========================================================================
    // 5. DYNAMIC OBJECT ALLOCATION using pointers
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "5. DYNAMIC OBJECT ALLOCATION (Using Pointers)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    Employee* emp4 = new Employee("Fatima Ahmed", 104, 65000.0);
    cout << "→ Dynamic employee created using 'new' operator\n";
    emp4->displayInfo();
    
    // ========================================================================
    // 6. PASSING OBJECT AS FUNCTION ARGUMENT
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "6. PASSING OBJECTS AS FUNCTION ARGUMENTS\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    emp1.compareWith(emp2);  // Passing emp2 as argument to emp1's function
    
    // ========================================================================
    // 7. RETURNING OBJECT FROM FUNCTION
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "7. RETURNING OBJECT FROM FUNCTION\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    Employee emp5 = emp2.createCopy();  // Function returns an Employee object
    cout << "→ Returned object displayed:\n";
    emp5.displayInfo();
    
    // ========================================================================
    // 8. COPY CONSTRUCTOR (Deep Copy Demonstration)
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "8. COPY CONSTRUCTOR & DEEP COPY\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    cout << "→ Creating a copy of emp3 using copy constructor...\n";
    Employee emp6 = emp3;  // Copy constructor called
    
    cout << "\nOriginal Employee (emp3):\n";
    emp3.displayInfo();
    
    cout << "\nCopied Employee (emp6):\n";
    emp6.displayInfo();
    
    // ========================================================================
    // 9. SHALLOW vs DEEP COPY DEMONSTRATION
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "9. SHALLOW vs DEEP COPY DIFFERENCE\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    
    demonstrateShallowVsDeepCopy();
    
    // ========================================================================
    // FINAL STATUS
    // ========================================================================
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "FINAL STATUS\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Total Active Employees: " << Employee::getTotalEmployees() << endl;
    
    // Clean up dynamic memory
    delete emp4;
    cout << "\n→ Dynamic employee deleted (memory freed)\n";
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "PROGRAM COMPLETED SUCCESSFULLY ✓\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    
    return 0;
}

// ============================================================================
// FUNCTION: Demonstrate Shallow vs Deep Copy
// ============================================================================
void demonstrateShallowVsDeepCopy() {
    cout << "\n┌─────────────────────────────────────────────────────┐\n";
    cout << "│  DEMONSTRATION: What if we didn't use deep copy?   │\n";
    cout << "└─────────────────────────────────────────────────────┘\n\n";
    
    cout << "→ Creating original employee...\n";
    Employee original("Bilal Hassan", 201, 70000.0);
    original.displayInfo();
    
    cout << "\n→ Creating a DEEP COPY of the employee...\n";
    Employee deepCopy = original;  // Deep copy constructor called
    
    cout << "\n→ Modifying ORIGINAL employee's salary to $80,000...\n";
    original.modifySalary(80000.0);
    
    cout << "\n┌─────────────────────────────────────────────────────┐\n";
    cout << "│  RESULT: Deep Copy Creates Separate Memory         │\n";
    cout << "└─────────────────────────────────────────────────────┘\n";
    
    cout << "\nOriginal Employee (MODIFIED):\n";
    cout << "Salary: $" << original.getSalary() << endl;
    
    cout << "\nDeep Copy Employee (UNCHANGED):\n";
    cout << "Salary: $" << deepCopy.getSalary() << endl;
    
    cout << "\n✓ CONCLUSION:\n";
    cout << "  → Original salary: $80,000 (modified)\n";
    cout << "  → Deep copy salary: $70,000 (unchanged)\n";
    cout << "  → Each object has its own separate memory!\n";
    
    cout << "\n⚠ What would happen with SHALLOW COPY?\n";
    cout << "  → Both would share the same memory\n";
    cout << "  → Modifying one would affect the other\n";
    cout << "  → This is why we use DEEP COPY with pointers!\n";
}