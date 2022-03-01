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
    
    /*
    start from root 
    initial offset = 0
    while (root)
    {
     gst_helper(root, offset)
     root = root->left
    }
    */

    void bstToGst_helper(TreeNode* root, int& offset) 
    {
        if (root)
        {
            bstToGst_helper(root->right, offset);
            // cout << root -> val << " ";
            root->val += offset;
            offset = root -> val;
            bstToGst_helper(root->left, offset);

        }
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        int offset = 0;
        bstToGst_helper(root, offset);
        return root;
    }
};



