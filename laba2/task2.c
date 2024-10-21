#include <stdio.h>

int binary_search(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    *comparisons = 0;  // Счетчик сравнений

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;  // Увеличиваем счетчик при каждом сравнении

        if (arr[mid] == target) {
            return mid;  // Элемент найден, возвращаем его индекс
        } else if (arr[mid] < target) {
            left = mid + 1;  // Продолжаем поиск в правой половине
        } else {
            right = mid - 1;  // Продолжаем поиск в левой половине
        }
    }
    return -1;  // Элемент не найден
}

int main() {
    int n, target, index, comparisons;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];

    // Ввод отсортированного массива
    printf("Введите отсортированные элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ввод искомого элемента
    printf("Введите элемент для поиска: ");
    scanf("%d", &target);

    // Поиск элемента в массиве
    index = binary_search(arr, n, target, &comparisons);

    // Вывод результатов
    if (index != -1) {
        printf("Элемент %d найден на позиции %d.\n", target, index);
    } else {
        printf("Элемент %d не найден в массиве.\n", target);
    }

    printf("Количество выполненных сравнений: %d\n", comparisons);

    return 0;
}
