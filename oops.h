#include<cstring>

#include<iostream>
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
	    this->str=new char[strlen(str)];
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

