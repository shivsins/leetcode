class ExamRoom {
public:
    int total;
    set<int> seats;
    int curr;
    ExamRoom(int n) {
        this->total=n;
        this->curr=0;
    }
    
    int seat() {
        if(curr==0){
            curr=1;
            seats.insert(0);
            return 0;
        }
        // if(curr==1){
        //     curr=2;
        //     int assigned=0;
        //     if(*seats.begin()-assigned<total-1-*seats.begin()){
        //         assigned=total-1;
        //     }
        //     seats.insert(assigned);
        //     return assigned;
        // }
        int start=0, end=*seats.begin(), dist=0, assigned=0;
        if(seats.find(start)==seats.end()){
            dist=end-start;
        }
        start=*seats.begin();
        auto it = seats.begin();
        it++;
        for(;it!=seats.end();it++){
            end=*it;
            int mid=(start+end)/2;
            if(mid-start>dist){
                dist=mid-start;
                assigned=mid;
            }
            start=end;
        }
        end=total-1;
        if(seats.find(end)==seats.end()){
            if(end-start>dist){
                assigned=end;
            }
        }
        seats.insert(assigned);
        curr++;
        return assigned;
    }
    
    void leave(int p) {
        seats.erase(p);
        curr--;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */