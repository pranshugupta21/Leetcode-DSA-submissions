class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]=i;
        }
        for(int i=0;i<t.length();i++){
            m2[t[i]]=i;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
          ans+=abs(m1[s[i]]-m2[s[i]]);
        }
        return ans;
    }
};