#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        b.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int res = peek();
        a.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        if (a.empty())
        {
            while (!b.empty())
            {
                a.push(b.top());
                b.pop();
            }
        }
        return a.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return a.empty() && b.empty();
    }

    stack<int> a;
    stack<int> b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(56);
    obj->push(7465);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    cout << param_2 << "|" << param_3 << "|" << param_4 << endl;
    return 0;
}
