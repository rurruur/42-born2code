# Fdf

## Objectives
이 프로젝트에서는 그래픽스 프로그래밍의 기본기, 특히 그중에서 공간에 점을 위치시키고, 이를 세그먼트와 결합하고, 렌더링한 장면을 특정 뷰포인트에서 관찰하는 방법을 알아본다.

또한 그래픽스 라이브러리인 miniLibX에 대해서도 살펴본다. 우리가 자체적으로 구현한 이 라이브러리는 윈도우를 열고, 픽셀을 배치하고, 윈도우창과 연결된 이벤트(키보드와 마우스)를 처리하는 데에 필요한 최소한의 기능을 담고 있다. 이 프로젝트에서 이벤트 프로그래밍을 접할 수 있다.

## Common Instructions

• This project will be corrected by humans only. So, feel free to organize and name
your files as you wish, but within the constraints listed here.

• The executable file must be named fdf.

• You must submit a Makefile.

• You cannot use global variables.

• You must use the miniLibX. Either in the version 
that is available on the system,
or from its sources. If you choose to work with the sources, you will need to apply
the same rules for your libft as those written above.

• For your mandatory part, you are allowed to use the following functions:
- open, read, write, close
- malloc, free
- perror, strerror
- exit
- All the functions defined in the math library (-lm and man 3 math)
- All the functions defined in the miniLibX library.

• You are allowed to use other functions to complete the bonus part as long as their
use is justified during your evaluation. Be smart!

• You can ask your questions on the forum, Slack, etc.

## Mandatory part
fdf 프로젝트는 세그먼트의 다양한 점들(x, y, z)을 연결하는 굴곡진 지형을 표현하는 간단한 그래픽 "와이어프레임" 모델을 만드는 프로젝트이다. 표현할 지형의 좌표와 그 정보는 파일로 저장되어 프로그램의 매개변수로 전달된다.

예시:
<img width="736" alt="Screen Shot 2022-04-11 at 11 11 46 PM" src="https://user-images.githubusercontent.com/94118504/162758550-3aa98779-6cc0-4514-b76d-a8cd8059ea35.png">

각 숫자는 공간 상의 점에 대응합니다.

- 가로 인덱스는 가로축 위치에 대응합니다.

- 세로 인덱스는 세로축 위치에 대응합니다.

- 숫자값은 좌표상 점의 높낮이에 대응합니다.


fdf 실행 예시:

`$>./fdf 42.fdf`

<img width="650" alt="Screen Shot 2022-04-11 at 11 16 34 PM" src="https://user-images.githubusercontent.com/94118504/162759258-4512249c-1c84-473f-96cc-b9bed76ffef4.png">

libft를 적절하게 사용하는 것을 잊지 마세요! get_next_line, ft_split, ft_getnbr 을 사용하면 파일에서 데이터를 간단하고 빠르게 읽어올 수 있습니다.

Remember that the goal of this project is not to parse maps! This doesn't mean that your program can crash when runned... it means that the map contained in the file will be properly formatted.

그래픽 표현을 구현할 때 아래를 고려해보세요.

• You can choose the type of projection: parallel, iso, conic.

• 투영 유형을 선택할 수 있습니다 : 평형투영법, 등축투영법, 원뿔투영법.

• You must be able to quit the program by pressing ’esc’.

• esc를 누르면 프로그램이 종료되어야 합니다.

• The use of images from minilibX is strongly encouraged.

• minilibX 의 images 를 사용하는 것을 강력하게 권장합니다.

• Find attached a binary called fdf as well as the example 42.fdf inside fdf.zip).

• 이 서브젝트의 42.fdf를 구현한, 첨부파일 fdf.zip내에 바이너리 파일인 fdf 파일을 찾아보세요.

`man mlx`

## Bonus part
• 높낮이에 따라 상자에 저마다 다른 색상을 채우기. (예 : 아래에는 녹색, 그 다음에는 갈색, 위는 흰색)

• 매개변수로 색상 스펙트럼을 지정하기.

• 숨겨진 표면을 올바르게 다루기.

• 투영 유형 변경하기.