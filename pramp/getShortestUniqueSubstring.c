//First mock interview pset I had to solve @ Pramp: https://www.pramp.com/challenge/wqNo9joKG6IJm67B6z34

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getShortestUniqueSubstring(char *arr, int arrLength, char *str, char *out) 
{
  int tempL = 0, stringL, index = 0, strLength = 0, flag, j, i, tempSize;
  char* string = (char *) malloc(sizeof(char *));
  int* ASCII = (int *) calloc(sizeof(int), 128);
  strcpy(string, "");
  
  for(int k = 0; k < arrLength; k++){
    ASCII[(int) arr[k]] = k + 1;
  }
  
  strLength = strlen(str);
  stringL = strLength;

  do{
    j = 0;
    tempSize = 1;
    tempL = 0;
    
    int* checkList = (int *) calloc(sizeof(int), arrLength);
    char* temp = (char *) malloc(sizeof(char));
       
    for(i = index; i < strLength; i++){
      
      flag = 0;
      
      if(ASCII[(int)str[i]] != 0){
         checkList[ASCII[(int)str[i]] - 1] = 1;
      }
       
      temp = (char *) realloc(temp, sizeof(char)*tempSize);
      
      temp[j] = str[i];
      tempL += 1;
      j++;
      tempSize++;
      
      for(int b = 0; b < arrLength; b++){
        if(checkList[b] == 0){
          flag = 1;
          break;
        }
      }
      
      if(flag == 0){
        if(stringL >= tempL){
          stringL = tempL;
          strcpy(string, temp);
        }
        break;
      }
    }
    
    index++;
    free(temp);
    free(checkList);
  }
  while(i != strLength);
  
  strcpy(out, string);
}

int main() {
  return 0;
}
