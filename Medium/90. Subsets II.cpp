class Solution {
public:
    
    set<vector<int>> temp_ans;
    
    void helper(vector<int>& nums, vector<int> temp, int curr){
        
        if (curr == nums.size()){
            temp_ans.insert(temp);
            return;
        }
        temp.push_back(nums[curr]);
        helper(nums, temp, curr + 1);
        temp.pop_back();
        helper(nums, temp, curr + 1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        int curr = 0;
        sort(nums.begin(), nums.end());
        helper(nums, temp, curr);
        
        vector<vector<int>> ans;
        ans.assign(temp_ans.begin(), temp_ans.end());
        return ans;
    }
};
