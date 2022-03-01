/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void maxDepth_helper(Node* root, int curr_depth ,int& max_depth) 
    {
        if (!root)
            return;
        
        max_depth = max(curr_depth, max_depth);
        for (auto child : root->children)
            maxDepth_helper(child, curr_depth + 1, max_depth);
    }
    
    int maxDepth(Node* root) 
    {
        if (!root)
            return 0;
        
        int max_depth = INT_MIN;
        
        maxDepth_helper(root, 1, max_depth);
        
        return max_depth;
    }
};
