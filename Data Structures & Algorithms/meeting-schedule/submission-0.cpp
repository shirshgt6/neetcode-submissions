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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int fc=intervals[0].start;
        int sc=intervals[0].end;
        int i=1;
        int n=intervals.size();
        while(i<n){
            if(intervals[i].start<sc)
            return false;
            fc=intervals[i].start;
            sc=intervals[i].end;
            i++;
        }
        return true;

    }
};
