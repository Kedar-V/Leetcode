struct initialise
{
  int val = 0;  
};

class Solution {
public:
    vector<string> split1(string s)
    {
        vector <string> ans;
        int count = 0;
        for (char c : s)
        {
            if (c == ' ')
                break;
            count++;
        }
        ans.push_back(s.substr(0, count));
        ans.push_back(s.substr(count+1, s.length()));
        return ans;
    }
    
    vector<string> split2(string s)
    {
        vector <string> ans;
        int count = 0;
        int prev = count;
        int len = s.length();
        for (char c : s)
        {
            if (c == '.')
            {
                ans.push_back(s.substr(prev, count-prev));
                prev = count + 1;
            }
            count++;
        }
        ans.push_back(s.substr(prev, count-prev));
        return ans;
    }
    
    
    vector<string> subdomainVisits(vector<string>& cpdomains)
    {
        unordered_map<string, initialise> hash;
        
        for(string s : cpdomains)
        {
            stringstream str;
            vector<string> temp = split1(s);
            vector<string> temp2 = split2(temp[1]);
            
            str << temp[0];
            
            int count;
            str >> count;
            int len = temp2.size();
            string domains = "";
            for (int i = len-1; i >= 0; i--)
            {
                domains = temp2[i] + domains;
                hash[domains].val += count;
                if (i == 0)
                    break;
                domains = "." + domains;
            }
        }
        
        vector<string> ans;
        
        for (auto S = hash.begin(); S != hash.end(); S++)
        {
            stringstream s;
            s << S->second.val;
            string temp = "";
            temp += s.str();
            temp += " ";
            temp += S->first;
            ans.push_back(temp);
        }
        return ans;
    }
};
