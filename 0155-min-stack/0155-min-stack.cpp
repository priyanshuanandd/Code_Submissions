class MinStack {
public:
    long long mini;
    stack<long long> stk;

    MinStack() {
        mini = INT_MAX;  // Use the maximum possible long long value
    }

    void push(int val) {
        if (val >= mini) {
            stk.push(val);
        } else {
            // Push the encoded value and update mini
            stk.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (stk.top() < mini) {
            // Restore the previous minimum value
            mini = 2 * mini - stk.top();
        }
        stk.pop();
    }

    int top() {
        if (stk.top() < mini) {
            // Return mini because top is encoded
            return mini;
        } else {
            return stk.top();
        }
    }

    int getMin() {
        return mini;  // Return the current minimum value
    }
};
