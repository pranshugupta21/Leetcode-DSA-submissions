class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> posT;
        for(int i = 0; i < t.length(); i++){
            posT[t[i]] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans += abs(i - posT[s[i]]);
        }
        return ans;
    }
};
