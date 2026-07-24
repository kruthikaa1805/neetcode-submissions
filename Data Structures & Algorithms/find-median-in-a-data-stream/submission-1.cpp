class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    int cnt=0;
    void addNum(int num) {
       maxi.push(num);
       int high=maxi.top();
       maxi.pop();
       mini.push(high);
       if(mini.size()>maxi.size())
       {
        int val=mini.top();
        mini.pop();
        maxi.push(val);
       }
       
    }
    
    double findMedian() {
        double median=maxi.top();
        if(mini.size()==maxi.size())
        median=(mini.top()+maxi.top())/2.0;
        return median;
    }
};
