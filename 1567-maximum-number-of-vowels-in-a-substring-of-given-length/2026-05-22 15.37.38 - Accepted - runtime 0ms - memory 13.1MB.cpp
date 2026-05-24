class Solution {
    auto isvowel(char ch){
        return ch=='a'||ch=='e' || ch=='i' || ch=='o'|| ch=='u'; 
    }
public:
    int maxVowels(string s, int k) {
        int vc=0,maxvc=0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i]))vc++;
        }
        maxvc=vc;
      for(int i=k;i<s.size();i++){
        vc+=isvowel(s[i]);
        vc-=isvowel(s[i-k]);
        maxvc=max(maxvc,vc);
      }
      return maxvc;
        }
};