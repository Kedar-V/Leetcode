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
    
    
    void get_leaf(TreeNode* root, vector<int>& leaves)
    {
        
        if(!root)
            return;
        
        get_leaf(root->left, leaves);
        if (!root->left && !root->right)
        {
            leaves.push_back(root->val);
            return;
        }
        get_leaf(root->right, leaves);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaves1;
        vector<int> leaves2;
        
        get_leaf(root1, leaves1);
        get_leaf(root2, leaves2);
        
        
        int len1 = leaves1.size();
        int len2 = leaves2.size();
        
        if (len1 != len2)
            return false;
        
        for (int i = 0; i < len1; i++)
        {
            if (leaves1[i] != leaves2[i])
                return false;
        }
        
        return true;
    }
};
