class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=potions.size();
        vector<int>res;
        for(int i=0;i<spells.size();i++){
            int l=0,h=n-1,ans=-1;
            while(l<=h){
                int m=l+(h-l)/2;
                if(1LL*potions[m]*1LL*spells[i]>=1LL *success){
                    ans=m;
                    h=m-1;
                }
                else l=m+1;
            }
           int no_of_potions=(ans==-1)? 0: n-ans; 
            res.push_back(no_of_potions);
        }
        return res;
    }
};