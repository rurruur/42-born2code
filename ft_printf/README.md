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
위 매크로는 함수가 가변 개수의 인수를 취할 때 함수에 대한 인수에 액세스하는 방법을 제공
매크로에는 두 가지 버전이 있다.
- STDARG.H - ISO C99 표준에 따라 정의된 매크로
- VARARGS.H - 더이상 사용하지 않지만 ANSI C89 표준 이전에 작성된 코드와의 호환성을 위해 유지

이러한 매크로는 함수가 고정된 수의 필수 인수에 가변 수의 선택적 인수가 붙은 형식을 사용한다고 가정
- 필수 인수 - 함수에 대한 일반 매개 변수로 선언되며 매개 변수 이름을 통해 액세스 가능
- 선택적 인수 - STDARG.H, VARARGS.H의 매크로를 통해 액세스 가능
- 매크로 - 목록의 첫 번째 선택적 인수에 대한 포인터를 설정하고, 목록에서 인수를 검색하고, 인수 처리가 완료되면 포인터를 리셋

#### STDARG.H에 정의된 C 표준 매크로
> ##### va_start
    - 함수로 전달되는 인수 목록의 첫 번째 선택적 인수로 ap를 설정
    - ap 인수의 형식은 va_list