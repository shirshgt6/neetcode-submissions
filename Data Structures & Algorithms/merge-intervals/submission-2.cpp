class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n=intervals.size();
      if(n==1)
      return intervals;
      sort(intervals.begin(), intervals.end());
      
      int i=0;
      vector<vector<int>>ans;

 
     while(i<n){
      int fc=intervals[i][0];
      int sc=intervals[i][1];
      i++;
      while(i<n&&intervals[i][0]<=sc){
        sc=max(intervals[i][1],sc);
        i++;
      }
      ans.push_back({fc,sc});
     }
      return ans;
    }
};
