#include "program.h"

void moveright(){
  switch(piece){
    case 'I':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-4,
             TetrominoI[0]+fixedpoint[1]-4, 2);
      fixedpoint[1]+=2;
      return;
    case 'i':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='!') return;
      for(int i=-2; i<2; ++i){
        if(center[fixedpoint[0]+i][fixedpoint[1]+2]=='[') return;
      }
      for(int i=-2; i<2; ++i){
        memcpy(center[fixedpoint[0]+i]+fixedpoint[1],
               TetrominoT[0]+8, 4);
      }
      fixedpoint[1]+=2;
      return;
    case 'J':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      fixedpoint[1]+=2;
      return;
    case 'K':
      if(center[fixedpoint[0]-1][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'j':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'k':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1]+2, 2);
      fixedpoint[1]+=2;
      return;
    case 'L':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+4]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1]+4, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      fixedpoint[1]+=2;
      return;
    case 'M':
      if(center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='[') return;
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'l':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]+1][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'm':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1]+2, 2);
      fixedpoint[1]+=2;
      return;
    case 'O':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+4]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+4,
             center[fixedpoint[0]-1]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      fixedpoint[1]+=2;
      return;
    case 'S':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             center[fixedpoint[0]+1]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      fixedpoint[1]+=2;
      return;
    case 's':
      if(center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'T':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      fixedpoint[1]+=2;
      return;
    case 'U':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 't':
      if(center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+4,
             TetrominoT[0]+10, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'u':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!'
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
    case 'Z':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+4]=='!') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+4,
             center[fixedpoint[0]+1]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      fixedpoint[1]+=2;
      return;
    case 'z':
      if(center[fixedpoint[0]-1][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]][fixedpoint[1]+4]=='!'
         || center[fixedpoint[0]][fixedpoint[1]+4]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      fixedpoint[1]+=2;
      return;
  }
}

