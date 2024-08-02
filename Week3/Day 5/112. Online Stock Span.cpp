class StockSpanner {
public:
    stack<pair<int, int>> s; // Ek stack banate hain jisme hum pair of (price, span) store karenge
    
    int next(int price) {
        int span = 1; // Har din ka initial span 1 hota hai
        
        // Jab tak stack khali nahi hota aur stack ke top ka price current price se kam ya barabar hota hai
        while (!s.empty() && s.top().first <= price) {
            // Span me stack ke top ka span add karte hain
            span += s.top().second;
            
            // Stack ke top element ko pop karte hain
            s.pop();
        }
        
        // Current price aur uska span stack me push karte hain
        s.push({price, span});
        
        // Span return karte hain
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
