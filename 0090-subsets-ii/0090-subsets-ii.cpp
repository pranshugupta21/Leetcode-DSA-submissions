class Solution {
public:
    void findallsubsets(vector<int>&nums,int i,vector<int>&ans,vector<vector<int>>&allsubsets){
        if(i==nums.size()){
          allsubsets.push_back({ans});
          return;
        }
       
        ans.push_back(nums[i]);
        findallsubsets(nums,i+1,ans,allsubsets);
        ans.pop_back();
         while(i<(nums.size()-1)&&nums[i]==nums[i+1]){
            i++;
        }
        findallsubsets(nums,i+1,ans,allsubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        findallsubsets(nums,0,ans,allsubsets);
        return allsubsets;
    }
};