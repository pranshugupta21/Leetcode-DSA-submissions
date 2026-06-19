class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxa=0,prefix=0;
        for(int i=0;i<n;i++){
            prefix+=gain[i];
            maxa=max(maxa,prefix);
        }
        return maxa;
    }
};