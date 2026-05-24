class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>idx,ans(queries.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                idx.push_back(i);
            }}
            int n1=idx.size();
        for(int j=0;j<queries.size();j++){
           if(n1<queries[j]){
             ans[j]=-1;
           }
           else{
            ans[j]=idx[queries[j]-1];
           }
        }
        return ans;

    }
};