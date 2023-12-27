// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// void main() {
//     int i,j,k,n,top=0,col,row;
//     char stack[20], ip[10], opt[10][10][10], ter[10];
//     for(i=0;i<10;i++) {
//         stack[i]=NULL;
//         ip[i]=NULL;
//         for(j=0;j<10;j++) {
//             opt[i][j][0] = NULL;
//         }
//     }
//     printf("Enter the no.of terminals: ");
//     scanf("%d",&n);
//     printf("\nEnter the terminals:\n");
//     scanf("%s",&ter);
//     printf("\nEnter the table values:\n");
//     for(i=0;i<n;i++) {
//         for(j=0;j<n;j++) {
//             printf("Enter the value for %c %c: ",ter[i],ter[j]);
//             scanf("%s",&opt[i][j][0]);
//         }
//     }
//     printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
//     for(i=0;i<n;i++) {
//         printf("\t%c",ter[i]);
//     }
//     printf("\n");
//     for(i=0;i<n;i++) {
//         printf("\n%c",ter[i]);
//         for(j=0;j<n;j++) {
//             printf("\t%c",opt[i][j][0]);
//         }
//     }
//     stack[top]='$';
//     printf("\n\nEnter the input string: ");
//     scanf("%s",&ip);
//     i=0;
//     printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
//     printf("\n%s\t\t\t%s\t\t\t",stack,ip);
//     while(i<=strlen(ip)) {
//         for(k=0;k<n;k++) {
//             if(stack[top]==ter[k])
//                 col=k;
//             if(ip[i]==ter[k])
//                 row=k;
//         }
//         if((stack[top]=='$')&&(ip[i]=='$')) {
//             printf("String is accepted\n");
//             break;
//         }
//         else if((opt[col][row][0]=='<') || (opt[col][row][0]=='=')) {
//             stack[++top]=opt[col][row][0];
//             stack[++top]=ip[i];
//             printf("Shift %c",ip[i]);
//             i++;
//         }
//         else {
//             if(opt[col][row][0]=='>') {
//                 while(stack[top]!='<') {
//                     --top;
//                 }
//                 top=top-1;
//                 printf("Reduce");
//             }
//             else {
//                 printf("\nString is not accepted");
//                 break;
//             }
//         }
//         printf("\n");
//         for(k=0;k<=top;k++) {
//             printf("%c",stack[k]);
//         }
//         printf("\t\t\t");
//         for(k=i;k<strlen(ip);k++) {
//             printf("%c",ip[k]);
//         }
//         printf("\t\t\t");
//     }
// }

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *input;
int i=0;
char lasthandle[6],stack[50],handles[][5]={")E(","E*E","E+E","i","E^E"};
//(E) becomes )E( when pushed to stack
int top=0,l;
char prec[9][9]={
                            /*input*/

            /*stack    +    -   *   /   ^   i   (   )   $  */

            /*  + */  '>', '>','<','<','<','<','<','>','>',

            /*  - */  '>', '>','<','<','<','<','<','>','>',

            /*  * */  '>', '>','>','>','<','<','<','>','>',

            /*  / */  '>', '>','>','>','<','<','<','>','>',

            /*  ^ */  '>', '>','>','>','<','<','<','>','>',

            /*  i */  '>', '>','>','>','>','e','e','>','>',

            /*  ( */  '<', '<','<','<','<','<','<','>','e',

            /*  ) */  '>', '>','>','>','>','e','e','>','>',

            /*  $ */  '<', '<','<','<','<','<','<','<','>',
                };

int getindex(char c) {
switch(c) {
    case '+':return 0;
    case '-':return 1;
    case '*':return 2;
    case '/':return 3;
    case '^':return 4;
    case 'i':return 5;
    case '(':return 6;
    case ')':return 7;
    case '$':return 8;
    }
}
int shift() {
    stack[++top]=*(input+i++);
    stack[top+1]='\0';
}
int reduce() {
    int i,len,found,t;
    for(i=0;i<5;i++) {  //selecting handles
        len=strlen(handles[i]);
        if(stack[top]==handles[i][0]&&top+1>=len) {
            found=1;
            for(t=0;t<len;t++) {
                if(stack[top-t]!=handles[i][t]) {
                    found=0;
                    break;
                }
            }
            if(found==1) {
                stack[top-t+1]='E';
                top=top-t+1;
                strcpy(lasthandle,handles[i]);
                stack[top+1]='\0';
                return 1;//successful reduction
            }
        }
    }
    return 0;
}
void dispstack() {
    int j;
    for(j=0;j<=top;j++)
        printf("%c",stack[j]);
}
void dispinput() {
    int j;
    for(j=i;j<l;j++)
        printf("%c",*(input+j));
}
void main() {
    int j;
    input=(char*)malloc(50*sizeof(char));
    printf("\nEnter the string\n");
    scanf("%s",input);
    input=strcat(input,"$");
    l=strlen(input);
    strcpy(stack,"$");
    printf("\nSTACK\tINPUT\tACTION");
    while(i<=l) {
        shift();
        printf("\n");
        dispstack();
        printf("\t");
        dispinput();
        printf("\tShift");
        if(prec[getindex(stack[top])][getindex(input[i])]=='>') {
            while(reduce()) {
                printf("\n");
                dispstack();
                printf("\t");
                dispinput();
                printf("\tReduced: E->%s",lasthandle);
            }
        }
    }
    if(strcmp(stack,"$E$")==0)
        printf("\nAccepted;");
    else
        printf("\nNot Accepted;");
}