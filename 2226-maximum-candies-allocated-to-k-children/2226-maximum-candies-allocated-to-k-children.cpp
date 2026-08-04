class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        
     //   long long low=*min_element(candies.begin(),candies.end()),high=accumulate(candies.begin(),candies.end(),0LL);
     long long low=1,high=*max_element(candies.begin(),candies.end());
        long long res=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canallocate(candies,k,mid)){
               res=mid;
               low=mid+1;
            }
            else{
             high=mid-1;
            }
        }
        return res;
    }
  private:
     bool canallocate(vector<int>&candies,long long k, long long candy){
        int c=0,n=candies.size(),i=0;
        for(int i=0;i<n;i++){
            c+=candies[i]/candy;
           if(c>=k) return true;
        }
        return false;
    }
};