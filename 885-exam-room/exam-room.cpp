class ExamRoom {
public:
    int total;
    set<int> seats;

    ExamRoom(int n) {
        total = n;
    }

    int seat() {
        // No seats occupied
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int assigned = -1;
        int maxDist = -1;

        // 1. Check left edge
        int first = *seats.begin();

        if (first > maxDist) {
            maxDist = first;
            assigned = 0;
        }

        // 2. Check gaps between occupied seats
        auto it = seats.begin();
        auto nextIt = next(it);

        while (nextIt != seats.end()) {
            int left = *it;
            int right = *nextIt;

            int mid = (left + right) / 2;
            int dist = mid - left;

            if (dist > maxDist) {
                maxDist = dist;
                assigned = mid;
            }

            ++it;
            ++nextIt;
        }

        // 3. Check right edge
        int last = *seats.rbegin();
        int rightDist = total - 1 - last;

        if (rightDist > maxDist) {
            maxDist = rightDist;
            assigned = total - 1;
        }

        seats.insert(assigned);
        return assigned;
    }

    void leave(int p) {
        seats.erase(p);
    }
};