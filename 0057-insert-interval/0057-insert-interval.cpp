class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        // skip the intervals which are less than newIntervals
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // merge overlapping Intervals  here we have intervals that are : intervals[i][1] > newIntervals[0]
        // because we skipped the intervals that are less than newIntervals 
        while(i<n && intervals[i][0]<=newInterval[1]){ // means the interval overlaps
          newInterval[0]=min(intervals[i][0],newInterval[0]);
          newInterval[1]=max(intervals[i][1],newInterval[1]);
          i++;
        }
        ans.push_back(newInterval);
        // push remaining intervals
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};