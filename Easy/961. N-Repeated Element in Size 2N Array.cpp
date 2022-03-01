struct initialise
{
  bool val = 0;  
};
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        
        unordered_map<int, initialise> hash;
        int len = A.size();
        for (int i = 0; i < len; i++)
        {
            if (hash[A[i]].val)
                return A[i];
            else
                hash[A[i]].val = true;
        }
        return -1;
    }
};
