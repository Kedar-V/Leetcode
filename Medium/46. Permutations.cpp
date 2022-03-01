class Solution {
public:
    vector<vector<int>> ans;
    
    void print_vec(vector<int> vec){
        for (int i : vec)
            cout << i << " ";
        cout << "\n-----------------------------------------------------\n";
    }

//     void helper(vector<int>&nums, int l, int r){
    
//         if (l == r)
//             ans.push_back(nums);
        
//         for (int i = l; i < r; i++){
            
//             swap(nums[l], nums[i]);
//             helper(nums, l+1, r);
//             swap(nums[i], nums[l]);
//         }  
        
//     }
//     void helper(vector<int>&nums, vector<int>& temp, vector<bool>& visited, int n){
    
//         if (temp.size() == n)
//             ans.push_back(temp);
        
//         for (int i = 0; i < n; i++){
            
//             if (!visited[i]){
//                 visited[i] = true;
//                 temp.push_back(nums[i]);
//                 helper(nums, temp, visited, n);
//             }
//             temp.erase(remove(temp.begin(), temp.end(), nums[i]));
//             visited[i] = false;
//         }  
        
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
        
//         vector<bool> visited(nums.size());
//         vector<int> temp = {};
//         helper(nums, temp, visited, nums.size());
//         return ans;
//     }
    
     void helper(vector<int>&nums, vector<int>& temp, vector<bool>& visited, int n){
        
        if (temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++){
            
            if (!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                helper(nums, temp, visited, n);
                temp.erase(remove(temp.begin(), temp.end(), nums[i]));
                visited[i] = false;
            }
            
        }
        
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<bool> visited(nums.size());
        vector<int> temp = {};
        helper(nums, temp, visited, nums.size());
        return ans;
    }
};
