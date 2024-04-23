class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        numstr = "123456789"
        ans = []
        for windowsize in range(len(str(low)), len(str(high))+1):
            lowb = 0
            highb = windowsize
            while(highb <= len(numstr)):
                num = int(numstr[lowb:highb])
                if num < low:
                    lowb += 1
                    highb += 1
                    continue
                    
                if num > high:
                    break
                ans.append(num)
                lowb += 1
                highb += 1
        return ans
        
