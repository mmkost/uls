#include "uls.h"

int mx_biggest(t_list *p) {
	int length = 0;
	int tmp = 0;
	while(p != NULL) {
		tmp = mx_strlen(p->data);
		if(tmp > length) 
			length = tmp;
		p = p->next;
	}
	if(length % 8 == 0) 
		length = length + 1;
	else {
		while(length % 8 != 0) 
			length++;
	}
	return length;
}
