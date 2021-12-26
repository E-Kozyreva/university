#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main();

int select_function(){

  int answer;
  
  printf("\nВыберите одну из функций:\n");
	printf("1.Сгенерировать последовательность из псевдослучайных символов.\n");
	printf("2.Ввести символы самостоятельно.\n");
	printf("Ваш ответ: ");
	scanf("%d", &answer);

  if (answer == 1 || answer == 2)
    return answer;
  else { 
    printf("\nВведите 1 или 2.\n");
    return select_function();
  }

  return 0;
}


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


void transferring_data_to_file(bool flag, int count, char array[count]){

  FILE *file;

  if (flag == false){
    file = fopen("Sorting.txt", "w");
    fprintf(file, "Неотсортированный массив:\n");
    for(int index = 0; index < count; index++)
          fprintf(file, "%c ", array[index]);
    fprintf(file, "\n");
    fclose(file);
  }
  else if (flag == true){
    file = fopen("Sorting.txt", "a+");
    fprintf(file, "Отсортированный массив:\n");
    for(int index = 0; index < count ; index++)
      fprintf(file, "%c ", array[index]);
    fprintf(file, "\n");
    fclose(file);
  }
}


void output_sorted_array(double time, int count, char array[count]){

  printf("\nНовый отсортированный массив:\n{");
  for (int index = 0; index < (count * 2); index++)
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
    while(location >= 0 && array[location] > element){
      array[location+1] = array[location];
      location = location - 1;
    }
      array[location+1] = element;
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


int launching_the_program(){

  int answer;

  printf("\nХотите повторить запуск программы по новой\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return main();
  else if (answer == 2)
    printf("\nПрограмма остановлена.");
  else {
    printf("Неверный ввод, введите 1 или 2.\n");
    return launching_the_program();
  }

  return 0;
}


int main(){

	int answer, count_elements;
  char random_element, random_characters[count_elements];
  bool flag_for_file;

  answer = select_function();

	switch (answer){
  case 1:
    srand(time(NULL));
    
		printf("\nВведите кол-во символов, которые хотите получить: ");
		scanf("%d", &count_elements);

    printf("Случайно сгененрированные символы:\n");
    for (int index = 0; index < count_elements; index++){
      random_element = 33 + rand()%93;
      printf("%c ", random_element);
      random_characters[index] = random_element;
    }
    printf("\n");

    transferring_data_to_file(flag_for_file = false, count_elements, random_characters);
    answer = type_of_sort();

		if (answer == 1){
      bubble_sort(count_elements, random_characters);
      launching_the_program();
		}
    else if (answer == 2){
      sorting_by_insertion(count_elements, random_characters);
      launching_the_program();
    }
    else if (answer == 3){
      clock_t time_start = clock(); 
      quick_sort(0, count_elements - 1, random_characters);
      clock_t time_end = clock() - time_start;
      transferring_data_to_file(flag_for_file = true, count_elements, random_characters);
      output_sorted_array((double)time_end / CLOCKS_PER_SEC, count_elements, random_characters);
      launching_the_program();
    }
    break;
	case 2:
		printf("\nВведите кол-во символов, которые хотите ввести: ");
		scanf("%d", &count_elements);
	  printf("Введите символы через Enter.\n");
    
    char element;
	  char array_of_characters[count_elements * 2];
    char sorted_array[count_elements], index_in_array = 0;

		for (int index = 0; index < (count_elements * 2); index++){
      scanf("%c", &element);
      array_of_characters[index] = element;
    }

    for (int index = 0; index < (count_elements * 2); index++){
      element = array_of_characters[index];
      if (element >=  33 && element <= 126){
        sorted_array[index_in_array] = element;
        index_in_array++;
      }
    }

    transferring_data_to_file(flag_for_file = false, count_elements, sorted_array);
    answer = type_of_sort();

		if (answer == 1){
      bubble_sort(count_elements, sorted_array);
      launching_the_program();
		}
    else if (answer == 2){
      sorting_by_insertion(count_elements, sorted_array);
      launching_the_program();
    }
    else if (answer == 3){
      clock_t time_start = clock(); 
      quick_sort(0, count_elements - 1, sorted_array);
      clock_t time_end = clock() - time_start;
      transferring_data_to_file(flag_for_file = true, count_elements, random_characters);
      output_sorted_array((double)time_end / CLOCKS_PER_SEC, count_elements, random_characters);
      launching_the_program();
    }
    break;
  }

  return 0;
}
