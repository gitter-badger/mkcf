#include <stdio.h>
#include "inc/config.h"

void printHeader(FILE *fpW);

int main(){
	FILE *fp;
	fp = fopen("main.c", "w");
	fputs("// Header\n", fp);
	printHeader(fp);
	fputs("\n// Sourcecode\n", fp);
	fputs("int main(){\n", fp);
	fputc('\n', fp);
	fputs("\treturn 0;\n", fp);
	fputc('}', fp);

	fclose(fp);

	return 0;
}

void printHeader(FILE *fpW){
	FILE *fpInc;
	char inc_string[MAX_LINE_LEN];

	fpInc = fopen(INCFILE, "r");
	if(!fpInc){
		printf("Did not fount %s\n", INCFILE);
		return;
	}

	while(getConfLine(fpInc, inc_string))
			fprintf(fpW, "#include %s", inc_string);

	fclose(fpInc);
}
