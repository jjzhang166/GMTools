


#define ERR_EXIT(m) \
	do \
{ \
	perror(m); \
} while(0)


#define SS_BREAK_IF(cond)            if(cond) break


/* Define NULL pointer value */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

