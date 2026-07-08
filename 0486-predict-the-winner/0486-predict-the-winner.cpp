class Solution {
public:
     int maxdiff(vector<int>&nums,int left,int right){
        if(left==right) return nums[left];
        int leftScore=nums[left]-maxdiff(nums,left+1,right);
        int rightScore=nums[right]-maxdiff(nums,left,right-1);
        return max(leftScore,rightScore);
     }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return maxdiff(nums,0,n-1)>=0;
    }
};