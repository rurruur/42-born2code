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

void va_start(va_list ap, prev_param);
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
    - prev_param: 인수 목록에서 첫 번째 선택적 인수 바로 앞에 오는 필수 매개 변수의 이름
    - va_arg를 처음으로 사용하기 전에 va_start를 사용해야 함
    - prev_param이 register 스토리지 클래스로 선언된 경우 매크로의 동작은 정의되지 않음
> ##### va_arg
    - ap가 제공하는 위치에서 type의 값을 검색
    - type의 크기를 사용하여 목록의 다음 인수를 가르키도록 ap를 증가시켜 다음 인수가 시작되는 위치를 결정
    - 함수에서 va_arg를 원하는 횟수만큼 사용하여 목록에서 인수 검색 가능
    - int보다 작은 값(예: char, bool, short)을 가변 개수의 인수를 사용하는 함수에 전달하면 int로 변환됨
> ##### va_copy
    - 인수 목록의 현재 상태로 복사본을 생성
    - src 매개 변수는 va_start로 초기화된 상태여야 하며, va_arg 호출에서 업데이트 되었을 수도 있음
    - va_arg가 dest에서 검색하는 다음 인수는 src에서 검색되는 다음 인수와 동일
> ##### va_end
    - ap 포인터를 NULL로 설정
    - 함수가 반환되기 전에 va_start 또는 va_copy로 초기화된 각 인수 목록에 대해 va_end를 호출해야 함

### 구현
~~~
int ft_printf(const char *, ...);
~~~
실제 printf처럼 버퍼 관리를 수행해서는 안 됨

다음 서식 지정자를 구현: cspdiuxX%
#### 서식 지정자
- ##### %c - 단일 문자(character) 출력

- ##### %s - 문자열 출력
    - if 포인터가 null이면 (null) 출력
    - else 문자열 출력

- ##### %p - 주소값을 16진수로 출력
    1. 포인터와 크기가 같은 unsigned long long 타입으로 주소값을 받아옴
    2. 16진수로 출력하기 때문에 (포인터 크기(8) * 2)로 ptr_size 선언
    3. 0x 출력
    4. address의 값을 시프트 연산자로 앞의 4비트씩 읽어서 0이 아닌 값이 나올 때까지 ptr_size--;
        - address >> (ptr_size * 4) & 15
        - while (ptr_size-- > 0)
    5. if ptr_size가 -1 이면 0 출력
       else 주소값 출력

- ##### %d - 10진수 정수 출력
    - ft_itoa 이용해서 문자열로 바꾼 후 문자열 출력

- ##### %i - 10진수 정수 출력
    - %d, %i는 printf에서는 출력이 동일, scanf에서 입력을 받을 때 다르게 동작
    - %d - 수를 10진수로 받음
    - %i - 기본적으로 10진수로 받지만, 16진수와 8진수를 허용(ex: 0x12, 012)

- ##### %u - 부호 없는 10진수 숫자
    - unsigned int로 값을 받아온 후 %d와 유사하게 처리

- ##### %x - 소문자 사용하여 수를 16진수로 출력
    1. 값을 16진수로 변환했을 때의 길이 구함
    2. 길이 + 1로 할당 후 문자열 생성
    3. 문자열 출력

- ##### %X - 대문자 사용하여 수를 16진수로 출력

- ##### %% - % 출력