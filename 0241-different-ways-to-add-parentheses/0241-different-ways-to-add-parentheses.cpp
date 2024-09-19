class Solution {
public:
    vector<int> recurse(string expr) {
        vector<int> res;
        if(expr.size() == 0) {
            return res;
        }
        if(expr.size() == 1) {
            res.push_back(stoi(expr));
            return res;
        }
        if(expr.size() == 2 && isdigit(expr[0])) {
            res.push_back(stoi(expr));
            return res;
        }
        for(int i = 0; i < expr.size(); i++) {
            char c = expr[i];
            if(isdigit(c)) {
                continue;
            }
            vector<int> left = recurse(expr.substr(0, i));
            vector<int> right = recurse(expr.substr(i + 1));
            for(auto l: left) {
                for(auto r: right) {
                    int computedResult = 0;
                    switch(c) {
                        case '+': 
                            computedResult = l + r;
                            break;
                        case '-':
                            computedResult = l - r;
                            break;
                        case '*':
                            computedResult = l * r;
                            break;
                    }
                    res.push_back(computedResult);
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return recurse(expression);
    }
};