class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0,maxlen=0;
        int n=nums.size();
        multiset<int>st;
        while(j<n){
            st.insert(nums[j]);
            int diff=*st.rbegin()-*st.begin();
            while(i<j&&diff>limit){
                auto it=st.find(nums[i]);
                st.erase(it);
                i++;
              diff=*st.rbegin()-*st.begin();   
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};