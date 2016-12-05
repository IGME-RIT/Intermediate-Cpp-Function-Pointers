/*
Function Pointers
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../header/testClass.h"
#include <iostream>
using namespace std;

// Function pointers are a helpful feature of c and c++ that allow us to pass a function as a parameter to another function.


// Say for example, you have 2 different functions:
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}


// We can set up a function that takes in a function pointer like this:
void operation(int a, int b, int functionPtr(int a, int b)) // int function(int a, int b) defines the type of function pointer that is passed in
{                                                           // in this example it will be named "functionPtr"
    int result = functionPtr(a, b); // Call the function pointer passed in.
    cout << result << endl;         // print out the resulting value.
};



int main() 
{
    {
        // To call the function, just pass in the name of a matching function to the call like this:
        cout << "Passing a function pointer as an parameter." << endl;
        cout << "operation(3, 2, add);" << endl;
        operation(3, 2, add);
        cout << "operation(3, 2, subtract);" << endl;
        operation(3, 2, subtract);
        // It's that easy!

        cin.get();
    }


    {
        cout << "Declaring, assigning, and using a function pointer." << endl;
        // Function pointers can be stored in a variable like this:
        int (*myFunctionPointer)(int a, int b);     // variable declaration
        myFunctionPointer = add;                    // assignment

        // This makes it possible to hold on to a function pointer for later use:

        cout << myFunctionPointer(55, 66) << endl;  // function call

        cin.get();
    }




    {
        // Function pointers can also point to the member function of an object.
        // This is different from pointing to a non member function, because the function also needs to be called on that specific object and type.
        cout << "Declaring, assigning, and using a function pointer to a member function." << endl;

        // A member function pointer declaration may look like this:
        void(testClass::*setVal)(int in) = &testClass::SetX;    // do (classType::*functionPointerName) to declare the name of the function pointer
                                                                // we can assign to it in the same line, (we get a pointer to the function testClass::SetX)

        testClass c;        // Now that we have a function pointer, we need an object to call this function on.


        (c.*setVal)(99);    // Calling the function looks like this. (c.*setVal) gets correct funciton on c.
                            // If c was a pointer, it would be (c->*setVal) instead


        cout << c.GetX() << endl;   // print out to verify that setVal worked.
        
        cin.get();
    }




    return 0;   // End Program.
}