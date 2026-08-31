class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;              // convert into largest subarray with sum equals 0
            }
        }
        unordered_map<int,int>zerosum;
        int sum=0,maxlen=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0) maxlen=i+1;
            else if(zerosum.find(sum)!=zerosum.end()){
                maxlen=max(maxlen,i-zerosum[sum]);
            }
            else{
                zerosum[sum]=i;
            }
        }
        return maxlen;
    }
};