class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>res;
        auto it1=lower_bound(nums.begin(),nums.end(),target);
        int firstidx=it1-nums.begin();
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        int lastidx=it2-nums.begin();
        lastidx--;
        for(int i=firstidx;i<=lastidx;i++) res.push_back(i);
        return res;
    }
};