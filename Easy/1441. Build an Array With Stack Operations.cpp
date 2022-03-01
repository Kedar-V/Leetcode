class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> ans;
        stack<int> stk;
        int len = int(target.size());
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (j == len)
                break;
            ans.push_back("Push");
            if (i == target[j])
            {
                j++;
                continue;
            }
            ans.push_back("Pop");

        }
        return ans;
    }
};
