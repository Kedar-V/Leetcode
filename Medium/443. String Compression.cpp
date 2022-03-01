class Solution {
public:
    vector<char> num_to_char(int count)
    {
        vector<char> ans;
        if (count == 0)
            ans.insert(ans.begin(),char(0));
        while(count > 0)
        {
            ans.insert(ans.begin(),(char((count%10)+int('0'))));
            count /= 10;
        }
        return ans;
    }
    
    int compress(vector<char>& chars) 
    {
        /*
        if curr is same as top -> increment count
        else pop top -> append char and count to string
        */
        
        stack<char> stk;
        stk.push(chars[0]);
        vector<char> ans;
        int i = 1;
        int n = chars.size();
        int count = 1;
        while (i < n)
        {
            if (chars[i] == stk.top())
            {
                count++;
            }
            else
            {
                int prev = stk.top();
                stk.pop();
                ans.push_back(prev);
                if (count > 1)
                {
                    vector<char> temp = num_to_char(count);
                    for (char c : temp)
                        ans.push_back(c);            
                }
                count = 1;
                stk.push(chars[i]);
            }
            i++;
        }
        int prev = stk.top();
        stk.pop();
        ans.push_back(prev);
        
        if (count > 1)
        {
            vector<char> temp = num_to_char(count);
            for (char c : temp)
                ans.push_back(c);            
        }

        
        chars = ans;
        return ans.size();
    }
};
