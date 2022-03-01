class Solution {
public:
    
    
    int binary_search(vector<int>& arr, int low, int high, int find)
    {  
        if (low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        if (arr[mid] == find)
            return mid;
              
        if (low == high)
            return -1;
        
        else if (arr[mid] > find)
            return binary_search(arr, low, mid, find);
        else
            return binary_search(arr, mid+1, high, find);
    }
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        
        vector<vector<int>> ans;
        
//         set<int> s;
        
        int len = arr.size();
        sort(arr.begin(), arr.end());
        
        int Min = INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            if (abs(arr[i+1]-arr[i]) < Min)
                Min = abs(arr[i+1] - arr[i]);
        }

        cout << Min << endl;
        

        
        for (int i = 0; i < len; i++)
        {
            vector<int> temp;
            int j = binary_search(arr, i+1, len-1, arr[i] + Min);
   //         cout << j << endl;
            if (j == -1)
                continue;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);
            
        }
        
        // for (int j = i+1; j < len; j++)
        // {
        //     vector <int> temp;
        //     if (abs(arr[i] - arr[j]) == Min)
        //     {
        //         temp.push_back(arr[i]);
        //         temp.push_back(arr[j]);
        //         sort(temp.begin(), temp.end());
        //         ans.push_back(temp);
        //     }
        // }
        
        return ans;
    }
};
