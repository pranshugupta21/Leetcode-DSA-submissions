class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
    unordered_map<char,int>mp;
    for(char ch:chars){
        mp[ch]++;
    }
    int sum=0;
    for(auto word:words){
        unordered_map<char,int>temp=mp;
        bool found=true;
        for(auto cha:word){
            if(temp[cha]>0){
                temp[cha]--;
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