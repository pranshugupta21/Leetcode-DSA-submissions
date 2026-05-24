class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>jj;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                jj.push_back(i);
            }
        }
        int n1=jj.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n1;j++){
                if(abs(i-jj[j])<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};