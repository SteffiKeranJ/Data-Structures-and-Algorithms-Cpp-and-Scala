
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        // cout << x.size() ;
        // if(x.size()==1) return false;
        for(int c = 0; c < x.length(); c++){
            if(x[c]=='{' || x[c] == '(' || x[c] == '[') {
                s.push(x[c]);
            }
            else {
                if(s.empty()) return false;
                char t = s.top();
                s.pop();
                if((t == '{' && x[c]!='}') || (t == '(' && x[c]!=')') || (t == '[' && x[c]!=']')) {
                    return false;
                } 
            }
        }
        return s.empty();
    }

};
