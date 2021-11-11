#include<iostream>
#include<vector>
#include<initializer_list>
#include<algorithm>
using namespace std;

class List{
private:
    struct node{
        int data;
        node* next;
    };
    node* list;
    node* head;
    node* tail;
    int list_size;

public:
    List() : list(nullptr), head(nullptr), tail(nullptr), list_size(0) {}

    List(const vector<int>& vec) : list(nullptr), head(nullptr), tail(nullptr), list_size(0){
        list_size = vec.size();
        // sort(vec.begin(), vec.end());
        list = new node;
        head = list;
        list->data = vec[0];
        for (int i = 1; i < vec.size(); i++){
            list->next = new node;
            list->next->next = nullptr;
            list = list->next;
            list->data = vec[i];
        }
        tail = list;
        list = head;
    }

    List(const List& cp) : list(nullptr), head(nullptr), tail(nullptr), list_size(0) {
        *this = cp;
        // if (!cp.head)
        //     return;
            
        // node* tmp = cp.head;
        // list_size = cp.list_size;
        // list = new node;
        // head = list;
        // list->data = tmp->data;
        // for(int i = 1; i < list_size; i++){
        //     list->next = new node;
        //     list->next->next = nullptr;
        //     list = list->next;
        //     tmp = tmp->next;
        //     list->data = tmp->data;
        // }
        // tail = list;
        // list = head;
    }

    List(const initializer_list<int>& _list){
        list_size = _list.size();
        list = new node;
        head = list;
        initializer_list<int>::iterator it = _list.begin();
        list->data = *it++;
        for (it; it != _list.end(); it++){
            list->next = new node;
            list->next->next = nullptr;
            list = list->next;
            list->data = *it;
        }
        tail = list;
        list = head;
    }

    List& operator=(const List& cp){
        
        if (this == &cp)
            return *this;
        if(head)
            this->~List();
        if (!cp.head)
            return *this;

        list_size = cp.list_size;
        node* tmp = cp.head;
        list = new node;
        head = list;
        list->data = tmp->data;
        for(int i = 1; i < list_size; i++){
            list->next = new node;
            list->next->next = nullptr;
            list = list->next;
            tmp = tmp->next;
            list->data = tmp->data;
        }
        tail = list;
        list = head;
        return *this;
    }

    List& operator=(List&& cp){
        if (this == &cp)
            return *this;
        swap(list_size, cp.list_size);
        swap(head, cp.head);
        swap(list, cp.list);
        swap(tail, cp.tail);
    }

    List(List&& other){
        head = tail = list = nullptr;
        list_size = 0;
        swap(list_size, other.list_size);
        swap(head, other.head);
        swap(list, other.list);
        swap(tail, other.tail);
    }

    ~List(){
        node* curr = head;
        node* next;

        while(curr != nullptr){
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    List& push_back(int data){
        if (head){
            tail->next = new node;
            tail->next->data = data;
            tail = tail->next;
            return *this;
        }
        head = new node;
        head->next = nullptr;
        head->data = data;
        tail = list = head;
        return *this;
    }

    friend ostream& operator<<(ostream& out, List& l){
        if(l.head){
            while(l.list){
                out << l.list->data << " ";
                l.list = l.list->next;
            }
            l.list = l.head;
            return out;
        }
        out << "list is empty";
        return out;
    }

    int size() const{
        return list_size;
    }

    // List& print_list(){
    //     while(list){
    //         cout << list->data << " ";
    //         list = list->next;
    //     }
    //     cout << endl;
    //     list = head;
    //     // cout << list << endl << head << endl << tail << endl;
    //     return *this;
    // }
};

int main(){

    List a;

    cout << a << endl;

    return 0;
}