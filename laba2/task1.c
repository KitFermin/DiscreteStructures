#include <stdio.h>

int sequential_search(int arr[], int size, int target, int *comparisons) {
    *comparisons = 0;  // Счетчик сравнений
    for (int i = 0; i < size; i++) {
        (*comparisons)++;  // Увеличиваем счетчик при каждом сравнении
        if (arr[i] == target) {
            return i;  // Возвращаем индекс найденного элемента
        }
    }
    return -1;  // Возвращаем -1, если элемент не найден
}

int main() {
    int n, target, index, comparisons;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];

    // Заполнение массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ввод искомого элемента
    printf("Введите элемент для поиска: ");
    scanf("%d", &target);

    // Поиск элемента в массиве
    index = sequential_search(arr, n, target, &comparisons);

    // Вывод результатов
    if (index != -1) {
        printf("Элемент %d найден на позиции %d.\n", target, index);
    } else {
        printf("Элемент %d не найден в массиве.\n", target);
    }

    printf("Количество выполненных сравнений: %d\n", comparisons);

    return 0;
}
