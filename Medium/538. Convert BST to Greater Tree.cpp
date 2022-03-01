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
    
    void inorder(TreeNode* root, int& prev)
    {
        if (!root)
            return;
        
        inorder(root->right, prev);
        
        prev += root->val;
        root->val = prev;
        
        inorder(root->left, prev);
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        
        if (!root)
            return NULL;
        
        int prev = 0;
        
        inorder(root, prev);

        return root;
    }
};
