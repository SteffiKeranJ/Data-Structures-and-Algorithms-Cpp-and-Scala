class Solution {
private:   
    int compute(int first, int second, string op) {
        if(op == "+") return first + second;
        if(op == "-") return first - second;
        if(op == "*") return first * second;
        if(op == "/") return first / second;
        
        return 0;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        set<string> operands= {"+", "-", "*", "/"};
        for(int i = 0; i < tokens.size(); ++i) {
            if(operands.find(tokens[i]) != operands.end() && !s.empty()) {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                s.push(compute(first, second, tokens[i]));
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
