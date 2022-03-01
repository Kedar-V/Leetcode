class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        stack<int> stk;
        stk.push(s[0]);
        for (int i = 1; i < len; i++)
        {
            if (!stk.empty())
            {
                if (stk.top() == tolower(s[i]) || stk.top() == toupper(s[i]))
                {
                    if (stk.top() != s[i])
                        stk.pop();
                    else
                        stk.push(s[i]);
                }
                else
                    stk.push(s[i]);
            }
            else
                stk.push(s[i]);
        }
        string ans = "";
        
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        len = ans.length();
        for (int i = 0; i < len/2; i++)
        {
            swap(ans[i], ans[len-i-1]);
        }
        return ans;
    }
};
