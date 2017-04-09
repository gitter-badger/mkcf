#include<stdio.h>

#define INCFILE "../conf/incfile.conf"
#define MAX_LINE_LEN 100

void includeHeader(FILE *fpW);

int main(){
	FILE *fp;
	fp = fopen("main.c", "w");

	includeHeader(fp);
	fprintf(fp, "\n");
	fprintf(fp, "int main(){\n");
	fprintf(fp, "\n");
	fprintf(fp, "\treturn 0;\n");
	fprintf(fp, "}");

	fclose(fp);

	return 0;
}

void includeHeader(FILE *fpW){
	FILE *fpInc;
	char inc_string[MAX_LINE_LEN];

	fpInc = fopen(INCFILE, "r");
	if(!fpInc){
		printf("Did not fount %s\n", INCFILE);
		return;
	}
	while(!feof(fpInc)){
		fgets(inc_string, MAX_LINE_LEN, fpInc);

		if(!(inc_string[0] == '#') && !(inc_string[0] == '\n'))
			fprintf(fpW, "#include%s", inc_string);
		else
			continue;
	}

	fclose(fpInc);
}