/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    void inorder(TreeNode* root, vector<TreeNode* >& Nodes) 
    {
        if (!root)
            return;
        
        inorder(root->left, Nodes);
        Nodes.push_back(root);
        inorder(root->right, Nodes);
    }
    
    
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<TreeNode*> Nodes;
        inorder(root, Nodes);
        
        root = Nodes[0];
        int len = Nodes.size();
        TreeNode* prev = root;
       
        for (int curr = 1; curr < len; curr++)
        {
            prev->left = NULL;
            prev->right = Nodes[curr];
            prev = Nodes[curr];
        }
        prev->left = NULL;
        prev->right = NULL;
        
        return root;
    }
};
