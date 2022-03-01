class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char> stk;
        
        int depth = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                stk.push(c);
                int curr_depth = stk.size(); 
                depth = max(depth, curr_depth);
            }
            if (c == ')')
            {
                stk.pop();
            }
        }
        return depth;
    }
};
