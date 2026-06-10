class Solution {
    int check(vector<int>&bloomDay,int m,int k,long long days){
        int c=0,num_of_bouquet=0,n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days)c++;
            else{
             num_of_bouquet+=c/k;
             c=0;
            }
        }
        num_of_bouquet+=c/k;
       return num_of_bouquet>=m;

    }
    public:
      int minDays(vector<int>& bloomDay, int m, int k) {
       long long n=bloomDay.size();
       if(1LL*m*k>n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(low<=high){
          long long mid=(low+(high-low)/2);
          if(check(bloomDay,m,k,mid)){
            ans=mid;
            high=mid-1;
          }  
          else{
            low=mid+1;
          }
        }
        return low;
    }
};