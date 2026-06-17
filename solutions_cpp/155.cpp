#include <stack>

class MinStack
{
  public:
    MinStack() {}

    void push(int value)
    {
        stack.push(value);
        if (minStack.empty() || value <= minStack.top())
            minStack.push(value);
    }

    void pop()
    {
        if (stack.top() == minStack.top())
            minStack.pop();
        stack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }

  private:
    std::stack<int> stack;
    std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */