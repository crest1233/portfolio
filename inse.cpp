#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Queue to store {number of multiplications, current value}
        queue<pair<int, int>> q;
        // Distance vector initialized to a large value (infinity)
        vector<int> dist(100000, INT_MAX); // Using 100000 to handle the values range
        dist[start] = 0;
        q.push({0, start});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int a = it.first;
            int b = it.second;
            
            for (int i = 0; i < arr.size(); i++) {
                int c = (b * arr[i]) % 100000; // Use modulo to prevent overflow
                
                if (dist[c] > dist[b] + 1) {
                    dist[c] = dist[b] + 1;
                    q.push({a + 1, c});
                    
                    // If the new value equals the end value, return the steps
                    if (c == end) {
                        return a + 1;
                    }
                }
            }
        }
        
        // If we exhaust the queue without finding the end value
        return -1;
    }
};

