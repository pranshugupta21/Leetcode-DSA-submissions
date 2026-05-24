class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int c=0;
        for(int in:nums){
            mp[in]++;
            c=max(c,mp[in]);
        }

        vector<vector<int>>ans(c);
        for(auto it: mp){
            int n=it.first;
            int freq=it.second;
            for(int i=0;i<freq;i++){
                ans[i].push_back(n);
            }
            }
            return ans;
        }
        
    
};