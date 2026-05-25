class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l=0,r=0,n=customers.size();
        int currsat=0,totalsat=0,maxsat=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
            totalsat+=customers[i];
            }
            else{
                if(i<minutes)currsat+=customers[i];
            }
        }
        maxsat=currsat;
        for(int r=minutes;r<n;r++){
            currsat+=grumpy[r]*customers[r];
            currsat-=grumpy[l]*customers[l];
            l++;
            maxsat=max(maxsat,currsat);
        }

        return maxsat+totalsat;
    }
};