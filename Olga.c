#include <stdio.h>
#include <stdbool.h>

int velha[3][3];
int jogador = 1;
bool teste[3][3] = {{false,false,false},{false,false,false},{false,false,false}};

void tabela(int k, int x, int y){
    velha[x][y] = k;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(velha[i][j] == 0){
                printf("_ "); 
            }
            else if(velha[i][j] == 1){
                printf("O ");
            }
            else if(velha[i][j] == 2){
                printf("X "); 
            }
        }
        printf("\n");
    }
}


int jogada(){
    int x, y, k;
    
    printf("\nJOGADOR %d: Digite a linha desejada: ", jogador);
    scanf("%d", &x);
    printf("\nJOGADOR %d: Digite a coluna desejada: ", jogador);
    scanf("%d", &y); 
            
    while(x < 0 || x > 2 || y < 0 || y > 2 || teste[x][y]){
        printf("Posição inválida. Por favor, escolha outra.\n");
                
        printf("\nJOGADOR %d: Digite a linha desejada: ", jogador);
        scanf("%d", &x);
        printf("\nJOGADOR %d: Digite a coluna desejada: ", jogador);
        scanf("%d", &y); 
    }
    teste[x][y] = true;
            
            
    if(jogador == 1){
        k = 1;
        jogador++;
    }
    else{
        k = 2;
        jogador = 1;
    }
            
    tabela(k, x, y);
    return k;
}

bool vencedor(){
    for(int i = 0; i<3; i++){
        if(velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2] && velha[i][0] == velha[i][2] && velha[i][0] != 0){
            return true;
        }
        else if(velha[0][i] == velha[1][i] && velha[1][i] == velha[2][i] && velha[0][i] == velha[2][i] && velha[0][i] != 0){
            return true;
        }
    }
    if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] == velha[2][2] && velha[0][0] != 0){
        return true;
    }
    else if(velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0] && velha[0][2] == velha[2][0] && velha[0][2] != 0){
        return true; 
    }
    return false;
}

int main(){
    bool derrota = false, continua = true;
    int k, i, x, y;
    
    tabela(k, x, y);
    
    printf("\nJOGADOR 1 = O\tJOGADOR 2 = X\n");
    
    while(continua){
        for(i=0; i<9; i++){
            k = jogada();
        
            if(vencedor()){
                derrota = true;
                printf("\nParabéns JOGADOR %d, você venceu!\n\n", k);
                i = 9;
            }
        }
        if(!derrota){
            printf("Vocês perderam, deu velha!\n\n");
        }
        printf("Você quer continuar jogando? (Sim = 1/Não = 0): ");
        scanf("%d", &x);
        
        if(x == 0){
            continua = false;
        }
        else if(x == 1){
            printf("\n\n");
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    velha[i][j] = 0;
                    printf("_ "); 
                }
                printf("\n");
            }
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < 3; y++){
                    teste[x][y] = false;
                }
            }
            
            printf("\nJOGADOR 1 = O\tJOGADOR 2 = X\n");
            jogador = 1;
        }
        else{
            printf("Opção inválida. O jogo será encerrado.\n");
            continua = false;
        }
    }
    return 0;
}