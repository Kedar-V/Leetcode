#include <unordered_map>
#include <set>
#include <queue>
class Solution {
public:
    
    
    void print_vec(vector<int>& vec){
        cout << "---NEIGHBOURS---\n";
        for (int i : vec)
            cout << i << " ";
        cout << "------------------------" << endl;
        
    }
    
    bool single_layer_bfs(vector<set<pair<int, int>>>& graph, int source, int n){
        
        int count = 0;
    
        for (auto neighbour : graph[source]){
            
            int dest = neighbour.first;
            int wt = neighbour.second;
            
            if (wt == 2)
                count++;
        }
        if (count == n-1)
            return true;
        return false;
        
    }
    
    
    
    void print_graph(vector<set<pair<int, int>>>& graph){
        
        int count = 0;
        for (auto row : graph){
            cout << count++ << "--> ";
            for (auto column : row){
                cout << column.first << "," << column.second << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
    }
    
    void add_edge(vector<set<pair<int, int>>>& graph, int source, int dest, int wt){
        graph[source].insert(make_pair(dest, wt));
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<bool> possible_judges(n+1, true);
        
        vector<set<pair<int, int>>> graph(n+1);
        
        possible_judges[0] = false;
        
        for (vector<int> trust_pair : trust){     
            int source = trust_pair[0];
            int dest = trust_pair[1];
            
            possible_judges[source] = false;            
            add_edge(graph, source, dest, 1);
            add_edge(graph, dest, source, 2);
        }
        
        // print_graph(graph);

        for (int i = 1; i < n+1; i++){
            if (possible_judges[i]){
                if(single_layer_bfs(graph, i, n))
                    return i;
            }
        }
        
        return -1;
        
        
        
    }
};



