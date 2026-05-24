class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int l=k-1,r=n-1;
        long long sum=0;
        for(int i=0;i<=l;i++){
            sum+=card[i];
        }
        long long maxsum=sum;
        while(l>=0){
            sum=sum-card[l]+card[r];
            l--;
            r--;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};