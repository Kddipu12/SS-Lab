#include<stdio.h>
#include<string.h>
struct {
    char dname[10],fname[10][10];
    int fcnt;
}dir;
void main(){
    int i,ch;
    char f[30];
    dir.fcnt=0;
    printf("\enter the name of directory---");
    scanf("%s",dir.dname);
    while(1){
        printf("\n\n 1.Create File\t2.Delete File \t3.Search File \n4.Display File $");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter the name of the file --");
            scanf("%s",dir.fname[dir.fcnt]);
            dir.fcnt++;
            break;

            case 2: printf("\enter the name of the file --");
            scanf("%s",f);
            for(i=0;i<dir.fcnt;i++){
                if(strcmp(f,dir.fname[i])==0)
                {
                    printf("File is %s deleted",f);
                    strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
                    break;
                }

            }
            if(i==dir.fcnt)
             printf("File %s not found",f);
            else
            {
               dir.fcnt--;
            }
            break;
            case 3: printf("\nenter the nae of the file --");
            scanf("%s",f);
            for(i=0;i<dir.fcnt;i++){
                if(strcmp(f,dir.fname[i])==0)
                {
                    printf("File %s is found",f);
                    break;
                }
            }
             if(i==dir.fcnt)
             printf("File %s not found",f);
             break;
             case 4:
              if(dir.fcnt==0)
                printf("\nDirectory Empty");
                else{
                    printf("\n The Files are --");

                }
                for(i=0;i<dir.fcnt;i++){
                    printf("\t%s",dir.fname[i]);
                }
                break;

             case 5:
             break;
        

        }
    }
}
