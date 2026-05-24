class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int minn=-1;
        int n=nums.size();
        bool poss = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=0;j<n;j++){
                    if(nums[j]==2){
                        minn= i-j;
                        poss = true;
                        break;
                    }
                }
            }
        }
        if(!poss) return -1;
        return abs(minn);
    }
};