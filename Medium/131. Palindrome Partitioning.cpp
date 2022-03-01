
/*
1) Partition at every index, check if the 2 partitions are palindromes appends the ones that are .

2) Otherwise repeat the process, same concept as MCM problem


a | bb

*/

class Solution {
public:

    
    bool is_palindromic(string str, int start, int end)
    {
        for (int i = 0; i < (end-start+1)/2; i++)
        {
            if (str[start+i] != str[end-i])
                return false;
        }
        return true;
    }
    
    void partition_helper(vector<vector<string>>& ans, vector<string>& curr ,string s, int start, int end)
    {
        if (start > end)
        {
            ans.push_back(curr);
            return ;
        }
        
        for (int k = start; k <= end; k++)
        {
            if (is_palindromic(s, start, k))
            {
                curr.push_back(s.substr(start, k - start + 1));
                
                partition_helper(ans, curr, s, k+1, end);
                
                curr.pop_back();
            }

        }
        return;
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> curr;
        partition_helper(ans, curr, s, 0, s.length()-1);
        
        int row = ans.size();
        int colm = ans[0].size();
        
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < colm; j++)
//             {
//                 cout << ans[i][j] << " ";
//             }
//             cout << "\n";
//         }
        
        return ans;
    }
};
