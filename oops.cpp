/* Member Function in C++ Classes
There are 2 ways to define a member function:

1. Inside class definition
2. Outside class definition

* We have to first declare the function prototype in the class definition.
* Then we have to use the scope resolution:: operator along with the class name and function name.
---------------------------------------------
Constructors
Constructors are special class members which are called by the compiler every time an object of that class is instantiated. Constructors have the same name as the class and may be defined inside or outside the class definition

* Default Constructors: The constructor that takes no argument is called default constructor.
* Parameterized Constructors: This type of constructor takes the arguments to initialize the data members.
* Copy Constructors: Copy constructor creates the object from an already existing object by copying it.
* Move Constructor: The move constructor also creates the object from an already existing object but by moving it.
-------------------------------------------------
Destructors
Destructor is another special member function that is called by the compiler when the scope of the object ends. It deallocates all the memory previously used by the object of the class so that there will be no memory leaks. The destructor also have the same name as the class but with tilde(~) as prefix.

--------------------------------------------------
A friend class 
can access private and protected members of other classes in which it is declared as a friend.

Friend Function
They are not the member functions of the class but can access and manipulate the private and protected members of that class for they are declared as friends.

A friend function can be:

A global function
A member function of another class

friend return_type function_name (arguments);    // for a global function
            or
friend return_type class_name::function_name (arguments);    // for a member function of another class

A friend function can be declared in any section of the class i.e. public or private or protected.

Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.

Friendship is not inherited.

--------------------------------------------------

Static Data Members

* Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created.
* It is initialized before any object of this class is created, even before the main starts outside the class itself.
* It is visible can be controlled with the class access specifiers.
* Its lifetime is the entire program.

We can access the static data member without creating the instance of the class. Just remember that we need to initialize it beforehand.

1. Accessing static data member using Class Name and Scope Resolution Operator
2. Accessing static data member through Objects

Yes, static member functions can be defined in a class. They can access static data members but cannot access non-static data members or this pointer.

------------------------------------------------------

This Pointer 

* In C++, the this pointer is an implicit pointer available within all non-static member functions of a class. It points to the object for which the member function is called, allowing member functions to access the invoking object's data members and other member functions.

* The this pointer is a constant pointer that holds the address of the current object. It is automatically passed to all non-static member functions as a hidden argument.

Why Use the this Pointer:
Disambiguation:

When a parameter or a local variable has the same name as a class member, the this pointer is used to distinguish between them.

Example(int value) {
    this->value = value; // 'this->value' refers to the class member, 'value' refers to the constructor parameter
}


Method Chaining:

The this pointer can be used to return the current object from a member function, enabling method chaining.

Example& incrementValue() {
    this->value++;
    return *this; // Returning the current object
}


Self-Referencing:

The this pointer allows an object to pass itself to another function.

void printValue(Example* obj) {
    std::cout << "Value: " << obj->value << std::endl;
}

void callPrint() {
    printValue(this); // Passing the current object
}

-------------------------------------------------------

*/

