class Solution {
public:
    bool hasAllCodes(string s, int k) {
       if(s.size()<k)return false;
        unordered_set<string>st;
        for(int i=0;i<=s.size()-k;i++){
            string bin=s.substr(i,k);
            st.insert(bin);
        }
        return st.size()==total_substrings=pow(2,k);
    }
};