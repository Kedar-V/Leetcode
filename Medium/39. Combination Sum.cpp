class Solution {
public:
    
    set<vector<int>> temp_ans;
    
    void solve(vector<int>& candidates, vector<int> temp, int target, int n){
        
        if (target == 0){
            // for (int i : temp)
            //     cout << i << " ";
            // cout << endl;
            sort(temp.begin(), temp.end());
            temp_ans.insert(temp);
            return;
        }
        else if (target < 0){
            return;
        }
        
        else{
            for (int i = 0; i < n; i++){
                
                temp.push_back(candidates[i]);
                solve(candidates, temp, target - candidates[i], n);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end(), greater<int>());
            
        vector<vector<int>> ans;
        solve(candidates, temp, target, n);
        ans.assign(temp_ans.begin(), temp_ans.end());
        return ans;
    }
};
