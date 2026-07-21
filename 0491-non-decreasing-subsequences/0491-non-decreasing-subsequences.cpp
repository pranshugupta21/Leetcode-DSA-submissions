class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        backtrack(nums,n,0,curr,ans);
        return ans;
    }
    private:
    void backtrack(vector<int>&nums,int n,int idx,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()>1){
        ans.push_back(curr);
      }
      unordered_set<int>used;
      for(int i=idx;i<n;i++){
         if((curr.empty()||nums[i]>=curr.back()) && used.find(nums[i])==used.end()){
            used.insert(nums[i]);         // while reverting back it checks whether the element has be used or not
        curr.push_back(nums[i]);
        backtrack(nums,n,i+1,curr,ans);
        curr.pop_back();
         }
      }
    }
};