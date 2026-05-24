class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int>mp;
        for(auto c:candyType){
            mp[c]++;
        }
        int want=n/2;
        int ans=0;
        for(auto num:mp){
          if(ans<want){
            ans++;
          }
        }
        return ans;
    }
};