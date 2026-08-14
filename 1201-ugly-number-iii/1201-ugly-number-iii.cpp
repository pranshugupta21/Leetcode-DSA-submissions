class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int low=1,high=2e9;
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countdivisiblenumbers(a,b,c,mid)>=n){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int countdivisiblenumbers(long long a,long long b,long long c, long long num){
    return num/a + num/b + num/c - num/lcm(a,b) - num/lcm(b,c) - num/lcm(c,a) + num/lcm(a,lcm(b,c));
    }
    long long gcd(long long a,long long b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    long long lcm(long long a,long long b){
        return (a*b)/gcd(a,b);
    }
};