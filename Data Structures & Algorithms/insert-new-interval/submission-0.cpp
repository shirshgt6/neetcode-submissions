class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>>ans;
      int fc=newInterval[0];
      int sc=newInterval[1];
      int i=0;
      int n=intervals.size();
      while(i<n&&intervals[i][1]<fc){
        ans.push_back(intervals[i]);
        i++;
      }
      while(i<n&&intervals[i][0]<=sc){
        fc=min(intervals[i][0],fc);
        sc=max(intervals[i][1],sc);
        i++;
      }
      ans.push_back({fc,sc});
      while(i<n){
        ans.push_back(intervals[i]);
        i++;
      }
      return ans;

    }
};
