#include<iostream>
#include<vector>

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

vector<Interval> insertInterval(vector<Interval> &inputIntervals,
                                    Interval &newInterval)
{
    vector<Interval> output = {};

    // Define Iterator
    vector<Interval>::const_iterator intervalItr = inputIntervals.begin();

    int newStart = newInterval.start;
    int newEnd = newInterval.end;

    while (intervalItr != inputIntervals.end()) {
        Interval interval = *intervalItr;

        // Non-overlapping case: Go to next interval
        if (newStart > interval.end || newEnd < interval.start) {
            output.push_back(interval);
            
        }
        else {
            //merge
            newStart = min(newStart, interval.start);
            newEnd = max(newEnd, interval.end);                
        }
        intervalItr++;
    }
    return output;
}

int main()
{
    vector<Interval> inputIntervals = {{1,3}, {5,7}, {8,12}};
    Interval newInterval = {4,6};

    vector<Interval> outputIntervals = insertInterval(inputIntervals,newInterval);

    for (auto interval:outputIntervals) {
        std::cout << interval.start << " " << interval.end << endl;
    }
    return 0;
}