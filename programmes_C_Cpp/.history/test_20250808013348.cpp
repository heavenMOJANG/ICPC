#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
// Ya no se necesita INF, usaremos numeric_limits si es necesario

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;

    // Calcular la suma inicial, se usa en múltiples casos.
    int initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        initial_sum += abs(a[i] - b[i]);
    }

    // Caso 1: k = 0, no hay rondas. El valor no cambia.
    if (k == 0) {
        cout << initial_sum << "\n";
        return;
    }

    // De aquí en adelante, k > 0.

    // Caso 2: n = 2. Ali solo puede elegir un par. Bahamin siempre maximiza.
    if (n == 2) {
        vector<int> c{a[0], a[1], b[0], b[1]};
        sort(c.begin(), c.end());
        // El valor maximizado por Bahamin es (s4 - s1) + (s3 - s2)
        cout << (c[3] - c[0]) + (c[2] - c[1]) << "\n";
        return;
    }

    // Caso 3: n > 2, k > 0. Ali elige el par con el mínimo aumento.
    // Creamos intervalos [min(a_i, b_i), max(a_i, b_i)]
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            intervals[i] = {a[i], b[i]};
        } else {
            intervals[i] = {b[i], a[i]};
        }
    }

    // Ordenamos por el punto de inicio para el algoritmo de barrido
    sort(intervals.begin(), intervals.end());

    int min_gap = numeric_limits<int>::max();
    bool overlap_found = false;
    int max_end_so_far = intervals[0].second;

    // Algoritmo de barrido para encontrar la brecha mínima
    for (int i = 1; i < n; ++i) {
        int current_start = intervals[i].first;
        int current_end = intervals[i].second;

        // Si el inicio actual es menor que el final más grande visto, hay superposición.
        if (current_start < max_end_so_far) {
            overlap_found = true;
            break; // El aumento mínimo posible es 0, no podemos mejorar.
        }
        
        // Si no, hay una brecha. Calculamos su tamaño.
        int gap = current_start - max_end_so_far;
        min_gap = min(min_gap, gap);
        
        // Actualizamos el final más grande que hemos visto
        max_end_so_far = max(max_end_so_far, current_end);
    }

    int increase = 0;
    if (!overlap_found) {
        // Si no se encontró ninguna superposición, el aumento es 2 * la brecha mínima.
        increase = 2 * min_gap;
    }
    // Si se encontró superposición, el aumento sigue siendo 0.

    cout << initial_sum + increase << "\n";
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}