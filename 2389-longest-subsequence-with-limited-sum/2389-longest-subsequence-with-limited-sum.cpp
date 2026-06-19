class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(auto q:queries){
            auto it=upper_bound(nums.begin(),nums.end(),q);
            int dis=(it-nums.begin());
            ans.push_back(dis);
        }
        return ans;
    }
};