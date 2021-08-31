class TrieNode {
public:
    int val;
    unordered_map<string, TrieNode*> children;
    TrieNode() {
        val = -1;
    }
};
class FileSystem {
    
private:
    TrieNode* root;
    
    vector<string> split(string path, char delim) {
        vector<string> res;
        path = path.substr(1, path.length());
        stringstream ss(path);
        string folder;
        while(getline(ss, folder, delim)) {
            res.push_back(folder);
        }
        return res;
    }
    
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    bool createPath(string path, int value) {
        vector<string> paths =  split(path, '/');
        int n = paths.size();
        TrieNode* curr = root;
        string p;
        int i;
        for(i= 0; i < n; ++i) {
            p = paths[i];
            if(!curr->children[p]) break;
            curr=curr->children[p];
        }
        if(i == n-1) {
            curr->children[p] = new TrieNode();
            curr->children[p]->val = value;
            return true;
        }
        return false;              
    }
    
    int get(string path) {
        if(!root) return -1;
        vector<string> paths=  split(path, '/');
        int n = paths.size();
        TrieNode* curr = root;
        for(string p: paths) {
            if(!curr->children[p]) return -1;
            curr = curr->children[p];
        }
        return curr->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
