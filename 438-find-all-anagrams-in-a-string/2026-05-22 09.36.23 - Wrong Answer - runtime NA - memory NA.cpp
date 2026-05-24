class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         string key =p;
         sort(p.begin(),p.end());
         vector<int>v;
        for (int i = 0; i + p.size() <= s.size(); i++) {
    string s1 = s.substr(i, p.size());
    sort(s1.begin(), s1.end());
    if (s1 == key) {
        v.push_back(i);
    }
}
         return v;
    }
};
