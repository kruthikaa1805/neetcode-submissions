class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    void addNum(int num) {
        maxi.push(num);
        int high=maxi.top();
        maxi.pop();
        mini.push(high);
        if(mini.size()>maxi.size())
        {
            int temp=mini.top();
            mini.pop();
            maxi.push(temp);
        }
    
    }
    
    double findMedian() {
        double median=maxi.top();
        if(mini.size()==maxi.size())
        {
           median=(maxi.top()+mini.top())/2.0;
        }
        return median;
    }
};
