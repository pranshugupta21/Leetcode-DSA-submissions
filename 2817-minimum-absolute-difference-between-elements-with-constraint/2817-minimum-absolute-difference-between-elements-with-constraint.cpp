class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans=INT_MAX;
        set<int>s;
        for(int i=x;i<nums.size();i++){
            s.insert(nums[i-x]);    // maintain a distance of x while moving forward
            auto it=s.upper_bound(nums[i]);
            if(it!=s.end()){
                ans=min(ans,*it-nums[i]);
            }
            if(it!=s.begin()){
                it--;
                ans=min(ans,(nums[i]-*(it)));
            }
        }
        return ans;
    }
};