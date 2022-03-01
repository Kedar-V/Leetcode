class Solution {
public:
    string freqAlphabets(string s) 
    {
        string ans = "";
        //Hashmap for mapping
        unordered_map<string, char> hash;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 1; i < 10; i++)
        {
            stringstream temp;
            temp << i;
            string ip = temp.str();
            hash[ip] = alpha[i-1];
        }
        
        for (int i = 10; i <= 26; i++)
        {
            stringstream temp;
            temp << i;
            temp << "#";
            string ip = temp.str();
            hash[ip] = alpha[i-1];
        }
        int n = s.length();
        for (int i = 0; i < n;)
        {
            if(i < n-2 && s[i+2] == '#')
            {
                string temp = s.substr(i, 3);
                ans = ans + hash[temp];
                i = i+3;
            }
            else
            {
                ans = ans + hash[s.substr(i,1)];
                i++;
            }
        }
        
        return ans;
    }
};
