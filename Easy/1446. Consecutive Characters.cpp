class Solution {
public:
    int maxPower(string s) 
    {
        stack<char> stk;
        stk.push(s[0]);
        
        int i = 1;
        int n = s.length();
        
        int power = 1;
        int count = 1;
        while(i < n)
        {
            if (s[i] == stk.top())
            {
                count++;
            }
            else
            {
                stk.pop();
                stk.push(s[i]);
                power = max(power, count);
                count = 1;
            }
            i++;
        }
        power = max(power, count);
        return power;
    }
};
