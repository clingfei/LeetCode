#include <vector>

using namespace std;

class Solution {
    vector<int> temp;
public:
    int reversePairs(vector<int>& nums) {
        int i = 0, j = nums.size() / 2;
        int cnt = 0;
        temp.reserve(nums.size());
        mergeSort(nums, 0, nums.size()-1, cnt);
        return cnt;
    }
    void mergeSort(vector<int> &nums, int low, int high, int &cnt) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, cnt);
        //cout << cnt <<  high << endl;
        mergeSort(nums, mid + 1, high, cnt);
        //cout << cnt <<  high << endl;
        int i = low, j = mid + 1;
        int id = low;
        while (i <= mid && j <= high) {
            if (nums[i] > nums[j]) {
                cnt += mid - i + 1;
                //cout << cnt << i << j << endl;
                temp[id++] = nums[j++];
            } else {
                temp[id++] = nums[i++];
            }
        }
        while (i <= mid) temp[id++] = nums[i++];
        while (j <= high) temp[id++] = nums[j++];
        copy(temp.begin()+low, temp.begin() + high + 1, nums.begin() + low);

        //cout << cnt <<  high << endl;
    }
};