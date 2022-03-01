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
            // int A1 = getArea(height, start + 1, end);
            // int A2 = getArea(height, start, end - 1);
            //cout << curr_area << " " << A1 << " " << A2 << endl;
            //cout << start << " " << end << "--->" << curr_area << endl;
            //int max_area = max({A1, A2, curr_area});
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
