class Solution {
    int check(vector<int>&piles,int h,long long mid){
       int n=piles.size();
       long long hours=0;
       for(int i=0;i<n;i++){
      hours+=(piles[i]+mid-1)/mid;
      if(hours>h) return 0;
       }
       return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end()),ans=-1;// minimum banana can koko eat is 1 & maximum is max_element
        while(low<=high){
         long long mid=low+(high-low)/2;
          if(check(piles,h,mid)){
            ans=mid;
            high=mid-1;
          }
          else{
            low=mid+1;
          }
        }
      return ans;
    }
};
