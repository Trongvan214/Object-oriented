//Author: Trong Van
//Student ID: x454v285
//Programming Number: 7
//filename: SLList.hpp
//Description: functions for the link list 

#ifndef __SLLIST__
#define __SLLIST__

// It's a template class
template<class T>
class SLList {
public:
    //iterator define
    class iterator;

    SLList();                       // Default Constructor
    SLList(T a);                    // Constructor that takes first item for list
    ~SLList();                      // Destructor
                                    // It shall not be possible to create copies or assign directly to the linked list
    iterator begin();               // begin()
    iterator end();                 // end()
    bool empty();                   // A function called empty that lets you know if the list is empty or not
    int size();                     // A function called size that tells you how big the list is
    T front();                      // A function called front that returns the key value of the front node (return by value only)
    void push_back(T _data);        // A function called push_back that adds a key to the end of the list
    iterator erase(iterator it);    // A function called erase that takes as a parameter an iterator that indicates the Node to be erased. 
                                    // It returns an iterator that indicates the position after the node that was erased
			                        // See the list class function of the same name at cplusplus.com
    void clear();                   // A function called clear that erases the list, but leaves the list object in a viable state
private:
    // Declare your Node class privately here
    class Node {
    public:
        Node(T _data);
        void changeNext(Node* newPointer);
        Node* returnNext();
        T returnData();
    private:
        T data;
        Node* next;
    };

    // A pointer to the first node in the list
    Node *head;
    int len; 
};


// Probably a good spot for the iterator class declaration
// It is contained within a template class
template<class T>
class SLList<T>::iterator {
public:
    iterator(Node* n);                      // Constructor that takes a Node pointer
    iterator operator ++(int);
    iterator& operator ++();                // Overloaded postfix and prefix increment operators
                                            // No decrements, this will be a forward-only iterator
    T operator *();                         // Overloaded de-reference operator, returns by value only
    friend bool operator ==(iterator it1, iterator it2){   // Overloaded equality operator
        return it1.nPtr == it2.nPtr;
    }      
    bool operator !=(iterator it);          // Overloaded inequality operator
private:
    Node* nPtr;                         // Node pointer (resource being managed by the iterator)
};

// Implementations of classes go here

//===================================================================================================================//
                                            //SLList member functions
//===================================================================================================================//

//--------------------------------default constructor ----------------------------//
template<class T>
SLList<T>::SLList()
    :head(nullptr)
    ,len(0)
{}

//--------------------------------constructor 1 parameter ----------------------------//
template<class T>
SLList<T>::SLList(T a)
    :head(nullptr)
    ,len(0)
{
    //start with a node
    Node* ptr = new Node(a);
    head = ptr;
    len++;
}

//--------------------------------destructor ----------------------------//
template<class T>
SLList<T>::~SLList(){
    delete head;
    head = nullptr;
}

//--------------------------------begin function ----------------------------//
template<class T>
typename SLList<T>::iterator SLList<T>::begin(){
    return iterator(head);
}

//--------------------------------end function ----------------------------//
template<class T>
typename SLList<T>::iterator SLList<T>::end(){
    return iterator(0);
}

//--------------------------------empty function ----------------------------//
template<class T>
bool SLList<T>::empty(){
    return head == nullptr;
}

//--------------------------------size function ----------------------------//
template<class T>
int SLList<T>::size(){
    return len;
}

//--------------------------------front function ----------------------------//
template<class T>
T SLList<T>::front(){
    if(head != nullptr)
        return head->returnData();
    else 
        return T();
}

//--------------------------------push_back function ----------------------------//
template<class T>
void SLList<T>::push_back(T _data){
    if (head != nullptr){
        Node* iter = head;
        //go to the end of linklist
        for (;iter->returnNext() != nullptr; iter = iter->returnNext());
        //put node there
        iter->changeNext( new Node(_data) );
    }
    //first node in 
    else{
        head = new Node(_data);
    } 
    //increase total nodes
    len++;
}

//--------------------------------erase function ----------------------------//
template<class T>
typename SLList<T>::iterator SLList<T>::erase(iterator it){
    Node* iter = head;
    Node *prev = nullptr;
    while(iter != nullptr && iter->returnData() != *it)
    {
            prev = iter;
            iter = iter->returnNext();
    }
    //hit the data
    if(iter != nullptr)
    {
        //first node case
        if(prev == nullptr)
        {
            //Deleting first node and connect it if any
            head = iter->returnNext();
        }
        else
        {
            //connect prev node to iter next
            prev->changeNext(iter->returnNext());
        }
        delete iter;
        //decrease node count
        len--;
    }
    //return node head pointing at
    if(prev == nullptr){
        return iterator(head);
    }
    return iterator(prev->returnNext());
}

//--------------------------------clear function ----------------------------//
template<class T>
void SLList<T>::clear(){
    Node* iter = head;
    Node* prev = head;
    while(iter != nullptr)
    {
        iter = iter->returnNext();
        delete prev;
        prev = iter;
    }
    head = nullptr;
    len = 0;
}
//===================================================================================================================//
                                            //iterator member functions
//===================================================================================================================//

//--------------------------------constructor 1 parameter ----------------------------//
template<class T>
SLList<T>::iterator::iterator(Node* n)
    :nPtr(n)
{};

//--------------------------------operator ++() --------------------------------//
template<class T>
typename SLList<T>::iterator& SLList<T>::iterator::operator ++(){
    if(nPtr != nullptr){
        nPtr = nPtr->returnNext();
    }
    return *this;
}

//--------------------------------operator ++(int) --------------------------------//
template<class T>
typename SLList<T>::iterator SLList<T>::iterator::operator ++(int){
    iterator temp = *this;
    ++*this;
    return temp;
}

//--------------------------------operator * --------------------------------//
template<class T>
T SLList<T>::iterator::operator *(){
    return this->nPtr->returnData();
}

//--------------------------------operator != --------------------------------//
template<class T>
bool SLList<T>::iterator::operator != (iterator it){
    return !((*this) == it);
}

//===================================================================================================================//
                                            //Node member functions
//===================================================================================================================//

//--------------------------------constructor 1 parameter --------------------------------//
template<class T>
SLList<T>::Node::Node(T _data)
    :data(_data)
    ,next(nullptr)
{};

//--------------------------------changeNext function --------------------------------//
template<class T>
void SLList<T>::Node::changeNext(Node* newPointer){
    next = newPointer;
}

//--------------------------------returnNext function --------------------------------//
template<class T>
typename SLList<T>::Node* SLList<T>::Node::returnNext(){
    return next;
}

//--------------------------------returnData function --------------------------------//
template<class T>
T SLList<T>::Node::returnData(){
    return data;
}

#endif