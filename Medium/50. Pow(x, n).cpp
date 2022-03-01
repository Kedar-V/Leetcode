class Solution {
public:
    // 2 2 2 2 2 2 2 2 2 2
    //  4.    4.  
    double calc_pow_rec(double x, unsigned int n){
        
        if (n == 1)
            return x;
        double temp = calc_pow_rec(x, n/2);
        
        if (n%2 == 0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
        
    }
    
    double calc_pow_iter(double x, unsigned int n){
        
        double result = 1;

        while (n > 0) {
            if (n % 2 != 0) {
            result = result * x;
            }

            x = x * x;
            n = n / 2;
        }

        return result;
    }
    
    
    double myPow(double x, int n) {
        
        if (n == 0 || x == 1)
            return 1;
        if (x == -1){
            if (n % 2 == 0)
                return 1;
            return -1;
        }
        if (n == INT_MIN)
            return 0;
        bool neg = (n < 0);
        if (neg){
            x = 1/x;
            unsigned int temp = -1*n;
            return calc_pow_rec(x, temp);
        }

        return calc_pow_rec(x, n);
    }
};
