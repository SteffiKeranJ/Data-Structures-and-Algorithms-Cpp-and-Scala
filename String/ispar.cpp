class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        // cout << x.size() ;
        // if(x.size()==1) return false;
        for(char c: x){
            if(c=='{' || c == '(' || c == '[') {
                s.push(c);
            }
            else {
                if(s.empty()) return false;
                char t = s.top();
                s.pop();
                if((t == '{' && c!='}') || (t == '(' && c!=')') || (t == '[' && c!=']')) {
                    return false;
                } 
            }
        }
        return s.empty();
    }

};
