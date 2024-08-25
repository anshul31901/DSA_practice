class StockSpanner {
public:
    stack<int>prev;
    vector<int>prices;
    int day;


    StockSpanner() {

        
        day = 0;
        prev.push(0);
        
        
        prices.push_back(1e9);
        
    }
    
    int next(int price) {

        prices.push_back(price);
        day++;
        while(!prev.empty()&&price>=prices[prev.top()]){
            prev.pop();
        }

        int span = day-prev.top();
        prev.push(day);
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
