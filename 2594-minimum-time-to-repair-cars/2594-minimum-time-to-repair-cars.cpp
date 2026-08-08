class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=-1;
        long long low=1,high=(long long)*min_element(ranks.begin(),ranks.end())*cars*cars;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long sum=0;
            for(auto r:ranks){
                sum+=sqrt(mid/r);         // cars that rank r can repair in mid minutes = sqrt(mid/r)
            }
            if(sum>=cars){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};