class Solution {
public:
string removeDuplicates(string S) {
    string ans;
    stack<char> stk;
    
    int len = int(S.length());
    
    for (int i = 0; i < len; i++)
    {
        bool flag = false;
        if (!stk.empty()) {
            if (stk.top() == S[i]) {
                flag = true;
                stk.pop();
            }
        }
        if (!flag)
            stk.push(S[i]);
        
    }
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    len = int(ans.length());
    for (int i = 0; i < len/2; i++) {
        swap(ans[i], ans[len-i-1]);
    }
    return ans; 
    }
};
