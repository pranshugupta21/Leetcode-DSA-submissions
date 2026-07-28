class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt=0;
        solve(nums,target,cnt,0,0);
       return cnt;
    }
    private:
    void solve(vector<int>&nums,int target,int &cnt,int i, int eval){
        if(i==nums.size()){
            if(eval==target)cnt++;
        return;
        }
            solve(nums,target,cnt,i+1,eval+nums[i]);
            solve(nums,target,cnt,i+1,eval-nums[i]);
    }
};