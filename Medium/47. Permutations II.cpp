class Solution {
public:
    
    set<vector<int>> temp_ans;
    
    void solve(vector<int>& nums, int n, vector<int> temp, vector<bool>& visited, int count){
        
        if (count == n){
            temp_ans.insert(temp);
        }
        
        for (int i = 0; i < n; i++){
            
            if (!visited[i]){
                temp.push_back(nums[i]);
                visited[i] = true;
                count++;
                solve(nums, n, temp, visited, count);
                temp.pop_back();
                count--;
                visited[i] = false;
            }
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int n = nums.size();
        vector<bool> visited(n, 0);
        vector<int> temp;
        
        solve(nums, n, temp, visited, 0);
        
        ans.assign(temp_ans.begin(), temp_ans.end());
        return ans;
    }
};
