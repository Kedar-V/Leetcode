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
    
    void averageOfLevels_helper(TreeNode* root, int curr_depth, vector<double>& ans, vector<int>& no_of_nodes)
    {
        if (!root)
            return;
        
         if (ans.size() <= curr_depth)
        {
            cout << root->val << endl;
            ans.push_back(root->val);
            no_of_nodes.push_back(1);
        }
        else
        {
            cout << root->val << endl;
            ans[curr_depth] += root -> val;
            no_of_nodes[curr_depth] += 1;
        }
        averageOfLevels_helper(root -> left, curr_depth + 1, ans, no_of_nodes);

        averageOfLevels_helper(root -> right, curr_depth + 1, ans, no_of_nodes);
        
    }
    
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        vector<int> no_of_nodes;
        
        averageOfLevels_helper(root, 0, ans, no_of_nodes);
        
        int len = ans.size();
        for (int i = 0; i < len; i++)
            ans[i] = ans[i] / no_of_nodes[i];
        
        return ans;
        
    }
};
