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

struct initialise
{
  int val = 0;  
};

class Solution 
{
public:
    
    void traverse(TreeNode* root, unordered_map<int, initialise>& hash, int& Max)
    {
        if(root)
        {
            traverse(root->left, hash, Max);
            hash[root->val].val += 1;
            Max = max(hash[root->val].val, Max);
            traverse(root->right, hash, Max);            
        }
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int, initialise> hash;
        int Max = 0;
        traverse(root, hash, Max);
        vector<int> ans;
        for (auto i : hash)
        {
            if (i.second.val == Max)
                ans.push_back(i.first);
        }
        return ans;
        
    }
};


