
#include"linkedlist.h"
#include<conio.h>


int main(){

 char chioce;
list_nodes_t *list_1 = create_list();
status_t ret;
char flag = 'y';



    
     
     while('y' == getch())
     {  system("cls");
        printf("\n======================\n");
        printf("1)append node\n");
        printf("2)insert node at begining\n");
        printf("3)insert node at certain position\n");
        printf("4)delete node at certain position\n");
        printf("5)search on node \n");
        printf("6)display list \n");
        printf("7)display size of list \n");
        printf("8)reverse list\n");
        printf("9)sort list\n");
        printf("10)swap two nodes\n");
        printf("11)modify data of nodes\n");
        printf("12)delete node by value\n");
        printf("Enter y->cointiue n->exit\n");
        printf("======================\n");
        printf("Enter your choice : ");
        scanf("%d",&chioce);
        system("@cls || clear");
           
        switch(chioce)
        {
            case  1 : 
                             
                ret = append_node(list_1);
                system("cls");              
                break;
            case  2 :
                insert_node_at_begining(list_1);
                system("cls");
                break;
            case  3 :
                insert_node_at_cretain_position(list_1);
                system("cls");
                break; 
            case  4 :
                delete_node_at_psition(list_1);
                system("cls");
                break;
            case  5 :
                printf("\ndata of node you search on : %d\n",search_on_node(list_1)->data);
                system("cls");
                break;
            case  6 :
                display_list(list_1);
                
                break;
            case  7 :
                printf("\nlength of list = %d\n",list_1->nodes_number);
                system("cls");
                break;
            case  8 :
                reverse_list(list_1);
                system("cls");
                break;
            case  9 :
               ret = sort_list(list_1);
               system("cls");
                break;
            case  10 :
                ret = sawp_two_nodes(list_1);
                system("cls");
                break;
            case  11 :
                ret = modify_node_data(list_1);
                system("cls");
                break;
            case  12 :
                ret = delete_node_by_value(list_1);
                system("cls");
                break;                           
            default:
                printf("\ninvalid chioce !!\n");
                system("cls");
                break;
    
        }
        printf("\nEnter y to retrun to main menu :");
        
     }    




return 0;
}
