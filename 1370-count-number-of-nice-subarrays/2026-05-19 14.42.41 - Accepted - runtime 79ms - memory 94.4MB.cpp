class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        freq[0]=1;
        int curr_odd=0;
        int nice_subarray=0;
        for(int n:nums){
            if(n%2!=0){
                curr_odd++;
            }
            int target=curr_odd-k;
            if(freq.count(target)){
                nice_subarray+=freq[target];
            }
            freq[curr_odd]++;
        }
        return nice_subarray;
    }
};