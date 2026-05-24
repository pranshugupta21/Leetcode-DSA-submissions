class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        int c1=0,c2=0;
        vector<int>v;
        for(int i:nums1){
            m1[i]++;
        }
        for(int j: nums2){
           m2[j]++;
        }
        for(int n1:nums1){
            if(m2.count(n1)){
              c1++;
            }
        }
          for(int n2:nums2){
            if(m1.count(n2)){
              c2++;
            }
        }
      v.push_back(c1);
      v.push_back(c2);
      return v;
    }
};