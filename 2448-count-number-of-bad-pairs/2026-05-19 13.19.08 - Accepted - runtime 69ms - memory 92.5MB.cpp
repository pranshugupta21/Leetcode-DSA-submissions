class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long good_pairs=0;
        long long total_pairs=(n*(n-1))/2;
        unordered_map<long ,long>mp;
        for(int i=0;i<n;i++){
            long long key=nums[i]-i;
            if(mp.count(key)){
              good_pairs+=mp[key];
            }
            mp[key]++;
        }

        return total_pairs-good_pairs;
    }
};