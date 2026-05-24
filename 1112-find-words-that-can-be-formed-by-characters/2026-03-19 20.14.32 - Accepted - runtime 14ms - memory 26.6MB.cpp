class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
    vector<int>freq(26,0);
    for(char ch:chars){
       freq[ch-'a']++;
    }
    int sum=0;
    for(auto word:words){
        vector<int>temp=freq;
        bool found=true;
        for(auto cha:word){
            if(temp[cha-'a']>0){
                temp[cha-'a']--;
            } else{
                found=false;
                break;
            }
        }
         if(found){
                sum+=word.size();
            }
      
    }
    return sum;
    }
};