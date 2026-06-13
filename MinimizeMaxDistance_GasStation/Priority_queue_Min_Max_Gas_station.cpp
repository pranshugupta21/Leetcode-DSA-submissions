class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n=stations.size();
          if(n<=1) return 0;
        vector<int>sections(n-1,0);
        priority_queue<pair<long double,int>>pq;
            for(int i=0;i<n-1;i++){
             pq.push({(long double)(stations[i+1]-stations[i]),i});
            }
           for(int gasstation=0;gasstation<K;gasstation++){
               auto it=pq.top();
               pq.pop();
                int sec=it.second;
                sections[sec]++;
               long double initdist=(long double)(stations[sec+1]-stations[sec]);
             
                long double dist=initdist/(sections[sec]+1);
                pq.push({dist,sec});
                
           }
          return pq.top().first; 
        }
    };
