# so_long
_요약: 이 프로젝트는 아주 간단한 2D 게임을 만들어 볼 겁니다. 텍스쳐, 스프라이트, 기본적인 게임플레이 요소들을 다뤄볼 있도록 설계되어 있어요._

- [Introcution](#introduction)
- [Mandatory part](#mandatory-part)
	- [허용 함수](#허용-함수)
	- [규칙](#규칙)
	- ["so_long" 프로그램](#so_long-프로그램)
- [구현](#구현)
	- [사용한-minilibx-라이브러리-함수](#사용한-minilibx-라이브러리-함수)
- [플레이 방법](#플레이-방법)

## Introduction
이번 프로젝트의 목표는 이전에 진행했던 이러한 프로젝트와 비슷합니다 : 엄격함 (Rigor), C언어 사용하기, 기본적인 알고리즘 사용하기, 정보 검색 등

그래픽 디자인 프로젝트로서, so long은 창, 색상, 이벤트, 모양 채우기 등과 같은 분야에서 여러분의 능력 향상을 도울 것입니다.

## Mandatory part

### 허용 함수
- open
- close
- read
- write
- malloc
- free
- perror
- strerror
- exit
- MinilibX 라이브러리 내의 모든 함수들
- libft 사용 가능

### 규칙
여러분은 돌고래가 물고기 몇 마리를 잡아먹은 뒤 지구를 탈출하는 작은 2D 게임을 만들어야 합니다. 굳이 돌고래나 물고기가 될 필요는 없습니다. 주인공이 특정 수집품을 모은 뒤 공간을 떠나는 방식이면 됩니다.

제약은 다음과 같습니다:

- 반드시 miniLibX를 사용해야 합니다. (운영체제에서 이용 가능한 라이브러리와 과제에서 제공되는 소스 중 하나를 사용하셔야 합니다) 만약 제공받은 소스를 이용해 작업하기로 했다면, Libft의 공통 지침 (Common Instructions) 과 같은 규칙을 따라야 합니다.
- 작업 창 관리는 부드럽게 동작하여야 합니다. (창 최소화, 다른 창으로 전환 등의 동작)
- 예시로는 물고기를 잡아먹는 돌고래를 들었지만, 주제는 어떤 것으로 정하셔도 상관 없습니다.
- 지도는 **세 가지 요소**들로 구성되어 있습니다: 벽, 수집품, 그리고 빈 공간
- 플레이어의 목표는 모든 수집품을 모으고 최소한의 움직임으로 맵을 탈출하는 것입니다.
- **각 움직임마다 현재까지 움직인 횟수가 쉘에 출력**되어야 합니다.
- 플레이어는 다음 방향으로 움직여야 합니다: 상하좌우
- 게임은 2D 시점으로 제작하여야 합니다. (탑뷰 또는 프로필)
- 실시간으로 진행되는 게임일 필요는 없습니다.
- 플레이어는 벽을 뚫고 지나갈 수 없습니다.
- 프로그램은 다음과 같은 룰을 따르며 이미지를 화면에 표시하여야 합니다
	- `W, A, S, D` 키를 이용하여 주인공을 조작합니다.
	- `ESC`는 창을 닫고 게임을 정상적으로 종료합니다.
	- `창 좌상단의 빨간 버튼` (mac) 또는 우상단의 빨간 X (windows) 를 누르면 창을 닫고 게임을 정상적으로 종료합니다.
	- minilibX의 images를 사용하는 것을 강력히 추천합니다!

### "so_long" 프로그램
여러분의 프로그램은 .ber 확장자의 파일을 첫 번째 인자로 받아야 합니다.
- 지도는 단 5개의 가능한 문자열로만 구성되어야 합니다: 0은 빈 공간, 1은 벽, C는 수집품, E는 맵의 출구, P는 주인공의 시작지점입니다.
- 다음은 간단한 지도의 예시입니다:
	```
	1111111111111
	10010000000C1
	1000011111001
	1P0011E000001
	1111111111111
	```
- 지도는 벽으로 둘러쌓여 있어야 합니다. 그렇지 않으면 에러를 반환해야 합니다.
- 지도는 최소한 하나의 출구, 하나의 물고기 (수집품), 하나의 시작 지점을 포함해야 합니다.
- 지도에서 출구로 가는 길의 유무 판단 (검증)은 굳이 해주지 않으셔도 됩니다.
- 지도는 반드시 **직사각형** 모양이어야 합니다.
- 이하의 규칙을 준수한 모든 종류의 지도를 파싱할 수 있어야 합니다.
- 지도 파일에서 어떠한 허점이 발견된다면, 프로그램은 "Error\n" 과 여러분이 직접 정한 에러 메시지를 출력한 후 제대로 종료되어야 합니다.

## 구현

### 사용한 MinilibX 라이브러리 함수
>details: [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html)

- `mlx_init`
	```c
	/*
	** @return	void*	the mlx instance
	*/
	void	*mlx_init();
	```
	Initializes the MLX library. **Must be called before ANY other function**. Will return NULL if initialization failed.

<br>

- `mlx_new_window`
	```c
	/*
	** @param	void	*mlx_ptr	the mlx instance pointer;
	** @param	int		size_x		the width of the window;
	** @param	int		size_y		the height of the window;
	** @param	char	*title		the title of the window;
	** @return	void*				the window instance pointer.
	*/
	void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
	```
	Creates a new window instance. It will return a window instance pointer. This should be saved for future reference.

<br>

- `mlx_hook`
	```c
	/*
	** @param	void	*win_ptr	the window instance pointer;
	** @param	int		x_event		the width of the window;
	** @param	int		x_mask		the height of the window;
	** @param	int		(*f)()		the handler function:
	** @param	void	*param		the parameter to give on each event;
	*/
	void	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
	```
	Register to any of the aforementioned events with the call of a simple hook registration function.
	- Prototype of event functions

		| Event | Code | Prototype |
		|:--:|:--:|:--:|
		| ON_KEYDOWN | 2 | `int (*f)(int keycode, void *param)` |
		| ON_KEYUP* | 3 | `int (*f)(int keycode, void *param)` |
		| ON_MOUSEDOWN* | 4 | `int (*f)(int button, int x, int y, void *param)` |
		| ON_MOUSEUP | 5 | `int (*f)(int button, int x, int y, void *param)` |
		| ON_MOUSEMOVE | 6 | `int (*f)(int x, int y, void *param)` |
		| ON_EXPOSE* | 12 | `int (*f)(void *param)` |
		| ON_DESTROY | 17 | `int (*f)(void *param)` |
		
		*_mlx_hook alias 존재_
	- Hooking alias
		- `mlx_expose_hook` function is an alias of mlx_hook on expose event (12).
		- `mlx_key_hook` function is an alias of mlx_hook on key up event (3).
		- `mlx_mouse_hook` function is an alias of mlx_hook on mouse down event (4).

<br>

- `mlx_xpm_file_to_image`
	```c
	/*
	** @param	void *mlx_ptr	the mlx instance;
	** @param	char *filename	the file to load;
	** @param	int  *width		a pointer to where the width ought to be written;
	** @param	int  *height	a pointer to where the height ought to be written;
	** @return	void*			the image instance, and NULL in case of error.
	*/
	void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	```
	Converts an xpm file to a new image instance.

<br>

- `mlx_put_image_to_window`
	```c
	/*
	** @param	void *mlx_ptr	the mlx instance;
	** @param	void *win_ptr	the window instance;
	** @param	int  x			the x location of where the image ought to be placed;
	** @param	int  y			the y location of where the image ought to be placed;
	** @return	int				has no return value (bc).
	*/
	int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
	```
	Puts an image to the given window instance at location (x,y). This is the recommended way to write large amounts of graphical data in one go. Do mind that when changing the memory of the locations, it will be displayed directly on the window.

<br>

- `mlx_loop`
	```c
	/*
	** @param	void *mlx_ptr	the mlx instance;
	** @return	int				has no return value (bc).
	*/
	int		mlx_loop(void *mlx_ptr);
	```
	Loop over the given MLX pointer. Each hook that was registered prior to this will be called accordingly by order of registration.

## 플레이 방법

```
$ git clone https://github.com/rurruur/42-born2code.git
$ cd so_long
$ make
$ 
```

> 사과를 모두 모아서 출구로 나가봅시다~

| Key | Description |
|:--:|:--:|
| `W` | 위쪽 이동 |
| `A` | 왼쪽 이동 |
| `S` | 아래쪽 이동 |
| `D` | 오른쪽 이동 |
| `ESC` | 종료 |