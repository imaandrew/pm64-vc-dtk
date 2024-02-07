#include "types.h"

s32 xlTextLen(s8* str) {
    s32 len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

s32 xlTextCopy(s8* dst, s8* src) {
    s32 i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';
    return i;
}

s32 xlTextConcat(s8* dst, s8* src) {
    s32 j;
    s32 i = 0;
    
    while (dst[i] != '\0')
        i++;

    j = 0;

    while (src[j] != '\0')
        dst[i++] = src[j++];

    dst[i] = 0;
    return j;
}
