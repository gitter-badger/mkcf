#include <stdio.h>
#include "inc/config.h"

int getConfLine(FILE *fp, char string[]){
  while(!feof(fp)){
    fgets(string, MAX_LINE_LEN, fp);
    if( string[0] != IGNRCHAR && string[0] != '\n' )
      return 1;
  }
  return 0;
}
