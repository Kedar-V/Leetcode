/*
1
1

3 1 
3

-1 3 1
3 -1

-3 -1 3
3 -1 -3

5 -3 -1
5 -1 -3

*/

// class Deque {
// public:
    
//     int k;
//     int curr_len;
//     int Max = INT_MIN;
//     vector<int> deque;
//     vector<int> max_deq;
    
//     Deque(int K){
//         k = K;
//         curr_len = 0;
//     }
    
//     void push(int i){
//         if (curr_len == k){
//             deque.erase(deque.begin());
//             deque.push_back(i);
//         }
//         else{
//             deque.push_back(i);
//             curr_len++;
//         }
//     }
    
//     void pop_front(){
//         if (curr_len == 0)
//             return;
//         deque.erase(deque.begin() + curr_len - 1);
//         curr_len--; 
//     }
    
//     void pop_back(){
//         if (curr_len == 0)
//             return;
//         deque.erase(deque.begin());
//         curr_len--;
//     }
    
//     bool empty(){
//         if (curr_len == 0)
//             return true;
//         return false;
//     }
    
//     int front(){
//         return deque[curr_len - 1];
//     }
    
//     int back(){
//         return deque[0];
//     }
    
//     void print(){
//         for (int i : deque)
//             cout << i << " ";
//         cout << endl;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         vector<int> ans;
//         int n = nums.size();
        
//         Deque* D = new Deque(k);
//         vector<int> deque = D -> deque;
        
//         for (int i = 0; i < k; i++){
//             while(!D -> empty() && D -> front() < nums[i]){
//                 D -> pop_front();                   
//             }
//             D -> push(nums[i]);
//         }
//         ans.push_back(D -> back());
//         // D -> print();
        
//         for (int i = k; i < n; i++){
//             if (nums[i-k] == D->back())
//                 D -> pop_back();
            
//             while(!D -> empty() && D -> front() < nums[i]){
//                 D -> pop_front();                   
//             }
//             D -> push(nums[i]);
//             ans.push_back(D -> back());
//             // D -> print();
//         }

//         return ans;
        
        vector<int> ans;
        int n = nums.size();
    
        deque<int> d;
        
        for (int i = 0; i < k; i++){
            while(!d.empty() && d.front() < nums[i]){
                d.pop_front();                   
            }
            d.push_front(nums[i]);
        }
        ans.push_back(d.back());
        // D -> print();
        
        for (int i = k; i < n; i++){
            if (nums[i-k] == d.back())
                d.pop_back();
            
            while(!d.empty() && d.front() < nums[i]){
                d.pop_front();                   
            }
            d.push_front(nums[i]);
            ans.push_back(d.back());
            // D -> print();
        }

        return ans;
    }
};
