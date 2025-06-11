class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        if (s.size() % 2) {
            return -1;
        }
        for (auto i : s) {
            if (i == ']' and (stk.empty() or stk.top() == ']')) {
                stk.push(']');
            } else if (i == ']') {
                stk.pop();
            } else if (i == '[') {
                stk.push(i);
            }
        }
        int open = 0;
        int closed = 0;

        while (!stk.empty()) {
            if (stk.top() == ']') {
                open++;
            } else {
                closed++;
            }
            stk.pop();
        }

        return ((open+1)/2);
    }    
};