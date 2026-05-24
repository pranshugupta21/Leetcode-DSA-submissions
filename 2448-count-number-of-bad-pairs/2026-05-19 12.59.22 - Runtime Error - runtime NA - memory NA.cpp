class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        long long total_pairs=n*(n-1)/2;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int key=nums[i]-i;
            c+=mp[key];
            mp[key]++;
        }

        return total_pairs-c;
    }
};