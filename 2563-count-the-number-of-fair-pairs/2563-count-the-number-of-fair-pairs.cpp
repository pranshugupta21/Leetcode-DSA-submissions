class Solution {
public:
    long long countatmost(vector<int>&nums,long long range){
        long long i=0,j=nums.size()-1;
        long long ans=0;
        while(i<j){
            if(nums[i]+nums[j]<=range) {
                ans+=j-i;
                i++;
            }
            else {
            j--;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long pairs=countatmost(nums,1LL*upper)-countatmost(nums,1LL*lower-1);
        return pairs;
    }
};