class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> operands;
        for(auto c: tokens) {
            if(c == "+" || c == "-" || c == "*" || c == "/") {
                if(c == "+") {
                    int f = stoll(operands.top());
                    operands.pop();
                    int s = stoll(operands.top());
                    operands.pop();
                    string result = to_string(f + 0LL + s);
                    operands.push(result);
                }
                else if(c == "-") {
                    int f = stoll(operands.top());
                    operands.pop();
                    int s = stoll(operands.top());
                    operands.pop();
                    string result = to_string(s - 0LL - f);
                    operands.push(result);
                }
                else if(c == "*") {
                    int f = stoll(operands.top());
                    operands.pop();
                    int s = stoll(operands.top());
                    operands.pop();
                    string result = to_string(f * 1LL * s);
                    operands.push(result);
                }
                else if(c == "/") {
                    int f = stoll(operands.top());
                    operands.pop();
                    int s = stoll(operands.top());
                    operands.pop();
                    string result = to_string(1LL * s / f);
                    operands.push(result);
                }
                else {
                    assert(false);
                }
            }
            else {
                operands.push(c);
            }
        }
        return stoll(operands.top());
    }
};