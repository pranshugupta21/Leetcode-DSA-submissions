class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int j=0;j<operations.size();j++){
            int pos=mp[operations[j][0]];
            nums[pos]=operations[j][1];
            mp[operations[j][1]]=pos;
        }
        return nums;
    }
};