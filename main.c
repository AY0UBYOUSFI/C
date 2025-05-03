#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>


struct List{
    int number;
    struct List *next;
};
typedef struct List *Tlist;


Tlist AddToList(Tlist L, int number){

    Tlist node = (Tlist) malloc(sizeof(struct List));
    node->number = number;


    if(L==NULL){
       L = node;
       L->next = NULL;
       return L;
    }
    else{

        Tlist T1 = L;
        while(T1->next!=NULL){
            T1=T1->next;
        }
        T1->next=node;
        node->next = NULL;
        return L;

    }
    return L;
}



void display(Tlist L){

   if(L==NULL)
     printf("empty list...");
    else{
        Tlist T = L;
        int i=0;
        while(T!=NULL){
            i++;
            printf("[%d:%d] -> ",i,T->number);
            if(T->next==NULL){
            printf("[NULL]");
            return;
            }
            else
            T=T->next;
        }


    }
return;

}


void CreatList(Tlist *p){

    int upperbound = rand()%100;
    int i=0,value=0;
    for(i=0;i<upperbound;i++){
        value = rand()%(i+1);
        *p=AddToList(*p,value);

    }

    display(*p);

}
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <windows.h>

void _ini_() {
    SetConsoleOutputCP(CP_UTF8);
    system("color 2");

    printf("\n");
    printf("  ##########################################################\n");
    printf("  #                                                        #\n");
    printf("  #     █████╗ ██╗   ██╗ ██████═╗██╗   ██╗██████═╗         #\n");
    printf("  #    ██╔══██╗██║   ██║██╔═══██║██║   ██║██╔══██║         #\n");
    printf("  #    ███████║████████║██║   ██║██║   ██║██████ ╝         #\n");
    printf("  #    ██╔══██║   ██╔══╝██║   ██║██║   ██║██╚══██║         #\n");
    printf("  #    ██║  ██║   ██║   ╚██████╔╝╚██████╔╝██████═╝         #\n");
    printf("  #    ╚═╝  ╚═╝   ╚═╝    ╚═════╝  ╚═════╝ ╚════╝           #\n");
    printf("###                                                        ###\n");
    printf("  #    ██████╗  ███████╗████████╗███████╗██████╗           #\n");
    printf("  #    ██╔══██╗ ██╔════╝╚══██╔══╝██╔════╝██╔══██╗          #\n");
    printf("  #    ██████╔╝ █████╗     ██║   █████╗  ██████╔╝          #\n");
    printf("  #    ██╔═══╝  ██╔══╝     ██║   ██╔══╝  ██╔═██║           #\n");
    printf("  #    ██║      ███████╗   ██║   ███████╗██║ ██║           #\n");
    printf("  #    ╚═╝      ╚══════╝   ╚═╝   ╚══════╝╚═╝ ╚═╝           #\n");
    printf("  #                                                        #\n");
    printf("  #       Dynamic Linked List Engine by Ayoub Peter        #\n");
    printf("  ##########################################################\n\n");

    Sleep(100);
}




int Lsize(Tlist L){
   Tlist tempL = L;
    int counter=0;

    if(tempL != NULL){
    while (tempL!=NULL){
        counter ++;
        tempL = tempL -> next;
    }

    }
    else
    return counter;

return counter;

}






bool Snode(Tlist L,int number){


Tlist tempL = L;

if(tempL==NULL)
    return false;


while(tempL!=NULL){
    if(tempL->number == number)
        return true;
    tempL = tempL->next;
}

return false;

}



Tlist DeletNode(Tlist L,int number){

    if(L==NULL)
        return L;
    else{
        Tlist Spointer = L;
        //if the node is the head of the linked list ...
        if(Spointer->number==number){
            if(Spointer->next == NULL)
                return Spointer->next;
            else{
                L=Spointer->next;
                free(Spointer);
                return L;
            }

        }




        else{

        Tlist SRELEVENT = Spointer;

        //search for the node ...

        while(Spointer->next!=NULL){
            if(Spointer->number == number)
                break;
            SRELEVENT = Spointer;
            Spointer = Spointer->next;
        }

        if(Spointer->next == NULL){
            SRELEVENT->next = NULL;
            free(Spointer);
            return L;
        }
        else{

            SRELEVENT->next = Spointer->next;
            free(Spointer);
            return L;
        }


        }




    }

return L;

}





int main(){




srand(time(NULL));
_ini_();
char tab = getchar();
//**************** second part ***************

Tlist p = NULL;

p = AddToList(p,10);

p = AddToList(p,30);
p = AddToList(p,14);
p = AddToList(p,23);
p = AddToList(p,53);
p = AddToList(p,75);

display(p);


p = DeletNode(p,10);
printf("\nwe delet node 10 ? \n");
display(p);


p = DeletNode(p,23);
printf("\nwe delet node 23 ? \n");
display(p);

p = DeletNode(p,75);
printf("\nwe delet node 75 ? \n");
display(p);



























/*

Tlist p= NULL;
int i =0;
for(i=0;i<5;i++){
    printf("\ntry [%d]\n",i);
    CreatList(&p);
}

 Tlist a = (Tlist) malloc(sizeof(struct List));
 a->number = 78;
 Tlist b = (Tlist) malloc(sizeof(struct List));
 b->number = 32;
 Tlist c = (Tlist) malloc(sizeof(struct List));
 c->number = 56;
 a->next=b;
 b->next=c;
 c->next= NULL;

 */





   // display(p);

     printf("\ncode running succesfuly ...");
    return 0;
}
