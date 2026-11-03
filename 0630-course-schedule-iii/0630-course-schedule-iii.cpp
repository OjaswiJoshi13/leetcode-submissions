class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {
                                                                    return a[1] < b[1];
                                                                });

        priority_queue<int> pq;
        int total = 0;

        for(int i = 0; i < n; i++) {
            int duration = courses[i][0];
            int deadline = courses[i][1];

            total += duration;
            pq.push(duration);

            if(total > deadline) {
                total -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};