#include "uls.h"

void mx_min_l() {
	struct stat buff;
	lstat(p->data, &buff);
	struct passwd *pw;
	pw = getpwuid(buff.st_uid);
	printf("%lld ", buff.st_blocks);
	//printf("-rw-r--r--  ");
	printf("%d ", buff.st_nlink); // страные цифры перед выводом
	printf("%s  ", pw->pw_name);
	printf("%d  ", buff.st_gid);
	printf("%lld ", buff.st_size);
	printf("%s ", str);
	printf("%s\n", files->data); 
}