#include<iostream>

class Stack{
private:
    int count;
    size_t _size;

protected:
    int* mData;

public:
	Stack(){
        count = 0;
        _size = 5;
        mData = new int[_size];
	}
    ~Stack()
    {
        delete [] mData;
    }

	void push(int val){ // кладет элемент в стек
        if (_size == 50)
            return;
        if (count == _size)
            {
                // _size += 5;
                extend(5);
            }
            mData[count] = val;
            ++count;
	}
    
	void pop(){ // извлекает элемент из стека
        --count;
	}
    
	bool isEmpty(){ // возвращает true, если стек пуст. false в противном случае
        return (count > 0 ? false : true);
	}

	int top(){ // возвращает верхний элемент стека не извлекая его
        return mData[count - 1];
	}
    
    void extend(int n)
    {
        _size += n;
        int *cpy = new int[_size];
        for (int i = 0; i < count; i++)
            cpy[i] = mData[i];
        delete [] mData;
        mData = cpy;
    }
};



int main(){




    return 0;
}