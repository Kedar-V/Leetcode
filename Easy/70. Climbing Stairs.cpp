class Solution {
public:
    struct initialise {
        int value = -1;
    };

    int climbStairs_helper(int n, int curr, unordered_map<int, initialise>& hash) {

        if(curr == n)
            return 1;
        if (curr > n)
            return 0;
        if (hash[curr].value != -1) {
            return hash[curr].value;
        }
        return hash[curr].value = climbStairs_helper(n, curr+1, hash) + climbStairs_helper(n, curr+2, hash);

    }

    int climbStairs(int n) {
        unordered_map<int, initialise> hash;
        int count1 = climbStairs_helper(n, 1, hash);
        int count2 = climbStairs_helper(n, 2, hash);
        return count1 + count2;
    }
};
