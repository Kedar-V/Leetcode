class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        l = len(s);
        visited = {}
        max_len = 0
        start_idx = 0
        for i in range(l):            
            if s[i] in visited:
                last_idx = visited[s[i]]
                start_idx = max(start_idx, last_idx + 1)
            curr_len = i - start_idx + 1
            visited[s[i]] = i
            max_len = max(max_len, curr_len)
        return max_len
