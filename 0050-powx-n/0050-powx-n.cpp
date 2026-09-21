class Solution {
private:
    void solve(double x, long long power, double &ans){
        if(power<=0) return;
        if(power%2==0){
            solve(x*x,power/2,ans);
        }
        else{
            ans=ans*x;
            solve(x,power-1,ans);
        }
    }
    
public:
    double myPow(double x, int n) {
        double base=x;
        long long power=(long long)n;
        if(n<0) base=1/base;

        double ans=1;

        solve(base,abs(power),ans);

        return ans;
    }
};