class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        
        visited = set()
        graph = {i : [] for i in range(n)}

        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        colors = [0 for _ in range(n)]
        def dfs(node, color):
            if node in visited:
                return

            visited.add(node)
            neighbours = graph[node]
            colors[node] = color

            for neighbour in neighbours:
                dfs(neighbour, color)

        color = 0
        for node in range(n):
            if node not in visited:
                dfs(node, color)
                color += 1
        
        colorNums = [0 for i in range(color)]
        for c in colors:
            colorNums[c] += 1

        ans = 0
        for i in range(color):    
            ans += colorNums[i] * (n - colorNums[i])

        return ans // 2


        
