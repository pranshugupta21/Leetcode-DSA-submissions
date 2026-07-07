class Solution {
    int helper(long long base,long long exp,long long mod){
        int ans=1;
        while(exp>0){
            if(exp%2==0){
                base=(base*base)%mod;
                exp/=2;
            }
            else{
                ans=(ans*base)%mod;
                exp-=1;
            }
        }
        return ans;

    }
public:
    int countGoodNumbers(long long n) {
        long long even_pos=(n+1)/2;  // 0,2,4,6,8
        long long odd_pos=n/2;       // 1,3,5,7
        long long mod=1e9+7;
        long long even_choices=helper(5,even_pos,mod)%mod;
        long long odd_choices=helper(4,odd_pos,mod)%mod;
        long long ans= (even_choices*odd_choices)%mod;
        int x=int(ans);
        return x;
    }
};