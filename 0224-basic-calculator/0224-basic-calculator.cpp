class Solution {
public:
    void removespace(string& s) {
        string a;
        for (auto i : s) {
            if (i == ' ') {
                continue;
            }
            a.push_back(i);
        }
        s = a;
    }
    int calculate(string s) {
        stack<int> stk;
        removespace(s);
        //cout << s << endl;
        int fl = 0;
        for (int i = 0; i < s.size(); i++) {
           // cout << s[i] << " --" << endl;
            if (s[i] >= '0' and s[i] <= '9') {
                int num = 0;
                while (i < s.size() and s[i] >= '0' and s[i] <= '9') {
                    num = (num * 10) + (s[i] - '0');
                    i++;
                }
                stk.push(num);
            }
            
            if (s[i] == '(') {
                string a;
                i++;
                int k = 1;
                while (k > 0) {
                    if (s[i] == '(') {
                        a.push_back('(');
                        k++;
                    } else if (s[i] == ')') {
                        if(k > 1){
                            a.push_back(')');
                        }
                        k--;
                    } else {
                        a.push_back(s[i]);
                    }
                    i++;
                }
                stk.push(calculate(a));
            }
            // if (!stk.empty()) {
            //     cout <<"i->" <<  i <<" " <<  stk.top() << endl;
            //     cout << "fl" << fl << endl;
            // }
            if (fl != 0) {
                // assert(stk.size() > 1);
                if (stk.size() == 1) {
                    int a = stk.top();
                    int k = (fl == 1) ? a : -1 * a;
                    fl = 0;
                    stk.push(k);
                } else {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    int k = (fl == 1) ? a + b : b - a;
                    stk.push(k);
                    fl = 0;
                }
            }
            if (i < s.size() and (s[i] == '+' or s[i] == '-')) {
                if (s[i] == '+') {
                    fl = 1;
                } else {
                    fl = -1;
                }
                
            }
        }
        //cout << s << " -->answer " << stk.top() << endl;
        return stk.top();
    }
};