class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>bonus(n+1,0);
        for(auto &b: boosts){
            long long l=b[0],r=b[1],v=b[2];
           bonus[l]+=v;
            bonus[r+1]+=-v;
        }
        for(int i=1;i<n;i++){
            bonus[i]=bonus[i]+bonus[i-1];                // Create Difference Array
        }
        long long req=0;
        for(int i=n-1;i>=0;i--){
            if(req>0){
                req+=monsters[i];
            }
            else{
              req=max(0LL,monsters[i]-bonus[i]);
            }
        }
        return req;
    }
};