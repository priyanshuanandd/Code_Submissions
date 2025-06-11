class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++)
            if (expression[i] == '*' or expression[i] == '+' or
                expression[i] == '-') {
                vector<int> v1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> v2 = diffWaysToCompute(expression.substr(i + 1));

                for (auto a : v1) {
                    for (auto b : v2) {
                        if (expression[i] == '*') {
                            res.push_back(a * b);
                        } else if (expression[i] == '-') {
                            res.push_back(a - b);
                        } else {
                            res.push_back(a + b);
                        }
                    }
                }
            }

        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};