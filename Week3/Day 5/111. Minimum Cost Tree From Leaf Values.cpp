class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // Ek stack banate hain jisme hum elements ko dalenge
        stack<int> s;
        s.push(INT_MAX);
        
        // Initial non-leaf node sum ko 0 se set karte hain
        int nonLeafSum = 0;
        
        // Array ke har element ke liye
        for (int a : arr) {
            // Jab tak stack ke top element se current element chota hai
            while (s.top() <= a) {
                // Stack ke top element ko pop karte hain aur usko mid banate hain
                int mid = s.top();
                s.pop();
                
                // Non-leaf node sum me mid aur stack ke top aur current element me se chote element ka product add karte hain
                nonLeafSum += mid * min(s.top(), a);
            }
            
            // Current element ko stack me dalte hain
            s.push(a);
        }
        
        // Jab tak stack me sirf ek element nahi ho jata
        while (s.size() > 2) {
            // Stack ke top element ko pop karte hain
            int mid = s.top();
            s.pop();
            
            // Non-leaf node sum me mid aur stack ke top element ka product add karte hain
            nonLeafSum += mid * s.top();
        }
        
        // Smallest possible sum of the values of each non-leaf node return karte hain
        return nonLeafSum;
    }
};
