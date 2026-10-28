class MinStack {
public:
    MinStack() {
        stk2.push(INT_MAX);
    }

    void push(int val) {
        stk1.push(val);
        stk2.push(min(val, stk2.top()));
    }

    void pop() {
        stk1.pop();
        stk2.pop();
    }

    int top() {
        return stk1.top();
    }

    int getMin() {
        return stk2.top();
    }

private:
    stack<int> stk1;
    stack<int> stk2;
};
