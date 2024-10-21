#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для сортировки слиянием с подсчетом количества сравнений
void merge(int arr[], int l, int m, int r, int *comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m, comparisons);
        merge_sort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
    }
}

// Функция для последовательного поиска с подсчетом сравнений
int sequential_search(int arr[], int size, int target, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Функция для двоичного поиска с подсчетом сравнений
int binary_search(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    *comparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Функция для заполнения массива случайными значениями
void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Заполнение случайными числами от 0 до 999
    }
}

int main() {
    srand(time(NULL));  // Инициализация генератора случайных чисел

    printf("Размер массива\tСравнения сортировки\tСравнения последовательного поиска\tСравнения двоичного поиска\n");
    printf("-------------------------------------------------------------------------------\n");

    // Изменяем размер массива от 20 до 500 с шагом 20
    for (int size = 20; size <= 500; size += 20) {
        int comparisons_sort = 0;
        int comparisons_seq = 0;
        int comparisons_bin = 0;
        int arr[size];
        int sorted_arr[size];

        // Заполнение массива случайными числами
        fill_array(arr, size);

        // Сортировка массива слиянием
        for (int i = 0; i < size; i++) {
            sorted_arr[i] = arr[i];  // Копируем массив для сортировки
        }
        merge_sort(sorted_arr, 0, size - 1, &comparisons_sort);

        // Выполняем K запросов для поиска
        for (int K = 0; K < 100; K++) {
            int target = rand() % 1000;  // Искомое значение

            // Последовательный поиск
            sequential_search(arr, size, target, &comparisons_seq);

            // Двоичный поиск
            binary_search(sorted_arr, size, target, &comparisons_bin);
        }

        // Вывод результатов для текущего размера массива
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", size, comparisons_sort, comparisons_seq, comparisons_bin);
    }

    return 0;
}
