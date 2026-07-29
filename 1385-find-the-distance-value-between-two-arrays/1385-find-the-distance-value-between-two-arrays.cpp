class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int dist=0;
        for(auto val:arr1){
            auto it=lower_bound(arr2.begin(),arr2.end(),val-d);  // checking range between(nums[i]-d to nums[i]+d) this is our forbidden zone
            if(it!=arr2.end()&&*it<=val+d) continue;  //it!=arr2.end() means arr2<=val-d and we are confirming is it in range (val+d)
            dist++;
        }
        return dist;
    }
};