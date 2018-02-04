#ifndef UI
#define UI

#include "sortedList.h"

// выводит в консоль меню с выбором действий
void displayMenu();

// возвращает введённый пользователем символ
char getChoice();

// в зависимости от choice тем или иным образом взаимодействует с list
void menu(SortedList* list, char choice);

#endif // UI

