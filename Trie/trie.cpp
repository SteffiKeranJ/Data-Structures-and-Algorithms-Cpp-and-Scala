class TrieNode {
    public: 
        bool isEnd;
        TrieNode* children[26];
        TrieNode() {
            isEnd= false;
            for(int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        TrieNode* newNode = root;
        for(int i = 0; i < n; ++i) {
            char newChar = word[i];
            int k = newChar - 'a';
            if(!newNode->children[k]) {
                newNode->children[k] = new TrieNode();
            }
            newNode = newNode->children[k];
        }
        newNode->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* searchNode = root;
        int n = word.size();
        for(int i = 0; i < n; ++i) {
            char newChar = word[i];
            int k = newChar - 'a';
            if(searchNode->children[k] == NULL) return false;
            searchNode = searchNode->children[k];
        }
        return searchNode->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* searchNode = root;
        int n = prefix.size();
        for(int i = 0; i < n; ++i) {
            char newChar = prefix[i];
            int k = newChar - 'a';
            if(searchNode->children[k] == NULL) return false;
            searchNode = searchNode->children[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
