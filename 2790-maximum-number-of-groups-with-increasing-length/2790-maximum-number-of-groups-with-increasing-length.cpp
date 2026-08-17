class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(),usageLimits.end());
        long long total=0,k=0;
        for(int i=0;i<usageLimits.size();i++){
          total+=usageLimits[i];
          if(total>=((k+1)*(k+2))/2){
            k++;
          }
        }
        return k;
    }
};