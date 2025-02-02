#include<cstring>

#include<iostream>

/*
 *	Class:
 *	Class is a blueprint for creating objects.
 *	It is a collection of data members and member functions.
 *	Data members are the variables that store the data.
 *	Member functions are the functions that operate on the data members.

 *  Object:
 *  Object is an instance of a class.
 *
 * Abstraction:
 *  Abstraction is the process of hiding the complex details and showing only the essential features of an object.
 *  It is the process of representing the essential features without including the background details or explanations.
 *  Ex: A car is an object. We know that it has 4 wheels, engine, etc. But we don't know the complex details of the car.
 *  When we create a class, we make some data members private and some public. It is also kind of abstraction. 
 *  We are hiding the complex details and showing only the essential features of the car.
 * We have abstract class in C++ which is a class has some properties and methods which are not implemented. The classes which inherit this abstract class must implement those methods.
 * 
 * Encapsulation:
 *  Encapsulation is the process of binding the data and the functions that operate on the data together.
 *  It is the process of wrapping the data (variables) and the functions that operate on the data (methods) together as a single unit.
 *  Ex: let us take a example of a class String. You can see that the data member str is private and we are intializing it with a constructor which is a member function.
 *  This is called encapsulation. We are binding the data and the functions that operate on the data together.
 * 
 * 
 * Polymorphism:
 * Polymorphism is the ability of an object to take on many forms.
 * 
 * There are two types of polymorphism in C++:
 * 1. Compile time polymorphism (Function overloading and operator overloading):
 * -> This type of polymorphism is calles as compile time polymorphism because the function is resolved at compile time(which means at the time of compilation compiler will know which function to call).
 * -> Function overloading is a process of having more than one function with the same name but different parameters.
 * -> Operator overloading is a process of overloading the operators to perform different operations.
 * 	For example: In class String we have defined different types of constructors, it is called function overloading.
 * 
 * 2. Runtime polymorphism (Virtual functions)
 * -> This type of polymorphism is calles as runtime polymorphism because the function is resolved at runtime.
 * -> In c++ it can be achieved by using virtual functions. I will add details about virtual functions in below code where I will use virtual functions.
 * */
class String{
	char *str;
public:
	/*
	 *	C++ compiler provied constructors, but those are generic constructors.
	 *	The perpose of defining constructor is to define behavior as we wish i.e initialize object as we wish.
	 *	
	 *	These are the default methods provided by the compiler:
	 *	1. Default constructor
	 *	2. Copy constructor
	 *	3. Copy assignment operator
	 *	4. Move constructor
	 *	5. Move assignment operator
	 *	6. Destructor

	 * 	Note:
	 * 	When we define any of the methods, compiler will not provide default methods.
	 * */

	/*
	 *	Default constructor:
	 *	When a object of the class created without any parameters, this constructor will be called
	 *  EX: String s; Here we are creating a object of the class without any parameters. This function will be called.
	 * 
	 * */
	String(){
	    std::cout<<"Default constructor called\n";
		str=nullptr;	
	}

	/*
	 *	Parameterized constructor:
	 *	When a object of the class created with parameters, this constructor will be called
	 *  
	 *  EX: String s("Hello"); Here we are creating a object of the class with a parameter.
	 * */
	String(const char str[]){
	    std::cout<<"Parameterized constructor called\n";
	    this->str=new char[strlen(str)];// "this" is a pointer to the current object. 
	    strcpy(this->str,str);
	}

	/*
	 *	Copy constructor:
	 *	When a object of the class created by copying another object, this constructor will be called
	 *	
	 *	Note:
	 *	1. If we don't define copy constructor, compiler will provide default copy constructor
	 *	2. If we define copy constructor, compiler will not provide default copy constructor

	 *  Purpose for copy constructor:
	 *  When we want to create a new object as a copy of an existing object, we use copy constructor.
	 *  
	 * You might have question about the copy constructor, when compiler provides default copy constructor, why we need to define our own copy constructor?
	 * -> The default copy constructor is a shallow copy constructor, it only copies the pointer to the same memory location.
	 * 	    In this case if we use default copy constructor, both the objects will point to the same memory location.
	 * 	    If we change the value of one object, it will reflect in the other object.
	 * -> If we want to create a new object as a copy of an existing object, we need to define our own copy constructor. This is called deep copy constructor.
	 *      If we define our own copy constructor, we need to allocate new memory for the new object and copy the value from the existing object.
	 *      In this case if we change the value of one object, it will not reflect in the other object.
	 * 
	 *  EX: 
	 * 	String s1("Hello"); 
	 * String s2(s1); Here we are creating a new object as a copy of an existing object. If we don't define copy constructor, default copy constructor will be called and 
	 * it will copy the pointer to the same memory location. i.e this.str=other.str;
	 * */
	String(String& other){
	    std::cout<<"Copy constructor called\n";
		str=new char[strlen(other.str)];
		strcpy(this->str,other.str);
	}

	/*
	 *	Copy assignment operator:
	 *	When a object of the class created by copying another object, this constructor will be called
	 * 
	 *	Purpose of copy assignment operator:
	 *	When we want to assign the value of one object to another object, we use copy assignment operator.
	 *  It is similar to copy constructor.
	 *  EX: 
	 *  String s1("Hello");
	 *  String s2;
	 *  s2=s1; Here we are assigning the value of s1 to s2. If we don't define copy assignment operator, default assignemnt operator will be called and 
	 *  it will copy content from s1 to s2. i.e this.str=other.str;
	 * */
	String& operator=(String& other){
	    std::cout<<"Copy assignment operator called\n";
		if(str!=nullptr){
			delete[] str;
		}
		str=new char[strlen(other.str)];
		strcpy(this->str,other.str);
		return *this;
	}

	/*
	 *	Move constructor:
	 *	When a object of the class created by moving another object, this constructor will be called
	 * 
	 *	Purpose of move constructor:
	 *	When we want to transfer the ownership of an object to another object, we use move constructor. 
	 * 	C++ 11 introduced move constructor to optimize the performance of the program.
	 *  This is possible because of the move semantics. 
	 * 	Due to move semantics, the source object is left in a valid but unspecified state.
	 *  And it makes the source object eligible for destruction.
	 * 
	 *  EX: 
	 *  String s1("Hello");
	 *  String s2(std::move(s1)); Here we are transferring the ownership of s1 to s2.
	 * */
	String(String&& other){
	    std::cout<<"Move constructor called\n";
		str=other.str;
		other.str=nullptr;
	}

	/*
	 *	Move assignment operator:
	 *	When a object of the class created by moving another object, this constructor will be called
	 * 
	 *	Purpose of move assignment operator:
	 *	When we want to transfer the ownership of an object to another object, we use move assignment operator. This is similar to move constructor.
	 *  EX: 
	 *  String s1("Hello");
	 *  String s2;
	 *  s2=std::move(s1; Here we are assigning the value of s1 to s2. If we don't define move assignment operator, default assignemnt operator will be called and 
	 *  it will copy content from s1 to s2. i.e this.str=other.str;
	 * */
	String& operator=(String&& other){
	    std::cout<<"Move Assignment operator called\n";
		if(str!=nullptr){
			delete[] str;
		}
		str=other.str;
		other.str=nullptr;
		return *this;
	}

	/*
	 *	Destructor:
	 *	When a object of the class destroyed, this destructor will be called
	 * 
	 *	Purpose of destructor:
	 *	When we want to release the memory allocated for the object, we use destructor.
	 *  EX: 
	 *  String s("Hello");
	 * 	when the created object goes out of scope, destructor will be called.
	 *  s.~String(); Here we are destroying the object s. If we don't define destructor, default destructor will be called and 
	 *  it will release the memory allocated for the object. i.e delete[] str;
	 * */
	~String(){
	    std::cout<<"Distructor called\n";
		if(this->str!=nullptr){
			delete[] str;
		}
	}
			
};

/*
* Inheritance:
* Inheritance is a mechanism in which a new class is created by adding new properties and methods to an existing class.
* The new class is called derived class and the existing class is called base class.
* The derived class inherits the properties and methods of the base class.
* The derived class can add new properties and methods of its own.
* The derived class can also override the properties and methods of the base class.
* 	
* Types of inheritance:
* 1. Single inheritance
* 2. Multiple inheritance
* 3. Multi-level inheritance
* 
* More details about inheritance will be added whenever that context comes.
*/

//Lets discuss Inheritance in with an example.

class parent{
private://Name is private so it can't be accessed by the child class. Child can not have father name.
	std::string parent_name;
protected://Surname is protected so it can be accessed by the child class. Child can have father surname.
	std::string surname;
public://setter and getter functions are public so they can be accessed by the child class and outside the class.
	parent(const std::string& name,const std::string& surname){
		this->parent_name=name;
		this->surname=surname;
	}
	void set_name(std::string name){
		parent_name=name;
	}
	void set_surname(std::string name){
		surname=name;
	}
	std::string& get_name(){
		return parent_name;
	}
	std::string& get_surname(){
		return surname;
	}
};

// Single inheritance
class child:public parent{
private:
	std::string child_name;
public:
	child(const std::string& name,const std::string& surname,const std::string& child_name):parent(name,surname),child_name(child_name){// Here we aere using initializer list to initialize the variables.
	}	

};

/*
* C++ allown multiple inheritance. In multiple inheritance, a class can inherit from more than one class.
* Because of multiple inheritance, a class can have multiple parent classes.
* Because of multiple inheritance, we see a ambiguity problem. To solve this problem, we use virtual inheritance.
* Let us see an example of multiple inheritance.
*
*/

class grandparent {
public:
	void display() {
		std::cout << "Grandparent\n";
	}
};

class parent1:public grandparent {
};

class parent2:public grandparent {
};


/*
commeninting below lines, because it will give an error because of ambiguity. But is a example for error

class child1 : public parent1, public parent2 {
};

*/

/*
*	As you can see child1 class is inheriting from parent1 and parent2. Both parent1 and parent2 inherited from the grandparent.
*	When we create an object of child1 class and call display() method, it will give an error because of ambiguity.
*	To solve this problem, we use virtual inheritance.
*/

class parent3 : public virtual grandparent {

};
class parent4 : public virtual grandparent {

};

class child2 : public parent3, public parent4 {};

/*
* Now when we create an object of child2 class and call display() method, it will not give an error because of virtual inheritance.
* Basically what virtual key word does is, it will create only one copy of the grandparent for child2 instance(It merges the copy). So there will not be any ambiguity.
*/