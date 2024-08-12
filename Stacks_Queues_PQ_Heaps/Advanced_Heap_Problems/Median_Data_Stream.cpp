#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> h1, h2; // h1: maxheap, h2: minheap
    MedianFinder() {
        while(!h1.empty()) h1.pop();
        while(!h2.empty()) h2.pop();
    }
    
    void addNum(int num) {
        h1.push(num); // max heap
        int temp = h1.top();
        h1.pop();
        h2.push(-temp); // min heap
        if(h1.size() != h2.size()) {
            temp = -h2.top();
            h2.pop();
            h1.push(temp);
        }
    }
    
    double findMedian() {
        if(h1.size() == h2.size())
            return (double(h1.top())-h2.top())/2.0;
        return h1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */