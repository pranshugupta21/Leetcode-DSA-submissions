class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1;i<=n;i++){
            int idx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            int cnt=n-idx;
            if(cnt==i) return i;
        }
        return -1;
    }
};