class Solution {
public:
    int mySqrt(int x) {
        long long low=0,high=x;
        while(low<=high){
            long long mid=(low+high)/2;
            long long sq=mid*mid;
            if(sq>x){
                high=mid-1;
            }
            else if(sq==x) return mid;
            else low=mid+1;
        }
        return high;
    }
};