# Minishell

> 간단한 쉘(나만의 작은 zsh, bash) 제작

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
