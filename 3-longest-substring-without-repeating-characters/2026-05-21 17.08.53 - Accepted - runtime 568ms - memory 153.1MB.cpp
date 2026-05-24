class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,c=0,len=0;
        unordered_set<char>st;
        while(i<s.size()){
          int j=i;
          c=0;
          while(j<s.size()&&st.find(s[j])==st.end()){
            st.insert(s[j]);
            c++;
            j++;
          }
          if(st.find(s[j])!=st.end()){
            st.clear();
          }
          len=max(c,len);
          i++;
        }
        return len;
    }
};