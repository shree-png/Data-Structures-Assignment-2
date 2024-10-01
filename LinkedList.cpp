#include "LinkedList.h"
#include <string>
#include <iostream>

int main() {
	try {
		Single_Linked_List<int> mylist;
		cout << "List is empty?: " << mylist.empty() << endl;
		cout << endl;

		cout << "Pushing front/back various values (see code)" << endl;
		mylist.push_front(50); //50
		mylist.push_front(40); //40 50
		mylist.push_back(30); //40 50 30
		mylist.push_back(20); //40 50 30 20
		mylist.push_front(10); //10 40 50 30 20
		mylist.push_back(0); //10 40 50 30 20 0
		cout << endl;
		mylist.print();

		cout << "Num items: " << mylist.get_num_items() << endl;
		cout << "Find Position of Value 15: " << mylist.find(15) << endl;
		cout << endl;

		cout << "Removal of index 0 sucessful?: " << mylist.remove(0) << endl;
		cout << endl;
		cout << endl;
		mylist.print();

		cout << "Num items: " << mylist.get_num_items() << endl;
		cout << endl;
		cout << "Removal of index 5 sucessful?: " << mylist.remove(5) << endl;
		cout << endl;
		mylist.print();

		cout << "Num items: " << mylist.get_num_items() << endl;
		cout << endl;
		cout << "Find position of value 0: " << mylist.find(0) << endl;
		cout << "Find position of value 40: " << mylist.find(40) << endl;
		cout << "Find position of value 30: " << mylist.find(30) << endl;
		cout << endl;
		cout << "List is empty?: " << mylist.empty() << endl;
		cout << endl;

		mylist.pop_back();
		cout << "Pop back called" << endl;
		mylist.pop_front();
		cout << "Pop front called" << endl;
		mylist.pop_front();
		cout << "Pop front called" << endl;
		cout << endl;
		mylist.print();

		mylist.pop_back();
		cout << "Pop back called" << endl;
		mylist.pop_back();
		cout << "Pop back called" << endl;
		cout << endl;
		mylist.print();

		cout << "List is empty?: " << mylist.empty() << endl;
		cout << endl;
		cout << "Removal of index 0 sucessful?: " << mylist.remove(0) << endl;
		cout << endl;

		mylist.insert(0, 19);
		cout << "Called insert with value 19 and index 0" << endl;
		cout << endl;
		mylist.print();

		cout << "Front of list: " << mylist.front() << endl;
		cout << endl;
		cout << "Back of list: " << mylist.back() << endl;
		cout << endl;

		mylist.insert(1, 20);
		cout << "Called insert with value 20 and index 1" << endl;
		cout << endl;
		mylist.print();

		mylist.insert(50, 21);
		cout << "Called insert with value 21 and index 50" << endl;
		cout << endl;
		mylist.print();

		mylist.insert(1, 16);
		cout << "Called insert with value 16 and index 1" << endl;
		cout << endl;
		mylist.print();

		mylist.insert(3, 33);
		cout << "Called insert with value 33 and index 3" << endl;
		cout << endl;
		mylist.print();

		cout << "Removal of index 2 successful?: " << mylist.remove(2) << endl;
		cout << endl;
		mylist.print();

		cout << endl;
		cout << "Front of list: " << mylist.front() << endl;
		cout << endl;
		cout << "Back of list: " << mylist.back() << endl;
		cout << endl;

		cout << "*****************************" << endl;
		cout << endl;

		cout << "Creating String List" << endl;
		Single_Linked_List<string> mystringlist;

		cout << endl;
		cout << "Pushing back string 'Shree'" << endl;
		mystringlist.push_back("Shree");
		cout << endl;
		mystringlist.print();

		cout << "Pushing front string 'Satoru'" << endl;
		mystringlist.push_front("Satoru");
		cout << endl;
		mystringlist.print();

		mystringlist.pop_front();
		cout << "Calling pop front" << endl;
		mystringlist.pop_back();
		cout << "Calling pop back" << endl;
		cout << endl;
		mystringlist.print();

		//cout << "Calling pop back" << endl;
		//cout << "Calling pop front" << endl;
		//cout << "Calling front" << endl;
		cout << "Calling back" << endl;
		cout << endl;
		//mystringlist.pop_back();
		//mystringlist.pop_front();
		//mystringlist.front();
		mystringlist.back();
		return 0;
	}

	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	//return 0;
}