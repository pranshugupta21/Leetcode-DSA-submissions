class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>freq(51,0),ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)freq[abs(nums[i])]++;
            if(i>=k){
                if(nums[i-k]<0){
                    freq[abs(nums[i-k])]--;
                }
            }
            if(i>=k-1){
                int beauty=0;
                int c=0;
                for(int val=50;val>=1;val--){
                    c+=freq[val];
                    if(c>=x){
                        beauty=-1*val;
                        break;
                    }
                }
                ans.push_back(beauty);
            }
            
        }
        return ans;
    }
};