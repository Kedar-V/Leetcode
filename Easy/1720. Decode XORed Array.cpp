class Solution 
{
public:
    vector<int> decode(vector<int>& encoded, int first) 
    {
       int n = encoded.size() + 1;
        encoded.insert(encoded.begin(), first);
  //     vector<int> ans(n);
       
      //  ans[0] = first;
        
        for(int i = 1; i < n; i++)
        {
            encoded[i] = encoded[i-1]^encoded[i];
        }
        return encoded;
    }
};
