class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        if(nums1==nums2) return 0;
        long long originalsum=0,maxdiff=0;
        long long mod=1e9+7;
        set<int>s(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++){
            long long diff=abs(nums1[i]-nums2[i]);
            originalsum+=diff;
            if(maxdiff<diff){
                auto it=lower_bound(s.begin(),s.end(),nums2[i]);
                if(it!=s.end()){
                maxdiff=max(maxdiff,diff-abs(*it-nums2[i])); //this is the gain that decrease the sum 
                }
                if(it!=s.begin()){
                    it--;
                  maxdiff=max(maxdiff,diff-abs((*it)-nums2[i]));  
                }   
            }
        }
       return (originalsum-maxdiff)%mod;
    }
};