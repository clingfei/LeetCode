#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char s = keysPressed[0];
        int max = releaseTimes[0];
        for (int i = 1; i <releaseTimes.size(); ++i) {
            if (releaseTimes[i] - releaseTimes[i - 1] == max) {
                if (keysPressed[i] > s)
                    s = keysPressed[i];
            }
            else if (releaseTimes[i] - releaseTimes[i - 1] > max) {
                max = releaseTimes[i] - releaseTimes[i - 1];
                s = keysPressed[i];
            }
        }
        return s;
    }
};