class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        # Go down m-1 times and go right n-1 times
        # ans = (m-1 + n-1)!/(m-1)!(n-1)!
        
        from math import factorial
        
        numerator = factorial(m+n-2)
        denominator1 = factorial(m-1)
        denominator2 = factorial(n-1)
        
        ans = numerator/denominator1
        ans = ans/denominator2
        
        return int(ans)
