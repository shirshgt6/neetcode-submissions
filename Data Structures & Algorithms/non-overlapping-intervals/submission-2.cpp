class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       int fc=intervals[0][0];
       int sc=intervals[0][1];
       int ans=0;
       for(int i=1;i<n;i++) {
          if(intervals[i][0]<sc){
            ans++;
            sc = min(sc, intervals[i][1]);
          }
          else{
            fc=intervals[i][0];
            sc=intervals[i][1];
          }
       }
       return ans;
    }
};
