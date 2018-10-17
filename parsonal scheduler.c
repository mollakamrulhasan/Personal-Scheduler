#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

void addrecord();
void viewrecord();
void deleterecord();

struct record
{
    char time[6];
    char date[16];
    char name[30];
    char place[25];
    char duration[10];
    char note[500];
    int id;
} ;
struct record e;

int main()
{
   int number= 123 ;

    int pass;
    printf("\n\n\tENTER PASSWORD :");
    scanf("%d",&pass);
   if(pass==number)
   {
       printf("Correct....Thank You\n");

   }
       else

   {
       printf("invalid Password");
       return 0;
   }

    int ch;
    printf("\n\n\t***********************************\n");
    printf("\t\t* PERSONAL SCHEDULER  *\n");
    printf("\t***********************************");
{

 time_t currentTime;

time(&currentTime);
struct tm *myTime=localtime(&currentTime);
printf("\n\n\t DATE:");

printf("%i/%i/%i \n",myTime->tm_mday,myTime->tm_mon + 1,myTime->tm_year + 1900);

}
{
  struct tm *local, *gm;
 time_t t;
 t=time(NULL);
 local= localtime(&t) ;
 printf("\n\t TIME: %d:%d:%d",local->tm_hour,local->tm_min,local->tm_sec);
}

   while(1)

        {
                printf("\n\n\t\tMAIN MENU:");
                printf("\n\n\t\xDB\xDB\xDB\xB2 ADD RECORD \t[1]\n");
                printf("\n\t\xDB\xDB\xDB\xB2 VIEW RECORD\t[2]\n");

                printf("\n\t\xDB\xDB\xDB\xB2 DELETE RECORD\t[3]\n");

                printf("\n\t\xDB\xDB\xDB\xB2 EXIT\t\t[4]\n");
                printf("\n\n\t\xDB\xDB\xDB\xB2 ENTER YOUR CHOICE:");
                scanf("%d",&ch);

            switch(ch)
                    {
                            case 1:
                            addrecord();
                            break;

                            case 2:
                            viewrecord();
                            break;


                            case 3:
                            deleterecord();
                            break;

                            case 4:
                            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE CREATED BY:\n\n\tMETHON\n\n\tREZA\n\n\tKAMRUL\n\n\tRAKIB\n\n\tSHIBLU...");
                            getch();
                            exit(0);

                            default:
                            printf("\nYOU ENTERED WRONG CHOICE..");
                            printf("\nPRESS ANY KEY TO TRY AGAIN");
                            getch();
                            break;
                    }
                system("cls");
        }
            return 0;
}
void addrecord( )
{
    char time[10];
                system("cls");

                FILE *fp ;
                fp = fopen ("kkkk.dat", "ab+" ) ;
                {printf("\n\n\t\t***************************\n");
                printf("\t\t* WELCOME TO THE ADD MENU *");
                printf("\n\t\t***************************\n\n");

                printf("RECORD  NO: ");
                scanf("%d",&e.id);

                fflush(stdin);
                printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");
                gets(e.date);
                printf("\n\tENTER TIME:");
                fflush(stdin);
                gets(e.time);

                printf("\tENTER NAME:");
                fflush(stdin);
                gets(e.name);
                fflush(stdin);
                printf("\tENTER PLACE:");
                gets(e.place);
                fflush(stdin);
                printf("\tENTER DURATION:");
                gets(e.duration);
                fflush(stdin);
                printf("\tNOTE:");
                gets(e.note);
                fwrite ( &e, sizeof ( e ), 1, fp ) ;
                printf("\nYOUR RECORD IS ADDED...\n");

                }
                fclose ( fp ) ;
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();
    }
void viewrecord( )
{               struct record k;
                char time[10];
                system("cls");
                FILE *fd ;
                fd = fopen("kkkk.dat","rb" ) ;
                printf("\nYOUR RECORD IS:");
                while(fread(&k, sizeof ( k ), 1, fd)==1)

                {

                printf("\n");
                printf("\nRECORD NO: %d",k.id);
                printf("\nDATE: %s",k.date);
                printf("\nTIME: %s",k.time);
                printf("\nMEETING WITH: %s",k.name);
                printf("\nMEETING AT: %s",k.place);
                printf("\nDURATION: %s",k.duration);
                printf("\nNOTE: %s",k.note);
                printf("\n");

                }
                fclose ( fd ) ;
                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();
    }

void deleterecord( )
{
           system("cls");

                int m;
                FILE *fp,*ft;
                printf("Enter The Record Id to  Delete:");
                scanf("%d",&m);
                fp=fopen("kkkk.dat","rb");
                ft=fopen("kkkk1.dat","wb");

                 while(fread(&e, sizeof(e),1,fp) == 1)
    {
        if(e.id!=m)
        {

            fwrite(&e,sizeof(e),1,ft);
        }

    }

              fclose(fp);
              fclose(ft);
        remove("kkkk.dat");
        rename("kkkk1.dat","kkkk.dat");
        printf("DELETED");

                getch(); }


