class Solution {
    int val(vector<int>& nums1, vector<int>& nums2,int x){
        int c=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]+nums2[j]==x)c++;
            }
        }
        return c;
    }
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            int a=0;
            if(it.size()==2){
                a=val(nums1,nums2,it[1]);
                ans.push_back(a);
            }
            else{
                int x=it[1];
                int y=it[2];
                int tar=it[3];
                for(int i=x;i<=y;i++){
                    nums2[i]+=tar;
                }
            }
        }
        return ans;
    }
};