//이 라이브러리는 C++ 언어로 작성된 라즈베이파이용 GPIO 및 다양한 인터페이스 제어가 가능한 라이브러리입니다.
#include <wiringPi.h>

//모든 GPIO를 사용하기 위한 필수 헤더입니다.
#include <softPwm.h>


//콘솔키를 입력받아 움직이는 차를 코딩해야하는데 리눅스에서는 <conio.h>가 없으므로 먼저 작성해야할 라이브러리가 있습니다.
//헤더이름은 본인이 원하는데로 아무거나 지정하여서 따로 저장을 해줍니다.
#include "linux_kbhit.h"
//그렇게 하여서 conio.h를 대신할 헤더를 불러와줬습니다.

int Left_motor_go = 28;       //왼쪽 앞으로 가는 바퀴는 포트 28번 (WiringPI port number)
int Left_motor_back = 29;     //왼쪽 뒤로 가는 바퀴는 포트 29번

int Right_motor_go = 24;      //오른쪽 앞으로 가는 바퀴는 포트 24번
int Right_motor_back = 25;    //오른쪽 뒤로 가는 바퀴는 포트 25번

int Left_motor_pwm = 27;      //모터의 속도를 제어하기 위한 것 입니다. 27번 포트.
int Right_motor_pwm = 23;     //동일합니다. 오른쪽으로 방향만 다르고 23번 포트.

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

//하기 로직도 동일합니다.

void brake(int time)
{
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);

  delay(time * 100);
}

void left(int time)
{
  
  digitalWrite(Left_motor_go, LOW);     
  digitalWrite(Left_motor_back, LOW);  
  softPwmWrite(Left_motor_pwm, 0);      

  
  digitalWrite(Right_motor_go, HIGH); 
  digitalWrite(Right_motor_back, LOW); 
  softPwmWrite(Right_motor_pwm, 150); 

  delay(time * 100);
}

void right(int time)
{
  
  digitalWrite(Left_motor_go, HIGH); 
  digitalWrite(Left_motor_back, LOW);   
  softPwmWrite(Left_motor_pwm, 150);    

  
  digitalWrite(Right_motor_go, LOW);    
  digitalWrite(Right_motor_back, LOW);  
  softPwmWrite(Right_motor_pwm, 0);     

  delay(time * 100);
}

void spin_left(int time)
{
  
  digitalWrite(Left_motor_go, LOW);    
  digitalWrite(Left_motor_back, HIGH); 
  softPwmWrite(Left_motor_pwm, 150);

  
  digitalWrite(Right_motor_go, HIGH);  
  digitalWrite(Right_motor_back, LOW); 
  softPwmWrite(Right_motor_pwm, 150);

  delay(time * 100);
}

void spin_right(int time)
{
  
  digitalWrite(Left_motor_go, HIGH);    
  digitalWrite(Left_motor_back, LOW);   
  softPwmWrite(Left_motor_pwm, 150);

  
  digitalWrite(Right_motor_go, LOW);    
  digitalWrite(Right_motor_back, HIGH); 
  softPwmWrite(Right_motor_pwm, 150);

  delay(time * 100);
}

void back(int time)
{
  
  digitalWrite(Left_motor_go, LOW);    
  digitalWrite(Left_motor_back, HIGH); 
  softPwmWrite(Left_motor_pwm, 150);

  
  digitalWrite(Right_motor_go, LOW);    
  digitalWrite(Right_motor_back, HIGH); 
  softPwmWrite(Right_motor_pwm, 150);

  delay(time * 100);
}

void main()
{

   wiringPiSetup();
  
  //특정한 핀을 입력으로 쓸지 출력으로 쓸지를 설정해주는 함수입니다.
  //OUTPUT의 경우 출력모드로 설정하며 INPUT의 경우 입력 모드로 설정하게 됩니다.
  //OUTPUT의 경우 LED를 켜거나 모터를 구동을 할 수 있으며, INPUT의 경우 센서값을 읽어오는데 사용할 수 있습니다.
  //INPUT_PULLUP은 내부의 풀업저항을 사용하는 입력모드입니다. 풀업저항 : https://blog.naver.com/jamduino/220820935325
  pinMode(Left_motor_go, OUTPUT);
  pinMode(Left_motor_back, OUTPUT);
  pinMode(Right_motor_go, OUTPUT);
  pinMode(Right_motor_back, OUTPUT);
  

  //softPwmCreate(핀번호, 시작펄스값(0 or 1), 주기(1~1024*0.1ms))
  //주기를 200으로 하면 20ms의 주기를 가진다.
  softPwmCreate(Left_motor_pwm,0,255); 
  softPwmCreate(Right_motor_pwm,0,255);
 
	//메인함수에서 콘솔키를 조작할 함수를 불러와주는데 이를 연속으로 입력받아야한다.그렇기 때문에 while문의 (1)로 무한반복하도록 했습니다.
	while (1)
	{	
		processkey();
	}	
	return;
}

//조작에 있어서 가장 중요한 함수입니다. 우선 함수의 이름은 알아보기 쉽게 processkey()라고 선언했습니다!
int		processkey()
{
	//정수로 선언을 하여도 좋습니다.
	int key;
	
	//원래는 _getch();로 하여서 받아야하지만 이건 사용환경이 리눅스입니다. 그렇기때문에 따로 기능을 구현한 라이브러리의 이름을 가져다가 씁니다.
	//그러면 key라는 값에 입력을 받겠다는 의미입니다.
	key = linux_kbhit();
	if (key == 0 | key == 224) key = linux_kbhit();
	
	//if문은 번거롭습니다. 그렇기 때문에 switch문으로 구현을 해줬습니다. wsad키는 게임에서 조작키에 많이 쓰이는 것이기 때문에 따로 설명이 필요 없어보입니다.
	switch (key)
	{
         case '0':
             delay(2000);
             break;
         case 'w' | 'W':
             run(10);
             break;
         case 's' | 'S':
             back(10);
             break;
         case 'a' | 'A':
             left(10);
             break;
         case 'd' | 'D':
             right(10);
             break;
         case '1':
             spin_left(10);
             break;
         case '3':
             spin_right(10);
             break;
	 //brake도 덤으로!
         case 'q' | 'Q':
             brake(5);
             break;
     }
	//그리고 메인함수로 호출시켜야하기 때문에 key값을 반환시켜줍니다!
	return (key); 
}
