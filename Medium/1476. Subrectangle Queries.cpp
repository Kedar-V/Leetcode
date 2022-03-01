class SubrectangleQueries {
public:
    vector<vector<int>> Matrix;
    
    SubrectangleQueries(vector<vector<int>>& rectangle) 
    {
        
        int row = rectangle.size();
        int colm = rectangle[0].size();
        
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < colm; j++)
                temp.push_back(rectangle[i][j]);
            
            Matrix.push_back(temp);
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)     {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
                Matrix[i][j] = newValue;
        }    
    }
    
    int getValue(int row, int col) {
        return Matrix[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
