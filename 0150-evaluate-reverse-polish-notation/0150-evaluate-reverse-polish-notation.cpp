class Solution {
public:
    int val(int a,int b,char c){
        if(c == '+'){
            return a+b;
        }
        else if(c=='-'){
            return b-a;
        }
        else if(c == '/'){
            int k = b/a;
            cout << k << endl;
            return k;
        }
        else{
            return a*b;
        }
        
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i : tokens){
            if(i == "+" or i == "-" or i == "/" or i == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(val(a,b,i[0]));
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};