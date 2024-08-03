class NestedIterator {
public:
    queue<int> q;
    
    void flattenList(vector<NestedInteger> &nestedList) {
        for(auto ni : nestedList) {
            if(ni.isInteger()) {
                q.push(ni.getInteger());
            } else {
                flattenList(ni.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }
    
    int next() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};
