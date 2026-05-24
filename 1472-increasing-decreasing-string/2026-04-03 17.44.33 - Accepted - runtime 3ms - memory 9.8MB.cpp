class Solution {
public:
    string sortString(string s) {
        vector<int> vc(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vc[s[i] - 'a']++;
        }
        int k=n;
        int j=0;
        while(k!=0){
            for(int i=0;i<26;i++){
                if(vc[i]!=0){
                    s[j]=i+'a';
                    k--;
                    j++;
                    vc[i]--;
                }
            }
            for(int i=25;i>=0;i--){
                if(vc[i]!=0){
                    s[j]=i+'a';
                    k--;
                    j++;
                    vc[i]--;
                }
            }
        }
        return s;
    }
};