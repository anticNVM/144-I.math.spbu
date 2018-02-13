#ifndef KMPALGO
#define KMPALGO

// Алгоритм Кнута-Морриса-Пратта для поиска построки в строке
// @return массив индексов вхождений needle в haystack
// @return int[0] = 0, если совпадения не найдены
int* KMP(const char* haystack, const char* needle);

#endif // KMPALGO

