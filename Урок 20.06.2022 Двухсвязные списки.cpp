// Связные списки Linked List
// 1. Односвязный список

#include <iostream>
#include"LinkedList.cpp"
#include"List.cpp"

class Man {
private:
	string name;
	int age;
public:
	Man(string name, int age) {
		this->name = name;
		this->age = age;
	}
	friend ostream& operator <<(ostream& out, Man& man) {
		out << man.name << " " << man.age;
		return out;
	}
	bool operator==(const Man& object)
	{
		return this->name == object.name && this->age == object.age;
	}
	bool operator!=(const Man& object)
	{
		return !(this->name == object.name && this->age == object.age);
	}
};

int main()
{
	Man man1("Viktor", 30);
	Man man2("Ivan", 30);
	Man man3("Petr", 30);
	Man man4("Qwerty", 22);
	Man man5("Pobeda", 50);
	LinkedList<Man>list1;
	list1.AddToHead(man1);
	list1.AddToHead(man2);
	list1.AddToHead(man3);
	list1.AddToTail(man3);
	list1.Show();
	list1.DeleteFromHead();
	cout << endl << endl;
	list1.Show();
	list1.DeleteFromTail();
	cout << endl << endl;
	list1.Show();
	list1.insert(man3, 1);
	cout << endl << endl;
	list1.Show();
	list1.removeAt(2);
	cout << endl << endl;
	list1.Show();
	//list1.clear();
	cout << endl << endl;
	list1.Show();
	List<Man>list2;
	list2.addToTail(man1);
	list2.addToTail(man2);
	list2.addToHead(man4);
	list2.addToHead(man3);
	list2.addToHead(man2);
	list2.addToHead(man1);
	list2.addToHead(man4);
 	list2.show();
	cout << endl;
	list2.insert(man5, 5);
	list2.show();
	cout << endl;
	list2.revers();
	list2.show();
	cout << endl;
	List<Man>list3;
	list3=list2;
	list3.show();
	list3.deleteFromHead();
	list3.deleteFromTail();
	list3.deleteFromTail();
	list3.deleteFromTail();
	list3.deleteFromTail();
	list3.deleteFromTail();
	/*list3.addToHead(man1);
	list3.addToHead(man5);*/
	cout << endl;
	list3.show();
	cout << endl;
	List<Man>list4=list3 + list2;
	list4.show();
	List<Man>list5;
	list5 = list3 * list2;
	list5.show();



}

