class Solution {
public:
    string reformatDate(string date) 
    {
        stringstream ss;
        ss << date;
        
        vector<string> Months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        vector<string> Months_h = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
        
        unordered_map<string, string> hash;
        
        
        for (int i = 0; i < 12; i++)
            hash[Months[i]] = Months_h[i];
        
        vector<string> Date;// Date Month Year
        
        string temp;
        while (ss >> temp)
            Date.push_back(temp);
        
        int pos = Date[0].find("s");
        if (pos == -1)
            pos = Date[0].find("n");
        if (pos == -1)
            pos = Date[0].find("r");
        if (pos == -1)
            pos = Date[0].find("t");
        
        string YYYY = Date[2];
        string MM = hash[Date[1]];
        string DD = Date[0].substr(0, pos);
 
        string ans;
        if (pos == 2)
            ans = YYYY + "-" + MM + "-" + DD;
        else
            ans = YYYY + "-" + MM + "-0" + DD;
        return ans;
    }
};
