class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
        st.insert(nums[i]);
        }
        int longest = 0;
        for(int i = 0; i < n; i++) {
           if(st.find(nums[i]-1)==st.end()){
              int current=nums[i];
              int count=0;
              while(st.find(current)!=st.end()){
                current++;
                count++;
              }
              longest=max(longest,count);
           }
           
        }
        return longest;
           
    }
};
