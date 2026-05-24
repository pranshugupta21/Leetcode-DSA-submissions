class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int minn=INT_MAX;
        int cnt=0;
        int n=nums.size();
        // bool poss = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=i+1;j<n;j++){
                    if(nums[j]==2){
                        minn= min(minn,abs(i-j));
                        cnt++;
                    }
                }
            }
            if(nums[i]==2){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]==1){
                        minn=min(minn,abs(i-j));
                        cnt++;
                    }
                }
            }
        }
        if(cnt==0) return -1;
        return minn;
    }
};