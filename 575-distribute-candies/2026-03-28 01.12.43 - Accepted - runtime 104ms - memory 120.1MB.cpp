class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int>st(candyType.begin(),candyType.end());
        int want=n/2;
        return min((int)st.size(),want);
    }
};