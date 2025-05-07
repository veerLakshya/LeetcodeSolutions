class StockSpanner {
public:
    stack<pair<int,int>> st;
    int day = 1;
    StockSpanner() {

    }
    int next(int price) {
        while(st.size() && st.top().first <= price) st.pop();
        int cur = (st.size() ? day-st.top().second : day);
        st.push({price, day});
        day++; 
        return cur;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */