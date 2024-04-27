class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        groups = []
        hashmaps = {}

        def getIndex(string):
            index = [0 for i in range(26)]
            for c in string:
                index[ord(c) - ord('a')] += 1
            return tuple(index)

        def group(string):
            nonlocal groups
            nonlocal hashmaps
            index = getIndex(string)
            if index in hashmaps:
                groups[hashmaps[index]].append(string)
            else:
                hashmaps[index] = len(groups)
                groups.append([string])

        for word in strs:
            group(word)
        
        return groups
