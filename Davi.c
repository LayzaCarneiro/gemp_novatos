#include <stdio.h>


char velha[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int nvelha[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
int registro[9];
int svd = 0;

void jogo(int ver, char vj){
    
      for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
          if(ver == nvelha[i][j] && vj == 'p'){
            velha[i][j] = 'X';
            printf("%3c", velha[i][j]);  
        } else if(ver == nvelha[i][j] && vj == 'i'){
            velha[i][j] = 'O';
            printf("%3c", velha[i][j]); 
        } else{
            printf("%3c", velha[i][j]); 
                  }
                }
            printf("\n");
            }
    }
    
int verificador(int pr){
    for(int i = 0; i < 9; i++){
        if(pr == registro[i]){
            registro[i] = 10;
            return 100;
        } 
    }
}

char vencedor(){
    if(velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X'){
        // velha pela linha 1
        return 'f';
    } else if(velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X'){
        // velha pela linha 2
        return 'f';
    } else if(velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X'){
        // velha pela linha 3
        return 'f';
    } else if(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X'){
       // velha pela coluna 1
       return 'f';
    } else if(velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X'){
       // velha pela coluna 2 
       return 'f';
    } else if(velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X'){
       // velha pela coluna 3 
       return 'f';
    } else if(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X'){
        // velha pela diagonal principal
        return 'f';
    } else if(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X'){
        // velha pela diagonal secundaria
        return 'f';
    }
    
    if(velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O'){
        // velha pela linha 1
        return 'f';
    } else if(velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O'){
        // velha pela linha 2
        return 'f';
    } else if(velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O'){
        // velha pela linha 3
        return 'f';
    } else if(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O'){
       // velha pela coluna 1
       return 'f';
    } else if(velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O'){
       // velha pela coluna 2 
       return 'f';
    } else if(velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O'){
       // velha pela coluna 3 
       return 'f';
    } else if(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O'){
        // velha pela diagonal principal
        return 'f';
    } else if(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O'){
        // velha pela diagonal secundaria
        return 'f';
    }
    
    return 'c';
} 




int main()
{
   int jogada[9], k = 0;
   char jog = 'c';
   int parabens, vel = 5;
   int psjoga, continua;
   
   for(int i = 0; i < 9; i++){
        registro[i] = i + 1 ;
    }
   
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%3c", velha[i][j]);
        }
        printf("\n");
    }
    
    
    while(jog == 'c'){
      if(k%2 == 0){
          do{
             printf("Vez do jogador X, escolha um numero para jogar:\n");
             scanf("%d", &jogada[k]);
             psjoga = verificador(jogada[k]);
                 if(psjoga == 100){
                   jogo(jogada[k], 'p');
                   continua = 0;
                   svd = svd + 1;
                 }else{
                   printf("Jogada invalida, a posição ja esta ocupada, ou não é um numero disponivel\n");
                   printf("Repita a jogada jogador X\n") ;
                   continua = 1;
          }
          }while(continua == 1);
          
      } 
      jog = vencedor();
      if(jog == 'f'){
          parabens = 1;
          break;
      }
      
      if(k%2 == 1){
             do{
                 printf("Vez do jogador O, escolha um numero para jogar:\n");
                 scanf("%d", &jogada[k]);
                 psjoga = verificador(jogada[k]);
                 if(psjoga == 100){
                   jogo(jogada[k], 'i');
                   continua = 0;
                   svd = svd + 1;
                 }  else{
                      printf("Jogada invalida, a posição ja esta ocupada, ou não é um numero disponivel\n");
                      printf("Repita a jogada jogador O\n") ;
                     continua = 1;
              }
             }while(continua == 1);
          }
      k++;
      jog = vencedor();
      if(jog == 'f' || svd == 9){
          if(svd == 9){
              vel = 10;
          }
          parabens = 2;
          break;
      }
    }
    if(vel == 10){
        printf("Deu velha -_-");
    }
    else if(parabens == 1){
        printf("Parabens jogador X, você venceu :D");
    }else{
        printf("Parabens jogador O, você venceu :D");
    }
    
}