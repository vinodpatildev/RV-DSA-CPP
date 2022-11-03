#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nc = abs(n);
        while(nc){
            if(nc&1){
                ans *= x;
            }
            nc = nc >> 1;
            x *= x;
        }
        return n<0? 1.0/(ans) : ans;        
    }
};
class SolutionStriver {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nc = abs(n);
        while(nc>0){
            if(nc%2 == 1){
                ans *= x;
                nc--;
            }else{
                x *= x;
                n /= 2;
            }
        }
        if(n<0){ ans = 1.0/(ans); }
        return ans;
    }
};
