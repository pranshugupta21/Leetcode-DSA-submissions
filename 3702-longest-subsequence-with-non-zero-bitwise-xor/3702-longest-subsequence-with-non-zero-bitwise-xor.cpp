class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int totalxor=0;
        bool allz=true;
        for(auto num:nums){
           totalxor^=num;
           if(num>0){
            allz=false;
           }
        }
        if(totalxor!=0) return n;
        if(allz){
            return 0;
        }
        else{
            return n-1;
        }
    }
};