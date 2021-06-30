#include<iostream>
#include<cstdio>
#include<cstring>

class CustomStack {
public:
    CustomStack()
    {
        count = 0;
    }
    ~CustomStack()
    {
    }
    void push(int val)
    {
        if (count == 0)
        {
            mData = new int[1];
            mData[0] = val;
            ++count;
            std::cout << "ok" << std::endl;
            return;
        }
        ++count;
        int *cpyData = new int[count];
        int i = 0;
        for (i; i < count - 1; i++)
            cpyData[i] = mData[i];
        delete [] mData;
        mData = cpyData;
        mData[i] = val;
        std::cout << "ok" << std::endl;
    }
    void pop()
    {
        // --count;
        int *cpy = new int[count - 1];
        int ret = mData[count - 1];
        int i = 0;
        for (i; i < count - 1; i++)
            cpy[i] = mData[i];
        delete [] mData;
        mData = cpy;
        --count;
        std::cout << ret << std::endl;
    }
    int top() const { return mData[count - 1]; }

    size_t size() const { return count; }

    bool empty() const { return (count > 0 ? false : true) ;}

    void extend(int n)
    {
        int *cpy = new int[n];
        for (int i = 0; i < count; i++)
            cpy[i] = mData[i];
        delete [] mData;
        mData = cpy;
    }

private:
    int count;

protected:
    int* mData;
};

int main() {

    CustomStack st;
    char a[15];
    int d;
    // bool flag = 1;

    while (1)
    {
        scanf("%s", a);
        if (!strcmp(a, "cmd_push"))
        {
            scanf("%d", &d);
            st.push(d);
        }
        else if (!strcmp(a, "cmd_pop"))
        {
            if (st.empty()){
                printf("error");
                return 0;
            }
            st.pop();
        }
        else if (!strcmp(a, "cmd_top"))
        {
            if (st.empty()){
                printf("error");
                return 0;
            }
            printf("%d\n", st.top());
        }
        else if (!strcmp(a, "cmd_size"))
        {
            printf("%ld\n", st.size());
        }
        else if (!strcmp(a, "cmd_exit"))
        {
            printf("bye");
            return 0;
        }

    }

    return 0;
}