#include <stdio.h>
#include <time.h>

// Формирование массива общих делителей M и N с поиском максимума
int gcd_common_divisors(int M, int N) {
    int min_value = (M < N) ? M : N;
    int max_divisor = 1;

    for (int i = 1; i <= min_value; i++) {
        if (M % i == 0 && N % i == 0) {
            max_divisor = i;
        }
    }
    return max_divisor;
}

// Перебор от 1 до min(M, N)
int gcd_brute_force_ascend(int M, int N) {
    int min_value = (M < N) ? M : N;
    int max_divisor = 1;

    for (int i = 1; i <= min_value; i++) {
        if (M % i == 0 && N % i == 0) {
            max_divisor = i;
        }
    }
    return max_divisor;
}

// Перебор от min(M, N) до 1
int gcd_brute_force_descend(int M, int N) {
    int min_value = (M < N) ? M : N;

    for (int i = min_value; i >= 1; i--) {
        if (M % i == 0 && N % i == 0) {
            return i;
        }
    }
    return 1;
}

// Алгоритм Евклида
int gcd_euclid(int M, int N) {
    while (N != 0) {
        int temp = N;
        N = M % N;
        M = temp;
    }
    return M;
}

// Функция для замера времени выполнения
void measure_time(int (*gcd_func)(int, int), int M, int N, const char *description) {
    clock_t start, end;
    start = clock();
    int result = gcd_func(M, N);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s\nGCD of %d and %d = %d, Time taken: %f seconds\n\n", description, M, N, result, time_taken);
}

int main() {
    // Примеры входных данных для проверки
    int test_cases[][2] = {
        {36, 60},
        {123456, 789012},
        {10000000, 5000000},
        {982451653, 57885161}  // большие простые числа
    };

    for (int i = 0; i < 4; i++) {
        int M = test_cases[i][0];
        int N = test_cases[i][1];

        printf("Test Case %d: M = %d, N = %d\n", i + 1, M, N);

        // Замеры для каждого метода вычисления НОД
        measure_time(gcd_common_divisors, M, N, "Common divisors method:");
        measure_time(gcd_brute_force_ascend, M, N, "Brute force ascending:");
        measure_time(gcd_brute_force_descend, M, N, "Brute force descending:");
        measure_time(gcd_euclid, M, N, "Euclidean algorithm:");
    }

    return 0;
}
