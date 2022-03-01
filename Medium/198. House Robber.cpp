class Solution {
public:
    struct initialise {
        int value = -1;
    };

    int rob_helper(vector<int>& nums, int curr, int len, unordered_map<int, initialise>& hash) {

        if (curr >= len)
            return 0;
        int Max = nums[curr];
        if (hash[curr].value != -1) {
            return hash[curr].value;
        }
        for (int i = 2; i < len; i++) {
            int temp = nums[curr] + rob_helper(nums, curr+i, len, hash);
            if (temp > Max) {
                Max = temp;
            }
        }
        return hash[curr].value = Max;
    }

    int rob(vector<int>& nums) {
        unordered_map<int, initialise> hash;
        int len = int(nums.size());
        return max(rob_helper(nums, 0, len, hash), rob_helper(nums, 1, len, hash));
    }
};
