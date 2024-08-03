class Solution
{
public:
    vector<int> maxOfMin(int arr[], int n)
    {
        stack<int> s;
        int left[n+1]; 
        int right[n+1]; 

        for (int i=0; i<n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n-1 ; i>=0 ; i-- ) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        vector<int> ans(n+1, 0);
        for (int i=0; i<n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        for (int i=n-1; i>=1; i--)
            ans[i] = max(ans[i], ans[i+1]);

        vector<int> res(ans.begin() + 1, ans.end());
        return res;
    }
};
