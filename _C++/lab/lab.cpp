#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

class CustomStack {
public:
    CustomStack()
    {
        count = 0;
        _size = 3;
        mData = new int[_size];
    }
    ~CustomStack()
    {
        delete [] mData;
    }

    void push(int val)
    {
        if (count == _size)
        {
            // _size += 5;
            extend(5);
        }
        mData[count] = val;
        ++count;
    }

    void pop()
    {
        --count;
    }

    int top() const { return mData[count - 1]; }

    size_t size() const { return count; }

    bool empty() const { return (count > 0 ? false : true) ;}

    void extend(int n)
    {
        _size += n;
        int *cpy = new int[_size];
        for (int i = 0; i < count; i++)
            cpy[i] = mData[i];
        delete [] mData;
        mData = cpy;
    }

private:
    int count;
    size_t _size;

protected:
    int* mData;
};



int main() {

    CustomStack st;
    std::string a;
    int d;
    // bool flag = 1;


    while (1)
    {
        // scanf("%s", a);
        std::cin >> a;
        if (a == "cmd_push")
        {
            // scanf("%d", &d);
            std::cin >> d;
            st.push(d);
            std::cout << "ok" << std::endl;
        }
        else if (a == "cmd_pop")
        {
            if (st.empty()){
                printf("error");
                return 0;
            }
            std::cout << st.top() << std::endl;
            st.pop();
        }
        else if (a == "cmd_top")
        {
            if (st.empty()){
                printf("error");
                return 0;
            }
            printf("%d\n", st.top());
        }
        else if (a == "cmd_size")
        {
            printf("%ld\n", st.size());
        }
        else if (a == "cmd_exit")
        {
            printf("bye\n");
            return 0;
        }

    }

    return 0;
}