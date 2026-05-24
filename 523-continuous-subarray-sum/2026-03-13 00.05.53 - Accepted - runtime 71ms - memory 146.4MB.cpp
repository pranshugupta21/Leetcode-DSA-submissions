class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool check=false;
        long long prefix=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
             prefix+=nums[i];
        long long rem=(prefix%k+k)%k;
        if(mp.count(rem)){
        if(i-mp[rem]>=2){
        return true;}
        }
        else{
        mp[rem]=i;
         }
    }
    return false;
    }
};