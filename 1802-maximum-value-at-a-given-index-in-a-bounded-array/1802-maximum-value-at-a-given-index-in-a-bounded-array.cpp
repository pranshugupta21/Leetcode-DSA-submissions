class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long low=1,high=maxSum;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isvalid(n,index,maxSum,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
private:
  bool isvalid(int n, int index,int maxsum ,long long val){
       long long leftsum=getSidesum(index,val);
       long long rightsum=getSidesum(n-index-1,val);
       return (leftsum+val+rightsum)<=maxsum;
  }
  long long getSidesum(long long count,long long x){
    if(count==0) return 0LL;
    if(count<=x-1){
        return(count*((x-1)+(x-count))/2);
    }
    else{
        return ((x*(x-1))/2)+(count-(x-1));
    }
  }
};