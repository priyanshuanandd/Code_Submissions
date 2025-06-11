class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int i = 0;
        int maxi = 0;
        while (i < s.size()) {

            if (s[i] == '(') {
                stk.push(i);
            }
            if (s[i] == ')') {
                stk.pop();

                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    maxi = max(maxi,i - stk.top());
                }
            }
            i++;
        }
        return maxi;
    }
};