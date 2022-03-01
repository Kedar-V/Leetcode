class Solution {
public:
    struct initialise
    {
        bool val = false;
    };
    
void readBinaryWatch_util(int num, int curr_len, bool* mins, bool* hours, vector<string> &ans, unordered_map<string, initialise> &hash)
{
    if (curr_len == num)
    {
        ostringstream str1;
        int hour = 0;
        for (int i = 0; i < 4; i++)
        {
            if (hours[i])
                hour += pow(2, i);
        }
        
        if (hour >= 12)
            return;
        
        int min = 0;
        for (int i = 0; i < 6; i++)
        {
            if (mins[i])
                min += pow(2, i);
        }
        
        if (min >= 60)
            return;
        str1 << hour;
        str1 << ":";
        if (min < 10)
        {
            str1 << "0";
            str1 << min;
        }
        else
        {
            str1 << min;
        }
//         cout << str1.str() << endl;
        string temp = str1.str();
        if (!hash[temp].val)
        {
            ans.push_back(temp);
            hash[temp].val = true;
        }
        return;
    }
    
    
    for (int i = 0; i < 6; i++)
    {
        if (!mins[i])
        {
            mins[i] = true;
            readBinaryWatch_util(num, curr_len+1, mins, hours, ans, hash);
            mins[i] = false;
        }
        
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (!hours[i])
        {
            hours[i] = true;
            readBinaryWatch_util(num, curr_len+1, mins, hours, ans, hash);
            hours[i] = false;
        }
    }
}

vector<string> readBinaryWatch(int num) {
    
    bool mins[6];
    bool hours[4];
    unordered_map<string, initialise> hash;
    vector<string> ans;
    
    if (num >= 9)
        return ans;
    
    if (num == 0)
    {
        ans.push_back("0:00");
        return ans;
    }
    
    memset(mins, false, sizeof(mins));
    memset(hours, false, sizeof(hours));
    
    for (int i = 0; i < 6; i++)
    {
        mins[i] = true;
        readBinaryWatch_util(num, 1, mins, hours, ans, hash);
        mins[i] = false;
    }
    
    for (int i = 0; i < 4; i++)
    {
        hours[i] = true;
        readBinaryWatch_util(num, 1, mins, hours, ans, hash);
        hours[i] = false;
    }
    // sort(ans.begin(),ans.end());
    return ans;
}
};
