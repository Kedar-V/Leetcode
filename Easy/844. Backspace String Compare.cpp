class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        stack<char> stk;
        stack<char> stk2;
        int len = S.length();
        int len2 = T.length();
        
        for (int i = 0; i < len; i++)
        {
            if (S[i] == '#')
            {
                if (!stk.empty())
                    stk.pop();
            }
            else
                stk.push(S[i]);
        }
        
        for (int i = 0; i < len2; i++)
        {
            if (T[i] == '#')
            {
                if (!stk2.empty())
                    stk2.pop();
            }
            else
                stk2.push(T[i]);
        }
        
        while (!stk.empty() && !stk2.empty())
        {
            if (stk.top() != stk2.top())
                return false;
            stk.pop();
            stk2.pop();
        }
        
        if (stk.empty() && stk2.empty())
            return true;
        
        return false;
        
    }
};
