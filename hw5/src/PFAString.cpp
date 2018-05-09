//Author: Trong Van
//Student ID: x454v285
//Programming Number: 5
//filename: PFAString.cpp
//Description:  implementation member function

#include <iostream>
#include <stdexcept>
#include "PFAString.hpp"

//----------------Default constructor----------------//
PFAString::PFAString()
    :_size(0)
    , _capacity(0)
    , arr(nullptr)
{};
//----------------Constructor that sets capacity ONLY----------------//
PFAString::PFAString(int capacity)
    : _size(0)
    , _capacity(0)
{
    if(capacity > 0){
        _size = capacity;
        _capacity = capacity;
    }
    arr = new std::string[_capacity];
    //set all values to NULL
    std::fill_n(arr, _capacity, std::string());
};
//----------------Constructor that sets capacity and initializes all elements----------------//
PFAString::PFAString(int capacity,  std::string initValue)
    : _size(0)
    , _capacity(0)
{
    if(capacity > 0){
        _size = capacity;
        _capacity = capacity;
    }
    arr = new std::string[_capacity];
    //set all values to initValue
    std::fill_n(arr, _capacity, initValue);
}
//----------------Copy Constructor----------------//
PFAString::PFAString(const PFAString& other)
    : _size(other._size)
    , _capacity(other._size)

{
    arr = new std::string[_capacity];
    for(int i = 0; i < other._size; i++){
        arr[i] = other.arr[i]; 
    }
}
//----------------Move Constructor----------------//
PFAString::PFAString(PFAString&& other)
    : _size(other._size)
    , _capacity(other._capacity)

{
    arr = new std::string[_capacity];
    for(int i = 0; i < other._size; i++){
        arr[i] = other.arr[i]; 
    }
    other = PFAString();
}
//----------------Destructor----------------//
PFAString::~PFAString(){
    if (arr) {
        delete[] arr;
    }
    arr = nullptr;
}
//----------------overload copy operator =----------------//
PFAString& PFAString::operator =(const PFAString &v){
    if(this != &v){
        if (arr != nullptr)
        {
            delete[] arr;
        }
        _size = v._size;
        _capacity = v._size;
        arr = new std::string[_capacity];
        for(int i = 0;i < _size; i++){
            arr[i] = v.arr[i];
        }
    }
    return *this;
}
//----------------overload move operator =----------------//
PFAString& PFAString::operator =(PFAString &&v){
    if(this != &v){
        if (arr != nullptr)
        {
            delete[] arr;
        }
        _size = v._size;
        _capacity = v._capacity;
        arr = new std::string[_capacity];
        for(int i = 0;i < _size; i++){
            arr[i] = v.arr[i];
        }
    }
    return *this;
}
//----------------operator overload ==----------------//
bool PFAString::operator == (const PFAString &v){
    if(_size != v._size){
        return false;
    }
    for(int i = 0; i < v._size; i++){
        if(arr[i] != v.arr[i]){
            return false;
        }
    }
    return true;
}
//----------------operator overload <----------------//
bool PFAString::operator < (const PFAString &v){
    int otherSize = v._size;
    for(int i = 0; i < _size; i++){
        if(i+1 > otherSize){
            return false;
        }
        else if(arr[i] < v.arr[i]){
            return true;
        }
    }
    //case where this object have less size than given object
    if(otherSize - _size > 0){
        return true;
    }
    return false;
}
//----------------operator overload !=----------------//
bool PFAString::operator != (const PFAString &v){
    return !(*this == v);
}
//----------------operator overload <=----------------//
bool PFAString::operator <= (const PFAString &v){
    return (*this < v) || (*this == v);
}
//----------------operator overload >-----------------//
bool PFAString::operator > (const PFAString &v){
    int otherSize = v._size;
    for(int i = 0; i < _size; i++){
        if(arr[i] > v.arr[i] || i+1 > otherSize){
            return true;
        }
    }
    return false;
}
//----------------operator overload >=----------------//
bool PFAString::operator >= (const PFAString &v){
    return !(*this < v);
}
//----------------size----------------//
int PFAString::size() const{  
    return _size;
}
//----------------capacity----------------//
int PFAString::capacity() const{
    return _capacity;
}
//----------------resize with size -----------------//
void PFAString::resize(int size){
    _size = size;
    std::string *temp = new std::string[_capacity];
    for(int i = 0; i < _size; i++){
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}
//----------------resize with size and string----------------//
void PFAString::resize(int size, std::string newValue){
    int prevSize = _size;
    _size = size;
    _capacity = size;
    std::string *temp = new std::string[_capacity];
    if(size > prevSize){
        for(int i = 0; i < prevSize; i++){
            temp[i] = arr[i];
        }
        for(int i = prevSize;i < _size; i++){
            temp[i] = newValue;
        }
    }
    else {
        std::fill_n(temp, _size, newValue);
    }
    delete [] arr;
    arr = temp;
}
//----------------push_back----------------//
void PFAString::push_back(const std::string &value){
    if(_size+1 > _capacity){
        expand_capacity();
    }
    arr[_size] = value;
    _size++;  
}
//----------------expand_capacity----------------//
void PFAString::expand_capacity(){
    if(_capacity == 0){
        _capacity = 1;
    }
    else {
        _capacity = _size * 2;
    }
    std::string *temp = new std::string[_capacity];
    for(int i = 0; i < _size; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

//----------------operator []----------------//
std::string& PFAString::operator[](int index){
    if(index < 0){
        throw std::out_of_range("Out of range");
    }
    else if(index > _size){
        throw std::out_of_range("Out of range");
    }
    return arr[index];   
}
//========================================================================================================================//
//========================================================================================================================//
                                            //All new or modify functions 

//extra function 
std::string& PFAString::at(int i){
    return (*this)[i];
}

//modify function
//----------------pop_back----------------//
void PFAString::pop_back(){
    if(_size > 0){
        _size--; 
    }
    else {
        throw std::out_of_range("Out of range");
    }
}

//trivial exception class
class AlreadyEmptied {};

//modify function
//----------------empty_array----------------//
void PFAString::empty_array(){
    if(_size == 0){
        throw AlreadyEmptied();
    }
    _size = 0;
    delete[] arr;
    arr = new std::string[_capacity];
}