    bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int len = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), sortcol); 
        for (int i = 0; i < len;)
        {   
            vector<int> temp;
            int curr_s = intervals[i][0];
            int curr_e = intervals[i][1];
            int start = curr_s;
            int end = curr_e;
            while (curr_s <= end)
            {   
                if (curr_s < start)
                    start = curr_s;
                if (curr_e > end)
                    end = curr_e;
                i++;
                if (i == len)
                    break;
                curr_s = intervals[i][0];
                curr_e = intervals[i][1];
            }
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
