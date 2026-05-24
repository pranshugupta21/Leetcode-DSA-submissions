class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[i]!=j-i)c++;
            }
        }
        return c;
    }
};