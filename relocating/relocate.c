#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *fp1,*fp2;
    int i,j,hexaddr,start_hexaddr;
    char line[100],startaddr[100];
    fp1=fopen("obj.txt","r");
    printf("enter the actual start address");
    scanf("%x",&start_hexaddr);
    do{
        fscanf(fp1,"%s",line);
        if(line[0]=='T'){
            for(i=2,j=0;line[i]!='^';i++,j++){
                 startaddr[j]=line[i];
                 
            }
            startaddr[j]='\0';
            fp2=fopen("temp.txt","r+");
            fprintf(fp2,"%s",startaddr);
            rewind(fp2);
            fscanf(fp2,"%x",&hexaddr);
            fclose(fp2);
            i=12;
            while(line[i]!='$'){
        if(line[i]!='^'){
         printf("%x\t%c%c\n",hexaddr+start_hexaddr,line[i],line[i+1]);
         hexaddr++;
         i+=2;


       }
        else{
           i++; 
        }

        }
    }

}while(!feof(fp1));
fclose(fp1);
}
