class Solution {
public:
    bool equalFrequency(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
             freq[i]--;
            unordered_set<int>st;
            for(auto f:freq){
                if(f>0) st.insert(f);
            }
            if(st.size()==1) return true;
            freq[i]++;
        }
        return false;
    }
};