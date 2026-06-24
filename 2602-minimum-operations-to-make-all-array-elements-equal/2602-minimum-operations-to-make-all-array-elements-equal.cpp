class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long>ans;
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
         for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
         }
         for(auto &q:queries){
            auto it=lower_bound(nums.begin(),nums.end(),q)-nums.begin();
            long long rsum=0,lsum=0;
           lsum=(it==0)? 0:prefix[it-1];
           rsum=prefix[n-1]-lsum;
           long long lcost=abs((q*it)-lsum);
           long long rcost=abs(rsum-(q*(n-it)));
            ans.push_back(lcost+rcost);
         }

        return ans;
    }
};