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
// int max_len_new_d(t_list *names) {
//     int max = 0;
//     int temp = 0;

//     for (int i = 0; names[i]; i++) {
//         temp = mx_strlen(names[i]->name);
//         if (temp > max)
//             max = temp;
//     }
//     if (max % 8 == 0)
//         max += 8;
//     else
//         max = 8 - (max % 8) + max;
//     return max;
// }

// void mx_print_tab(int len, int maxlen) {
//     int count = 0;
//     int p;

//     p = maxlen - len;
//     if (p % 8 != 0)
//         count = (p / 8) + 1;
//     else
//         count = p / 8;
//     for (int i = 0; i < count; i++)
//         mx_printchar('\t');
// }

