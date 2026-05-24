class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>freq;
        int bs=0;
        int px=0;
      //  freq[0]=1;
        for(int nm:nums){
            px+=nm;
            if(px==goal)bs++;
            int target=(px-goal);
            if(freq.count(target)){
                bs+=freq[target];
            }
            freq[px]++;
        }
        return bs;
    }
};