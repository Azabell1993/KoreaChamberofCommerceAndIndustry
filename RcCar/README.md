# parkjiwoo_rc_car_0411_finished

**Ubuntu Linux 기준입니다.**

**라즈베이파이4는 초소형 컴퓨터로 ioT라고 사물인터넷이 구현되는 현장에 쓰이는 컴퓨터입니다.**  
**앞으로는 구글이 인공지능을 라즈베리 파이에 심을 계획을 갖고 있다는 보도도 있습니다. 그만큼 작지만 아주 강력하고 빠른 기능의 컴퓨터입니다!**  
**이 코드는 RC-CAR를 방향키로 조작하여서 자신이 원하는 방향대로 움직여주도록 해줍니다.**  

(우분투 20.04 이후의 버전에서는 apt-get이 아니라 apt만 쓰 입니다.) --2021.07.14
    
깃 설치  
```$ sudo apt-get install git```  
```$ sudo apt-get install git-core```  
    
wringPi 라이브러리 설치  
```$ sudo git clone git://git.drogon.net/wiringPi```  
```$ cd wiringPi```    
```$ ./build```  
    
위의 과정을 거치면  
```$ sudo gpio readall```  
입력시 WiringPi핀 확인이 가능합니다.  
    
아두이노 && 라즈베리파이 시 사용되는 헤더  
```c
#include <wiringPi>  
#include <wiringPiSPI.h>
```

WiringPi 라이브러리를 받았다면 컴파일시 마지막에 -lwiringPi를 추가하여야 합니다.  

```$ sudo gcc hello.c -o hello -lwiringPi```  
```$ sudo g++ hello.c -o hello -lwiringPi```
    
필자는 리눅스 터미널 기반으로 작업을 하였기 때문에 IDE 컴파일러를 사용하시는 분들은 구글 검색을 이용하시면 될 것 같습니다. 
    
    구동 영상 : https://www.youtube.com/watch?v=EvCKlxC5PeI
    

전역 변수로 각 핀들의 번호를 선언해줍니다.  
```c
int Left_motor_go = 28;
```

  
리눅스에서는 conio.h활용이 안되기 때문에 라이브러리를 직접 만들어서 사용을 해야 합니다.
```c
#ifndef LINUX_KBHIT_H_
#define LINUX_KBHIT_H_

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int linux_kbhit(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;
}

#endif

```

  
선언한 함수의 이름이 linux_kbhit()이므로 _getch()대신에 사용을 합니다.
```c
int linux_kbhit(void)
```

```c
key = linux_kbhit();
```
    
내장 함수 사용으로 구현을 해줍니다. 이때, 150은 모터 출력을 조정하는 상수입니다.
```c
void run(int time)
{
  //왼쪽 모터 전진 
  //digitalWrite는 사용하는 핀들을 제어하는 함수입니다.
  //High 또는 Low값으로 디지털 핀에 쓰이는데 high의 경우 5v이고, Low의 경우 0v로 설정됩니다. 따라서 5v의 경우 활성화이고 0v의 경우 비활성화입니다.
  //페라메타 오른쪽에 HIGH 또는 LOW값을 적으며, 왼쪽의 인자에는 전역변수로 선언해둔 이름을 불러와줍니다. 
  digitalWrite(Left_motor_go, HIGH);  //on 
  digitalWrite(Left_motor_back, LOW); //off
  //softPwmWRite는 모터를 제어해주기위한 함수입니다.
  softPwmWrite(Left_motor_pwm, 150);   

  //오른쪽 모터 전진 
  digitalWrite(Right_motor_go, HIGH);  //on
  digitalWrite(Right_motor_back, LOW); //off
  softPwmWrite(Right_motor_pwm, 150);  

  //라즈베이파이에서의 타이머 사용입니다. 
  delay(time * 100);
}
```

