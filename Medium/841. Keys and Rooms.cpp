class Solution {
public:
    
    void AddEdge(vector<set<int>>& graph, int source, int destination){        
        graph[source].insert(destination);
    }
    
    void PrintGraph(vector<set<int>>& graph){
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
    
    void Dfs(vector<set<int>>& graph, vector<bool>& visited, int source){
        
        visited[source] = true;
        // cout << source << " \n";
        for (int neighbour : graph[source]){
            if (!visited[neighbour])
                Dfs(graph, visited, neighbour);
        }
        
    }
    
    bool IsMother(int n, vector<set<int>>& graph){
        
        vector<bool> visited(n, 0);
        int last_vertex = 0;
        
//         for (int i = 0; i < n; i++){
//             if (!visited[i]){
//                 Dfs(graph, visited, i);
//                 last_vertex = i;        
//             }
//         }
            
// //      Check if last vertex is mother vertex   
            
//         for (int i = 0; i < n; i++)
//             visited[i] = false;
//         cout << last_vertex << "hello\n";
        Dfs(graph, visited, last_vertex);
        
        for (bool i: visited){
            if (!i)
                return false;
        }
        return true;
        
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<set<int>> graph(n);
        
        for (int room = 0; room < n; room++){
            for (int key : rooms[room]){
                AddEdge(graph, room, key);
            }
        }
        
        // PrintGraph(graph);
        
        return IsMother(n, graph);
        
    }
};
