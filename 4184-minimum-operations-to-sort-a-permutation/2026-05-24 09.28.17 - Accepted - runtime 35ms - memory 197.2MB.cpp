
class Solution {
private:
    int kmp(const vector<int>& txt, const vector<int>& pat) {
        int n = txt.size(), m = pat.size();
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        for (int i = 0, j = 0; i < n; ) {
            if (txt[i] == pat[j]) {
                i++; j++;
                if (j == m) return i - m;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return -1;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<int> goal(n);
        iota(goal.begin(), goal.end(), 0);
        vector<int> dbl = nums;
        dbl.insert(dbl.end(), nums.begin(), nums.end());
        int res = INT_MAX;
        int p1 = kmp(dbl, goal);
        if (p1 != -1) {
            res = min(res, p1);
            if(p1>0){
                res=min(res,(n-p1)+2);
            }
        }
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        vector<int> dblRev = rev;
        dblRev.insert(dblRev.end(), rev.begin(), rev.end());
        
        int p2 = kmp(dblRev, goal);
        if (p2 != -1) {
            res = min(res, 1 + p2);
            res = min(res, 1 + ((n - p2) % n));
        }
        return res == INT_MAX ? -1 : res;
    }
};
