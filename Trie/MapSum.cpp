class TrieNode {
public:
    bool isEnd;
    int val;
    TrieNode* children[26] = {NULL};
    TrieNode() {
        isEnd = false;
        val = 0;
    }
};

class MapSum {
private:
    TrieNode* root;
    unordered_map<string, int> map;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val - map[key];
        int n = key.size();
        TrieNode* curr = root;
        for(int i = 0; i < n; ++i) {
            int k = key[i] - 'a';
            if(!curr->children[k]) {
                curr->children[k] = new TrieNode();
            }
            curr->children[k]->val +=delta;
            curr = curr->children[k];
        }
        map[key] = val;
        curr->isEnd = true;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        TrieNode* curr = root;
        for(int i = 0; i < n; ++i) {
            int k =  prefix[i] - 'a';
            if(!curr->children[k]) return 0;
            curr = curr->children[k];
        }
        return curr->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
