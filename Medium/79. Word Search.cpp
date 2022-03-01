class Solution {
public:
    vector<vector<char>> new_board;
    
    int m;
    int n;
    
    bool IsValid(int x, int y){
        
        if ((x >= 0 && x < m) && (y >= 0 && y < n))
            return true;
        return false;       
    }
    
    bool solve(vector<vector<bool>>& visited, int curr_x, int curr_y, string word, string& target, int curr_len){
        
        // cout << word << endl;
        if(word[curr_len-1] != target[curr_len-1]){
            return false;
        }
        
        if(curr_len == target.length()){
            return true;
        }
            
        // vector<pair<int, int>> moves = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
        // for (auto move: moves){
        // int next_x = curr_x + move.first;
        // int next_y = curr_y + move.second;


        if (IsValid(curr_x - 1, curr_y) && !visited[curr_x-1][curr_y]){
            word = word + new_board[curr_x - 1][curr_y];
            visited[curr_x - 1][curr_y] = true;
            if (solve(visited, curr_x - 1, curr_y, word, target, curr_len + 1))
                return true;
            visited[curr_x - 1][curr_y] = false;
            word.pop_back();
        }
        
        if (IsValid(curr_x + 1, curr_y) && !visited[curr_x+1][curr_y]){
            word = word + new_board[curr_x + 1][curr_y];
            visited[curr_x + 1][curr_y] = true;
            if (solve(visited, curr_x + 1, curr_y, word, target, curr_len + 1))
                return true;
            visited[curr_x + 1][curr_y] = false;
            word.pop_back();
        }
        
        if (IsValid(curr_x, curr_y - 1) && !visited[curr_x][curr_y-1]){
            word = word + new_board[curr_x][curr_y-1];
            visited[curr_x][curr_y-1] = true;
            if (solve(visited, curr_x, curr_y - 1, word, target, curr_len + 1))
                return true;
            visited[curr_x][curr_y-1] = false;
            word.pop_back();
        }
        
        if (IsValid(curr_x, curr_y + 1) && !visited[curr_x][curr_y+1]){
            word = word + new_board[curr_x][curr_y+1];
            visited[curr_x][curr_y+1] = true;
            if (solve(visited, curr_x, curr_y+1, word, target, curr_len + 1))
                return true;
            visited[curr_x][curr_y+1] = false;
            word.pop_back();
        }
            
        // }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        new_board = board;
        m = board.size();
        n = board[0].size();
        string str(1, board[0][0]);
        reverse(word.begin(), word.end());
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                string str(1, new_board[i][j]);
                visited[i][j] = true;
                if(solve(visited, i, j, str, word, 1))
                    return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};
