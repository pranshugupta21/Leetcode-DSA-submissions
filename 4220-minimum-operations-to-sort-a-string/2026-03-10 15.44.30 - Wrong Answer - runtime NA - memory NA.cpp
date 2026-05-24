class Solution {
public:
    int minOperations(string s) {
        bool sorted=true;
        int n=s.length();
        for(int i=0;i<s.length();i++){
            if(s[i]>s[i+1]){
                sorted=false;
            }
        }
        if(sorted) return 0;
        if(n==2) return -1;
        int breaks=0;
        for (int i=0;i<n-1;i++){
            if(s[i]>s[i+1]) breaks++;
        }
        return breaks;
    }
};