class Solution {
private:
    // needed to prevent cycles, use a hashmap
    unordered_map<int, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        // check if the root is null
        if(!node) return node;
        // if the node is already present
        if(visited[node->val]) return visited[node->val];
       
        // if the node is not present, clone the node
        Node* tmp = new Node(node->val);
        // put the cloned node into the map
        visited[node->val] = tmp;
        
        // iterate over the neighbours and perform dfs
        for(int i = 0; i < node->neighbors.size(); ++i){
            tmp->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        
        // return
        return tmp;
    }
};
