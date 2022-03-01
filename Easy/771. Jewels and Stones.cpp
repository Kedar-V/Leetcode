struct initialise
{
  bool val = false;  
};

class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        unordered_map<char, initialise> hash;
    
        for (char c : J)
            hash[c].val = true;

        int count = 0;
        for (char c : S)
        {
            if (hash[c].val)
                count++;
        }
        return count;   
    }
};
