class Solution {
  public:
  int noofgasstation(vector<int>&stations,long double dist){
      int c=0;
      int n=stations.size();
      for(int i=0;i<n-1;i++){
          long double diff=(long double)stations[i+1]-stations[i];
          int noofstationsbetween=(ceil((diff/dist)-1e-9))-1;
        /*  if(noofstationsbetween*dist==diff){
              noofstationsbetween--;
          }*/
          c+=noofstationsbetween;
      }
      return c;
  }
    double minMaxDist(vector<int> &stations, int K) {
        int n=stations.size();
          if(n<=1) return 0;
      long double low=0;
      long double high=0;
      for(int i=0;i<n-1;i++){
          high=max(high,(long double)(stations[i+1]-stations[i]));
      }
      while(high-low>1e-6){
          long double mid=low+(high-low)/2.0;
          int cnt=noofgasstation(stations,mid);
          if(cnt>K)low=mid;
          else{
              high=mid;
          }
      }
      return high;                //Tc: O(Nlog(maxdistance(high)/10^-6))
        }
    };
