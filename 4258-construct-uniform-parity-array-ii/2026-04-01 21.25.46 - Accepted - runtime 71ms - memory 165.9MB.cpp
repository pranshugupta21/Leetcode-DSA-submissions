class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool e=false;
        for(int i:nums1){
          if(i%2==1){
              e=false;
              break;
          }
        }
        if(e) return true;
        int n1=nums1[0];
        for(int i=1;i<nums1.size();i++){
        int k=nums1[i]-n1;
            if(nums1[i]%2!=n1%2){
               if(k>=1&&k%2==n1%2){ 
            }
            else{
                return false;
            }
        } 
            }
            
        return true;
    }
};