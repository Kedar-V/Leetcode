#include <unordered_map>

class Solution {
public:
    
//     int get_index(char c) {return c - 'a';}
    
//     bool AreAnagrams(string s1, string s2){
            
//         int n1 = s1.length();
//         int n2 = s2.length();
//         // vector<int> f1(26, 0);
//         // vector<int> f2(26, 0);
//         unordered_map <int, int> f1;
//         unordered_map <int, int> f2;
        
//         if (n1 != n2)
//             return false;
        
//         for (int i = 0; i < n1; i++){
//             int s1_index = get_index(s1[i]);
//             int s2_index = get_index(s2[i]);
//                 f1[s1_index] += 1;
//                 f2[s2_index] += 1;
//         }
        
//         for (int i = 0; i < n1; i++){
//             int c1 = get_index(s1[i]);
//             int c2 = get_index(s2[i]);
//             // cout << f1[c1] << "---" << f2[c2] << endl;
//             if (f1[c1] != f2[c1] || f1[c2] != f2[c2])
//                 return false;
//         }
//         return true;
//     }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        int n = strs.size();
        
        unordered_map<string, vector<string>> anagrams;
        
        for (auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            if (anagrams.find(temp) != anagrams.end())
                anagrams[temp].push_back(str);
            else{
                vector<string> t = {str};
                anagrams[temp] = t;
            }
            
        }
        
        for (auto i : anagrams){
            ans.push_back(i.second);
        }
        return ans;
    }
};
