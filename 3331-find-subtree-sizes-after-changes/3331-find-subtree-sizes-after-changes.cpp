class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n);
        for (int u = 1; u < n; ++u) {
            children[parent[u]].push_back(u);
        }
        vector<int> answer(n, 1);
        vector<int> previousSame(n, -1);
        vector<int> last(26, -1);
        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {
            int u = st.top().first;
            bool exiting = st.top().second;
            st.pop();

            int letter = s[u] - 'a';

            if (!exiting) {
                previousSame[u] = last[letter];
                last[letter] = u;

                st.push({u, true});
                for (int v : children[u]) {
                    st.push({v, false});
                }
            } else {
                last[letter] = previousSame[u];

                int newParent = previousSame[u];
                if (newParent == -1) {
                    newParent = parent[u];
                }

                if (newParent != -1) {
                    answer[newParent] += answer[u];
                }
            }
        }

        return answer;
    }
};