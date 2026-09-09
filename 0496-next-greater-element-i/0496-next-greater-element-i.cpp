class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans(nums2.size(),-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<nums2[i]) st.pop();
            if(!st.empty()) ans[i]=nums2[st.top()];
            st.push(i);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int>ans1(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            ans1[i]=ans[mp[nums1[i]]];
        }
        return ans1;
    }
};