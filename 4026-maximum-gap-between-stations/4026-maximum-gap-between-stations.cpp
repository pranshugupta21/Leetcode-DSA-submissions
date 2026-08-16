class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size(),m=station.size();
        if(n<=1) return 0;
        vector<int>prefix(n),suffix(n);
        int j=0;
        // leftmost side matching
        for(int i=0;i<n;i++){
            while(j<m && station[j]!=skill[i]){
                j++;
            }
            prefix[i]=j;
            j++;
        }
         j=m-1;
         // match from right side
        for(int i=n-1;i>=0;i--){
            while(j>=0 && station[j]!=skill[i]){
                j--;
            }
            suffix[i]=j;
            j--;
        }
        int gap=0;// cal maximum gap from right and left side
        for(int i=1;i<n;i++){
            gap=max(gap,suffix[i]-prefix[i-1]);
        }
        return gap;
    }
};