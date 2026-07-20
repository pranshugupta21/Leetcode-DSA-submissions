class Solution {
public:
    int countArrangement(int n) {
        vector<int>nums;
        int count=0;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        permutation(n,nums,count,0);
        return count;
    }
    private:
         void permutation(int n,vector<int>&nums,int &count,int idx){
            if(idx==n){
                count++;
                return;
            }
            for(int i=idx;i<n;i++){
                swap(nums[i],nums[idx]);
                if(nums[idx]%(idx+1)==0 || (idx+1)%nums[idx]==0){
                    permutation(n,nums,count,idx+1);
                }
                swap(nums[i],nums[idx]);
            }
         }
};