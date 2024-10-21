/*
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

// Функция для заполнения массива отсортированными значениями
void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Массив с элементами от 1 до size
    }
}

int main() {
    srand(time(NULL));  // Инициализация генератора случайных чисел

    // Переменные для хранения количества сравнений
    int comparisons_seq, comparisons_bin;
    
    // Переменные для хранения индексов искомых элементов
    int index_seq, index_bin;

    // Шаг увеличения размера массива
    int step = 20;
    
    // Максимальный размер массива
    int max_size = 500;
    
    // Вывод заголовка таблицы
    printf("| Размер массива (N) |\t| Практическая сложность последовательного поиска | \t | Практическая сложность двоичного поиска |\n");

    // Цикл для увеличения размера массива
    for (int size = step; size <= max_size; size += step) {
        int arr[size];
        
        // Заполнение массива отсортированными значениями
        fill_array(arr, size);

        // Генерация случайного искомого значения
        int target = rand() % size + 1;

        // Последовательный поиск
        index_seq = sequential_search(arr, size, target, &comparisons_seq);

        // Двоичный поиск
        index_bin = binary_search(arr, size, target, &comparisons_bin);

        // Вывод результатов для текущего размера массива
        printf("%d\t\t\t\t\t%d\t\t\t\t\t\t\t%d\n", size, comparisons_seq, comparisons_bin);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Функция для заполнения массива отсортированными значениями
void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Массив с элементами от 1 до size
    }
}

int main() {
    srand(time(NULL));  // Инициализация генератора случайных чисел

    // Переменные для хранения количества сравнений
    int comparisons_seq, comparisons_bin;
    
    // Переменные для хранения индексов искомых элементов
    int index_seq, index_bin;

    // Шаг увеличения размера массива
    int step = 1000;
    
    // Максимальный размер массива
    int max_size = step * 50; 
    
    // Вывод заголовка таблицы
    printf("| Размер массива (N) |\t| Искомое число |\t| Индекс (последовательный) |\t| Сравнения (последовательный) |\t| Индекс (двоичный) |\t| Сравнения (двоичный) |\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Цикл для увеличения размера массива
    for (int size = step; size <= max_size; size += step) {
        int arr[size];
        
        // Заполнение массива отсортированными значениями
        fill_array(arr, size);

        // Генерация случайного искомого значения
        int target = rand() % (size+1000) + 1;

        // Последовательный поиск
        index_seq = sequential_search(arr, size, target, &comparisons_seq);

        // Двоичный поиск
        index_bin = binary_search(arr, size, target, &comparisons_bin);

        // Вывод результатов для текущего размера массива
        printf("%d\t\t\t%d\t\t\t%d\t\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", 
            size, target, index_seq, comparisons_seq, index_bin, comparisons_bin);
    }

    return 0;
}
