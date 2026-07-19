class Solution {
public:
    void backtrack(vector<vector<int>>&ans,vector<int>&nums,int idx,int n){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            backtrack(ans,nums,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        backtrack(ans,nums,0,n);
        return ans;
    }
};