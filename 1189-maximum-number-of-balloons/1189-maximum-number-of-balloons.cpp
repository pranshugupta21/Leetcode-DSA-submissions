class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(char ch:text){
            if(ch=='a'||ch=='b'||ch=='l'||ch=='o'||ch=='n')mp[ch]++;
        }
        if(mp['a']==0||mp['b']==0||mp['o']==0||mp['n']==0||mp['l']==0) return 0;
       // if(mp['l']<2||mp['o']<2) return 0;
        int c=INT_MAX;
        for(auto& it:mp){
            int num=it.second;
            if(it.first=='l'||it.first=='o') num/=2;
            c=min(c,num);
        }
        return c;
    }
};