#ifndef CONFIG_H
#define CONFIG_H

#define IGNRCHAR '#'
#define MAX_LINE_LEN 50
#define INCFILE "../conf/incfile.conf"
#define MKCFCONF "../conf/mkcf.conf"
#define CONFDELI "="

extern int getConfLine(FILE *fpConf, char string[]);
extern int getConfOption(FILE *fpConf, char option[], char ans[]);

#endif
