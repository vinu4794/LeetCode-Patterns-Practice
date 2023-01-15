#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Point {
    public:
        int x = 0;
        int y = 0;

        Point(int x, int y) 
        {
            this->x = x;
            this->y = y;
        }

        int euclideanDistance() const 
        {
            return (x*x) + (y*y);
        }

        const bool operator<(const Point& p)
        {
            return (p.euclideanDistance() > this->euclideanDistance());
        }
};

class kClosestPointsOrigin {
    public:
        static vector<Point> compute(vector<Point> points, int k)
        {
            // Put first k elements inside the heap
            vector<Point> maxHeap(points.begin(), points.begin() + k);
            make_heap(maxHeap.begin(), maxHeap.end());
            
            for (int i = k; i < points.size(); i++) {
                if (points[i].euclideanDistance() < maxHeap.front().euclideanDistance()) {
                    pop_heap(maxHeap.begin(), maxHeap.end());
                    maxHeap.pop_back();
                    maxHeap.push_back(points[i]);
                    push_heap(maxHeap.begin(),maxHeap.end());
                }
            }
            
            return maxHeap;
        }
};

int main(int argc, char **argv)
{   
    vector<Point> out = kClosestPointsOrigin::compute({{1,3}, {3,4}, {2,-1}},2);
    for (auto point:out) {
        cout << "[" << point.x << ", " << point.y << "]";
    }

    return 0;
}