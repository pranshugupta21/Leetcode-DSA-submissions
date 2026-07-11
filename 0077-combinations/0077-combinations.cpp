class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,int n,int k,int i){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(curr.size()>k) return;
        for(int start=i;start<=n;start++){
        curr.push_back(start);
        solve(ans,curr,n,k,start+1);
        curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,n,k,1);
        return ans;
    }
};