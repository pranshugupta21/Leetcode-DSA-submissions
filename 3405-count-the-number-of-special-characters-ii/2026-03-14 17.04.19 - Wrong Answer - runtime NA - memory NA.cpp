class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>a(150,-1);
        vector<int>b(150,-1);
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>=65&&s[i]<=90){
                a[s[i]]=i;
            }
            else{
                b[s[i]]=i;
            }
        }
        for(int j=0;j<150;j++){
            if(b[j]==-1|| a[j-32]==-1) continue;
             if(b[j]<a[j-32]) count++;
        }
        return count;
    }
};