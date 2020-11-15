/* 
 * 提供：
 * 1. 错误信息打印的宏
 * 2. 常用函数（如malloc）的错误处理包装函数
 */
#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define FatalErrorInFunc(LOCATION, MSG) fprintf(stderr, "%s: %s\n", LOCATION, MSG), exit(1)

#define MALLOC_FAIL_MSG "Malloc Failed!!!"
#define CALLOC_FAIL_MSG "Calloc Failed!!!"

void *malloc_fatal(size_t size, const char *location);
void *calloc_fatal(size_t num, size_t size, const char *location);
