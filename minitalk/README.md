# minitalk
- UNIX signal을 이용한 소규모 데이터 교환 프로그램을 작성

## Common Instructions
- 실행파일은 각각 `client`와 `server`로 이름을 지어야 합니다.
- Makefile 에서는 다음의 룰을 정의하고 있어야 합니다. `$(NAME)`, `all`, `clean`, `fclean`, `re`
- 필수파트를 위해서 다음의 함수만을 사용하실 수 있습니다. :
    - `write`
    - `signal`
        ```
        #include <signal.h>
        
        void (*signal(int sig, void (*func)(int)))(int);
        // or
        typedef void (*sig_t) (int);
        sig_t signal(int sig, sig_t func);
        ```
        - sig: 받은 시그널
        - func: 시그널 받았을 때 수행할 동작
        - 에러 발생 시 SIG_ERR가 리턴됨 + errno가 전역 변수로 설정
        - 한번 사용하고 나면 signal action을 디폴트값으로 리셋함
    - `sigemptyset`
        ```
        #include <signal.h>

        int sigemptyset(sigset_t *set);
        ```
        - initializes a signal set to be empty
        - signal set 생성, sigset_t에 저장
        - sigemptyset() or sigfillset()은 sigset_t 사용 전 호출 필요
        - 에러 없음, 리턴값 0
    - `sigaddset`
        ```
        #include <signal.h>

        int sigaddset(sigset_t *set, int signo);
        ```
        - adds the specified signal signo to the signal set
        - 에러 없음 리턴값 0
    - `sigaction`
        ```
        #include <signal.h>

        struct sigaction {
            union __sigaction_u __sigaction_u;  // signal handler
            sigset_t sa_mask;  // signal mask to apply
            int sa_flags;  // sa_flags specifies a set of flags which modify the behavior of the signal.
        };

        union __sigaction_u {
            void (*__sa_handler)(int);
            void (*__sa_sigaction)(int, siginfo_t *, void *);
        };

        #define sa_handler __sigaction_u.__sa_handler
        #define sa_sigaction __sigaction_u.__sa_sigaction

        int sigaction(int sig, const struct sigaction *restrict act,
            struct sigaction *restrict oact);
        ```
        - 글로벌 시그널 마스크는 현재 프로세스로의 전달이 막힌 시그널들의 집합 정의
        - 프로세스의 시그널 마스크는 그의 부모로부터 초기화됨(보통 비어있음)
        - sigaction() 호출은 sig가 가리키는 시그널에 액션을 할당
        - 리턴: 성공=0, 아니면 -1(with global variable errno)
        ```
        int main()
        {
            struct sigaction act;

	        act.sa_handler = signal_handler;
	        sigemptyset(&act.sa_mask);  // sa_mask: 비워뒀으므로 모든 시그널 블록되지 않음
	        act.sa_flags = 0;
	        sigaction(SIGUSR1, &act, NULL);
	        sigaction(SIGUSR2, &act, NULL);
        }
        ```
    - `kill`
        ```
        #include <signal.h>

        int kill(pid_t pid, int sig);
        ```
        - sends a signal to the processes specified by the pid operands.
    - `getpid`
    - `malloc`
    - `free`
    - `pause`
        - calling thread to pause until a signal is received
    - `sleep`
        - seconds
    - `usleep`
        - microseconds
    - `exit`

### signal() vs sigaction()
- signal()은 한번 호출 후 signal action을 디폴트(SIG_DFL)로 리셋
- sigaction()은 sa_flag를 이용한 다양한 기능의 지원
- more:  <a href="https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal">difference between sigaction and signal(stackoverflow)</a>

## Mandatory part
- 클라이언트와 서버가 서로 통신하는 프로그램
- 서버와 클라이언트 중 서버가 먼저 실행되어야 하며, 실행된 후에 반드시 PID를 표시
- 클라이언트가 실행될 때 다음의 매개변수를 받습니다:
    - 서버 PID
    - 전송할 문자열
- 클라이언트는 매개변수로 전달한 문자열을 서버로 통신, 서버는 문자열이 수신되면 해당 문자열을 표시
- 서버와 클라이언트의 통신은 **오직 UNIX signal**을 이용
- 서버는 문자열을 매우 빠른 속도로 표시할 수 있어야 함
	- 즉, 표시되는 시간이 너무 길다고 생각된다면, 그건 너무 길다고 여겨야 합니다. (힌트 : 100개의 문자로 이루어진 문자열을 표시하는 데 1초가 걸린다면 그건 **어마어마하게 긴 것**입니다.)
- 서버는 재시작 없이 여러 클라이언트로부터 문자열을 연속으로 수신 가능
- **SIGUSR1**과 **SIGUSR2** 두 신호만 사용 가능

### 구현
- 서버 프로그램 작동 후 서버의 pid 확인 -> 클라이언트 프로그램을 pid와 문자열을 매개변수로 실행하여 문자열 전달
    - `./client [pid] "문자열"`
- **SIGUSR1**과 **SIGUSR2**를 이용해서 비트 하나씩 보내서 char 문자로 합친 후 한 글자씩 출력
- 1이면 **SIGUSR1**(30), 0이면 **SIGUSR2**(31)
- 받은 시그널 값(sig) % 2 해서 char에 합산
- 문자열 끝나면 127(111 1111) 전송하여 개행 출력(다음 문자열과 구분하기 위함)
- 개행 출력 후 클라이언트 프로세스로 완료했다고 시그널 전송
- 클라이언트는 SIGUSR1 받으면 완료 메세지 출력 후 종료 or 못받으면 실패 메세지 출력

## Bonus
- 소규모 수신 확인 시스템을 추가
- 유니코드 문자 지원