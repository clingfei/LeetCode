#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int mod = static_cast<int>(1e9 + 7);
        unordered_map<long, long> umap;
        for (int a : arr) 
            umap[a]++;
        long long res = 0;
        for (int i = 0; i < arr.size()-2; ++i) {
            int j = i + 1;
            while (j < arr.size() - 1) {
                int z = target - arr[j] - arr[i];
                if (z < arr[i] || z < arr[j] || umap.find(z) == umap.end()) {++j; continue;}
                if (z == arr[i] && z == arr[j]) {
                    if (umap[z] < 3) { ++j; continue; }
                    res += ((umap[z] - 2) * (umap[z] - 1) * umap[z] / 6) % mod;
                } else if (arr[i] == arr[j]) {
                    res += (umap[arr[i]] * (umap[arr[i]] - 1) / 2 * umap[z]) % mod;
                } else if (arr[j] == z) {
                    if (umap[z] < 2) { ++j; continue;}
                    res += (umap[z] * (umap[z] - 1) / 2 * umap[arr[i]]) % mod;
                    //cout << i << j << res << endl;
                } else {
                    res += (umap[arr[i]] * umap[arr[j]] * umap[z]) % mod;
                }
                while (j + 1 < arr.size() && arr[j+1] == arr[j])
                    ++j;
                if (j + 1 == arr.size()) break;
                j++;
                
            }
            while (i + 1 < arr.size() && arr[i + 1] == arr[i]) {
                ++i;
            }
            if (i + 1 == arr.size()) break;
        }
        return res;
    }
};