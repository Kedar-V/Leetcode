class Solution {
public:
    
    vector<int> memoize;
    
    static bool str_comp(string& s1, string& s2){
        
        return s1.length() > s2.length();
    }
    
    bool compare(string s1, string s2){    
        if (s1.compare(s2) == 0){
            return true;
        }
        return false;
    }
    
    bool helper(string s, vector<string>& wordDict, int start){
        // cout << start << endl;
        
        if (start == s.length())
            return true;
        
        if (memoize[start] != -1)
            return memoize[start];
        
        bool flag = false;
        for (string word : wordDict){
            
            int w_len = word.length();
            // cout << word << endl;
            if (compare(s.substr(start, w_len), word)){
                // cout << word << endl;
                memoize[start] = helper(s, wordDict, start + w_len);
                flag = flag || memoize[start];
            }
            
        }
        return flag;  
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for (int i = 0; i < 300; i++){
            memoize.push_back(-1);
        }
           
        sort(wordDict.begin(), wordDict.end(), str_comp);
        return helper(s, wordDict, 0);
        
    }
};
