class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        int n=nums.size();
        if(target==0){
            int c1=n;
            for(auto i:nums){
                if(i==0) c1--;
            }
           return c1; 
        } 
        vector<int>xorr(nums.size(),0);
        xorr[0]=nums[0];
        int s=nums[0];
        int sum=s;
        for(int i=1;i<nums.size();i++){
            xorr[i]=xorr[i-1]^nums[i];
            s=s^nums[i];
        }
        if(s==target) return 0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]^s)==target) {
                //c++;
                return 1;
            }
            //else c++;
        }
         return c==0? -1:c;
    }
};