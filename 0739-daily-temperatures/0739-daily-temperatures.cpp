class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        st.push(n - 1);
        vector<int> res(n);
        res[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = 0;
                st.push(i);//agar empty huwa to
            } else {
                res[i] = st.top() - i; 
                st.push(i);
            }
        }

        return res;
        
    }
};