#ifndef CONFIG_H
#define CONFIG_H

extern int getConfLine(FILE *fp, char string[]);

#define IGNRCHAR '#'
#define MAX_LINE_LEN 50
#define INCFILE "../conf/incfile.conf"

#endif
