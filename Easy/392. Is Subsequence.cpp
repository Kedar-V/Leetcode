class Solution {
public:
    bool isSubsequence_helper(string s, string t, int len, int i)
    {
        if (len == s.length())
            return true;

        if (i == t.length())
            return false;

        if (s[len] == t[i])
            return isSubsequence_helper(s, t, len+1, i+1);

        return isSubsequence_helper(s, t, len, i+1);
    }


    bool isSubsequence(string s, string t) {
        return isSubsequence_helper(s, t, 0, 0);
    }
};
