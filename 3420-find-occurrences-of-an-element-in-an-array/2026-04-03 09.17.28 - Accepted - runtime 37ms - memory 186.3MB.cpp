class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>ans(queries.size());
        unordered_map<int,int>mp;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                c++;
                mp[c]=i;
            }}
        for(int j=0;j<queries.size();j++){
           if(mp.find(queries[j])!=mp.end()){
            ans[j]=mp[queries[j]];
           }
           else{
            ans[j]=-1;
           }
        }
        return ans;

    }
};