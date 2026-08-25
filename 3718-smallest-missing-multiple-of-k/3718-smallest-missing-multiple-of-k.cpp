class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int idx=1;
        int req=k*idx;
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0 && prev!=nums[i]){
                if(nums[i]!=req) break;
                else{
                    idx++;
                    req=k*idx;
                }
            }
            prev=nums[i];
        }
        return req;
    }
};