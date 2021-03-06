**How to Run This build**  
```c
$ compile.sh
```  

**Shell Script File**  
```c
#!/bin/bash

#####################################################################
#Script Name	: compile.sh                                        #
#Description	: 2021.06.09                                        #
#Args			:                                                   #
#Author			:                                                   #
#Email			: jeewoo19930315@gmail.com                          #
#Blog			: azabell.github.io                                 #
#####################################################################

catch_name()
{
	echo -n "USER NAME : "
	whoami > whoami.txt
	cat whoami.txt
	cat whoami.txt >> whoami_saved.txt
}

run_main()
{
	echo "-------------------------------------------------------------\n"
	echo "만나서 반갑습니다."
	echo "-------------------------------------------------------------\n"
	echo "make 명령어를 자동실행합니다. -------------------------------\n"
	echo "-------------------------------------------------------------\n"
	make
	echo " ------------------------------------------------------------\n"
	echo " gcc -o main main.c error_functions.o를 자동실행----\n"
	echo " ------------------------------------------------------------\n"
	gcc -o main main.c error_functions.o
	echo " ------------------------------------------------------------\n"
	echo " -------------이제 정보를 기입하세요.------------------------\n"
	echo " ------------------------------------------------------------\n"

	./main


	echo "-------------------------------------------------------------\n"
	echo "------------------저장된 정보를 보여드립니다.----------------\n"
	cat whoami_saved.txt
	echo "-------------------------------------------------------------\n"
	echo "-------------text file입니다.--------------------------------\n"
	cat notepad.txt
	echo "-------------------------------------------------------------\n"
	echo "------------------저장된 정보를 로그에 저장시킵니다.---------\n"
	cat notepad.txt >> Log.txt
	echo "-------------------------------------------------------------\n"
	echo "------------------Log file 정보를 열람합니다.----------------\n"
	cat Log.txt

	echo "=============================================================\n"
	echo "makef file로 생성된 잔여 파일들을 자동삭제합니다. \n"
	echo "=============================================================\n"

	make clean
}

catch_name
run_main
```  
직접 만들어둔 리눅스 **API**(C언어 프로그래밍 파일)을 이용하여서 파일 스트림 함수에 errExit()이 실행이 가능하도록 Makefile을 직접 구현하였습니다.  
그리고 쉘 스크립트 자동화로 프로그램을 실행하고 컴퓨터 사용자의 이름과 성적까지 로그파일로 저장이 되게 프로그래밍을 하였습니다.  
  
단독 C언어 프로그램 실행만으로는 저장이 한 번만 되도록 하였습니다.  

아래는 리눅스 자동화 쉘 스크립트로 만들어진 파일과 구현 모습입니다.  
  
![Screenshot from 2021-06-09 21-00-43](https://user-images.githubusercontent.com/75885992/121351705-081f1000-c967-11eb-8b3b-7fab32891524.png)
![Screenshot from 2021-06-09 21-01-00](https://user-images.githubusercontent.com/75885992/121351710-09503d00-c967-11eb-9ccb-ecae089f3086.png)

![Screenshot from 2021-06-09 21-09-49](https://user-images.githubusercontent.com/75885992/121351814-21c05780-c967-11eb-9af8-9879f2997328.png)

**반복하여서 build를 하고 정보를 추가로 입력한다면 Log파일에 내역이 추가가 됩니다.**  

![Screenshot from 2021-06-09 21-13-50](https://user-images.githubusercontent.com/75885992/121352402-c9d62080-c967-11eb-97f3-50c14dde47d9.png)
![Screenshot from 2021-06-09 21-14-02](https://user-images.githubusercontent.com/75885992/121352404-cb074d80-c967-11eb-9c36-0e1b5a7d6311.png)

