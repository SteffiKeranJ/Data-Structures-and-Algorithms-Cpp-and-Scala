class Codec {
public:
    // Encodes a tree to a single string.
     string serialize(TreeNode* root) {
        if(!root) return "x,";
        string l=serialize(root->left);
        string r=serialize(root->right);
        return to_string(root->val)+","+l+r;
    }
    
    TreeNode* deserializeHelper(queue<string>& q) {
        string ch=q.front();
        q.pop();
        if(ch=="x") return NULL;
        TreeNode* root=new TreeNode(stoi(ch));
        root->left=deserializeHelper(q);
        root->right=deserializeHelper(q);
        return root;       
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> q;
        cout << data<< endl;
        while (ss.good()) {
            string str;
            getline(ss, str,',');
            q.push(str);
        }
        return deserializeHelper(q);
    }
};
