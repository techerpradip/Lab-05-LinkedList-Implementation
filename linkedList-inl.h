/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

// Constuctor method: initializes the private fields.
template <typename T> LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr; 
    this->size =0;
}

// Destrcutor method: to delete the objects in the linked list.
template <typename T> LinkedList<T>::~LinkedList() {
    if(size != 0){
        for(int i=0; i<this->size; i++) {
            LinkedListNode<T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }
}

// Confirms that there are this->size elements in the list.
template <typename T> void LinkedList<T>::checkInvariants() {
    int tracker = 0; //a tracker to keep track of size as we traverse.
    if(this->head != nullptr){
        LinkedListNode<T>* current = this->head;
        tracker = 1;
        while(current->next != nullptr) {
            current = current->next;
            tracker += 1;
        }
    }
    if(tracker != this->size) {
        throw runtime_error("Invariant doesn't hold.");
    }
}

// Returns the size of the list.
template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

// Determines whether the list is empty.
template <typename T> bool LinkedList<T>::isEmpty() {
    if(this->size == 0){
        return true;
    } else{
        return false;
    }
}

// Retruns the first element of the list.
template <typename T> T LinkedList<T>::getFirst() {
    if(this->size != 0){
        return this->head->value;
    } else{
        throw runtime_error("List is Empty.");
    }
}
 // Returns the last element of the list.
template <typename T> T LinkedList<T>::getLast() {
     if(this->size != 0){
        return this->tail->value;
    } else{
        throw runtime_error("List is Empty.");
    }
}

// Returns the element in the given index in the list.
template <typename T> T LinkedList<T>::get(int index) {
    if(index >= 0 && index < this->size) { // confirms the validity of index.
        int tracker = 0;
        LinkedListNode<T>* current = this->head;
        while(tracker < index) {
            current = current->next;
            tracker += 1;
        }
        return current->value;
    } else {
        throw runtime_error("index i is out of bounds.");
    }
}

// Inserts a value at the beginning of this list.
template <typename T> void LinkedList<T>::insertFirst(T value) {
    if(this->size > 0){
        LinkedListNode<T>* new_element = new LinkedListNode<T>(value, nullptr);
        LinkedListNode<T>* instance = this->head;
        this->head = new_element;
        new_element->next = instance;
        this->size += 1;
    }if(this->size == 0){
        LinkedListNode<T>* new_element = new LinkedListNode<T>(value, nullptr);
        this->head = new_element;
        this->tail = new_element;
        this->size += 1;
    }
}

// Inserts the value at the end of this list.
template <typename T> void LinkedList<T>::insertLast(T value) {
    if(this->size > 0){
        LinkedListNode<T>* new_element = new LinkedListNode<T>(value, nullptr);
        this->tail->next = new_element;
        this->tail = new_element;
        this->size += 1;
    }if(this->size == 0){
        LinkedListNode<T>* new_element = new LinkedListNode<T>(value, nullptr);
        this->head = new_element;
        this->tail = new_element;
        this->size += 1;
    }
}

// Removes and returns the first element from the list.
template <typename T> T LinkedList<T>::removeFirst() {
    LinkedListNode<T>* instance = this->head;
    if(this->size == 1){
        this->head = nullptr;
        this->tail = nullptr;
        T first_value = instance->value;
        delete instance; // deletes the first node.
        this->size -= 1;
        return first_value; // returns the first element.
    }if(this->size > 1) {
        this->head = this->head->next;
        T first_value = instance->value;
        delete instance; // deletes the first node.
        this->size -= 1;
        return first_value; // returns the first element.
    } else{
        throw runtime_error("List is Empty.");
    }
}

// Removes and returns the last element from the list.
template <typename T> T LinkedList<T>::removeLast() {
    if(this->size == 1) {
        LinkedListNode<T>* final_instance = this->head;
            this->head = nullptr;
            this->tail = nullptr;
            T last_value = final_instance->value;
            delete final_instance; // deletes the last node.
            this->size -= 1;
            return last_value; // returns the last element.
    } if(this->size > 1) {
        LinkedListNode<T>* current = this->head;
        while(current->next != this->tail) {
            current = current->next;
        }
        LinkedListNode<T>* final_instance = this->tail;
        this->tail = current;
        this->tail->next = nullptr;
        T last_value = final_instance->value;
        delete final_instance; // deletes the last node.
        this->size -= 1;
        return last_value; // returns the last element.
    } else{
        throw runtime_error("List is Empty.");
    }
}