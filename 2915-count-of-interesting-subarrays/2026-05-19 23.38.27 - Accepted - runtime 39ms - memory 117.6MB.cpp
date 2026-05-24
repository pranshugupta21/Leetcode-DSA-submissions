
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<long long,long long>freq;
        freq[0]=1;
        long long interesting_subarray=0;
        long long prefix_sum=0;
        for(int nm:nums){
            if(nm%modulo==k){
                prefix_sum=(prefix_sum+1)%modulo;
            }
            int target=(prefix_sum-k+modulo)%modulo;
            if(freq.count(target)){
                interesting_subarray+=freq[target];
            }
            freq[prefix_sum]++;
        }
        return interesting_subarray;
    }
};