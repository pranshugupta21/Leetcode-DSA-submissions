class Solution {
public:
    #define  ll long long
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        for(ll n1:nums){
            mp[n1]++;
        }
        ll max_len=1;
        if(mp.count(1)){
            ll ones_count=mp[1];
            if(ones_count%2==0) ones_count--;
            max_len=max(max_len,ones_count);
        }
        for(auto pair:mp){
            ll x=pair.first;
            if(x==1) continue;
            ll curr_len=0;
            while(mp.count(x)&&mp[x]>=2){
                curr_len+=2;
                x=x*x;
            }
            if(mp.count(x)){
                curr_len+=1;
            }
            else{
                curr_len-=1;
            }
            max_len=max(max_len,curr_len);
        }
       return max_len;
    }
};