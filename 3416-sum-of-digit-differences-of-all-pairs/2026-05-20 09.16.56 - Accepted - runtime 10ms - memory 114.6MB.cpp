class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long diff=0;
        int freq[10][10]={0};
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int pos=0;
            while(val>0){
                int digit=val%10;
                diff+=(i-freq[pos][digit]);
                freq[pos][digit]++;
                val/=10;
                pos++;
            }
        }
        return diff;
    }
};