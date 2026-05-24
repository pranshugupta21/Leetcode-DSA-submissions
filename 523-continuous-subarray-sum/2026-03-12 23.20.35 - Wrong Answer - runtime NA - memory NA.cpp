class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool check=false;
        int prefix=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
        int rem=(prefix%k+k)%k;
        if(mp.count(rem)&&rem!=0){
            if(i-mp[rem]>=2){
            check=true;
            return check;
            }   
        }
        mp[rem]=i+1;
        prefix+=nums[i];
        }
        return check;
    }
};