struct initialise
{
    int val = 0;    
};

class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        string hashing = "balloon";
        
        unordered_map<char, initialise> hash;
        unordered_map<char, initialise> hash2;
      
        for (char c : hashing)
            hash[c].val = 1;
        
        
        for (char c : text)
            hash2[c].val += hash[c].val;
        
        int count = min({hash2['b'].val, hash2['a'].val, hash2['n'].val, hash2['l'].val/2 ,hash2['o'].val/2});
        return count;
    }
};
