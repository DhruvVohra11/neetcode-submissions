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
        // A person with no meetings can definitely attend them all!
        if (intervals.empty()) {
            return true;
        }

        // 1. Sort the intervals by their start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // 2. Loop through and check for overlaps
        for (int i = 0; i < intervals.size() - 1; i++) {
            // If the current meeting ends AFTER the next one starts, it's a conflict.
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }

        // If we made it through the whole calendar without conflicts, return true
        return true;
    }
};