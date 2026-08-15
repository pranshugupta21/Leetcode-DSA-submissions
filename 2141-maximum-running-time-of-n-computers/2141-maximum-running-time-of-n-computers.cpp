class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low=*min_element(batteries.begin(),batteries.end());
        long long high=accumulate(batteries.begin(),batteries.end(),0LL);
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long minutes=0;
            for(auto bat:batteries){
                minutes+=min((long long)bat,mid);
            }
            if(minutes>=(n*mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};