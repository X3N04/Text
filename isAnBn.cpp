#include <cassert> 
#include <cstdlib> 
#include <string> 
#include <iostream> 
template<class ItemType> 
class ListInterface 
{ 
public: 
virtual void setEntry(int position, const ItemType& newEntry) = 0; 
virtual ItemType getEntry(int position) const = 0; 
virtual void insert(const ItemType& newEntry) = 0; 
virtual bool remove(const ItemType & newEntry) = 0; 
virtual bool isEmpty() const = 0; 
virtual int getLength() const = 0; 
virtual void clear() = 0; 
}; 
template<class ItemType> 
class Node 
{ 
private: 
ItemType item; 
Node<ItemType>* next; 
public: 
Node(); 
Node(const ItemType& anItem); 
Node(const ItemType& anItem, Node<ItemType>* nextNodePtr); 
void setItem(const ItemType& anItem); 
void setNext(Node<ItemType>* nextNodePtr); 
ItemType getItem() const; 
Node<ItemType>* getNext() const; 
}; 
template<class ItemType> 
Node<ItemType>::Node() : next(nullptr) 
{ 
} 
template<class ItemType> 
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) 
{ 
} 
template<class ItemType> 
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : 
item(anItem), next(nextNodePtr) 
{ 
} 
template<class ItemType> 
void Node<ItemType>::setItem(const ItemType& anItem) 
{ 
item = anItem; 
} 
template<class ItemType> 
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) 
{ 
next = nextNodePtr; 
} 
template<class ItemType> 
ItemType Node<ItemType>::getItem() const 
{ 
return item; 
} 
template<class ItemType> 
Node<ItemType>* Node<ItemType>::getNext() const 
{ 
return next; 
} 
template<class ItemType> 
class LinkedList : public ListInterface<ItemType> 
{ 
private: 
Node<ItemType>* headPtr; 
int itemCount; 
static Node<ItemType>* free; 
Node<ItemType>* trav_p; 
bool TraverseOK; 
Node<ItemType>* getListEl(void); 
Node<ItemType>* getNodeAt(int position) const; 
void printRevHelper(Node<ItemType>* curPtr) const; 
void freeListEl(Node<ItemType>* curPtr); 
public: 
LinkedList(); 
LinkedList(const LinkedList<ItemType>& aList); 
virtual ~LinkedList(); 
void setEntry(int position, const ItemType& newEntry); 
ItemType getEntry(int position) const; 
int getLength() const; 
bool isInList(const ItemType& key); 
Node<ItemType>* traverse(bool first); 
void insert(const ItemType& newEntry); 
bool remove(const ItemType & newEntry); 
bool isEmpty() const; 
void clear(void); 
void printList(int direction) const; 
static int Forward; 
static int Reverse; 
}; 
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::free = nullptr; 
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::getListEl(void) 
{ 
Node<ItemType>* curPtr; 
if (free != nullptr) 
{ 
curPtr = free; 
free = free->getNext(); 
} 
else 
curPtr = new Node<ItemType>; 
curPtr->setItem(NULL); 
curPtr->setNext(nullptr); 
return curPtr; 
} 
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const 
{ 
assert((position >= 1) && (position <= itemCount)); 
Node<ItemType>* curPtr = headPtr; 
for (int skip = 1; skip < position; skip++) 
curPtr = curPtr->getNext(); 
return curPtr; 
} 
template<class ItemType> 
void LinkedList<ItemType>::printRevHelper(Node<ItemType>* curPtr) const 
{ 
if (curPtr != NULL) 
{ 
printRevHelper(curPtr->getNext()); 
std::cout << curPtr->getItem() << std::endl; 
} 
} 
template<class ItemType> 
void LinkedList<ItemType>::freeListEl(Node<ItemType>* curPtr) 
{ 
curPtr->setItem(NULL); 
curPtr->setNext(free); 
free = curPtr; 
} 
 
 
template<class ItemType> 
int LinkedList<ItemType>::Forward = 1; 
template<class ItemType> 
int LinkedList<ItemType>::Reverse = -1; 
 
 
template<class ItemType> 
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) 
{ 
} 
template<class ItemType> 
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) 
{ 
if(headPtr != nullptr) clear(); 
Node<ItemType> *curPtr = aList.headPtr; 
while (curPtr != NULL) 
{ 
insert(itemCount, curPtr->getItem()); 
curPtr = curPtr->getNext(); 
} 
} 
template<class ItemType> 
LinkedList<ItemType>::~LinkedList() 
{ 
clear(); 
} 
template<class ItemType> 
void LinkedList<ItemType>::setEntry(int position, const ItemType & newEntry) 
{ 
bool ableToSet = (position >= 1) && (position <= itemCount); 
if (ableToSet) 
{ 
Node<ItemType>* nodePtr = getNodeAt(position); 
nodePtr->setItem(newEntry); 
} 
else 
{ 
std::string message = "setEntry() called with an empty list or "; 
message = message + "invalid position."; 
std::cout << ("Precondition Violated Exception: " + message); 
exit(EXIT_FAILURE); 
} 
} 
template<class ItemType> 
ItemType LinkedList<ItemType>::getEntry(int position) const 
{ 
bool ableToGet = (position >= 1) && (position <= itemCount); 
if (ableToGet) 
{ 
Node<ItemType>* nodePtr = getNodeAt(position); 
return nodePtr->getItem(); 
} 
else 
{ 
std::string message = "getEntry() called with an empty list or "; 
message = message + "invalid position."; 
std::cout << ("Precondition Violated Exception: " + message); 
exit(EXIT_FAILURE); 
} 
} 
template<class ItemType> 
int LinkedList<ItemType>::getLength() const 
{ 
return itemCount; 
} 
template<class ItemType> 
bool LinkedList<ItemType>::isInList(const ItemType & entry) 
{ 
Node<ItemType>* curPtr = headPtr; 
while (curPtr != nullptr && curPtr->getItem() < entry) 
{ 
curPtr = curPtr->getNext(); 
} 
return curPtr != nullptr && curPtr->getItem() == entry; 
} 
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::traverse(bool first) 
{ 
if (first) 
{ 
trav_p = headPtr; 
TraverseOK = true; 
} 
else if (TraverseOK == false) 
{ 
return nullptr; 
} 
else if (trav_p != nullptr) 
{ 
trav_p = trav_p->getNext(); 
} 
if (trav_p != nullptr) 
{ 
return trav_p; 
} 
return nullptr; 
} 
template<class ItemType> 
void LinkedList<ItemType>::insert(const ItemType& newEntry) 
{ 
Node<ItemType>* newNode = getListEl(); 
Node<ItemType>* curPtr, *prevPtr; 
TraverseOK = false; 
newNode->setItem(newEntry); 
for (curPtr = headPtr, prevPtr = nullptr; 
curPtr != nullptr && curPtr->getItem() < newNode->getItem(); 
prevPtr = curPtr, curPtr = curPtr->getNext()); 
if (prevPtr == nullptr) 
{ 
newNode->setNext(headPtr); 
headPtr = newNode; 
} 
else 
{ 
newNode->setNext(curPtr); 
prevPtr->setNext(newNode); 
} 
++itemCount; 
} 
template<class ItemType> 
bool LinkedList<ItemType>::remove(const ItemType& newEntry) 
{ 
Node<ItemType>* curPtr = headPtr, *prevPtr = nullptr; 
while (curPtr != nullptr && curPtr->getItem() != newEntry) 
{ 
prevPtr = curPtr; 
curPtr = curPtr->getNext(); 
} 
if (curPtr == nullptr) 
return false; 
else if (prevPtr == nullptr) 
headPtr = headPtr->getNext(); 
else 
prevPtr->setNext(curPtr->getNext()); 
--itemCount; 
freeListEl(curPtr); 
TraverseOK = false; 
return true; 
} 
template<class ItemType> 
bool LinkedList<ItemType>::isEmpty() const 
{ 
return itemCount == 0; 
} 
 
 
template<class ItemType> 
void LinkedList<ItemType>::clear() 
{ 
Node<ItemType>* curPtr = headPtr, *prevPtr; 
while (curPtr != nullptr) 
{ 
prevPtr = curPtr; 
curPtr = curPtr->getNext(); 
delete prevPtr; 
} 
curPtr = free; 
while (curPtr != nullptr) 
{ 
prevPtr = curPtr; 
curPtr = curPtr->getNext(); 
delete prevPtr; 
} 
free = nullptr; 
} 
template<class ItemType> 
void  LinkedList<ItemType>::printList(int direction) const 
{ 
Node<ItemType>* curPtr = headPtr; 
if (direction == Forward) 
{ 
while (curPtr != NULL) 
{ 
std::cout << curPtr->getItem() << std::endl; 
curPtr = curPtr->getNext(); 
} 
} 
else 
printRevHelper(curPtr); 
} 
 
 
#if 0 // #if 1 to compile as a standalone program, not a library 
int main() 
{ 
int choice = 0, key; 
Node<int> d, *e; 
LinkedList<int> list; 
while (choice != 8) 
{ 
std::cout << "\n\n1. add an element\n" 
<< "2. see if an element exists\n" 
<< "3. remove an element by key\n" 
<< "4. print forward\n" 
<< "5. print reverse\n" 
<< "6. traverse (first)\n" 
<< "7. traverse (next)\n" 
<< "8. quit\n" << "\nEnter choice : " 
<< std::flush; 
std::cin >> choice; 
switch (choice) 
{ 
case 1: 
std::cout << "Enter key : " << std::flush; 
std::cin >> key; 
d.setItem(key); 
e = new Node<int>; 
(*e) = d; 
list.insert(e->getItem()); 
break; 
case 2: 
std::cout << "Enter key : " << std::flush; 
std::cin >> key; 
if (list.isInList(key)) 
std::cout << "Key " << key << " is in the list\n"; 
else 
std::cout << "Nah man, the key " << key << " isn't there\n"; 
break; 
case 3: 
std::cout << "Enter key : " << std::flush; 
std::cin >> key; 
if (list.remove(key)) 
std::cout << "Node has been removed" << std::endl; 
else 
std::cout << "Failed to remove node" << std::endl; 
break; 
case 4: 
list.printList(list.Forward); 
break; 
case 5: 
list.printList(list.Reverse); 
break; 
case 6: 
e = list.traverse(true); 
if (e == nullptr) 
std::cout << "There is no first key!\n"; 
else 
std::cout << "Node has data " << e->getItem() << std::endl; 
break; 
case 7: 
e = list.traverse(false); 
if (e == nullptr) 
std::cout << "There is no next key!\n"; 
else 
std::cout << "Node has data " << e->getItem() << std::endl; 
break; 
case 8: std::cout << "Goodbye!" << std::endl; 
break; 
default: 
std::cout << "Do you even numbers, bro???\n\n" << std::flush; 
} 
} 
return 0; 
} 
#endif 
 
 
 

