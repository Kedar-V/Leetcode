class Solution:
    def reverseWords(self, s: str) -> str:
        
        temp = s.split(" ")
        l = len(temp)
        
        for i in range(l):
            temp[i] = temp[i][::-1]
            
        ans = ""
        
        for i in range(l):
            ans = ans + temp[i] + " "
            
            
        return ans[:-1]
