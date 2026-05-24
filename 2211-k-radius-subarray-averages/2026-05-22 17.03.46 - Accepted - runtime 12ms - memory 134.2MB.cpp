class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(n<2*k+1){
           return ans;
        }
        long long windowsum=accumulate(nums.begin(),nums.begin()+(2*k+1),0LL);
        ans[k]=windowsum/(2*k+1);
        for(int i=k+1;i<n-k;i++){
          windowsum+=nums[i+k];
          windowsum-=nums[i-k-1];
          ans[i]=windowsum/(2*k+1);
        }
        return ans;
    }
};