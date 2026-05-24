class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_set<int>st;
        vector<vector<int>>ans;
        vector<int>v;
        int s=nums.size();
        int c=0;
        for(int in: nums){
            if(st.find(in)!=st.end()){
              st.clear();
              ans.push_back(v);
              v.clear();
            }
            c++;
            st.insert(in);
            v.push_back(in);
            if(c==s){
                ans.push_back(v);
            }
        }
        return ans;
    }
};