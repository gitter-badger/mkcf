#include <stdio.h>
#include <string.h>
#include "inc/config.h"

void printHeader(FILE *fpW);
void printMain(FILE*fpW);


int main(){
	FILE *fp;
	if(!(fp = fopen("main.c", "w"))){
		printf("Could not open %s\n", "main.c");
		return 1;
	}

	fputs("// Header\n", fp);
	printHeader(fp);
	fputs("\n// Sourcecode\n", fp);
	printMain(fp);

	fclose(fp);

	return 0;
}

void printHeader(FILE *fpW){
	FILE *fpInc;
	char inc_string[MAX_LINE_LEN];

	if(!(fpInc = fopen(INCFILE, "r"))){
		printf("Could not open %s\n", INCFILE);
		return;
	}

	while(getConfLine(fpInc, inc_string))
			fprintf(fpW, "#include %s", inc_string);

	fclose(fpInc);
}

void printMain(FILE *fpW){
	FILE *fpR;
	if(!(fpR = fopen(MKCFCONF, "r"))){
		printf("Could not open %s\n", MKCFCONF);
		return;
	}

	fputs("int main(", fpW);
	if( getConfOption(fpR, "mainarg", "yes") )
		fputs("int argc, char *argv[]", fpW);
	fputs( "){\n", fpW);
	fputc('\n', fpW);
	fputs("\treturn 0;\n", fpW);
	fputc('}', fpW);
}
