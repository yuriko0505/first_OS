// mysprintf.c
// http://bttb.s1.valueserver.jp/wordpress/blog/2017/12/17/makeos-5-2/
// http://wisdom.sakura.ne.jp/programming/c/c62.html -動的引数-

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

// 文字列をそのままコピー
int str2str (char *str, int len_assign, const char *s) {
    int len_buf = 0;
    if (len_assign > 0) {
        for (; len_buf < len_assign; len_buf++) {
            *(str++) = *(s++);
        }
    } else {
        while (*(s) != 0) {
            *(str++) = *(s++);
            len_buf++;
        }
    }
    return len_buf;
}

// 文字列を全て大文字にしてコピー
int str2STR (char *str, int len_assign, const char *s) {
    int len_buf = 0;
    if (len_assign > 0) {
        for (; len_buf < len_assign; len_buf++) {
            if ('a' <= *s && *s <= 'z') {
                *(str++) = *(s++) - 0x20;
            } else {
                *(str++) = *(s++);
            }
        }
    } else {
        while (*(s) != 0) {
            if ('a' <= *s && *s <= 'z') {
                *(str++) = *(s++) - 0x20;
            } else {
                *(str++) = *(s++);
            }
            len_buf++;
        }
    }
    return len_buf;
}

// 文字列をファイル名フォーマットに整形
// FILENAME.EXT
int str2fname (char *str, int len_assign, const char *s) {
    int pos_period = 0;
    str2str(str, 11, "        HRB");
    for (; pos_period<12; pos_period++) {
        if (s[pos_period] == '.') {
            str2STR(str, pos_period, s);
            str2STR(str+8, 3, s+pos_period+1);
            break;
        } else if (s[pos_period] == 0x00) {
            str2STR(str, 0, s);
        }
    }
    return 11;
}

void sprintf (char *str, char *fmt, ...)
/* <usage>
%d:     int型の整数を10進法で表示
%05x:   int型の整数を16進法で表示
%5s:    char*型の文字列を先頭から5文字分コピー
%S:     char*型の文字列を全て大文字にしてコピー
*/
{
    __builtin_va_list list;
    int i, len_output;
    __builtin_va_start(list, fmt);

    while (*fmt) {
        if(*fmt=='%') {
            int len_assign = 0;
            char head = ' ';
            fmt++;
            if (*fmt != 'd' && *fmt != 'x' && *fmt != 's' && *fmt != 'S') {
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
                    len_output = dec2asc(str, head, len_assign, __builtin_va_arg(list, int));
                    break;
                case 'x':
                    len_output = hex2asc(str, head, len_assign, __builtin_va_arg (list, int));
                    break;
                case 's':
                    if (head == 'f') { len_output = str2fname(str, len_assign, __builtin_va_arg (list, const char*)); }
                    else { len_output = str2str(str, len_assign, __builtin_va_arg (list, const char*)); }
                    break;
                case 'S':
                    len_output = str2STR(str, len_assign, __builtin_va_arg (list, const char*));
                    break;
            }
            str += len_output; fmt++;
        } else {
            *(str++) = *(fmt++);
        }   
    }
    *str = 0x00; //最後にNULLを追加
    __builtin_va_end(list);
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

int strncmp(const char *s1, const char *s2, const int l) {
    int i = 0;
    for (; i < l-1; i++){
        if (s1[i] != s2[i]) break;
    }

    return (int)(s1[i] - s2[i]);
}
