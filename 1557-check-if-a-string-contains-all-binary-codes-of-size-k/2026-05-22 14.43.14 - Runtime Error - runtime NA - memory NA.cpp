class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total_substrings=pow(2,k);
        unordered_set<string>st;
        for(int i=0;i<=s.size()-k;i++){
            string bin=s.substr(i,k);
            st.insert(bin);
        }
        return st.size()==total_substrings;
    }
};