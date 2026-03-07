/*Autores: Lucas Espíndula Borges, André Moraes Rodrigues, Gabriel dos Santos do Amaral*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[256];
    scanf("%255[^\n]", s);

    for (int i = 0; i < strlen(s); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = ((s[i] - 'a' + 3) % 26) + 'a';
            printf("%c", s[i]);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = ((s[i] - 'A' + 3) % 26) + 'A';
            printf("%c", s[i]);
        }
        else{
            printf("%c", s[i]);
        }
    }
}