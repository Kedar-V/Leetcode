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
    
    bool isValidBST_util(TreeNode* root, long& prev)
    {
        if (root)
        {
            if (!isValidBST_util(root->left, prev))
                return false;
            if (root->val <= prev)
                return false;
            prev = long(root->val);
            if (!isValidBST_util(root->right, prev))
                return false;
            
            return true;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) 
    {
        long prev = LONG_MIN;
        
        if (!root)
            return true;
        
        if (!root->left && !root->right)
            return true;
        
        return isValidBST_util(root, prev);
    }
};
