class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m) return(findMedianSortedArrays(nums2,nums1));
        int low=0,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int r=(n+m+1)/2-mid;// no of elements on right portion
            int Aleft=(mid==0)? INT_MIN : nums1[mid-1];
            int Bleft=(r==0)? INT_MIN : nums2[r-1];

            int Aright=(mid==n)? INT_MAX : nums1[mid];
            int Bright=(r==m)? INT_MAX : nums2[r];
            if(Aleft<=Bright&&Bleft<=Aright){
                if((n+m)%2==0){
                    return ((max(Aleft,Bleft)+min(Aright,Bright))/2.0);
                }
                return max(Aleft,Bleft);
            }
            if(Aleft>Bright) high=mid-1;
            else low=mid+1;
    }
    return 0.0;
    }
};