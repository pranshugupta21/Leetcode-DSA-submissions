class Solution {
public:
    string originalDigits(string s) {
     vector<int>freq(26,0);
     for(char c: s ){
     freq[c-'a']++;
     }
     vector<int>cnt(10);
     // unique character 
     cnt[0]=freq['z'-'a'];
     cnt[2]=freq['w'-'a'];
     cnt[4]=freq['u'-'a'];
     cnt[6]=freq['x'-'a'];
     cnt[8]=freq['g'-'a'];
    // derived 
     cnt[1]=freq['o'-'a']-cnt[0]-cnt[2]-cnt[4];
     cnt[3]=freq['r'-'a']-cnt[4]-cnt[0];
     cnt[5]=freq['f'-'a']-cnt[4];
     cnt[7]=freq['s'-'a']-cnt[6];
     cnt[9]=freq['i'-'a']-cnt[6]-cnt[5]-cnt[8];
     string result="";
     for(int i=0;i<=9;i++){
        result+=string(cnt[i],'0'+i);
     }
     return result;
    }
};