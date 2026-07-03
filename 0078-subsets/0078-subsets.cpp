class Solution {
    void findsubsets(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&allsubsets){
        if(i==nums.size()){
            allsubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        findsubsets(nums,ans,i+1,allsubsets);
        ans.pop_back();
        findsubsets(nums,ans,i+1,allsubsets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allsubsets;
        vector<int>ans;
        findsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};