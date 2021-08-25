#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
class List
{
private:
	struct node{
		T data;
		node* next;
	};
	node* list;
	node* head;
	node* tail;
	int count_elem;
	int iter;
	node* last_iter;		//probably need a prev pointer of struct
public:
	explicit List(int hm = 0, const T& _data = 0){
		count_elem = hm;
		if (hm == 0){
			head = tail = list = nullptr;
			return;
		}
		list = new node;
		head = list;
		for (int i = 1; i < hm; i++){
			list->data = _data;
			list->next = new node;
			list->next->next = nullptr;
			list = list->next;
		}
		tail = list;
		last_iter = list = head;
		iter = 0;
	}
	List& push(const T& _data){
		if(count_elem == 0){
			count_elem++;
			list = new node;
			tail = head = list;
			list->next = nullptr;
			list->data = _data;
			return *this;
		}
		count_elem++;
		tail->next = new node;
		tail = tail->next;
		tail->next = nullptr;
		tail->data = _data;
		return *this;
	}
	List& show_list(){
		cout << "Elements in list: " << count_elem << endl;
		int i = 0;
		while(list){
			cout << i+1 << ": " << list->data << endl;
			i++;
			list = list->next;
		}
		list = head;
		return *this;
	}

	const T& operator[](int i) const{
		if (i < 0 || i > count_elem-1){
			std::cerr << "Error" << endl;
			std::exit(1);
		}
		node* tmp = list;
		// cout << "ANd here ok" << endl;
		for (int j = 0; j < i; i++)
			tmp = tmp->next;
		return tmp->data;
	}
	T& operator[](int i){
		if (i < 0 || i > count_elem-1){
			std::cerr << "Error" << endl;
			std::exit(1);
		}
		node* tmp = list;
		// cout << "Here" << endl;
		for (int j = 0; j < i; j++){
			tmp = tmp->next;
			// cout << j << " iter" << endl;
		}
		return tmp->data;
	}
	int get_count() const{
		return count_elem;
	}

};


int main(){

	List<int> a(10);

	for (int i = 0; i < 10; i++)
		std::cin >> a[i];
	a.show_list();

	// a.push(4).push(23).push(12).push(999);
	// a.show_list();
	// a[2] = 1234;
	// a.show_list();
	// cout << "here with for: " << endl;
	// for(int i = 0; i < a.get_count(); i++)
	// 	cout << i+1 << ": " << a[i] << endl;



	return 0;
}