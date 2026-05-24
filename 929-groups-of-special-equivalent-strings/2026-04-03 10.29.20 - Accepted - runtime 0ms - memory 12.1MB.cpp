class Solution {
public:
      int numSpecialEquivGroups(vector<string>& A) {
      set<pair<string,string>>s;
      for(auto word:A){
        string even,odd;
        for(int i=0;i<word.size();i++){
            if(i%2==0) even.push_back(word[i]);
            else odd.push_back(word[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        s.insert({even,odd});
      }
      return s.size();
}  
};