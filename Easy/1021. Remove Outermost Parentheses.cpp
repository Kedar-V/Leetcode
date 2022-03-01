class Solution {
public:
    string removeOuterParentheses(string S) {

        stack<char> stk;
        string ans = "";

        int len = S.length();
        queue<char> temp;
        for (int i = 0; i < len; i++)
        {

            if (S[i] == '(')
            {
                stk.push(S[i]);

                if (stk.size() > 1) {
                    ans += S[i];
                }
            }
            else
            {
                if (stk.size() > 1) {
                    ans += S[i];
                }
                stk.pop();
            }
        }
        return ans;
    }
};
