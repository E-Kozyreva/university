#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main();
int answer_vector_selection(int count, int array[count]);
int vector_selection(int count, int array[count]);

void transferring_data_to_file(int count, int array[count]){

  FILE *file;
  file = fopen("Vectors.txt", "w");
  fprintf(file, "Массив символов(чисел):\n");
  for( int index = 0; index < count; index++)
    fprintf(file, "%d\n", array[index]);
  fprintf(file, "\n");
  fclose(file);
}


int the_first_norm_of_vector(int count, int array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += abs(array[index]);
  
  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Первая норма вектора равна: %f\n\n", sum);
  fclose(file);
  
  printf("\nПервая норма вектора равна: %lf\n", sum);
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int the_second_norm_of_vector(int count, int array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += pow(abs(array[index]), 2);

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Вторая норма вектора равна: %f\n\n", sqrt(sum));
  fclose(file);
  
  printf("\nВторая норма вектора равна: %lf\n", sqrt(sum));
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);
  
  return 0;
}


int the_Helder_norm_of_vector(int count, int array[count]){

  int answer, pow_for_number;
  double sum = 0;

  printf("\nВведите степень для числа: ");
  scanf("%d", &pow_for_number);

  for (int index = 0; index < count; index++)
    sum += pow(abs(array[index]), pow_for_number);

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Гельдерова норма вектора равна: %f\n\n", pow(sum, 1/count));
  fclose(file);
  
  printf("\nГельдерова норма вектора равна: %lf\n", pow(sum, 1/count));
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int infinite_norm_of_vector(int count, int array[count]){

  float max = 0;
  int answer;

  for (int index = 0; index < count; index++)
    if(array[index] > max)
      max = abs(array[index]);
  
  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Бесконечная норма вектора равна: %f\n\n", max);
  fclose(file);

  printf("\nБесконечная норма вектора равна: %lf\n", max);
  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int normalization_of_the_array_vector(int count, int array[count]){

  int answer;
  double sum = 0;

  for (int index = 0; index < count; index++)
    sum += pow(abs(array[index]), 2);

  FILE *file;
  file = fopen("Vectors.txt", "a+");
  fprintf(file, "Нормировка вектора:\n");

  printf("\nНормировка вектора:\n");
  for(int index = 0; index < count; index++){ 
    printf("%f\n", array[index] / sqrt(sum));
    fprintf(file, "%f\n", array[index] / sqrt(sum));
  }

  printf("\n");
  fprintf(file, "\n");
  fclose(file);

  printf("\nХотите подсчитать другую норму вектора?");
  printf("\n1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int vector_selection(int count, int array[count]){
  
  int answer;

  printf("\nВыберите одну из допонительных функций:");
  printf("\n1.Вычислить первую норму вектора.");
  printf("\n2.Вычислить вторую норму вектора.");
  printf("\n3.Вычислить Гельдерову норму вектора.");
  printf("\n4.Вычислить бесконечную норму вектора.");
  printf("\n5.Нормировка вектора.");
  printf("\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    the_first_norm_of_vector(count, array);
  else if (answer == 2)
    the_second_norm_of_vector(count, array);
  else if (answer == 3)
    the_Helder_norm_of_vector(count, array);
  else if (answer == 4)
    infinite_norm_of_vector(count, array);
  else if (answer == 5)
    normalization_of_the_array_vector(count, array);
  else
    return vector_selection(count, array);

  return 0;
}


int answer_vector_selection(int count, int array[count]){
  
  int answer;

  printf("\nХотите подсчитать норму вектора?\n");
  printf("1.Да\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1)
    return vector_selection(count, array);

  return 0;
}


int launching_the_program(){

  int answer;

  printf("\n\nХотите повторить запуск программы ");
  printf("по новой для сортировки массива?\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);
  printf("\n");

  if (answer == 1)
    return main();
  else if (answer == 2)
    return 0;
  else{
    printf("Неверный ввод, введите 1 или 2.\n");
    return launching_the_program();
  }

  return 0;
}


int main(){
  
  int answer, count, element, index_in_array;
  int letters[count], scan_elements[count * 2];
  int limit_min, limit_max;
  
  printf("\nВыберите одну из функций:\n");
  printf("1.Сгенерировать последовательность из псевдослучайных символов.\n");
  printf("2.Ввести символы самостоятельно.\n");
  printf("3.Считать символы из файла.\n");
  printf("Ваш ответ: ");
  scanf("%d", &answer);

  if (answer == 1){

    printf("\nВведите кол-во символов, которые хотите получить: ");
	  scanf("%d", &count);

    printf("Случайно сгененрированные символы:\n");
    for (int index = 0; index < count; index++){
      element = 33 + rand()%93;
      printf("%c ", element);
      letters[index] = element;
    }
    printf("\n");

    transferring_data_to_file(count, letters);
    answer_vector_selection(count, letters);
    launching_the_program();

  }
  else if (answer == 2){

    for (int index = 0; index < (count * 2); index++){
      scanf("%d", &element);
      scan_elements[index] = element;
    }

    for (int index = 0; index < (count * 2); index++){
      element = scan_elements[index];
      if (element >=  33 && element <= 126){
        letters[index_in_array] = element;
        index_in_array++;
      }
    }

    transferring_data_to_file(count, letters);
    answer_vector_selection(count, letters);
    launching_the_program();
  }
  else if (answer == 3){

    FILE *file;
    file = fopen("text.txt", "r");

    fscanf(file, "%d", &count);
    for (int index = 0; index < count; index++){
      fscanf(file, "%d", &element);
      letters[index] = element;
    }

    transferring_data_to_file(count, letters);
    answer_vector_selection(count, letters);
    launching_the_program();
  }

  return 0;
}
