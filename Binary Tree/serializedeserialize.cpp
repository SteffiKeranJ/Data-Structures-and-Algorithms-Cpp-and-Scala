/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "x,";
        string l = serialize(root->left);
        string r = serialize(root->right);
        return to_string(root->val) + ","+l+r;
    }
    
    TreeNode* deserializeHelper(queue<string>& q) {
        string front = q.front();
        q.pop();
        if(front == "x") return NULL;
        TreeNode* curNode = new TreeNode(stoi(front));
        curNode->left = deserializeHelper(q);
        curNode->right = deserializeHelper(q);
        return curNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> q;
        string str;
        while(ss.good()) {
            getline(ss, str, ',');
            q.push(str);
        }
        return deserializeHelper(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
