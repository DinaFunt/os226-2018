
#include <stddef.h>
#include <string.h>

int strcmp(const char *s1, const char *s2) {
    for (; *s1 && *s2; s1++, s2++) 
    {
        if (*s1 > *s2)
        {
            return 1;
        }
        if (*s1 < *s2)
        {
            return -1;
        }
    }
    if (!(*s1) && *s2)
    {
        return (-1);
    }
    if (!(*s2) && *s1)
    {
        return 1;
    }
    return 0;
}

size_t strlen(const char *s) {
    size_t l = 0;
    while (*s) 
    {
        l++;
        s++;
    }
    return l;
}

char *strchr(const char *s, int c) {
    for (; *s; s++)
    {
        if (*s == c)
        {
            return (char *)s;
        }
    }
    return NULL;
}

size_t strspn(const char *str, const char *accept) {
    int x = 0;
    const char *tmp;
    for (; *str; str++)
    {
        for (tmp = accept; *tmp; tmp++)
        {
            if (*str == *tmp)
            {
                break;
            }
        }
        if (*tmp)
        {
            x++;
        }
        else
        {
            return x;
        }
    }
    return x;
}

size_t strcspn(const char *str, const char *reject) {
    int x = 0;
    const char *tmp;
    for (; *str; str++)
    {
        for (tmp = reject; *tmp; tmp++)
        {
            if (*str == *tmp)
            {
                return x;
            }
        }
        x++;
    }
    return x;
}

char *strtok_r(char *str, const char *delim, char **saveptr) {
    char *tmp;
    if (str == NULL) 
    {
        str = *saveptr;
   	    if (str == NULL) 
   	    {
            return NULL;
        }
    }

    for (; strcspn(str, delim) == 0 && *str; str++);
    if (*str == '\0')
    {
        str = NULL;
        *saveptr = NULL;
        return str;
    }

    tmp = str;
    str = str + strcspn(str, delim);

    while (strcspn(str, delim) == 0 && *str)
    {
        *str = '\0';	
        str++;
    }

    *saveptr = str;	
    str = NULL;

    return tmp;
}