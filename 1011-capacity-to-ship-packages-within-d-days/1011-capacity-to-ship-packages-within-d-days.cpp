class Solution {
    int check(vector<int>&weights,int days,int k){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=k){
                load+=weights[i];
            }
            else{
                day++;
                load=weights[i];
            }
            if(day>days) return 0;
        }
        return(day<=days);
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(check(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};