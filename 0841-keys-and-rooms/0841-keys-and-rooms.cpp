class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool> &vis) {

        vis[i] = true;
        for (int key : rooms[i]) {
            if (!vis[key]) {
                dfs(key, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for (auto v : vis) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};