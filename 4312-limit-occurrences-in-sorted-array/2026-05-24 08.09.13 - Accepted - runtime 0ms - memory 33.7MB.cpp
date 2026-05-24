class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int n:nums){
            mp[n]++;
            if(mp[n]<=k){
                ans.push_back(n);
            }
            
        }
       return ans;
    }
};