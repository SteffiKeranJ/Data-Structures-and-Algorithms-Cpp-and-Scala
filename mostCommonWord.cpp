class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // add the banned words to a hashed set
        unordered_set<string>ban (banned.begin(), banned.end());
        unordered_map<string, int> counter;
        
        for(auto & c : paragraph) {
            // check if the word in the paragraph is an alphabet
            // if it is an alphabet, convert it to lowercase or replace it with empty string
            c=  isalpha(c) ? tolower(c) : ' ';
        }
        istringstream iss(paragraph);
        string w;
        pair<string, int> res("",0);
        while(iss >> w) {
            if(ban.find(w) == ban.end() && ++counter[w] > res.second) {
                res = make_pair(w, counter[w]);
            }
        }

        return res.first;
       }
    };
