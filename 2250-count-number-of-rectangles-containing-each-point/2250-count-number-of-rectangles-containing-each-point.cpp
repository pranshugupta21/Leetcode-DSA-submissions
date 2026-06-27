class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>>y_x(101);
        vector<int>c;
        int n=rectangles.size();
        sort(rectangles.begin(),rectangles.end());  // n log n
        for(auto &v:rectangles){
           y_x[v[1]].push_back(v[0]);      // n
        }
         for(auto &p:points){
            int x=p[0];
            int y=p[1];               //p*100*logn
            int count=0;
            for(int h=y;h<=100;h++){
              if(y_x[h].empty()) continue;
              auto it=lower_bound(y_x[h].begin(),y_x[h].end(),x);
              count+=y_x[h].end()-it;
            }
            c.push_back(count);
            }
           return c;
         }
};