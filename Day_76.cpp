#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        vector<long long> availableAt(n, 0);  // Time when each room is free
        vector<int> roomCount(n, 0);          // Meeting count per room
        
        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1], duration = end - start;
            int chosenRoom = -1;
            
            // Find the smallest-numbered free room
            for (int i = 0; i < n; ++i) {
                if (availableAt[i] <= start) {
                    chosenRoom = i;
                    break;
                }
            }
            
            // If no free room, find the room that becomes available the earliest
            if (chosenRoom == -1) {
                long long earliest = LLONG_MAX;
                for (int i = 0; i < n; ++i) {
                    if (availableAt[i] < earliest) {
                        earliest = availableAt[i];
                        chosenRoom = i;
                    }
                }
                
                start = availableAt[chosenRoom];
            }
            
            availableAt[chosenRoom] = start + duration;
            roomCount[chosenRoom]++;
        }
        
        
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomCount[i] > roomCount[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};