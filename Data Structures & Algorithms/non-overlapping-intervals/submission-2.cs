public class Solution {
    public int EraseOverlapIntervals(int[][] intervals) {
        if (intervals.Count() <= 1)   return 0;
        Array.Sort(intervals, (a, b) => { return a[0] - b[0]; });

        var previousInterval = new[] {intervals[0][0], intervals[0][1]};

        int ret = 0;

        for (int i = 1 ; i < intervals.Count() ; i++){
            //if overlap
            if (previousInterval[0] < intervals[i][1] && intervals[i][0] < previousInterval[1]){
                //if new interval ends before previous interval, chagne the previousInterval's 1 index with new interval's 1 index
                if (previousInterval[1] > intervals[i][1]){
                    previousInterval[1] = intervals[i][1];
                }
                ret++;
            }else{
                previousInterval[0] = intervals[i][0];
                previousInterval[1] = intervals[i][1];
            }          
        }return ret;
    }
}
