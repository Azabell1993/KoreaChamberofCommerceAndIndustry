#include "program.h"

int movedown()
{
  switch(piece){
    case 'I':
      if(center[fixedpoint[0]+1][fixedpoint[1]-4]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<4; ++i){
        if(center[fixedpoint[0]+1][fixedpoint[1]-4+i*2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-4,
             center[fixedpoint[0]]+fixedpoint[1]-4, 8);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1]-4,
             TetrominoI[0]+fixedpoint[1]-4, 8);
      return 0;
    case 'i':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]++ -2]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      return 0;
    case 'J':
      if(center[fixedpoint[0]+1][fixedpoint[1]-2]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<3; ++i){
        if(center[fixedpoint[0]+1][fixedpoint[1]-2+i*2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1]-2, 6);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 4);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      return 0;
    case 'K':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]][fixedpoint[1]+2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 4);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1]+2,
             TetrominoT[0]+10, 2);
      return 0;
    case 'j':
      if(center[fixedpoint[0]+2][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]+2]=='='
         || center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 6);
      memcpy(center[fixedpoint[0]++ +1]+fixedpoint[1]-2,
             TetrominoO[0]+10, 4);
      return 0;
    case 'k':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+2][fixedpoint[1]-2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1]-2,
             TetrominoO[0]+10, 4);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]++ +1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      return 0;
    case 'L':
      if(center[fixedpoint[0]+1][fixedpoint[1]-2]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<3; ++i){
        if(center[fixedpoint[0]+1][fixedpoint[1]-2+i*2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1]-2, 6);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 4);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      return 0;
    case 'M':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+2][fixedpoint[1]+2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             TetrominoO[0]+10, 4);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]++ +1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      return 0;
    case 'l':
      if(center[fixedpoint[0]+2][fixedpoint[1]-2]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]-2]=='='
         || center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 6);
      memcpy(center[fixedpoint[0]++ +1]+fixedpoint[1],
             TetrominoO[0]+10, 4);
      return 0;
    case 'm':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]][fixedpoint[1]-2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             TetrominoT[0]+10, 2);
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 4);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1]-2,
             TetrominoT[0]+10, 2);
      return 0;
    case 'O':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<2; ++i){
        if(center[fixedpoint[0]+1][fixedpoint[1]+i*2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 4);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 4);
      return 0;
    case 'S':
      if(center[fixedpoint[0]+2][fixedpoint[1]-2]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<2; ++i){
        if(center[fixedpoint[0]+2][fixedpoint[1]-2+i*2]=='['
           || center[fixedpoint[0]+1][fixedpoint[1]+2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1]-2,
             center[fixedpoint[0]+1]+fixedpoint[1]-2, 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoS[0]+8, 6);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 4);
      return 0;
    case 's':
      if(center[fixedpoint[0]+1][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+2][fixedpoint[1]+2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+10, 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoO[0]+10, 4);
      memcpy(center[fixedpoint[0]++ +2]+fixedpoint[1]+2,
             TetrominoT[0]+10, 2);
      return 0;
    case 'T':
      if(center[fixedpoint[0]+1][fixedpoint[1]-2]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<3; ++i){
        if(center[fixedpoint[0]+1][fixedpoint[1]-2+i*2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1]-2, 6);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoT[0]+8, 6);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      return 0;
    case 'U':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1]+2, 2);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      return 0;
    case 't':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]+2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 6);
      return 0;
    case 'u':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+1][fixedpoint[1]-2]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             center[fixedpoint[0]]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 2);
      memcpy(center[fixedpoint[0]++ -1]+fixedpoint[1],
             TetrominoI[0]+fixedpoint[1], 2);
      return 0;
    case 'Z':
      if(center[fixedpoint[0]+2][fixedpoint[1]]=='='){
        initpiece();
        return 0;
      }
      for(int i=0; i<2; ++i){
        if(center[fixedpoint[0]+2][fixedpoint[1]+i*2]=='['
           || center[fixedpoint[0]+1][fixedpoint[1]-2]=='['){
          if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
          initpiece();
          return 0;
        }
      }
      memcpy(center[fixedpoint[0]+2]+fixedpoint[1],
             center[fixedpoint[0]+1]+fixedpoint[1], 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1]-2,
             TetrominoZ[0]+8, 6);
      memcpy(center[fixedpoint[0]++]+fixedpoint[1]-2,
             TetrominoI[0]+fixedpoint[1]-2, 4);
      return 0;
    case 'z':
      if(center[fixedpoint[0]+1][fixedpoint[1]+2]=='['
         || center[fixedpoint[0]+2][fixedpoint[1]]=='='
         || center[fixedpoint[0]+2][fixedpoint[1]]=='['){
        if(fixedpoint[0]==1 || fixedpoint[0]==2) return gameover();
        initpiece();
        return 0;
      }
      memcpy(center[fixedpoint[0]-1]+fixedpoint[1]+2,
             TetrominoI[0]+fixedpoint[1], 2);
      memcpy(center[fixedpoint[0]]+fixedpoint[1],
             TetrominoT[0]+8, 4);
      memcpy(center[fixedpoint[0]+1]+fixedpoint[1],
             TetrominoO[0]+10, 4);
      memcpy(center[fixedpoint[0]++ +2]+fixedpoint[1],
             TetrominoT[0]+10, 2);
      return 0;
  }
  return 0;
}
