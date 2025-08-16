#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

// Función para resolver un solo caso de prueba
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n), b(n);
    long long initial_sum_a = 0;
    long long initial_sum_b = 0;

    // Leer los arreglos de entrada
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Paso 1: Normalización - asegurar a[i] >= b[i]
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            std::swap(a[i], b[i]);
        }
    }

    // Calcular la suma inicial (v = sum(a[i] - b[i]))
    for (int i = 0; i < n; ++i) {
        initial_sum_a += a[i];
        initial_sum_b += b[i];
    }
    long long game_value = initial_sum_a - initial_sum_b;

    // Paso 2: Identificar los mejores intercambios
    // Ordenar 'a' de forma ascendente para encontrar los elementos más pequeños
    std::sort(a.begin(), a.end());
    // Ordenar 'b' de forma descendente para encontrar los elementos más grandes
    std::sort(b.begin(), b.end(), std::greater<long long>());

    // Paso 3: Calcular la ganancia de los k intercambios más rentables para Bahamin
    for (int i = 0; i < k; ++i) {
        // Si el elemento más grande de 'b' es mayor que el más pequeño de 'a',
        // un intercambio es rentable.
        if (b[i] > a[i]) {
            // La ganancia es 2 * (b[i] - a[i])
            game_value += 2 * (b[i] - a[i]);
        } else {
            // Si b[i] <= a[i], entonces no hay más intercambios rentables
            // porque ambos arreglos están ordenados.
            break;
        }
    }

    // Paso 4: Imprimir el resultado final
    std::cout << game_value << std::endl;
}

int main() {
    // Acelerar la entrada/salida
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Manejar múltiples casos de prueba
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}