class NumArray
{
public:
    int *seg;
    int len;
    int n;
    vector<int> arr;
    int Mid(int s, int e) {return s + (e-s)/2;}
    
    int construct_ST(vector<int>& nums, int seg_s, int seg_e, int curr, int len)
    {
        
        if (seg_s == seg_e)
            return seg[curr] = nums[seg_s];
        
        //Index of children
        int left = 2*curr + 1;
        int right = 2*curr + 2;
        
        int mid = Mid(seg_s, seg_e);
        
        //Parent seg = sum of children
        seg[curr] = construct_ST(nums, seg_s ,mid , left, len) + construct_ST(nums, mid+1, seg_e, right, len);
        
        return seg[curr];
    }
    
    NumArray(vector<int>& nums)
    {
        int N = int(nums.size());
        if (N > 0)
        {
            int height = (int)(ceil(log2(N)));
            int max_nodes = 2*pow(2, height) - 1;
            
            seg = new int[max_nodes];
            arr = nums;
            
            construct_ST(nums, 0, N-1, 0, max_nodes);
            
            len = max_nodes;
            n = N;
        }
    }
    
    
    void update_util(int i, int diff, int seg_s, int seg_e, int curr)
    {
        if (i < seg_s || i > seg_e)
            return;
        
        seg[curr] += diff;
        
        if (seg_s != seg_e)
        {
            int mid = Mid(seg_s, seg_e);
            
            update_util(i, diff, seg_s, mid, 2*curr + 1);
            update_util(i, diff, mid+1, seg_e, 2*curr + 2);
        }
    }
    
    void update(int i, int val)
    {
        int diff = val - arr[i];
        arr[i] = val;
        update_util(i, diff, 0, n-1, 0);
    }
    
    int sumRange_util(int L, int R, int seg_s, int seg_e, int curr)
    {
        // if the curr_seg is part of the required range
        if (L <= seg_s && R >= seg_e)
            return seg[curr];
        
        // if the curr_seg is not part of the required range
        if (L > seg_e || R < seg_s)
            return 0;
        
        // if the curr_seg overlaps with the given range
        int mid = Mid(seg_s, seg_e);
        
        return sumRange_util(L, R, seg_s, mid, curr*2 + 1) + sumRange_util(L, R, mid + 1, seg_e, curr*2 + 2);
    }
    
    int sumRange(int i, int j)
    {
//        if (i < 0 || j >= n)
//            return -1;
//
        return sumRange_util(i, j, 0, n-1, 0);
    }
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
