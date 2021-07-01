#include "program.h"

void show_next(){
  switch(next){
    case 0:
      memcpy(left[11]+WIDTH-10, TetrominoI[1]+8, 8);
      return;
    case 1:
      memcpy(left[10]+WIDTH-8, TetrominoJ[0]+8, 2);
      memcpy(left[11]+WIDTH-8, TetrominoJ[1]+8, 6);
      return;
    case 2:
      memcpy(left[10]+WIDTH-4, TetrominoL[0]+12, 2);
      memcpy(left[11]+WIDTH-8, TetrominoL[1]+8, 6);
      return;
    case 3:
      memcpy(left[10]+WIDTH-6, TetrominoO[0]+10, 4);
      memcpy(left[11]+WIDTH-6, TetrominoO[1]+10, 4);
      return;
    case 4:
      memcpy(left[10]+WIDTH-6, TetrominoS[0]+10, 4);
      memcpy(left[11]+WIDTH-8, TetrominoS[1]+8, 4);
      return;
    case 5:
      memcpy(left[10]+WIDTH-6, TetrominoT[0]+10, 2);
      memcpy(left[11]+WIDTH-8, TetrominoT[1]+8, 6);
      return;
    case 6:
      memcpy(left[10]+WIDTH-8, TetrominoZ[0]+8, 4);
      memcpy(left[11]+WIDTH-6, TetrominoZ[1]+10, 4);
      return;
  }
}

void updatescrn(){
  clear();
  printw("\n");
  for(int i=2; i<HEIGHT; ++i){
    if(shownext) show_next();
    printw("%s", left[i]);
    printw("%s", center[i]);
    if(showtext) printw("%s", right[i]);
    printw("\n");
  }
  refresh();
  if(shownext){
    memcpy(left[10]+WIDTH-10, "        ", 8);
    memcpy(left[11]+WIDTH-10, "        ", 8);
  }
}

void updatescore(){
  char *tmp=malloc(sizeof *tmp * 15);
  sprintf(tmp, "%-14d", score);
  memcpy(left[7]+9, tmp, 14);
  free(tmp);
}

