class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixleft(n,0);
        vector<int>prefixright(n,0);
        for(int i=1;i<n;i++){
            prefixleft[i]=prefixleft[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            prefixright[i]=prefixright[i+1]+nums[i+1];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int sum=abs(prefixleft[i]-prefixright[i]);
            ans[i]=sum;
        }
        return ans;
    }
};