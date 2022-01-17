# ft_printf

- Norm 규칙
- 메모리 누수
- Makefile $(NAME), all, clean, fclean, re
- libft 사용 시 libft 폴더 안에 소스 + Makefile 추가
    - 해당 프로젝트의 Makefile은 libft의 Makefile로 라이브러리 컴파일 후, 프로젝트를 컴파일

## Mandatory part
실제 printf의 동작을 모방한 ft_printf를 포함하는 라이브러리를 작성
제출 파일: *.c, */*.c, *.h, */*.h, Makefile
Makefile 규칙: all, clean, fclean, re, bonus
외부 함수: malloc, free, write, va_start, va_arg, va_copy, va_end

### 외부 함수
~~~
#include <stdarg.h>

void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
~~~
