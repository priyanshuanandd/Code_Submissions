class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        for(auto i : s)
        {
            if(i == ')' and (stk.empty() or stk.top() == ')')){
                stk.push(i);
            }   
            else if(i  == ')'){
                stk.pop();
            }
            else{
                stk.push('(');
            }
        }

        return stk.size();
    }
};