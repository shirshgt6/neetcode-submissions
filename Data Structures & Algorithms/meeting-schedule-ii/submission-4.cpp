/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval&a,Interval&b){
            return a.start<b.start;
        });
        int room=1;
        int n=intervals.size();

        if(n == 0)
            return 0;

        int fc=intervals[0].start;
        int sc=intervals[0].end;
        multiset<int>st;
        st.insert(sc);
        for(int i=1;i<n;i++){
           int smallestend=*st.begin(); //gives smallest end
           if(smallestend<=intervals[i].start){
              st.erase(st.begin());
              st.insert(intervals[i].end);
           }
           else{
            room++;
            st.insert(intervals[i].end);
           }

        }
        return room;
    }
};
