/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-29 21:38:49
 *   Description   ：
 */
using namespace std;
class MedianFinder {
private:
    priority_queue<int> firstQ; 
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; 
public:
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); 
        else secQ.push(num); 
        
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};

int main(){
    return 0;
}
