class TrieNode {
public:    
    bool isEnd;
    int val;
    TrieNode* children[26] = {NULL};
    
    TrieNode(){
        isEnd = false;
        val = -1;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void addToTrie(string word, int index) {
        TrieNode* curr = root;
        for(char w : word) {
            int k = w-'a';
            if(!curr->children[k]) curr->children[k] = new TrieNode();
            curr = curr->children[k];
            
        }
        curr->isEnd = true;
        if(curr->val == -1)  curr->val = index;
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
            if(curr->val > -1) break;
        }
        return (s=="" || curr->val == -1) ? word : s;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0; i < dictionary.size(); ++i) addToTrie(dictionary[i], i);
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
