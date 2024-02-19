#include <stddef.h>
#include <stdint.h>

extern "C" void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    for (size_t i = 0; i < n; i++) { pdest[i] = psrc[i]; }

    return dest;
}

extern "C" void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;

    for (size_t i = 0; i < n; i++) { p[i] = (uint8_t)c; }

    return s;
}

extern "C" void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) { pdest[i] = psrc[i]; }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) { pdest[i - 1] = psrc[i - 1]; }
    }

    return dest;
}

extern "C" int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) { return p1[i] < p2[i] ? -1 : 1; }
    }

    return 0;
}

extern "C" size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len]) { len++; }
    return len;
}

extern "C" char *strcpy(char *dest, const char *src) {
    size_t i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

extern "C" char *strncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = 0;
        i++;
    }
    return dest;
}

extern "C" size_t strlcpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (src[i] && i < n - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return i;
}
