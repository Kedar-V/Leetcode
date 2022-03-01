class Solution {
public:
    
    void AddEdge(vector<vector<int>>& graph, int source, int destination){        
        graph[source].push_back(destination);
    }
    
    void RemoveEdge(vector<vector<int>>& graph, int source, int destination){
        graph[source].erase(remove(graph[source].begin(), graph[source].end(), destination));
    }
    
    void PrintGraph(vector<vector<int>>& graph){
        int count = 0;
        for (auto row : graph){
            cout << count++ << "--> ";
            for (int column : row){
                cout << column << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
        
    }
    
    bool isCycleUtil(vector<vector<int>>& graph, vector<bool>& visited, int source, int parent){
        
        visited[source] = true;
        cout << source << endl;
        for (int neighbour : graph[source]){
            
            if(!visited[neighbour]){
                if(isCycleUtil(graph, visited, neighbour, source)){
                    return true;
                }
            }
            else if (neighbour != parent)
                return true;
        }
        return false;
        
    }
    
    bool isCycle(vector<vector<int>>& graph, int n){
    
        vector<bool> visited (n+1, 0);
        
        for (int i = 1; i < n+1; i++){
            if (!visited[i]){
                if (isCycleUtil(graph, visited, i, -1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        
        bool flag = 0;
        vector<int> ans;
        int n = 0;
        for (auto edge : edges){
            for (int i : edge){
                n = max(n, i);
            }
        }
        vector<vector<int>> graph(n+1);
        
    
        for (vector<int> edge : edges){
            int start = edge[0];
            int dest = edge[1];
            AddEdge(graph, start, dest);
            AddEdge(graph, dest, start);
        }
        // PrintGraph(graph);
        // cout << isCycle(graph, n) << endl;
        // RemoveEdge(graph, 2, 4);
        // RemoveEdge(graph, 4, 2);
        // PrintGraph(graph);
        // cout << isCycle(graph, n) << endl;
        for (auto iter = edges.rbegin(); iter != edges.rend(); iter++){
            
            int start = (*iter)[0];
            int dest = (*iter)[1];
            RemoveEdge(graph, start, dest);
            RemoveEdge(graph, dest, start);
            
            PrintGraph(graph);
            if (!isCycle(graph, n)){
                ans.push_back(start);
                ans.push_back(dest);
                break;
            }
            else{
                AddEdge(graph, start, dest);
                AddEdge(graph, dest, start);
            }   
        } 
      
        return ans;
    }
};
