using namespace std;

class Solution {
public:
    
    bool IsOvf(long num){
        
        if (num > INT_MAX || num < INT_MIN)
            return true;
        return false;
        
    }
    
    int reverse(int x) {
        
        long num = x;
        bool flag = false;
        if (num < 0){
            flag = true;
            num = num*(-1);
        }
        
        string rev_num = to_string(num);
        std::reverse(rev_num.begin(), rev_num.end());
        
        long N = stol(rev_num);
        
        if(!IsOvf(N)) {
            
            if (flag) return -1*N;
            
            return N;
        }
        
        return 0;
        
        
    }
};
