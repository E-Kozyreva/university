#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main();

int type_of_sort(){

  int answer;

  printf("\nВыберите тип сортировки символов:\n");
	printf("1.Сортировка пузырьком.\n");
	printf("2.Сортировка вставкой.\n");
	printf("3.Быстрая сортировка.\n");
	printf("Ваш ответ: ");
	scanf("%d", &answer);

  if (answer == 1 || answer == 2 || answer == 3)
    return answer;
  else {
    printf("Неверный ввод, введите 1 или 2, или 3.\n");
    return type_of_sort();
  }

  return 0;
}


int output_data_from_file(int count, char array[count]){

  int answer;

  printf("Хотите вывести на экран все символы из файла?\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);
  printf("\n");

  if (answer == 1){
    printf("Символы, которые находятся в файле:\n{");
    for (int index = 0; index < count; index++)
      printf("%c", array[index]);
    printf("}\n");
  }
  else if(answer != 1 && answer != 2){
    printf("Неверный ввод.\nОтветьте на вопрос заново.\n\n");
    return output_data_from_file(count, array);
  }
  
  return 0;
}


void transferring_data_to_file(bool flag, int count, char array[count]){

  FILE *file;

  if (flag == false){
    file = fopen("Sorting.txt", "w");
    fprintf(file, "Неотсортированный массив:\n");
    for (int index = 0; index < count; index++)
			fprintf(file, "%c ", array[index]);
    fprintf(file, "\n");
    fclose(file);
  }
  else if (flag == true){
    file = fopen("Sorting.txt", "a+");
    fprintf(file, "Отсортированный массив:\n");
    for (int index = 0; index < count ; index++)
      fprintf(file, "%c ", array[index]);
    fprintf(file, "\n");
    fclose(file);
  }
}


void output_sorted_array(double time, int count, char array[count]){

  printf("\nНовый отсортированный массив:\n{");
  for (int index = 0; index < count; index++)
    printf("%c", array[index]);
  printf("}\n");
  printf("Время сортировки: %lf\n", time);
}


void bubble_sort(int count, char array[count]){

  int element;
  bool flag, flag_for_file;

  clock_t time_start = clock(); 
  for (int circle = count - 1; circle >= 0; circle--){
    flag = true;
    for (int index = 0; index < circle; index++){
      if (array[index] > array[index + 1]){
        element = array[index];
        array[index] = array[index + 1];
        array[index + 1] = element;
        flag = false;
      }
    }
    if (flag == true)
        break;
  }
  clock_t time_end = clock() - time_start;
  transferring_data_to_file(flag_for_file = true, count, array);
  output_sorted_array((double)time_end / CLOCKS_PER_SEC, count, array);
}


void sorting_by_insertion(int count, char array[count]){

  int element, location;
  bool flag_for_file;

  clock_t time_start = clock(); 
  for (int index = 1; index < count; index++){
    element = array[index];
    location = index - 1;
    while (location >= 0 && array[location] > element){
      array[location + 1] = array[location];
      location = location - 1;
    }
      array[location + 1] = element;
  }
  clock_t time_end = clock() - time_start;
  transferring_data_to_file(flag_for_file = true, count, array);
  output_sorted_array((double)time_end / CLOCKS_PER_SEC, count, array);
}


void quick_sort(int begin, int end, char array[end]){

  if (begin < end){
    int left = begin, right = end, middle = array[(left + right) / 2];
    do{
      while (array[left] < middle)
        left++;
      while (array[right] > middle)
        right--;
      if (left <= right){
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;
        left++;
        right--;
      }
    } while (left <= right); {
      quick_sort(begin, right, array);
      quick_sort(left, end, array);
    }
  }
}


int reset_sorting(){

  int answer;

  printf("\nХотите сбросить сортировку?\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);
  printf("\n");

  if (answer == 1){ 
    printf("Сортировка сброшена.Программа запустится по новой, ожидайте.\n\n");
    return main();
  }
  else if (answer == 2)
    return 0;
  else { 
    printf("Неверный ввод, введите 1 или 2.\n");
    return reset_sorting();
  }
  
  return 0;
}


int launching_the_program(){

  int answer;

  printf("\nХотите повторить запуск программы по новой\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1){ 
    printf("\n\n");
    return main();
  }
  else if (answer == 2)
    printf("\nПрограмма остановлена.");
  else {
    printf("Неверный ввод, введите 1 или 2.\n");
    return launching_the_program();
  }

  return 0;
}


int main(){

  FILE *file;
  file = fopen("text.txt", "r");

  int answer, count;
  int array_index = 0;
  char element;
  bool flag_for_file;

  fscanf(file, "%d", &count);
  char characters[count];

  for (int index = 0; index < (count * 2); index++){ 
    fscanf(file, "%c", &element);
    if (element >= 33 && element <= 126){ 
      characters[array_index] = element;
      array_index++;
    }
  }

  output_data_from_file(count, characters);
  answer = type_of_sort();
  transferring_data_to_file(flag_for_file = false, count, characters);

  if (answer == 1){ 
    bubble_sort(count, characters);
    reset_sorting();
    launching_the_program();
  }
  else if (answer == 2){ 
    sorting_by_insertion(count, characters);
    reset_sorting();
    launching_the_program();
  }
  else if (answer == 3){ 
    clock_t time_start = clock(); 
    quick_sort(0, count - 1, characters);
    clock_t time_end = clock() - time_start;
    transferring_data_to_file(flag_for_file = true, count, characters);
    output_sorted_array((double)time_end / CLOCKS_PER_SEC, count, characters);
    reset_sorting();
    launching_the_program();
  }
  
  return 0;
}
