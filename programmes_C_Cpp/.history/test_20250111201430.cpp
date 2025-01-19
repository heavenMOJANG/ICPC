#include <iostream>
#include <vector>

using namespace std;

vector<int> calculate_final_stones(int N, vector<int>& A) {
    vector<int> stones = A; // Copy initial stones
    vector<int> adults;     // Track adults
    int active_adults = 0;  // Track the number of adults with at least one stone

    for (int t = 1; t <= N; t++) {
        int new_adult_index = t - 1;

        // The new adult receives stones equal to the number of active adults
        int stones_received = active_adults;
        stones[new_adult_index] += stones_received;

        // Mark the new adult
        adults.push_back(new_adult_index);

        // If the new adult has stones, they become an active adult
        if (stones[new_adult_index] >= 1) {
            active_adults++;
        }

        // Deduct one stone from each active adult
        active_adults -= stones_received;
    }

    return stones;
}

int main() {
    int N = 10;
    vector<int> A = {2, 9, 1, 2, 0, 4, 6, 7, 1, 5};

    vector<int> final_stones = calculate_final_stones(N, A);

    // Output the final stones
    for (int i = 0; i < N; i++) {
        cout << final_stones[i] << " ";
    }
    cout << endl; // Output: 0 2 4

    return 0;
}