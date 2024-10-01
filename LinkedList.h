#pragma once
#include <string>
#include <iostream>
using namespace std;

template<typename item_type>
struct Node {
	item_type data;
	Node* nextPtr;
	Node(const item_type& data_item, Node* next_ptr = nullptr) : data(data_item), nextPtr(next_ptr) {}
};

template<typename item_type>
class Single_Linked_List {

private: // update to protected if necessary, make public for testing purposes ONLY
	Node<item_type>* head;
	Node<item_type>* tail;
	size_t num_items; //changed from unsigned int to size_t

public:
	Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0){} //default constructor

	//Single_Linked_List(item_type);

	~Single_Linked_List() {
		Node<item_type>* tempPtr = head;
		while (tempPtr != nullptr) {
			Node<item_type>* nextPtr = tempPtr->nextPtr;
			delete tempPtr;
			tempPtr = nextPtr;
		}
		head = nullptr;
		tail = nullptr;
	}

	void push_front(const item_type& item) {
		Node<item_type>* new_node = new Node<item_type>(item, head);
		head = new_node;
		if (num_items == 0) //or you can do if tail == NULL
			tail = new_node;
		num_items++;
	}

	void push_back(const item_type& item) {
		Node<item_type>* new_node = new Node<item_type>(item);
		if (num_items == 0)
			head = new_node;
		else 
			tail->nextPtr = new_node;
		
		tail = new_node;
		num_items++;
	}

	void pop_front() {
		if (head == nullptr) //FIXME: make a try/catch block!
			throw exception("ERROR: Cannot delete node-- list is empty");
		
		if (head == tail) { //would it be more efficient to call pop_back() or vice/versa? ASK! yes!!
			delete head;
			head = nullptr;
			tail = nullptr;
			num_items--; //ADDED
			return;
		}

		Node<item_type>* delNode = head;
		head = head->nextPtr;
		delete delNode;
		delNode = nullptr;
		num_items--;
	}

	void pop_back() {
		if (head == nullptr) //FIXME: make a try/catch block!
			throw exception("ERROR: Cannot delete node-- list is empty");

		//add something to check if there's only one node
		if (head == tail) {//or do if num_items == 1
			pop_front(); //***
			return;
			/*delete head;
			head = nullptr;
			tail = nullptr;*/
		}
		else {
			//Node<item_type>* delNode = tail; placeholder not required
			Node<item_type>* currNode = head;
			while (currNode->nextPtr != tail)
				currNode = currNode->nextPtr; /*we must traverse the list since we cannot access
			previous nodes*/

			delete tail;
			tail = currNode;
			tail->nextPtr = nullptr;

			//delete delNode;
			//delNode = NULL;
		}
		num_items--;
	}

	item_type front() {
		if (head == nullptr)
			throw exception("ERROR: cannot return value-- list is empty");

		return head->data;
	}

	item_type back() {
		if (head == nullptr) //FIXME: must be "NULL", not "null"
			throw exception("ERROR: cannot return value-- list is empty");

		return tail->data;
	}

	bool empty() {
		return head == nullptr;
	}

	void insert(size_t index, const item_type& item) {
		//error catching: index < 0
		//doesn't work-- size_t can't be negative.
		/*if (index < 0)
			throw exception("ERROR: index must be 0 or higher");*/

		//special cases: empty list OR index beyond list
		if (head == nullptr || index >= num_items) {
			push_back(item);
			//num_items++; push_back already increments
			return;
		}

		//special case: index = 0
		if (index == 0) {
			push_front(item);
			return;
		}

		//normal case
		int counter = 1;
		Node<item_type>* currNode = head;
		Node<item_type>* insertNode = new Node<item_type>(item);
		while (counter < index) {
			currNode = currNode->nextPtr;
			counter++;
		}
		insertNode->nextPtr = currNode->nextPtr;
		currNode->nextPtr = insertNode; //doesn't work for 0, needs its own case

		num_items++;
	}

	bool remove(size_t index) {
		//false: list is empty (nothing to remove) or index is beyond the last node
		if (head == nullptr || index >= num_items)
			return false;

		//special case: index is 0 (first node)
		if (index == 0) {
			pop_front();
			return true; //CHECK: will this line be reached? (pop_front() has its own returns)
		}

		//normal case:
		int counter = 1;
		Node<item_type>* currNode = head;
		while (counter < index) {
			currNode = currNode->nextPtr;
			counter++; 
		}
		Node<item_type>* delNode = currNode->nextPtr;
		currNode->nextPtr = currNode->nextPtr->nextPtr;
		delete delNode;
		if (index == num_items - 1) {
			tail = currNode;
		}

		num_items--;
		return true;
		
	}

	size_t find(const item_type& item) {
		size_t index = 0;
		Node<item_type>* currNode = head;
		while (currNode != nullptr) {
			if (currNode->data == item) {
				return index;
			}
			currNode = currNode->nextPtr;
			index++;
		}
		return num_items;
	}

	void print() { //for testing purposes
		cout << "Current List:" << endl;
		Node<item_type>* tempPtr = head;
		while (tempPtr != nullptr) {
			cout << tempPtr->data << " " << endl;
			tempPtr = tempPtr->nextPtr;
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}

	//getters, also for testing purposes
	item_type gethead() {
		return head->data;
	}

	item_type gettail() {
		return tail->data;
	}

	size_t get_num_items() {
		return num_items;
	}
};
