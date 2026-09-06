class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        int groups=n; // initial total groups
        int maxspeed=speed[n-1];
        for(int i=n-1;i>0;i--){
            if(position[i]-position[i-1]<=distance){
                groups--;
            }
            else if(speed[i-1]>maxspeed){
                groups--;            // in both cases the merging will happen and the maxspeed will be of rightmost i.e. speed[i] 
            }
            else{
                maxspeed=speed[i-1];  // maxspeed will shift to its left
            }
        }
        return groups;     
    }
};