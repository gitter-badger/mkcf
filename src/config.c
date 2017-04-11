#include <stdio.h>
#include <string.h>
#include "inc/config.h"

int getConfLine(FILE *fpConf, char string[]){
  while(!feof(fpConf)){
    fgets(string, MAX_LINE_LEN, fpConf);
    if( string[0] != IGNRCHAR && string[0] != '\n' )
      return 1;
  }
  return 0;
}

int getConfOption(FILE *fpConf, char option[], char ans[]){
  //IF optionans = ans
  char confLine[MAX_LINE_LEN];

  while(getConfLine(fpConf, confLine))
    if( strstr(confLine, option) &&  strstr(confLine, ans) )
      return 1;
  return 0;
}
