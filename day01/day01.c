#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{

  FILE *filepointer = fopen("./input.txt", "r");
  int left_list[1000] = {0};
  int right_list[1000] = {0};
  int full_list[2000];
  char buffer[2000];
  char *token;
  int index = 0;
  int diff_ans = 0;
  int sim_ans = 0;
  int difference;
  int left_index = 0, right_index = 0;
  int count = 0;


  // get the full text input and save it in full_list
  while(fgets(buffer, sizeof(buffer), filepointer)) {
    //printf("Buffer: %s", buffer);
    token = strtok(buffer, "   ");
    
    while(token != NULL) {
      full_list[index] = atoi(token);
      token = strtok(NULL, "   ");
      index++;
    }
  }


  left_list[left_index++] = full_list[0];
  printf("%d\n", left_list[0]);
  right_list[right_index++] = full_list[1];
  printf("%d\n", right_list[0]);


  // Split it into left and right
  for (int i = 2; i < index; i++) {
    if (i % 2 == 0) {
      left_list[left_index++] = full_list[i];
    } else {
      right_list[right_index++] = full_list[i];
    }
  }

 
  printf("%d\n", left_list[0]);
  printf("%d\n", right_list[0]);

 


  // sort both lists
  for (int i = 0; i < left_index; i++) {
    for (int j = 0; j < left_index - i - 1; j++) {
      if (left_list[j] > left_list[j+1]) {
        int temp = left_list[j];
        left_list[j] = left_list[j+1];
        left_list[j + 1] = temp;
        //printf("left_list: %d\n", left_list[i]);
      }  
    }
  }


  printf("%d\n", left_list[0]);
  printf("%d\n", right_list[0]);

  for (int i = 0; i < right_index; i++) {
    for (int j = 0; j < right_index - i - 1; j++) {
      if (right_list[j] > right_list[j+1]) {
        int temp = right_list[j];
        right_list[j] = right_list[j+1];
        right_list[j + 1] = temp;
      }
    }
  }

  printf("Get the difference");
  // get the difference between both lists
  for (int i = 0; i < left_index; i++) {
    if (left_list[i] > right_list[i]) {
      difference = (left_list[i] - right_list[i]);
      diff_ans += difference;
      printf("\n%d. %d - %d = %d\n",i, left_list[i], right_list[i], difference);
    } else {
      difference = (right_list[i] - left_list[i]);
      diff_ans += difference;
      printf("\n%d. %d - %d = %d\n",i, left_list[i], right_list[i], difference);
    }
  }


  // get the Similiarity
  for (int i = 0; i < left_index; i++) {
    for (int j = 0; j < right_index; j++) {
      if (left_list[i] == right_list[j]) {
        count++;
      }
    }
    sim_ans += left_list[i] * count;
    printf("%d. Diff: %d\n", i, sim_ans);
    printf("%d. Count: %d\n", i, count);
    count = 0;
  }

  printf("\nIndex: %d", index);
  printf("\nAnswer: %d\n", diff_ans);
  printf("Similiarity: %d\n", sim_ans);
  printf("\nleft_index: %d\n", left_index);
  printf("right_index: %d\n", right_index);
  printf("\n%d", left_list[0]);
  printf("\n%d", right_list[0]);
  printf("\n%d", left_list[left_index-1]);
  printf("\n%d", right_list[right_index-1]);
  

  return 0;
};
