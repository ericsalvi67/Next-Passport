/*Fazer um programa escrito na linguagem C que leia o Número do Passaporte em uma string, no formato LLDDDDDD,
 onde L é uma letra maiúscula e D é um dígito e escreva o passaporte com numeração subsequente. Caso o número for 999999, 
 encontre o conjunto de letras subsequente. */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define N 10

 int tamanho(char str[N])
 {
    int i ;

    for(i=0;str[i]!='\0';i++);

    return i;
 }

int verify(char str[N])
 {
    int i,c;

    c=tamanho(str);
    if(c>8) return 0;

    for(i=0;i<c;i++)
    {
        if(i<2)
        {
            if(!(str[i]>=65 && str[i]<=90)) return 0;
        }
        else 
        {
            if(!(str[i]>=47 && str[i]<=57)) return 0;
        }
    }
    return 1;
 }

 void nextpass(char str[N])
 {
    int i,c;

    c=tamanho(str)-1;

    str[c]+=1;

    for(i=c;i>=0;i--)
    {
        if(str[i]>'9' && i>1)
        {   
            str[i]='0';
            str[i-1]+=1;
        }
        else if(str[i]>'Z')
        {
            str[i]='A';
            str[i-1]+=1;
        }
    }  
 }

 int main()
 {
    char str[N];

    printf("DIGITE O PASSAPORTE: ");
    scanf("%s", str);

    if(verify(str))
    {
        printf("\nPASSAPORTE VALIDO");
        printf("\n%s",str);
        printf("\t=>");
        nextpass(str);
        printf("\t%s", str);
    }
    else printf("\nPASSAPORTE INVALIDO");
 }
