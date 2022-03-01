class Solution {
public:
    
    void Dfs(int n, vector<vector<int>>& graph, vector<bool>& visited, int source){
        
        visited[source] = true;
        // cout << source << endl;
        for (int i = 0; i < n; i++){
            if (graph[source][i] && !visited[i]){
                Dfs(n, graph, visited, i);
            }
        }
        
    }
    
    void print_graph(vector<vector<int>>& graph){
        int count = 0;
        cout << "     ";
        for (auto x : graph[0])
            cout << count++ << " ";
        cout << endl;
        count = 0;
        for (auto row : graph){
            cout << count++ << "--> ";
            for (int column : row){
                cout << column << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<bool> visited(n, 0);
        int count = 0;
        // print_graph(isConnected);
        for (int src = 0; src < n; src++){
            if (!visited[src]){
                Dfs(n, isConnected, visited, src);
                count++;
            }

        }
        return count;
    }
};
