class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m=worker.size(),n=profit.size();
        long long maxprofit=0;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end());                         // sorting the vector pair according to diificulty
        sort(worker.begin(),worker.end());
        int j=0;
        long long profitsum=0;
        for(int i=0;i<m;i++){
            while(j<n && vp[j].first<=worker[i]){
               profitsum=max(profitsum,1LL*vp[j].second);  // keeping the maximum profit to till this difficulty
               j++;
            }
            maxprofit+=profitsum;
        }
        return maxprofit;
    }
};