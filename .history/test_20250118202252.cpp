#include <iostream>
#include <cmath>

using namespace std;

int count_squares_in_circle(int R) {
    int count = 0;
    double R_squared = R * R;

    // Iterate over possible i values
    for (int i = -int(R - 0.5); i <= int(R - 0.5); ++i) {
        double i_offset = i + 0.5;
        double max_j_squared = R_squared - i_offset * i_offset;

        if (max_j_squared < 0) {
            continue; // No valid j for this i
        }

        // Calculate the range for j
        double max_j = sqrt(max_j_squared) - 0.5;
        double min_j = -max_j;

        // Convert to integer bounds
        int j_min = ceil(min_j);
        int j_max = floor(max_j);

        // Count the number of valid j values
        if (j_max >= j_min) {
            count += j_max - j_min + 1;
        }
    }

    return count;
}

int main() {
    int R;
    cout << "Enter the radius R: ";
    cin >> R;

    int result = count_squares_in_circle(R);
    cout << "Number of squares completely inside the circle: " << result << endl;

    return 0;
}