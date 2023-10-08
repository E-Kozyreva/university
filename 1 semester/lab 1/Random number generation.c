#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main();


int functions(){

  int answer;

  printf("\nВыберите одну из функций программы:");
  printf("\n1.Ввести числа самостоятельно.");
  printf("\n2.Генерации случайных чисел.");
  printf("\nВаш ответ: ");
  scanf("%d", &answer);

  return answer;
}


void checking_the_condition(int count, double array[count]){

  int index_part;
  double whole_part, fractional_part, random_number;
  char char_index[20], buff_index[10];
  double number_index, sum = 0;

  for (int index = 0; index < count; index++){
    fractional_part = modf(array[index], &whole_part);
    number_index = fractional_part * 1000000;
            
    for (int parts = 1; parts < 7; parts++){
      sprintf(char_index, "%lf", number_index);  
      index_part = atoi(strncat(buff_index, char_index, parts));

      for (int i_count = 0; i_count < count; i_count++){
        if (index_part != i_count)
          sum += array[index];
      }
      memset(buff_index, 0, sizeof(buff_index));
    }
  }
  printf("\nСумма чисел, прошедших по условию равна: %lf", sum);
}


int launching_the_program(){

  int answer;

  printf("\n\nХотите повторить запуск программы?\n");
  printf("1.Да.\n2.Нет.\nВаш ответ: ");
  scanf("%d", &answer);

  if (answer == 1 || answer == 2)
    return answer;
  else{
    printf("\nНеверный ввод, введите 1 или 2.");
    return launching_the_program();
  }

  return 0;
}


int main(){ 

  int answer, count_numbers;
  double max, min;
  double number, random_number;
  double numbers_array[count_numbers];
  double random_numbers[count_numbers];

  answer = functions();

  if (answer == 1){

    printf("\nВведите кол-во чисел, которые вы хотите ввести: ");
    scanf("%d", &count_numbers);
    printf("Введите числа через Enter.\n");

    for (int index = 0; index < count_numbers; index++){
      scanf("%lf", &number);
      numbers_array[index] = number;
    }
    checking_the_condition(count_numbers, numbers_array);
    answer = launching_the_program();

    switch (answer){
      case 1:
        return main();
        break;
      case 2:
        printf("\nПрограмма остановлена.");
        break;
    }
  }
  else if (answer == 2){

    srand(time(NULL));

    printf("\nВведите кол-во чисел, которые вы хотите получить: ");
    scanf("%d", &count_numbers);
    printf("Введите минимальное число для диапазона: ");
    scanf("%lf", &min);
    printf("Введите максимальное число для диапазона: ");
    scanf("%lf", &max);
    printf("\nСлучайно сгенерированные числа:\n");

    for (int index = 0; index < count_numbers; index++){
      random_number = (double)(rand()) / RAND_MAX * (max - min) + min;
      random_numbers[index] = random_number;
      printf("%d | %lf\n", index + 1, random_number);    
    }
    checking_the_condition(count_numbers, random_numbers);
    answer = launching_the_program();

    switch (answer){
      case 1:
        return main();
        break;
      case 2:
        printf("\nПрограмма остановлена.");
        break;
    }
  }
  else{
      printf("\nВведен некорректный ответ.\n\n");
      return main();
  }

  return 0;
}
