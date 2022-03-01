class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int len = int(nums.size());
        
        stack <int> temp;
        temp.push(nums[len-1]);
        bool flag = false;
        for (int i  = len-2; i >= 0; i--)
        {
            if (temp.top() < nums[i])
            {
                if (flag)
                    return false;
                else
                {
                    flag = true;
                    
                    int temp2 = temp.top();
                    temp.pop();
                    
                    if (!temp.empty())
                    {
                        if (temp.top() > nums[i])
                            temp.push(nums[i]);
                        else
                            temp.push(temp2);
                    }
                    else
                        temp.push(nums[i]);
                }
            }
            else
                temp.push(nums[i]);
                
        }
        return true;
    }
};
