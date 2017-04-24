#ifndef CONFIG_H
#define CONFIG_H

#define IGNRCHAR '#'
#define MAX_LINE_LEN 50
#define INCFILE "/usr/local/etc/mkcf/incfile.conf"
#define MKCFCONF "/usr/local/etc/mkcf/mkcf.conf"
#define CONFDELI "="

extern int getConfLine(FILE *fpConf, char string[]);
extern int getConfOption(FILE *fpConf, char option[], char ans[]);

#endif
