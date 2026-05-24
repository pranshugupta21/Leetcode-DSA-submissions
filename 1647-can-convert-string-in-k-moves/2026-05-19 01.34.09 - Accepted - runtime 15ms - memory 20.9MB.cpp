class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.size();
        if(n!=t.size()) return false;
        vector<int>shiftmoves(26,0);
        for(int i=0;i<n;i++){
                int shift=(t[i]-s[i]+26)%26;
                if(shift>k)return false;
                if(shift==0) continue;
                long long reqmoves=shift+(26LL * shiftmoves[shift]);
                if(reqmoves>k) return false;  
                shiftmoves[shift]++;
            }
            return true;
        }
};