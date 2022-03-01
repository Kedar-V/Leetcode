class Solution {
public:
vector<int> dailyTemperatures(vector<int>& T) {
    
    stack<pair<int, int>> stk;
    
    int len = int(T.size());
    
    vector<int> ans(len);
    
    stk.push(make_pair(-1,len-1));
    
    for (int i = len-1; i >= 0 ; i--)
    {
        if (stk.top().first > T[i])
            ans[i] = stk.top().second - i;
        else
        {
            while (stk.top().first <= T[i] && stk.top().first != -1)
                stk.pop();
            
            if (stk.top().first > T[i])
                ans[i] = stk.top().second - i;
            else
                ans[i] = 0;
        }
        stk.push(make_pair(T[i],i));
    }
    return ans;
}
};
