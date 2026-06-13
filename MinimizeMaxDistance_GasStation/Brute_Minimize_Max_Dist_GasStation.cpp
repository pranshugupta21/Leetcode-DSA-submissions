class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        
        int n=stations.size();
        if(n==1&&K==1) return 0;
        vector<int>sections(n-1,0);
        for(int gasstation=0;gasstation<K;gasstation++){
            int maxidx=-1;
            long double maxvalue=0;
            for(int i=0;i<n-1;i++){
                int diff=stations[i+1]-stations[i];
                long double dist=(long double)diff/(sections[i]+1);
                if(maxvalue<dist){
                    maxvalue=dist;
                    maxidx=i;
                }
            }
            sections[maxidx]++;
            
        }
        long double ans=-1;
        for(int i=0;i<n-1;i++){
             int diff=stations[i+1]-stations[i];
            long double dist=(long double)diff/(sections[i]+1);
            ans=max(ans,dist);
        }
        return ans;
    }
};
