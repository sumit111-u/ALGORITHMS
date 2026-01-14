
class Solution {
    struct SegTree {
        vector<int> count;
        vector<long long> total_len;
        const vector<int>& coords;
        int n;

        SegTree(const vector<int>& x_coords) : coords(x_coords) {
            n = x_coords.size();
            count.assign(4 * n, 0);
            total_len.assign(4 * n, 0);
        }

        void update(int node, int start, int end, int L, int R, int val) {
            if (L <= start && end <= R) {
                count[node] += val;
            } else {
                int mid = (start + end) / 2;
                if (L <= mid) update(2 * node, start, mid, L, R, val);
                if (R > mid) update(2 * node + 1, mid + 1, end, L, R, val);
            }
            if (count[node] > 0) {
                total_len[node] = coords[end + 1] - coords[start];
            } else if (start != end) {
                total_len[node] = total_len[2 * node] + total_len[2 * node + 1];
            } else {
                total_len[node] = 0;
            }
        }
    };

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> x_coords;
        vector<vector<int>> events;
        for (auto& s : squares) {
            x_coords.push_back(s[0]);
            x_coords.push_back(s[0] + s[2]);
            events.push_back({s[1], 1, s[0], s[0] + s[2]});
            events.push_back({s[1] + s[2], -1, s[0], s[0] + s[2]});
        }
        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
        sort(events.begin(), events.end());

        SegTree st(x_coords);
        vector<pair<double, long long>> stages;
        double total_area = 0;

        for (int i = 0; i < events.size() - 1; ++i) {
            int L = lower_bound(x_coords.begin(), x_coords.end(), events[i][2]) - x_coords.begin();
            int R = lower_bound(x_coords.begin(), x_coords.end(), events[i][3]) - x_coords.begin() - 1;
            st.update(1, 0, x_coords.size() - 2, L, R, events[i][1]);

            double height = events[i+1][0] - events[i][0];
            long long width = st.total_len[1];
            total_area += height * width;
            stages.push_back({(double)events[i][0], width});
        }

        double half_area = total_area / 2.0;
        double current_area = 0;
        for (int i = 0; i < stages.size(); ++i) {
            double next_y = (i + 1 < events.size() - 1) ? events[i+1][0] : events.back()[0];
            double stage_area = (next_y - stages[i].first) * stages[i].second;
            if (current_area + stage_area >= half_area - 1e-9) {
                return stages[i].first + (half_area - current_area) / stages[i].second;
            }
            current_area += stage_area;
        }
        return events.back()[0];
    }
};
