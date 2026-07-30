class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>lis;
        int n=obstacles.size();
        vector<int>lisList(n);
        for(int i=0;i<n;i++){
            if(lis.empty()||lis.back()<=obstacles[i]){  //if threre is no element in Longest increasing subsequence or the last element is lesser than or equal to current obstacles it will form an LIS
                lis.push_back(obstacles[i]);
                lisList[i]=lis.size();
            }
            else{
                // find the next greater element in obstacles and update the value with current obstacles for further , course list size of LIS will be upperbound_index+1
                int idx=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
                lis[idx]=obstacles[i];
                lisList[i]=idx+1;
            }
        }
        return lisList;
    }
};