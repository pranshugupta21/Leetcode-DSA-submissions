class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long div1=(long long)divisor1;
        long long div2=(long long)divisor2;
        long long low=0,high=1e10,ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
             long long cnt1=mid-(mid/div1);
             long long cnt2=mid-(mid/div2);
             long long bothcnt=mid-(mid/std::lcm(div1,div2));// divisible by both so shouldn't be in either array
             if(cnt1>=uniqueCnt1 && cnt2>=uniqueCnt2 && bothcnt>=(long long)(uniqueCnt1+uniqueCnt2)){
                ans=mid;
                high=mid-1;
             }
             else{
                low=mid+1;
             }
        }
        return ans;
    }
};