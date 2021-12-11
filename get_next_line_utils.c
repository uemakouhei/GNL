#include "get_next_line.h"
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        const char      *srcpt;
        char            *pt;

        srcpt = (char *)src;
        pt = (char *)dst;
        if (pt == NULL && srcpt == NULL)
                return (NULL);
        while (n--)
        {
                *pt++ = *srcpt++;
        }
        return (dst);
}
