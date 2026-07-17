class Solution {
public:
    int total_score=0;
    void solve(vector<vector<int>>&matrixscore,vector<bool>&visitedmentors,int index,int score){
        int n=matrixscore.size();
        if(index>=n){
            total_score=max(total_score,score);
            return;
        }
        for(int i=0;i<n;i++){
            if(visitedmentors[i]==false){
                visitedmentors[i]=true;
             solve(matrixscore,visitedmentors,index+1,score+matrixscore[index][i]);
             visitedmentors[i]=false;
            }
        }

    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int index=0;
        int m=students.size();
        int n=students[0].size();
        vector<bool>visitedmentors(n,false);
        vector<vector<int>>matrixscore(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int score=0;
                for(int k=0;k<n;k++){                   // precompute all the possible combinations score
                    if(students[i][k]==mentors[j][k]) score++;
                }
                matrixscore[i][j]=score;
            }
        }
        int score=0;
        solve(matrixscore,visitedmentors,index,score);
        return total_score;
    }
    
};