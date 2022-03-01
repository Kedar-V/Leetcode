class Solution {
public:
    
    /*  
    0 - 000
    1 - 001
    2 - 010
    3 - 011
    4 - 100
    5 - 101
    6 - 110
    7 - 111
    */

    vector<int> countBits(int num) {
        
        vector<int> arr(num+1, 0);
        for (int i = 1; i <= num; i++)
        {
           // if ((i & (i-1)) == 0)
           //     arr[i] = 1;
            if (i % 2 == 0)
                arr[i] = arr[i>>1];
            else
                arr[i] = arr[i-1] + 1;
                
        }
        
        return arr;
    }
};
