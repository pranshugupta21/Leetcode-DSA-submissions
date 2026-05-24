class Solution {
    
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n+1,0);
        for(int i=1;i<n+1;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        int total=0;
        for(int l=0;l<n;l++){
         for(int r=l;r<n;r+=2){
           total+=prefix[r+1]-prefix[l];
         }
        }
        return total;

    }

};
        