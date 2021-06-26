int myAtoi(char * s){
    
    int min = -pow(2, 31);
    int max = pow(2, 31) - 1;
    
    int result = 0;
    int operation = 1;
    bool started = false;
    
    
    while (*s != '\0') {
        
        if (*s != '-' && *s != '+' && *s != ' ' 
            && !isdigit(*s)) return result;
        
        if (started && !isdigit(*s)) return result;
        
        if (*s == '+' || *s == '-') {
            if (started) return 0;
            
            operation = *s == '-' ? -operation : operation;
            *s++;
            if (!isdigit(*s)) return 0;
        }
        
        
        if (*s >= '0' && *s <= '9') {
            int num = *s - '0';
            
            if (operation < 0) {
                if (result < min/10) return min;
                else if (result == min / 10) {
                    if (-num <= (min % 10)) return min;
                }
            } else {
                if (result > max / 10) return max;
                else if (result == max / 10) {
                    if (num >= max % 10) return max;
                }
            }
            
            result = result * 10 + num * operation;
            
            started = true;
        }
        
        *s++;
    }
    
    return result;
    
}
