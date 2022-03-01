struct initialise
{
  int val = 0;  
};

struct initialise_bool
{
  bool val = false;  
};

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, initialise> hash;
        
        for (int i: arr)
            hash[i].val++;
        
        unordered_map<int, initialise_bool> hash2;
        
        for (auto itr = hash.begin(); itr != hash.end(); itr++)
        {
            if(hash2[itr -> second.val].val)
                return false;
            hash2[itr -> second.val].val = true;
        }
        return true;
    }
};
