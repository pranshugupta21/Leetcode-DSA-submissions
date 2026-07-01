class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(128,0);
        for(char ch:s){
            freq[ch]++;
        }
        int c=0;
        bool hasodd=false;
        for(int i=0;i<128;i++){
            if(freq[i]%2!=0){
             c+=freq[i]-1;
             hasodd=true;
            }
            else c+=freq[i];
        }
        if(hasodd)c++;
        return c;
    }
};