class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&curr,int cnt,int k,int sum){ 
        if(curr.size()==k){
            if(sum==0){
            ans.push_back(curr);
            }
            return;
        }
        if(cnt>9||cnt>sum) return;
        curr.push_back(cnt);
        solve(ans,curr,cnt+1,k,sum-cnt); //pick
        curr.pop_back();
         solve(ans,curr,cnt+1,k,sum);    //notpick
         
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,1,k,n);
        return ans;
    }
};