class TrieNode {
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
};

class WordDictionary {
private:
    TrieNode* root;
    
     bool searchHelper(string word, TrieNode* current) {
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!current->children[ch - 'a']) 
                    return false;
                current = current->children[ch - 'a'];
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(current->children[j] && searchHelper(word.substr(i + 1), current->children[j])){
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isEnd;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int l = word.size();
        TrieNode* cur = root;
        for(int i = 0; i < l; ++i) {
            int k = word[i] - 'a';
            if(!cur->children[k]) {
                cur-> children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
       return searchHelper(word, root);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
