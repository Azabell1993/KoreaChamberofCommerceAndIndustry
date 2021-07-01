
#include "program.h"

/* console function list header */
#include "move_down.h"
#include "move_right.h"
#include "move_left.h"
#include "move_rotate.h"
#include "Print_screen.h"

void toplist(){
  
  char *buffer=malloc(sizeof *buffer * TOPLSITMAXLINELENGTH);

  FILE *f;
  clear();

  if(!(f=fopen("toplist", "r")))
    printw("\n\n\n   The score must be greater than zero. "
           " to be added ;)\n");
  else{
    printw("\n");
    while(fgets(buffer, TOPLSITMAXLINELENGTH, f) != NULL)
      printw("                        %s", buffer);
    fclose(f);
  }
  
  refresh();
  free(buffer);

  getch();
}

void addscore(){
  if(!score) return;
  FILE *f;
  

  if(!(f=fopen("toplist", "r"))){
    if(!(f=fopen("toplist", "w")))
      exit(1);
    fprintf(f, "NAME          LVL SCORE        \n%-13s %2d  %-14d\n",
            name, level, score);
    fclose(f);
    return;
  }

  f=fopen("toplist", "r");

  int num;
  int added = 0;

  char *buffer=malloc(sizeof *buffer * TOPLSITMAXLINELENGTH);
  FILE *tmp;
  
  if(!(tmp=fopen("tmp", "a+")))
  	exit(1);

  int cntr;
  cntr = 21;  

  while(fgets(buffer, TOPLSITMAXLINELENGTH, f) != NULL && --cntr){
    num = strtol(buffer+18, NULL, 10);
    if(!added && score>num && num!=0){
      fprintf(tmp, "%-13s %2d  %-14d\n", name, level, score);
      score=0;
    }
    fputs(buffer, tmp);
  }

  if(cntr && score) fprintf(tmp, "%-13s %2d  %-14d\n", name, level, score);

  fclose(f);
  fclose(tmp);

  remove("toplist");
  rename("tmp", "toplist");

  free(buffer);
}

int gameover(){
  nodelay(stdscr, FALSE);
  if(!end) addscore();
  end = 1;

  memcpy(center[9], "     << GAME___OVER >>   \0"
                    "                         \0"
                    "                         \0"
					"                         \0"
                    "                         \0", WIDTH*5);
  

  memcpy(center[16], "    : QUIT    : RESET   \0"
                     "        : TOPLIST       \0", WIDTH*2);

  center[16][3] = toupper(EXT);
  center[16][13] = toupper(RSET);
  center[17][7] = toupper(TPLS);

  clear();

  printw("\n");

  for(int i=2; i<HEIGHT; ++i){
    if(i == 9 || i == 15 || i == 16) attron(COLOR_PAIR(2));
    else if( i == 18) attron(COLOR_PAIR(1));
    printw("%s", left[i]);
    if(i == 14 || i == 15) attron(COLOR_PAIR(1));
    printw("%s", center[i]);
    printw("%s\n", right[i]);
  }

  refresh();
  return 1;

}

void checkclr(){

  int cleard;
  cleard = 0;

  if(fixedpoint[0] > 2){
    for(int i=-2; i<2; ++i){
      if(!strncmp(center[fixedpoint[0]+i]+3,"][][][][][][][][][", 18)){
        ++cleard;
        for(int j=fixedpoint[0]+i; j>0; --j)
          memcpy(center[j]+2, center[j-1]+2, 20);
      }
    }

    if(cleard)
	{
      score += SCORE;
      score += dropped;
      dropped = 0;
      updatescore();
      updatescrn();
    }
  }
  clrlines += cleard;
}

void initpiece(){
  
  checkclr();

  int current;

  current = next;

  next = rand() % 7;


  switch(current){
    case 0:
      memcpy(center[0], TetrominoI[0], WIDTH*2);
      fixedpoint[0] = 1;
      fixedpoint[1] = 12;
      piece = 'I';
      return;
    case 1:
      memcpy(center[0], TetrominoJ[0], WIDTH*2);
      fixedpoint[0] = 1;
      fixedpoint[1] = 10;
      piece = 'J';
      return;
    case 2:
      memcpy(center[0], TetrominoL[0], WIDTH*2);
      fixedpoint[0] = 1;
      fixedpoint[1] = 10;
      piece = 'L';
      return;
    case 3:
      memcpy(center[0], TetrominoO[0], WIDTH*2);
      fixedpoint[0] = 1;
      fixedpoint[1] = 10;
      piece = 'O';
      return;
    case 4:
      memcpy(center[0], TetrominoS[0], WIDTH*2);
      fixedpoint[0] = 0;
      fixedpoint[1] = 10;
      piece = 'S';
      return;
    case 5:
      memcpy(center[0], TetrominoT[0], WIDTH*2);
      fixedpoint[0] = 1;
      fixedpoint[1] = 10;
      piece = 'T';
      return;
    case 6:
      memcpy(center[0], TetrominoZ[0], WIDTH*2);
      fixedpoint[0] = 0;
      fixedpoint[1] = 10;
      piece = 'Z';
      return;
  }
}

void init(){
  memcpy(left[0], "                        \0"
                  "                        \0"
                  "                        \0"
                  "  PLAYER:               \0"
                  "                        \0"
                  "  LEVEL:                \0"
                  "                        \0"
                  "  SCORE:                \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0"
                  "                        \0", (HEIGHT)*(WIDTH));
  memcpy(center[0], "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "<! . . . . . . . . . .!>\0"
                    "========================\0"
                    "MMMMMMMMMMMMMMMMMMMMMMMM\0", (HEIGHT)*(WIDTH));
  memcpy(right[0], "                        \0"
                   "                        \0"
                   "                        \0"
                   "    : LEFT     :RIGHT   \0"
                   "         :ROTATE        \0"
                   "    : DROP     :RESET   \0"
                   "    : SHOW/HIDE NEXT    \0"
                   "    : HIDE THIS TEXT    \0"
                   "    : EXIT              \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0"
                   "                        \0", (HEIGHT)*(WIDTH));
}

void updatelevel(){
  char *tmp=malloc(sizeof *tmp * 15);
  sprintf(tmp, "%-14d", level);
  memcpy(left[5]+9, tmp, 14);
  free(tmp);
}

void setkeybind()
{
    right[3][3]=toupper(MOVL);
    right[3][14]=toupper(MOVR);
    right[4][8]=toupper(ROTA);
    right[5][3]=toupper(DROP);
    right[5][14]=toupper(RSET);
    right[6][3]=toupper(SNXT);
    right[7][3]=toupper(STXT);
    right[8][3]=toupper(EXT);
}

int game()
{
  nodelay(stdscr, FALSE);

  init();

  setkeybind();

  clear();

  end = 0;
  score = 0;

  level = startlevel;

  clrlines = 0;

  memcpy(left[3]+10, name, strlen(name));
  printw("\n\n\n       Press any key to start\n");

  refresh();
  getch();
  updatescore();
  updatelevel();
  initpiece();
  updatescrn();
  nodelay(stdscr, TRUE);
  gettimeofday(&t1, NULL);


  while(!usleep(DELAY)){
    switch(getch()){
      case DROP:
        if(movedown()) continue;
        ++dropped * 1000;
        updatescrn();
        continue;

      case EXT:
        return 1;

      case RSET:
        return 0;

      case STXT:
        if(end) continue;
        showtext=!showtext;
        updatescrn();
        continue;

      case SNXT:
        if(end) continue;
        shownext=!shownext;
        updatescrn();
        continue;

      case MOVR:
        if(end) continue;
        moveright();
        updatescrn();
        continue;

      case MOVL:
        if(end) continue;
        moveleft();
        updatescrn();
        continue;

      case ROTA:
        if(end || fixedpoint[0]<2) continue;
        rotate();
        updatescrn();
        continue;

      case TPLS:
        if(!end) continue;
        toplist();

    }
    if(end){
      gameover();
      continue;
    }
    if(clrlines == LINESFORLVLUP){
      if(level<MAXLEVEL){
        ++level;
        updatelevel();
        clrlines = 0;
      }
    }
    gettimeofday(&t2, NULL);
    if((((t2.tv_sec-t1.tv_sec) * 1000) + ((t2.tv_usec-t1.tv_usec)/1000))
       > DROPINTERVAL){
      if(movedown()) continue;
      updatescrn();
      gettimeofday(&t1, NULL);
    }
  }//while


  return 1;
}


int main(void)
{
  name=malloc(sizeof *name * 14);
  srand(time(NULL));

  initscr();

  start_color();
  cbreak();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));

  do{
    clear();
	printw("\n\n\n       input the level : (1-%d): ", MAXLEVEL);
    refresh();
    scanw("%d ", &startlevel);
  }while(startlevel<1 || startlevel>MAXLEVEL);
 
  clear();
 
  printw("\n\n\n       input the your name : ");
  refresh();
  scanw("%13s ", name);

  clear();

  refresh();

  noecho();
  curs_set(0);
  next=rand()%7;
  
  while(!game());
  
  free(name);
  endwin();
  
  return (0);
}
