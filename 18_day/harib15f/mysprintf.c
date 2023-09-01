// mysprintf.c
// http://bttb.s1.valueserver.jp/wordpress/blog/2017/12/17/makeos-5-2/
// http://wisdom.sakura.ne.jp/programming/c/c62.html -動的引数-

#include <stdarg.h>

//10進数からASCIIコードに変換
int dec2asc (char *str, char head, int len_assign, int dec) {
    int len_dec = 0, len_buf; //桁数
    int buf[10];
    while (1) { //10で割れた回数（つまり桁数）をlenに、各桁をbufに格納
        buf[len_dec++] = dec % 10;
        if (dec < 10) break;
        dec /= 10;
    }
    if (len_assign > 0) {
        len_buf = len_assign;
        for (int i=len_dec; i<len_assign; i++) {
            *(str++) = head;
        }
    } else {
        len_buf = len_dec;
    }
    while (len_dec) {
        *(str++) = buf[--len_dec] + 0x30;
    }
    return len_buf;
}

//16進数からASCIIコードに変換
int hex2asc (char *str, char head, int len_assign, int dec) {
    int len_hex = 0, len_buf; //桁数
    int buf[10];  //16で割れた回数（つまり桁数）をlenに、各桁をbufに格納
    while (1) {
        buf[len_hex++] = dec % 16;
        if (dec < 16) break;
        dec /= 16;
    }
    if (len_assign > 0) {
        len_buf = len_assign;
        for (int i=len_hex; i<len_assign; i++) {
            *(str++) = head;
        }
    } else {
        len_buf = len_hex;
    }
    while (len_hex) {
        len_hex --;
        *(str++) = (buf[len_hex]<10)?(buf[len_hex] + 0x30):(buf[len_hex] - 9 + 0x60);
    }
    return len_buf;
}

void sprintf (char *str, char *fmt, ...) {
    va_list list;
    int i, len_output;
    //va_start (list, 2);
    va_start (list, fmt); //警告が出るので修正 second parameter of 'va_start' not last named argument

    while (*fmt) {
        if(*fmt=='%') {
            int len_assign = 0;
            char head = ' ';
            fmt++;
            if (*fmt != 'd' && *fmt != 'x') {
                if (*fmt < '1' || *fmt > '9') {
                    head = *fmt;
                    fmt++;
                }
                while (*fmt >= '0' && *fmt <= '9') {
                    len_assign *= 10;
                    len_assign += *fmt - 0x30;
                    fmt++;
                }
            }
            switch(*fmt){
                case 'd':
                    len_output = dec2asc(str, head, len_assign, va_arg (list, int));
                    break;
                case 'x':
                    len_output = hex2asc(str, head, len_assign, va_arg (list, int));
                    break;
            }
            str += len_output; fmt++;
        } else {
            *(str++) = *(fmt++);
        }   
    }
    *str = 0x00; //最後にNULLを追加
    va_end (list);
}

int strcmp(const char *s1, const char *s2) {
    if (*s1 == 0 && *s2 == 0) {
        return 0;
    }

    do {
        if (*s1 != *s2) break;
    } while (*(++s1) & *(++s2));

    return (int)(*s1 - *s2);
}
