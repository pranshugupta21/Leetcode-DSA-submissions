class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1=nums1[0];
        int n2=nums2[0];
        bool f=false;
        int minn=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    minn=nums1[i];
                    f=true;
                    break;
                }
            }
            if(f){
                break;
            }
        }
        int minn1=(n1*10)+(n2);
        if(minn>minn1){
            minn=minn1;
        }
        return minn;
    }
};