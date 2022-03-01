using namespace std;

class Solution {
public:
    string maps[10] = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void helper(vector<int>& digits, string temp, int curr_digit, int n){

        if (curr_digit == n){
            if (temp.length())
                ans.push_back(temp);
            return;
        }
        int digit = digits[curr_digit];
        
        for (int i = 0; i < maps[digit].length(); i++){
            temp = temp + maps[digit][i];
            helper(digits, temp, curr_digit + 1, n);
            temp.pop_back();
        }   
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();
        vector<int> digit(n+1);
            
        for(int i = 0; i < n; i++){
            
            string curr = "";
            digit[i] = int(digits[i]) - int('0');
        }
//      {2, 3}   
        
        helper(digit, "", 0, n);
        
        return ans;
        
    }
};
