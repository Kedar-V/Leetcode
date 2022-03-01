struct initialise
{
  bool val = false;  
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string, initialise> visited;
        string ans = "";
        int rows = paths.size();
        for (int i = 0; i < rows; i++)
            visited[paths[i][0]].val = true;
        
        for (int i = 0; i < rows; i++)
        {
            if (!visited[paths[i][1]].val)
                ans = paths[i][1];
        }
        
        return ans;
    }
};
