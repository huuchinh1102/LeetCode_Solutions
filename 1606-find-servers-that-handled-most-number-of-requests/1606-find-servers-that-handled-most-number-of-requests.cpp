class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        using BusyServer = pair<long long, int>; // finishTime, serverId
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busyServers;
        set<int> freeServers;
        for (int id = 0; id < k; id++) {
            freeServers.insert(id);
        }
        vector<int> handled(k, 0);
        int maxHandled = 0;
        for (int i = 0; i < (int)arrival.size(); i++) {
            long long time = arrival[i];
            while (!busyServers.empty() && busyServers.top().first <= time) {
                int id = busyServers.top().second;
                busyServers.pop();
                freeServers.insert(id);
            }

            if (freeServers.empty()) {
                continue;
            }

            // Tìm ID rảnh đầu tiên >= i % k.
            set<int>::iterator it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) {
                it = freeServers.begin();
            }

            int id = *it;
            freeServers.erase(it);
            busyServers.push({time + load[i], id});

            handled[id]++;
            maxHandled = max(maxHandled, handled[id]);
        }
        vector<int> ans;
        for (int id = 0; id < k; id++) {
            if (handled[id] == maxHandled) {
                ans.push_back(id);
            }
        }
        return ans;
    }
};