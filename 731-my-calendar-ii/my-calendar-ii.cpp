class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int sum=0;
        for(auto &[f,s] : m){
            sum+=s;
            if(sum>2){
                m[startTime]--;
                m[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */