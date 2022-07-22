/*
LB, April 2022
FILE USED TO TEST WHAT LEARNED IN THE
CPP PRIMER BOOK
*/

// INCLUDES
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// DEFINES
#define IOSTREAM
#define STRING
#define VECTOR
#define ARRAYS
#define EXPRESSIONS
#define STATEMENTS
#define FUNCTIONS

// using std::cout; // to tell compiler that when we use cout it is from std
// using std::cin; // to tell compiler that when we use cin it is from std


// FUNCTIONS

size_t count_calls() {
    static size_t counter = 0; // value will persist across calls
    return ++counter;
}

// pass by VALUE
int factorial(int val) {
    int ret = 1; // local variable
    while (val > 1)
        ret *= val--; // assign ret*val and decrement val
    return ret;
}

// pass by value
void reset(int *p) {
    *p = 0; // change the value to which p points
}

// pass by REFERENCE
void reset_by_reference(int &i) {
    i = 0;
}

bool isShorter(const std::string &s1, const std::string &s2) {
    // reference parameters that are not changed inside a function should be references to CONST
    return s1.size() < s2.size();
}

// arguements passed by reference used to return more values
std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

// Managing ARRAY PARAMETERS: 
// first method is to use a marker to specify the extent of a string, for example C-style strings terminate with the null character (not reported here).

// void print_array1(int[]) equivalent to: void print_array1(int*)

// Second method: using std library conventions
void print_array(const int *beg, const int *end) {
    while (beg != end) // print every element not icluding end
        std::cout << *beg++ << " "; // print current element and advance pointer
    std::cout << std::endl;
}

// Third method: explicitly passing a size parameter
void print_array(const int *ia, size_t size) {
    for (size_t i = 0; i != size; ++i)
        std::cout << ia[i] << " ";
    std::cout << std::endl;
}

// The 2 functions above are OVERLOADED: they have the same name but different parameter lists

// inline function
inline const int is_larger(const int num1, const int num2) {
    return (num1 > num2) ? num1 : num2;
}

void print_vector_int(std::vector<int> &vec) {
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}


// ---------------------------------------- MAIN ----------------------------------------

int main() {

#ifdef IOSTREAM

    std::cout << "------------------------ IOSTREAM ------------------------" << std::endl;
    std::cout << "This is std::cout" << std::endl;
    std::cerr << "This is std::cerr" << std::endl;
    std::clog << "This is std::cerr" << std::endl;

    // size of data types (in bytes)
    std::cout << "Size of int: " << sizeof(int) << std::endl;
    std::cout << "Size of char: " << sizeof(char) << std::endl;
    std::cout << "Size of short: " << sizeof(short) << std::endl;
    std::cout << "Size of float: " << sizeof(float) << std::endl;
    std::cout << "Size of double: " << sizeof(double) << std::endl;

    std::cout << "newline\ntab\tvertical tab\vformfeed\f" << std::endl;

    float float_number = 5.34;
    // initialization
    // int int_number{float_number}; warning: narrowing conversion
    int int_number(float_number); // no warning but the number is truncated
    std::cout << int_number << std::endl;

#endif

#ifdef STRING

    std::cout << "------------------------ STRINGS ------------------------" << std::endl;
    std::string str;
    std::cout << "Insert a string (exit to terminate):\n" << std::endl;
    //std::cin >> str;
    //std::cout << "You typed:\n" << str << std::endl; // this will return only the first word

    std::string word;
    //while (std::cin >> word)  // read until end-of-file
    //    std::cout << word << std::endl;  // write each word followed by a new line


    std::string line;
    while (getline(std::cin, line)) // read entire line as a string, exit if "exit"
        if (!line.empty()) {
            if (line != "exit") {
            std::cout << line << std::endl;
            }
            else break;
    }

    std::string str2("hello world");
    // print characters in str one to a line using a RANGE FOR
    for (auto c : str2)
        std::cout << c << std::endl;

    // convert str2 to uppercase
    for (auto &c : str2) // for every char in str2 (c is a reference!)
        c = toupper(c);
    std::cout << str2 << std::endl;

    // USING ITERATORS
    for (auto it = str2.begin(); it != str2.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    std::cout << str2 << std::endl;

#endif

#ifdef VECTOR

    std::cout << "------------------------ VECTORS ------------------------" << std::endl;
    std::vector<int> emptyvec;
    std::vector<int> ivec(10,0); // 10 elements = 0
    std::vector<int> ivec2 = {3,7,4,6,3,7,10};

    ivec.push_back(11);
    // print ivec
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
    // print ivec2
    for (auto i : ivec2)
        std::cout << i << " ";
    std::cout << std::endl;
    // square all elements in ivec2
    for (auto &i : ivec2) 
        i *= i;
    // print ivec2
    for (auto i : ivec2)
        std::cout << i << " ";
    std::cout << std::endl;
    // append to ivec2 elements from 0 to 9
    for (decltype(ivec2.size()) ix = 0; ix != 10; ++ix)
        ivec2.push_back(ix);
    // print ivec2
    for (auto i : ivec2)
        std::cout << i << " ";
    std::cout << std::endl;

    // square all elements using ITERATORS
    for (auto it = ivec2.begin(); it != ivec2.end(); ++it)
    *it = (*it)*(*it);
    // print ivec2
    for (auto i : ivec2)
        std::cout << i << " ";
    std::cout << std::endl;

#endif

#ifdef ARRAYS

    std::cout << "------------------------ ARRAYS ------------------------" << std::endl;

    const unsigned size = 5; // used for size of arrays
    int int_arr[size];
    int int_arr2[size] = {0,1,-2,3,4};
    int int_arr3[] = {5,-2,5,8};

    // print elements of int_arr2
    for (auto i : int_arr2)
        std::cout << i << " ";
    std::cout << std::endl;

    // print elements of int_arr2 + 10
    for (auto &i : int_arr2) {
        i = i +10;
        std::cout << i << " ";
        }
    std::cout << std::endl;

    int *beg = std::begin(int_arr3); // begin and end are not member functions
    int *end = std::end(int_arr3);
    while (beg != end && *beg >= 0)
        ++beg;
    std::cout << "The first negative element is: " << *beg << std::endl;

    // Arrays are pointers:
    std::string nums[] = {"one","two","three"}; // array of strings
    std::string *pointer = &nums[0];
    std::string *pointer2 = nums; // equivalent to p2 = &nums[0]
    std::cout << pointer << " " << pointer2 << std::endl; // print the same memory address
    
#endif

#ifdef EXPRESSIONS

    std::cout << "------------------------ EXPRESSIONS ------------------------" << std::endl;

    int i = 0;
    std::cout << i << " " << ++i << std::endl; // the result is undefined!

    // Member access operator
    // ptr->mem = (*ptr).mem
    std::string s1 = "a string";
    std::string *point = &s1; // pointer to first el of string
    auto size_s1 = s1.size(); // member fcn of string s1
    std::cout << "Size = " << size_s1 << std::endl;
    size_s1 = (*point).size(); // size of the object to which point points
    std::cout << "Size = " << size_s1 << std::endl;
    size_s1 = point->size(); // equivalent
    std::cout << "Size = " << size_s1 << std::endl;

    // Conditional operator
    int grade = 30;
    std::string exam_result = (grade < 18) ? "fail" : "pass";
    std::cout << "The result of the exam is: " << exam_result << std::endl;

    // Static cast
    int base = 5, heigh = 3;
    double area = static_cast<double> (base*heigh)/2;
    // double area = (double) base*heigh/2; // equivalent to previous line
    std::cout << "Area = " << area << std::endl;

#endif

#ifdef STATEMENTS

    std::cout << "------------------------ STATEMENTS ------------------------" << std::endl;

    // Switch statement
    int priority = 2;

    switch (priority) {
        case 0:
            std::cout << "Low priority" << std::endl;
            break;
        case 1:
            std::cout << "Medium priority" << std::endl;
            break;
        case 2:
            std::cout << "High priority" << std::endl;
            break;
        default:
            std::cout << "Undefined priority" << std::endl;
            break;
    }

    std::vector<int> vec = {0,2,4,7,4,3,-1,4,1,0,-5,7,4,9};
    // read elements of vector and print them until a negative element is encountered
    for (auto el:vec) {
        if (el < 0)
            break; // exit the for loop
        else 
            std::cout << el << "\t";
    }
    std::cout << std::endl;

    // read elements of vector and print them omitting negative values
    for (auto el:vec) {
    if (el < 0)
        continue; // go to next iteration of the for loop
    else 
        std::cout << el << "\t";
    }
    std::cout << std::endl;
    /*
    if (vec[0] == 0)
        throw std::runtime_error("Runtime error! :)");

    try {
        //
    }
    catch (std::runtime_error err) {
        std::cout << err.what() << std::endl;
    }
    */

#endif


#ifdef FUNCTIONS

    std::cout << "------------------------ FUNCTIONS ------------------------" << std::endl;

    for (size_t i = 0; i != 10; i++)
        std::cout << "Count calls: " << count_calls() << std::endl;

    // Passing arguments by VALUE
    int num = 5;
    int fact = factorial(num);
    std::cout << "Factorial of " << num << " is " << fact <<std::endl;

    // Pointers behaviour
    int n = 0, ii = 42;
    int *p = &n, *q = &ii; // p points to n, q points to i
    std::cout << "n is " << n << " with address " << p << std::endl;
    std::cout << "n is " << *p << " with address " << p << std::endl; // same as previous line
    *p = 42; // value of n is changed
    std::cout << "n is " << n << " with address " << p << std::endl;
    p = q; // p now points to ii, values in ii and n are unchanged
    *p = 10;
    std::cout << "ii is " << ii << " with address " << p << " or, equivalently " << q << std::endl;

    // Pointer parameters (passed by value)
    int num_2 = 10;
    std::cout << "num_2 is " << num_2 << std::endl;
    reset(&num_2);
    std::cout << "num_2 after reset is " << num_2 << std::endl;


    // Passing arguments by REFERENCE
    int num_3 = 15;
    std::cout << "num_3 is " << num_3 << std::endl;
    reset_by_reference(num_3);
    std::cout << "num_3 after reset is " << num_3 << std::endl;

    std::string string1 = "First string";
    std::string string2 = "Second string, longer";
    std::cout << isShorter(string1,string2) << std::endl;

    // use pass by reference to return more values
    std::string::size_type occurs = 0;
    std::string::size_type index = find_char(string2, 'o', occurs); // same as auto index = ...
    std::cout << "First index of the character is " << index 
              << ", in the string there are " << occurs << " occurences " << std::endl;

    // an array cannot be passed by value:
    int array_to_print[] = {1,2,3};
    size_t array_size = sizeof(array_to_print)/sizeof(array_to_print[0]);
    // size_t array_size = std::end(array_to_print) - std::begin(array_to_print); // equivalent

    // the function print_array is overloaded: the compiler deduces which of the 2 we want to use based on the argument we pass
    print_array(std::begin(array_to_print), std::end(array_to_print));
    print_array(array_to_print, array_size);

    // Initializer_list ...

    // Default arguments...

    // Inline function
    std::cout << is_larger(5,8) << std::endl;

    print_vector_int(ivec2);

#endif







    return 0; // success
}