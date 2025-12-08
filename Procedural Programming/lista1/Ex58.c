/*Leia uma matriz 10 x 3 com as notas de 10 alunos em 3 provas. Crie um vetor que armazene a nota
final de cada aluno, calculada a partir da média aritmética das notas das 3 provas. Imprima o vetor
resultante. Além disso, calcule e imprima a média da turma.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nalunos, Nprovas;
    printf("Digite o numero de alunos da turma: ");
    scanf("%d", &Nalunos);
    printf("Digite o numero de provas realizadas: ");
    scanf("%d", &Nprovas);
    int mt[Nalunos][Nprovas];
    
    for (int i = 0; i < Nalunos; i++){
        for (int j = 0; j < Nprovas; j++){
            
            printf("Digite a nota do aluno %i na prova %i: ", i+1, j+1);
            scanf("%d", &mt[i][j]);
            
        }
        printf("\n");
    }
    
    float nf[Nalunos], soma;
    
    for (int i = 0; i < Nalunos; i++){
        
        soma = 0;
        
        for (int j = 0; j < Nprovas; j++){
            
            soma += mt[i][j];
            
        }
        
        nf[i] = soma / (float) Nprovas;
        
    }
    
    for (int i = 0; i < Nalunos; i++){
        
        if (nf[i] >= 7){
            printf("A nota final do aluno %d e: %.1f\t (Aprovado!)\n\n", i+1, nf[i]);
        }
        else{
           printf("A nota final do aluno %d e: %.1f\t (Reprovado!)\n\n", i+1, nf[i]); 
        }
    }
    
    float media, sm = 0;
    
    for (int i = 0; i < Nalunos; i++){
        
        sm += nf[i];
        media = sm / (float) Nalunos;
        
    }
    
    printf("A note media da turma e: %.2f\n", media);

    system("pause");
    return 0;
}