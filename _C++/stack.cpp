#include<iostream>
using namespace std;
#include<string>
#include<cstring>

template<typename T>
class stack{
private:
	struct node{
		node* next;
		T data;
	};
	node* list;
	int size;
	node* head;
	node* tail;
public:
	stack(){
		size = 0;
		list = head = tail = nullptr;
	}
	~stack(){
		list = head;
		while(list){
			head = list->next;
			delete list;
			list = head;
		}
	}
	stack& push(T _data){
		size++;
		if(head == nullptr){
			list = new node;
			tail = head = list;
			list->data = _data;
			return *this;
		}
		tail->next = new node;
		tail->next->next = nullptr;
		tail = tail->next;
		tail->data = _data;
		return *this;
	}
	stack& show_stack(){
		while(list){
			cout << list->data << " ";
			list = list->next;
		}
		cout << endl;
		list = head;
		return *this;
	}
	stack& remove(){
		size--;
		while(list->next->next != nullptr)
			list = list->next;
		tail = list;
		delete list->next;
		tail->next = nullptr;
		list = head;
		return *this;
	}
	stack& _size(){
		cout << "Stack size is " << size << endl;
		return *this;
	}
	void jd(){
		cout << sizeof(node*) << endl;
	}
};


int main()
{
	// stack<int> a;
	// a.push(3);
	// a.push(21);
	// a.push(21);
	// a.push(32);
	// a.push(78);
	// a.show_stack();
	// cout << a._size() << endl;
	// a.remove().remove();
	// a.show_stack();
	// cout << a._size() << endl;
	// a.push(111).push(432).push(456);
	// a.show_stack();
	// cout << a._size() << endl;

	stack<const char*> a;
	a.push("Hello:0").push("LOLO").push("KEKEKITSWORK").show_stack().remove().remove().show_stack();

	// a.show_stack();
	// a.push(32).push(43).push(54).show_stack()._size().remove().show_stack()._size();
	// cout << sizeof(stack<int>) << endl;




	return 0;
}