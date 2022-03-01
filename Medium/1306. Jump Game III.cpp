class Solution {
public:
    vector<vector<int>> graph;
    
    void AddEdge(int start, int end){
        graph[start].push_back(end);
    }
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int src, int dest){
        
        if (nums[src] == dest)
            return true;
        
        bool temp = 0;
        for (int neighbour: graph[src]){
            if (visited[neighbour])
                continue;
            
            visited[neighbour] = 1;
            
            temp = max(temp, dfs(nums, visited, neighbour, dest));
        }
        return temp;
    }
    
    bool canReach(vector<int>& nums, int start) {
        
        int n = (int)nums.size();
        graph.resize(n);
        
        for (int i = 0; i < n; i++){
            if (nums[i] == 0)
                continue;
            
            int left = i - nums[i];
            int right = i + nums[i];
            
            if (left >= 0) AddEdge(i, left);
            if (right < n) AddEdge(i, right);
        }
//        print_graph(graph);
        vector<bool> visited(n, 0);
        
        return dfs(nums, visited, start, 0);
            
    }

};
