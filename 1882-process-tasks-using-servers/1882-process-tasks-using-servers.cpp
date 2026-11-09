class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using FreeServer = pair<int, int>;      
        using BusyServer = pair<long long, int>;

        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> freeServers;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busyServers;

        for (int i = 0; i < (int)servers.size(); i++) {
            freeServers.push({servers[i], i});
        }
        vector<int> ans(tasks.size());
        long long time = 0;
        for (int j = 0; j < (int)tasks.size(); j++) {
            time = max(time, (long long)j);
            if (freeServers.empty() && busyServers.top().first > time) {
                time = busyServers.top().first;
            }
            while (!busyServers.empty() && busyServers.top().first <= time) {
                int index = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[index], index});
            }

            int index = freeServers.top().second;
            freeServers.pop();

            ans[j] = index;
            busyServers.push({time + tasks[j], index});
        }

        return ans;
    }
};