class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<bool>valid1(n,false);
        vector<bool>valid2(n,false);
        int maxl=nums[0];
        valid1[0]=true;
        valid2[n-1]=true;
        int maxr=nums[n-1];
        for(int i=1;i<nums.size()-1;i++){
           if(nums[i]>maxl){
               valid1[i]=true;
           }
            maxl=max(maxl,nums[i]);
            }
        for(int i=nums.size()-2;i>=1;i--){
           if(nums[i]>maxr){
               valid2[i]=true;
           } 
            maxr=max(maxr,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(valid1[i]||valid2[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
        }
};