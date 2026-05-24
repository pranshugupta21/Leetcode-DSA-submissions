class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long total=accumulate(beans.begin(),beans.end(),0ll);
        long long prefixsum=0;
        long long mincost=LLONG_MAX;
        for(int i=0;i<n;i++){
            long long rightsum=total-prefixsum-beans[i];
            long long rightcount=n-i-1;
            long long cost=prefixsum+(rightsum-(beans[i]*rightcount));
            if(cost<mincost){
                mincost=cost;
            }
            prefixsum+=beans[i];
        }
        return mincost;
    }
};