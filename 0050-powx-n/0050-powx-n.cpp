class Solution {
public:
    double myPow(double x, int n) {
       long long num=n;
       if(num<0){
        x=1.0/x;
        num=-num;
       }
        double ans=1.0;
        while(num>0){
            if(num%2==1){
                ans=ans*x;
                num=num-1;
            }
            else{
                num/=2;
                x=x*x;
            }
        }
        return ans;
            }
};