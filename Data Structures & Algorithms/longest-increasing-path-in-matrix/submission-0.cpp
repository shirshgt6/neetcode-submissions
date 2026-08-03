class Solution {
public:
    vector<vector<int>>dp;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool valid(int i,int j ,int n,int m){
        return (i<n&&j<m&&i>=0&&j>=0);
    }
    int cal(int i,int j,int n,int m,vector<vector<int>>&matrix){
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(valid(ni,nj,n,m)&&matrix[ni][nj]>matrix[i][j])
            ans=max(ans,1+cal(ni,nj,n,m,matrix));
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              res=max(cal(i,j,n,m,matrix),res); 
            }
        }
        return res;
    }
};
