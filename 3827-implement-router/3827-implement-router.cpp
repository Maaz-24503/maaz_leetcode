class Router {
private:
    struct Packet {
        int source;
        int destination;
        int timestamp;
        bool operator==(const Packet &o) const {
            return source == o.source && destination == o.destination && timestamp == o.timestamp;
        }
    };

    struct PacketHash {
        size_t operator()(const Packet &p) const {
            return hash<int>()(p.source) ^ (hash<int>()(p.destination) << 1) ^ (hash<int>()(p.timestamp) << 2);
        }
    };

    struct DestList {
        vector<Packet> packets;
        int start = 0;   
        void forward() { start++; }
    };

    queue<Packet> all;                              
    unordered_set<Packet, PacketHash> uniquePackets;  
    unordered_map<int, DestList> byDest;             
    int limit;

    int leftBound(vector<Packet> &v, int l, int r, int startTime) {
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m].timestamp >= startTime) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    int rightBound(vector<Packet> &v, int l, int r, int endTime) {
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m].timestamp <= endTime) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (uniquePackets.count(p)) return false;

        byDest[destination].packets.push_back(p);
        uniquePackets.insert(p);
        all.push(p);

        if ((int)all.size() > limit) {
            forwardPacket();
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (all.empty()) return {};
        Packet p = all.front();
        all.pop();
        uniquePackets.erase(p);
        byDest[p.destination].forward();
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!byDest.count(destination)) return 0;
        auto &lst = byDest[destination];
        if (lst.start >= (int)lst.packets.size()) return 0;

        int l = leftBound(lst.packets, lst.start, (int)lst.packets.size() - 1, startTime);
        int r = rightBound(lst.packets, lst.start, (int)lst.packets.size() - 1, endTime);
        if (l == -1 || r == -1) return 0;
        return r - l + 1;
    }
};
