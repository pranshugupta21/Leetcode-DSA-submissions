class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>prefixN(n+1,0);
        vector<int>suffixY(n+1,0);
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                prefixN[i+1]=prefixN[i]+1;
            }
            else{
                prefixN[i+1]=prefixN[i];
            }
        }
        for(int j=n-1;j>=0;j--){
            if(customers[j]=='Y'){
                suffixY[j]=suffixY[j+1]+1;
            }
            else{
                suffixY[j]=suffixY[j+1];
            }
        }
        int penality=INT_MAX;
        int indexhour=-1;
        for(int i=0;i<n+1;i++){
            int pena=prefixN[i]+suffixY[i];
            if(pena<penality){
              penality=pena;
             indexhour=i;
            }
        }
        return indexhour;
        
    }
};