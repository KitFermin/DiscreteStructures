#include <stdio.h>
#include <math.h>
#include <time.h>

// Функция проверки числа на простоту (полный перебор от 2 до N)
int is_prime_full(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Функция проверки числа на простоту (перебор только четных чисел от 2 до N)
int is_prime_even(int n) {
    if (n <= 1) return 0;
    if (n % 2 == 0 && n != 2) return 0; // исключаем четные числа, кроме 2
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Функция проверки числа на простоту (перебор от 2 до sqrt(N))
int is_prime_sqrt(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Функция проверки числа на простоту (перебор только четных чисел от 2 до sqrt(N))
int is_prime_sqrt_even(int n) {
    if (n <= 1) return 0;
    if (n % 2 == 0 && n != 2) return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Функция для замера времени выполнения
void measure_time(int (*is_prime_func)(int), int n) {
    clock_t start, end;
    start = clock();
    int result = is_prime_func(n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("N = %d, Prime: %d, Time taken: %f seconds\n", n, result, time_taken);
}

int main() {
    int n_values[] = {10007, 100003, 1000003, 10000019}; // Примеры входных данных (большие числа)

    // Замеры для каждого метода проверки на простоту
    for (int i = 0; i < 4; i++) {
        int n = n_values[i];
        
        printf("Full brute-force check:\n");
        measure_time(is_prime_full, n);
        
        printf("Even brute-force check:\n");
        measure_time(is_prime_even, n);
        
        printf("Sqrt brute-force check:\n");
        measure_time(is_prime_sqrt, n);
        
        printf("Even sqrt brute-force check:\n");
        measure_time(is_prime_sqrt_even, n);

        printf("\n");
    }
    
    return 0;
}
