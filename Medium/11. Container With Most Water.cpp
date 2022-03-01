class Solution {
public:
    
    int getArea(vector<int>& height, int start, int end){
        if (start >= end)
            return -1;
        
        return min(height[start], height[end]) * (end - start);
    }
        
    int maxArea(vector<int>& height) {
        
        int start = 0;
        int end = height.size() - 1;
        int Max = INT_MIN;
        
        while (start < end){
            int curr_area = getArea(height, start, end);
            Max = max(Max, curr_area);
            if ( height[start] < height[end] ){
                start += 1;
            }
                
            else {
                end -= 1;
            }
            
        }
        return Max;
        
        
    }
};
