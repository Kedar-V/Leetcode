class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max = 0;
        int len = prices.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = i+1; j < len; j++)
            {
                if (prices[j] - prices[i] > max)
                    max = prices[j] - prices[i];
            }
        }
        return max;
    }
};
