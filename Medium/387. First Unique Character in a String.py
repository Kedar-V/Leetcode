class Solution:
    def firstUniqChar(self, s: str) -> int:
        hm = {}
        for i in range(len(s)):
            c = s[i]
            if c not in hm:
                hm[c] = i
            else:
                hm[c] = len(s)
            
        min_i = -1
        for c, i in hm.items():
            if i != len(s):
                if min_i != -1:
                    min_i = min(min_i, i)          
                else:
                    min_i = i  


        return min_i


            
