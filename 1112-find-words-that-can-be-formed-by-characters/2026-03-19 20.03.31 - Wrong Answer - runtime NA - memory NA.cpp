class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
    unordered_map<char,int>mp;
    for(char ch:chars){
        mp[ch]++;
    }
    int sum=0;
    for(auto word:words){
        bool found=true;
        for(auto cha:word){
            if(mp.find(cha)==mp.end()) {
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