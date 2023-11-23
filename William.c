#include <stdio.h>
int num[3] = {1 , 2 ,3};
char campo [3][3] = {{0, 0, 0},{0,0,0},{0,0,0}};
char itens[3] = {'_', 'X', 'O'};
int linha, coluna, player;
// função pra imprimir a tabela;
void tabela(){
printf(" %d %d %d \n", num[0], num[1], num[2]);
printf(" - - - - \n");
for(int i = 0; i< 3; i++){
printf("%d", num[i]);
printf("|");
for(int j = 0; j < 3; j++){
if (campo[i][j] == 1){
printf("%3c", itens[1]);
}else if(campo[i][j] == 2) {
printf ("%3c", itens[2]);
}else{
printf("%3c", itens[0]);
}
}
printf("\n");
}
}
// algumas coisas que precisaram ser declaradas antes;
char escolha;
int liga = 1;
// função para escolher quem vai primeiro;
void inicio(){
printf("quem vai primeiro? \n");
printf("[X ou O] (O = letra): ");
scanf (" %c",& escolha);
while (escolha != 'x' && escolha != 'X' && escolha != 'O'&& escolha != 'o'){
printf("digite um valor valido: ");
scanf(" %c",& escolha);
}
}
// quando a vitoria acontecer, vai acontecer isso;
void vitoria(int N){
if (N == 1){
printf("O jogador [X] venceu!!\n");
}else{
printf("O jogador [O] venceu!!\n");
}
printf("\n");
liga = 0;
tabela();
}
// condições de vitoria ( coloquei a função vitoria dentro dessa função);
// fiz um loop for para nao ter que escrever isso tudo duas vezes;
void condi(){
for(int i = 1; i <3; i ++){
if ( campo[0][0] == i){
if (campo [0][1] == i && campo[0][2] == i){
vitoria(i);
}else {
if (campo[1][0] == i && campo[2][0] == i){
vitoria(i); 
}
}
}
if ( campo[2][2] == i){
if(campo[2][0] == i && campo[2][1] == i){
vitoria(i);
}else if (campo[0][2] == i && campo[1][2] == i){
vitoria(i); 
}
}
if (campo[1][1] == i){
if (campo[0][1] == i && campo[2][1] == i){
vitoria(i);
}else if (campo[1][0] == i && campo[1][2] == i){
vitoria(i); 
}else if (campo[0][0] == i && campo[2][2] == i){
vitoria(i);
}else if (campo[2][0] == i && campo[0][2] == i){
vitoria(i);
}
}
}
}
// aqui na main é que o codigo começa mas tive que declarar algumas coisas antes;
int main()
{
inicio();
printf("\n");
/** 
* esse liga pode ser entendido como uma tonada, enquanto ele for = 1 o codigo vai ficar rodando infinitamente
* como eu coloquei la no codigo que se a vitoria acontecer, ele vira 0, se o valor de liga mudar o loop while acaba;
**/
while(liga == 1){
tabela();
printf("\n");
printf("digite as coordenandas do tabuleiro\n");
printf("linha e coluna nessa ordem: ");
scanf("%d %d", &linha, &coluna);
//caso coloque coordenadas invalidas:
while (linha > 3 || linha < 0 || coluna > 3 || coluna < 0){
printf("digite uma coordenada válida: ");
scanf("%d %d", &linha, &coluna);
}
/** como na matriz que é o tabuleiro, já esta declarado que todos os valores são 0,
* quando eu marco uma coordenada ela fica com 1 = [X] ou 2 = [O], logo se a coordenada que eu
* marcar for diferente de 0, vou estar marcando uma coordenada ja marcada entao 
* tem esse verificador para impedir isso;
**/
if (campo[linha - 1][coluna - 1] != 0 )do {
printf("a coordenada ja esta ocupada\n ");
printf("digite uma coordenada válida: ");
scanf("%d %d", &linha, &coluna);
}while(campo[linha - 1][coluna - 1] != 0);
printf("\n");
// cidigo para trocar de x para o;
if ( escolha == 'X' || escolha == 'x'){
player = 1;
campo[linha - 1][coluna - 1] = player;
escolha = 'O';
} else{
player = 2;
campo[linha - 1][coluna - 1] = player;
escolha = 'X';
}
condi();
}
return 0;
}