class Solution:
    def countAndSay(self, n: int) -> str:
        def say(s):
            sayStr = ""
            prev = s[0]
            count = 1
            for c in s[1:]:
                if prev == c:
                    count += 1
                else:
                    sayStr = sayStr + f"{count}{prev}"
                    count = 1
                    prev = c
            sayStr = sayStr + f"{count}{prev}"
            return sayStr

        dp = ["" for _ in range(n)]
        dp[0] = "1"

        for i in range(1, n):
            dp[i] = say(dp[i-1])

        return dp[n-1]


