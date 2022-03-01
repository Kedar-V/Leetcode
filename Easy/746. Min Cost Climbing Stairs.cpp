class Solution {
public:
    struct initialise {
        int value = -1;
    };

    int minCostClimbingStairs_helper(vector<int>& cost, int step, int len, unordered_map<int, initialise>& hash)
    {
        if (step >= len)
            return 0;

        if (hash[step].value != -1) {
            return hash[step].value;
        }
        return hash[step].value = min(cost[step] + minCostClimbingStairs_helper(cost, step+1, len, hash),cost[step] + minCostClimbingStairs_helper(cost, step+2, len, hash));

    }

    int minCostClimbingStairs(vector<int>& cost) {

        unordered_map<int, initialise> hash;
        int len = int(cost.size());
        int cost1 = minCostClimbingStairs_helper(cost, 0, len, hash);
        int cost2 = minCostClimbingStairs_helper(cost, 1, len, hash);
        return min(cost1, cost2);
    }
};
