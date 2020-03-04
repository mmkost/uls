void mx_swap_char(char *s1, char *s2) {
    int c = *s2;
    
    *s2 = *s1;
    *s1 = c;
}
