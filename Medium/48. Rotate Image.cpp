    
// 00 01 02   1) exhange, 
// 10 11 12
// 20 21 22

using namespace std;


// 3 6 

class Solution {
public:
    
    void print_matrix(vector<vector<int>>& matrix){
        for (auto i : matrix){
            for (int j : i){
                cout << j << " ";
            }
            cout << endl;
        }
         cout << endl;
    }
    
    void swap_matrix(vector<vector<int>>& matrix){
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);  
            }
            // cout << "-----------\n";
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                swap(matrix[j][i], matrix[i][j]);  
            }
            
            // cout << "-----------\n";
        }
        // print_matrix(matrix);
        swap_matrix(matrix) ;
        // print_matrix(matrix);
    }
};
