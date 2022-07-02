# Minishell

> 간단한 쉘(나만의 작은 zsh, bash) 제작

## 목차
- [Introduction](#introduction)
- [Mandatory part](#mandatory-part)
- [외부 함수 설명](#외부-함수-설명)

## Introduction
The existence of shells is linked to the very existence of IT. At the time, all coders agreed
that communicating with a computer using aligned 1/0 switches was seriously
irritating. It was only logical that they came up with the idea to communicate with
a computer using interactive lines of commands in a language somewhat close
to english.
With Minishell, you’ll be able to travel through time and come back to problems
people faced when Windows didn’t exist.

## Mandatory part

| Program name | minishell |
| --- | --- |
| Turn in files | * |
| Makefile | NAME, all, clean, fclean, re |
| Arguments |  |
| External functs. | `readline`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_histroy`, `printf`, `malloc`, `free`, `write`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `errno`, `isatty`,`ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs` |
| Libft authorized | Yes |
| Description | Write a shell |

나의 쉘은 해야 한다...
- Not interpret unclosed quotes or unspecified special characters like \ or;.
- Not use more than one global variable, think about it and be ready to explain why you do it.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
- 다음의 내장 기능을 수행할 수 있어야 한다...
	- `echo` with option -n
	- `cd` with only a relative or absolute path
	- `pwd` with no options
	- `exprot` with no options
	- `unset` with no options
	- `env` with no options or arguments
	- `exit` with no options
- `’` inhibit all interpretation of a sequence of characters.
	- ?
- `"` inhibit all interpretation of a sequence of characters except for $.
	- ?
- 리다이렉션:
	- `<` 입력을 리다이렉션
	- `>` 출력을 리다이렉션
	- `<<` 소스에서 구분자를 포함한 줄을 만나기 전까지 입력을 받음
	- `>>` 출력을 추가 모드로 리다이렉션
- Pipes `|` The output of each command in the pipeline is connected via a pipe to the input of the next command.
- Environment variables ($ followed by characters) should expand to their values.
- $? should expands to the exit status of the most recently executed foreground pipeline.
- ctrl-C ctrl-D ctrl-\ should work like in bash.
- When interactive:
	- ctrl-C print a new prompt on a newline.
	- ctrl-D exit the shell.
	- ctrl-\ do nothing

Anything not asked is not required.

For every point, if you have any doubt take bash as a reference.

### 외부 함수 설명

- `readline`
	```c
	/*
	** @header	<stdio.h> <readline/readline.h> <readline/history.h>
	** @param	const char	*prompt	프롬프트로 사용(출력)
	** @return	char*			터미널에서 읽은 문자열
	*/
	char	*readline(const char *prompt);
	```
	터미널에서 한 줄을 읽고 리턴
	
	프롬프트가 널이거나 빈 문자열이면 프롬프트 출력되지 않음
	
	반환값은 malloc 사용해서 할당하여 반환 -> 사용 후 free 필요
	
	개행은 제거됨
	
	라인을 읽는 동안 EOF를 만났고, 빈 라인일 경우 NULL 리턴

<br>

- `rl_on_new_line`
	```c
	/*
	** @return	int		??
	*/
	int	rl_on_new_line(void);
	```
	Tell the update routines that we have moved onto a new (empty) line, usually after ouputting a newline.

	`rl_redisplay` 실행 위해 필요

<br>

- `rl_replace_line`
	```c
	/*
	** @param	const char	*str	입력된 문자열을 str로 바꿈
	** @param	int			??
	*/
	void	rl_replace_line(const char *str, int);
	```
	현재까지 입력된 프롬프트의 문자열을 str로 바꿔준다.

	ctrl + C 처럼 프롬프트를 입력하지는 않고 새로운 프롬프트를 출력해야 할 때 

	rl_replace_line(””, 1);처리를 해준다면 새로운 프롬프트를 비워줄 수 있게 된다.

<br>

- `rl_redisplay`
	```c
	void	rl_redisplay(void);
	```
	readline 함수의 인자(prompt) 다시 출력

<br>

- `add_history`
	```c
	/*
	** @param	const char	*str	해당 문자열을 history로 저장
	** @param	int			??
	*/
	int	add_history(const char *str);
	```
	str을 history로 저장

	프롬프트에서 방향키 위 아래를 통해 입력했던 명령어 기록을 불러올 수 있다.

<br>

- `fork`
	```c
	/*
	** @header	<unistd.h>
	** @return	pid_t		process ID of the child process
	*/
	pid_t	fork(void);
	```
	create a new process
	
	새 프로세스(자식 프로세스)는 부모 프로새스의 복사본이다.
	
	자식, 부모 다른점:

	- 프로세스 ID(unique)
	- The child process has its own copy of the parent's descriptos.
		Thes descriptors referece the same underlying objects, so that, for instance, file pointers in file objects are shared between the child and the parent, so that an lseek(2) on a descriptor in the child process can affect a subsequent read or write by the parent. This descriptor copying is also used by the shell to establish standard input and output for newly created processes as well as to set up pipes.
	- 자식 프로세스의 리소스는 0으로 설정(참조 setrlimit(2))
	
	성공적으로 완료되면 0을 자식 프로세스에 반환, 자식 프로세스의 ID를 부모 프로세스에 반환
	
	실패하면 -1이 부모 프로세스로 반환, 자식 프로세스 생성 x, 전역변수 errno 설정

<br>

- `wait`
	```c
	/*
	** @header	<sys/wait.h>
	** @param	int		*stat_loc	종료된 프로세스 정보
	** @return	pid_t				process ID of the child process
	*/
	pid_t	wait(int *stat_loc);
	```
	wait을 호출한 프로세스 실행 중단. 언제까지?

		- 종료된 자식 프로세스에서 stat_loc 정보를 사용 가능
		- 시그널 수신

	리턴값:
	
		- 중지되거나 종료된 자식 프로세스로 인해 종료 -> 자식 프로세스의 ID
			- stat_loc 영역에 종료된 프로세스에 대한 종료 정보 포함
		- 그렇지 않으면 -1 반환, errno 설정

	stat_loc:

		- stat_loc의 값이 NULL 포인터가 아닌 경우 여기에 정보 저장
		- stat_loc에 0이 저장되는 경우
			- The process returned 0 from main()
			- The process called _exit() or exit() with a status argument of 0
			- The process was terminated because the last thread in the process terminated

<br>

- `wait4`
	```c
	/*
	** @header	<sys/wait.h>
	** @param	pid_t		pid		기다릴 자식 프로세스 pid
	** @param	int		*stat_loc	종료된 프로세스 정보
	** @param	int		options		프로세스의 종료 상태 체크 시 사용
	** @param	struct rusage	*rusage		자식 프로세스의 리소스 사용량
	** @return	pid_t				process ID of the child process
	*/
	pid_t	wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
	```
	이런 프로그램을 위한 인터페이스 제공:
	
	- 특정 자식 프로세스를 기다려야 하거나
	- 자식 프로세스에 의해 누적된 리소스 사용량이 필요하거나
	- 옵션이 필요한 프로그램

	다른 wait 함수들은 wait4()를 이용하여 구현된다.

	만약 pid가...
	
	- -1: the call waits for any child process
	- 0: the call waits for any child process in the process group of the caller
	- -1 보다 작은 경우: the call waits for any process whose process group id equals the absolute value of pid

	만약 rusage가 0이 아니면, 종료된 프로세스와 그 프로세스의 자식들이 사용한 리소스에 대한 정보가 담긴다.
	
	리턴값:
	
	- 중지되거나 종료된 자식 프로세스로 인해 리턴되는 경우
		- 자식 프로세스의 pid 리턴
	- If there are no children not previously awaited, -1 is returned with errno set to [ECHILD].
	- if WNOHANG is specified and there are no stopped or exited children, 0 is returned.
	- If an error is detected or a caught signal aborts the call, a value of -1 is returned and errno is set to indicate the error.

	stat_loc에 사용 가능한 매크로

	| macro | 설명 |
	|:--:|:--:|
	| WIFEXITED(status) | 프로세스가 _exit(2) or exit(3)으로 정상 종료된 경우 true |
	| WIFSIGNALED(status) | 시그널 수신으로 종료된 경우 true |
	| WIFSTOPPED(status) | 종료가 아니라 중지되어 재시작 가능한 경우 true |
	| WEXITSTATUS(stats) | WIFEXITED가 참일 경우, exit()으로 넘겨줬던 인자의 하위 8 비트 리턴 |
	| WTERMSIG(status) | WIFSIGNALED가 참일 경우, 받았던 시그널 번호 리턴 |
	| WCOREDUMP(status) | WIFSIGNALED가 참일 경우, 프로세스의 이미지가 포함된 코어 파일 생성된 경우 true |
	| WSTOPSIG(status) | WIFSTOPPED가 참일 경우, 프로세스를 중단시킨 시그널 번호 리턴 |

<br>

- `waitpid`
	```c
	/*
	** @header	<sys/wait.h>
	** @param	pid_t	pid		기다릴 자식 프로세스 pid
	** @param	int	*stat_loc	종료된 프로세스 정보
	** @param	int	options		프로세스의 종료 상태 체크 시 사용
	** @return	pid_t			process ID of the child process
	*/
	pid_t	waitpid(pid_t pid, int *stat_loc, int options);
	```
	rusage 값이 0인 wait4()와 동일

<br>

- `wait3`
	```c
	/*
	** @header	<sys/wait.h>
	** @param	pid_t	pid		기다릴 자식 프로세스 pid
	** @param	int	*stat_loc	종료된 프로세스 정보
	** @param	int	options		프로세스의 종료 상태 체크 시 사용
	** @return	pid_t			process ID of the child process
	*/
	pid_t	wait3(pid_t pid, int *stat_loc, int options);
	```	
	pid 값이 -1인 wait4()와 동일

<br>

- `signal`
	```c
	/*
	** @header	<signal.h>
	** @param	int	sig		시그널 번호
	** @param	void	(*func)(int)	시그널 처리 핸들러
	** @return	void	*()(int)	이전에 설정된 시그널 핸들러
	*/
	void	(*signal(int sig, void (*func)(int));)(int);
	or
	typedef void (*sig_t) (int);

	sig_t	signal(int sig, sig_t func);
	```	
	시그널 처리 방법 설정

<br>

- `getcwd`
	```c
	/*
	** @header	<unistd.h>
	** @param	char	*buf	작업 디렉토리 절대 경로 저장
	** @param	size_t	size	buf 사이즈(byte)
	** @return	char*		buf
	*/
	char	*getcwd(char *buf, size_t size);
	```	
	현재 작업중인 디렉토리의 절대경로를 buf에 복사한다.

	buf가 널이면, 필요한 만큼 할당하여 사용하고, size는 무시됨

	리턴값:
	
	- buf
	- 실패: -1, errno 설정

<br>

- `chdir`
	```c
	/*
	** @header	<unistd.h>
	** @param	const char	*path	디렉토리 경로
	*/
	int	chdir(const char *path);
	```
	현재 작업 디렉토리를 path로 변경(/로 시작하면 안됨)

	리턴값:
	
	- 성공 0
	- 실패 -1, errno 설정

<br>

- `stat`
	```c
	/*
	** @header	<sys/stat.h>
	** @param	const char	*path	파일 경로
	** @param	struct stat	*buf	파일 정보 저장
	*/
	int	stat(const char *restrict path, struct stat *restrict buf);
	```
	파일의 정보를 얻음

	읽기, 쓰기 or 실행 권한 없어도 가능

	`lstat`은 stat()과 동일하지만, 경로 이름이 심볼릭 링크인 경우 참조하는 파일이 아닌 링크 자체에 대한 정보 반환

	`fstat`은 stat()과 동일하지만, path가 상대경로를 지정하는 경우는 현재 작업 디렉토리가 아닌 fd와 연결된 디렉토리에서 파일 검색

	- `int	fstat(int fd, struct stat *buf);`

	리턴값: 성공시 0, 실패시 -1(with errno)

<br>

- `unlink`
	```c
	/*
	** @header	<unistd.h>
	** @param	const char	*path	삭제하려는 링크 이름
	*/
	int	unlink(const char *path);
	```
	path의 링크를 제거하고 링크가 참조한 파일의 링크 수를 줄임

	파일의 링크 수가 0이 되고, 파일을 연 프로세스가 없으면 파일과 관련된 모든 리소스 회수

	마지막 링크가 지워질 때 프로세스가 파일을 열면, 링크는 제거되지만 파일에 대한 모든 참조가 닫힐 때까지 파일 제거 지연

	리턴값: 성공시 0, 실패시 -1(with errno)

<br>

- `execve`
	```c
	/*
	** @header	<unistd.h>
	** @param	const char	*path	파일 경로
	** @param	char *const	argv[]	인수 목록
	** @param	char *const	envp[]	인수가 아닌 정보
	*/
	int	execve(const char *path, char *const argv[], char *const envp[]);
	```
	호출 프로세스를 새로운 프로세스로 변환
	
	새 프로세스는 path로 지정된 일반 파일로 구성

	The argument **argv** is a pointer to a null-terminated array of character pointers to null-terminated character strings. At least one
     argument must be present in the array; by custom, the first element should be the **name of the executed program** (for example, the last component of path).

     The argument **envp** is also a pointer to a null-terminated array of character pointers to null-terminated strings. A pointer to this array is normally stored in the global variable environ. These strings pass information to the new process that is not directly an argument to the command.

	실패한 경우에만 -1 리턴
