#include "uls.h"

void mx_multcol(int ws, int length, t_list *names) {
	int size = mx_list_size(names);
	t_list *copy  = NULL;
	int col = ws / length;
	int str = size / col;
	if (size % col != 0) 
		str++;
	col = size / str;
	if (size % str != 0)
		col++;
	mx_printstr(names->data);
	 mx_printchar('\n');
	for(int j = 0; j < col; j++) {
		if (names->next != NULL)
		    copy = names->next;
		for(int i = 0; i < str; i++) {
			if (names->next != NULL)
			    names = names->next; 
		}
		mx_printstr(names->data);
		mx_printchar('\n');
		mx_printstr(copy->data);
		mx_printchar('\n');
	}
	// for(int i = 0; i < str; i++) {
	// 	names = names->next; 
	// }
    mx_printchar('\n');
}
