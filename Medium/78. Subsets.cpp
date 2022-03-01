class Solution {
public:
    
    vector<int> helper(vector<int>& nums, int index, set<vector<int>>& subs, vector<int> temp){
        
        if (index == nums.size())
            return temp;
        
        vector<int> temp2 = helper(nums, index+1, subs, temp);
        subs.insert(temp2);
        // cout << "temp2\n";
        // for(auto i: temp2)
        //     cout << i << " ";
        // cout << endl;
        temp.push_back(nums[index]);
        
        vector<int> temp3 = helper(nums, index+1, subs, temp);
        // cout << "temp3\n";
        // for(auto i: temp3)
        //     cout << i << " ";
        // cout << endl;
        subs.insert(temp3);
        // temp3.insert(temp3.end(), temp2.begin(), temp2.end());
        return temp;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums){
        
        set<vector<int>> sub;
        vector<int> temp;
        helper(nums, 0, sub, temp);
        vector<vector<int>> subs{sub.begin(), sub.end()};
        
        return subs;
    }
};
