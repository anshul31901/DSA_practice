// 621. Task Scheduler

// ============================================================
// APPROACH 1: Heap + Queue Simulation
// TC: O(m * n) worst case  |  SC: O(1) (26 letters max)
// Idea: simulate time tick by tick. Always run the most frequent
// available task (max-heap). After running a task, it goes on
// "cooldown" (queue) until time t + n + 1, then re-enters the heap.
// ============================================================
class SolutionHeap {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;

        priority_queue<int> pq;
        for (int f : freq) if (f > 0) pq.push(f);

        queue<pair<int,int>> q; // {time task becomes eligible again, remaining count}
        int t = 0;

        while (!q.empty() || !pq.empty()) {
            t++;

            // release any task whose cooldown just expired
            if (!q.empty() && q.front().first == t) {
                pq.push(q.front().second);
                q.pop();
            }

            // run the most frequent available task
            if (!pq.empty()) {
                int cnt = pq.top(); pq.pop();
                cnt--;
                if (cnt > 0) q.push({t + n + 1, cnt});
            }
            // if pq empty here, this tick is forced idle
        }
        return t;
    }
};

// ============================================================
// APPROACH 2: Math Formula (preferred, expected solution)
// TC: O(m)  |  SC: O(1)  -- independent of n entirely
//
// Idea: the most frequent task(s) force a skeleton:
//   A _ _ | A _ _ | A _ _ | A      (maxFreq=4, n=2)
// (maxFreq-1) blocks of width (n+1), plus a tail of maxCount
// (how many distinct letters are tied at maxFreq).
//
//   intervals = (maxFreq - 1) * (n + 1) + maxCount
//
// This is a hard lower bound forced by the bottleneck task(s).
// If there's enough OTHER task volume to fill every gap in that
// skeleton, there's no idle at all and the answer is just
// tasks.size(). So the true answer is whichever is bigger.
//
//   answer = max(tasks.size(), intervals)
// ============================================================
class SolutionFormula {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = count(freq.begin(), freq.end(), maxFreq);

        int intervals = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), intervals);
    }
};

// ============================================================
// QUICK MENTAL CHECK (not "distinct count vs n" -- that's wrong):
// Compare GAP SLOTS vs FILLER VOLUME:
//   gap slots  = (maxFreq - 1) * n
//   filler     = tasks.size() - maxCount * maxFreq
//   filler >= gap slots  -> no idle, answer = tasks.size()
//   filler <  gap slots  -> idle forced, answer = intervals
//
// Example: freq=[4,4,3,3], n=2 -> gaps=6, filler=6  -> tasks.size() wins (14)
// Example: freq=[5,1,1],   n=2 -> gaps=8, filler=2  -> intervals wins  (13)
// ============================================================
