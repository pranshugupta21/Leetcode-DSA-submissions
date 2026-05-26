class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int l=0,n=cards.size();
        vector<int>last_seen(100001,-1);
        int len=INT_MAX;
          for(int r=0;r<n;r++){
           if(last_seen[cards[r]]!=-1){
            len=min(len,r-last_seen[cards[r]]+1);
           }
           last_seen[cards[r]]=r;
        }
        return len==INT_MAX? -1:len;
    }
};