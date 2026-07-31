class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        if(nums1==nums2) return 0;
        long long originalsum=0,maxgain=0;
        long long mod=1e9+7;
        vector<int>sorted_nums1=nums1;
        sort(sorted_nums1.begin(),sorted_nums1.end());
        for(int i=0;i<nums1.size();i++){
            long long org_diff=abs(nums1[i]-nums2[i]);
            originalsum+=org_diff;
            auto it=lower_bound(sorted_nums1.begin(),sorted_nums1.end(),nums2[i]);
            if(it!=sorted_nums1.end()){
                long long new_diff=abs(*it-nums2[i]);
                maxgain=max(maxgain,org_diff-new_diff);
            }
            if(it!=sorted_nums1.begin()){
                long long new_diff=abs(*(it-1)-nums2[i]);
                maxgain=max(maxgain,org_diff-new_diff);
            }
        }
       return (originalsum-maxgain)%mod;
    }
};