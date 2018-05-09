//Author: Trong Van
//Student ID: x454v285
//Programming Number: extra 2
//filename: PFAString.hpp
//Description:  declare the vector class 

#ifndef PFASTRING_HPP
#define PFASTRING_HPP

#include <string>

class PFAString {
public:
    PFAString();
    PFAString(int capacity);
    PFAString(int capacity,  std::string initValue);
    PFAString(const PFAString& other);          //copy 
    PFAString(PFAString&& other);               //move
    ~PFAString();                               //destructor
    int capacity() const;
    int size() const;
    void push_back(const std::string &value); 
    void pop_back(); 
    void resize(int size); // size only
    void resize(int size, std::string newValue); //size and string
    void empty_array(); 
    std::string& operator[](int index);
    PFAString& operator =(const PFAString &v);   //overload copy operator =
    PFAString& operator =(PFAString &&v);        //overload move operator =
    bool operator == (const PFAString &v);
    bool operator != (const PFAString &v);
    bool operator < (const PFAString &v);
    bool operator <= (const PFAString &v);
    bool operator > (const PFAString &v);
    bool operator >= (const PFAString &v);
    //extra function and on the bottom in .cpp
    std::string& at(int i);
private:
    int _size;
    int _capacity;               // Capacity and size are two different things
    std::string *arr;
    //private helper function 
    void expand_capacity();
};
#endif