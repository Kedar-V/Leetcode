class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        vector<int> edge1 = edges[0];
        vector<int> edge2 = edges[1];
        
        for (int i = 0; i < 2; i++){
            int curr = edge1[i];
            for (int j = 0; j < 2; j++){
                // cout << curr << " " << edge2[j] << endl;
                if (curr == edge2[j])
                    return curr;
            }
        }
        return 0;
    }
};
