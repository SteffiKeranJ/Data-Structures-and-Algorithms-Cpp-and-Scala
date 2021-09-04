class TrieNode {
public:    
    bool isEnd;
    TrieNode* children[26] = {NULL};
    
    TrieNode(){
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void addToTrie(string word) {
        TrieNode* curr = root;
        for(char w : word) {
            int k = w-'a';
            if(!curr->children[k]) curr->children[k] = new TrieNode();
            curr = curr->children[k];
            if(curr->isEnd) return;
            
        }
        curr->isEnd = true;
        return;
    }
    
    string replaceWord(string word) {
        TrieNode* curr = root;
        string s = "";
        for(int i = 0; i < word.size(); ++i) {
            int k = word[i]-'a';
            if(!curr->children[k]) {
                break;
            }
            s+= word[i];
            curr = curr->children[k];
            if(curr->isEnd) break;
        }
        return (s=="" || curr->isEnd == false) ? word : s;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string dict: dictionary) addToTrie(dict);
        istringstream  ss(sentence);
        string word;
        vector<string> resword;
        while(ss >> word) {
            resword.push_back(replaceWord(word));
        }
        int n = resword.size();
        string resSentence = "";
        for(int i = 0; i < n; ++i) {
            resSentence += resword[i];
            if(i < n-1) resSentence += " ";
        }
        return resSentence;
    }
};
