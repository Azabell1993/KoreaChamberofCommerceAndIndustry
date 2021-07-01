#include "program.h"

void rotate(){
  switch(piece){
    case 'I':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]]=='='
         || center[fixedpoint[0]-1][fixedpoint[1]]=='['
         || center[fixedpoint[0]-2][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]-2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-4,
             TetrominoI[0]+fixedpoint[1]-4, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='i';
      return;
    case 'i':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='<'
         || center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]][fixedpoint[1]-4]=='['
         || center[fixedpoint[0]][fixedpoint[1]-4]=='!') return;
      memcpy(center[fixedpoint[0]-2]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-4,
             TetrominoI[1]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[1]+12, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      piece ='I';
      return;
    case 'J':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]]=='='
         || center[fixedpoint[0]-1][fixedpoint[1]]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='K';
      return;
    case 'K':
      if(center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]][fixedpoint[1]-2]=='<'
         || center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      piece ='j';
      return;
    case 'j':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoO[0]+10, 6);
      piece ='k';
      return;
    case 'k':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!'
         || center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]-2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoT[0]+10, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 4);
      piece ='J';
      return;
    case 'L':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]]=='='
         || center[fixedpoint[0]-1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoT[0]+10, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoO[0]+10, 4);
      piece ='M';
      return;
    case 'M':
      if(center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]][fixedpoint[1]-2]=='<'
         || center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoT[0]+10, 6);
      piece ='l';
      return;
    case 'l':
      if(center[fixedpoint[0]-1][fixedpoint[1]]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoO[0]+10, 4);
      piece ='m';
      return;
    case 'm':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!'
         || center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]-1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoT[0]+6, 6);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      piece ='L';
      return;
    case 'S':
      if(center[fixedpoint[0]-1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoT[0]+6, 6);
      piece = 's';
      return;
    case 's':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='<'
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoO[0]+10, 6);
      piece = 'S';
      return;
    case 'T':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]]=='=') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='U';
      return;
    case 'U':
      if(center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]][fixedpoint[1]-2]=='<') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='t';
      return;
    case 't':
      if(center[fixedpoint[0]-1][fixedpoint[1]]=='[') return;
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='u';
      return;
    case 'u':
      if(center[fixedpoint[0]][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='!') return;
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece ='T';
      return;
    case 'Z':
      if(center[fixedpoint[0]-1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoO[0]+8, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      piece = 'z';
      return;
    case 'z':
      if(center[fixedpoint[0]][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]][fixedpoint[1]-2]=='<'
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='[') return;
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoO[0]+10, 6);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      piece = 'Z';
      return;
  }
}

