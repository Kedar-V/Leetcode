class Solution {
public:
    
    int count_rows_neg(vector<int>& arr, int n)
    {
        int low = 0;
        int high = n;
        
        int count = 0;
        while (low < high)
        {
            int mid = low + (high - low)/2;

            if (arr[mid] < 0)
            {
                count = n - mid;
                high = mid;  
            }
            
            else
                low = mid + 1;
        }
        return count;
    }
    
    int countNegatives(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        
        if (rows == 0)
            return 0;
        
        int colm = grid[0].size();
        
        int count = 0;
        for (int i = 0 ; i < rows; i++)
        {
  //          cout << count_rows_neg(grid[i], colm) << endl;
            count += count_rows_neg(grid[i], colm);
        }
        
        return count;
    }
};
