class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, mid, H)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool canEatAll(vector<int>& piles, int K, int H) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + K - 1) / K;
            if (hours > H) {
                return false;
            }
        }
        return hours <= H;
    }
};
