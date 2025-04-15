class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        pair<int,int> cur{startTime, endTime};
        auto nxt = st.lower_bound(cur); //first greater or equal starting time
        if(nxt != st.end()){
            if(nxt->first < cur.second) return false;
        }
        if(nxt != st.begin()){
            auto last = prev(nxt);
            if(last->second > startTime) return false;
        }
        st.insert(cur);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */