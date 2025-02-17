#include "ui_util.h"

#include <string.h>

#include "ui_priv.h"

void vui_strcpy(char *dst, const char *src)
{
    if (src)
        strncpy(dst, src, MAX_BUTTON_TEXT);
    else
        dst[0] = 0;
    dst[MAX_BUTTON_TEXT-1] = 0;
}

size_t vui_utf8_cp_len(const char *s)
{
    size_t count = 0;
    while (*s) {
        count += (*s++ & 0xC0) != 0x80;
    }
    return count;
}

char *vui_utf8_advance(char *s)
{
    if ((*s & 0xF0) == 0xF0) {
        return s + 4;
    } else if ((*s & 0xE0) == 0xE0) {
        return s + 3;
    } else if ((*s & 0xC0) == 0xC0) {
        return s + 2;
    }
    return s + 1;
}