#include<stdio.h>
void main() {
    char s[5],ch='y',s1[4];
    do { 
        printf("\nEnter any operator: ");
        scanf("%s",&s);
        switch(s[0]) {
            case'>':
                if(s[1]=='=')
                    printf("\nValid operator : Greater than or equal");
                else
                    printf("\nValid operator :  Greater than");
            break;
            case'<':
                if(s[1]=='=')
                    printf("\nValid operator : Less than or equal");
                else
                    printf("\nValid operator : Less than");
            break;
            case'=':
                if(s[1]=='=')
                    printf("\nValid operator : Equal to");
                else
                    printf("\nValid operator : Assignment");
            break;
            case'!':
                if(s[1]=='=')
                    printf("\nValid operator : Not Equal");
                else
                    printf("\nValid operator :  Bit Not");
            break;
            case'&':
                if(s[1]=='&')
                    printf("\nValid operator : Logical AND");
                else
                    printf("\nValid operator : Bitwise AND");
            break;
            case'|':
                if(s[1]=='|')
                    printf("\nValid operator : Logical OR");
                else
                    printf("\nValid operator : Bitwise OR");
            break;
            case'+':
                if(s[1]=='+')
                    printf("\nValid operator : Unary operator");
                else
                    printf("\nValid operator : Addition");
            break;
            case'-':
                if(s[1]=='-')
                    printf("\nValid operator : Unary operator");
                else
                    printf("\nValid operator : Substraction");
            break;
            case'*':
                printf("\nValid operator : Multiplication");
            break;
            case'/':
                printf("\nValid operator : Division");
            break;
            case'%':
                printf("\nValid operator : Modulus");
            break;
            default:
                printf("\nInvalid operator !!!!");
            break;
        }
        printf("\n do you want to continue(y:yes,n:No): ");
        scanf("\n%c",&ch);
    } while(ch=='Y'||ch=='y');
}