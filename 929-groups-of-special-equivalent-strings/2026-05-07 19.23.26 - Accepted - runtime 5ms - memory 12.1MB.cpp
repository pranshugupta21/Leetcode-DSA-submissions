class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string ,string>>st;
        for(int i=0;i<words.size();i++){
            string s="";
            s+=words[i];
            string even="";
            string odd="";
            for(int j=0;j<s.size();j++){
              if(j%2==0){
                even+=s[j];
              }
              else{
                odd+=s[j];
              }
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            st.insert({even,odd});
        }
        return st.size();
    }
};