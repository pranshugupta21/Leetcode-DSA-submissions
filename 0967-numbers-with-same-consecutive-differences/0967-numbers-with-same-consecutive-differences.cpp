class Solution {
public:
    void dfs(vector<int>&ans,int num,int n,int k){
        if(n==0){
            ans.push_back(num);
            return;
        }
        int last_digit=num%10;
      if(last_digit+k<=9)  dfs(ans,((num*10)+last_digit+k),n-1,k);
      if(k!=0 && last_digit-k>=0)  dfs(ans,((num*10)+last_digit-k),n-1,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int num=1;num<=9;num++){
            dfs(ans,num,n-1,k);
        }
        return ans;

    }
};