#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Interval {
    public:
        int start;
        int end;

        Interval(int start, int end) 
        {
            this->start = start;
            this->end = end;
        }
};

vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    vector<Interval> mergedIntervals;

    // Sort the intervals according to start index
    sort(intervals.begin(), intervals.end(), 
    [](const Interval &x, const Interval &y) {return x.start < y.start;});

    // Define Iterator
    vector<Interval>::const_iterator intervalItr = intervals.begin(); 

    // Get starting interval
    Interval interval = *intervalItr++;
    
    // First interval
    int start = interval.start;
    int end = interval.end;

    while(intervalItr != intervals.end()) {
        Interval currentInterval = *intervalItr;

        if (currentInterval.start <= interval.end) {
            // merge
            interval.end = max(currentInterval.end, interval.end);
            intervalItr++;
        }
        else {
            mergedIntervals.push_back(interval);
            intervalItr++;
            interval = currentInterval;
        }        
    }
    mergedIntervals.push_back(interval);

    return mergedIntervals;
}

int main()
{
    vector<Interval> intervals = {{6,7}, {2,4}, {5,9}};

    vector<Interval> mergedIntervals = mergeIntervals(intervals);

    for (auto iterator:mergedIntervals) {
        std::cout << iterator.start << " " << iterator.end << endl;
    }

    return 0;
}