
#include<stdio.h>
struct patient
{
    int id;
    char name[20];
    int dob;
    int cy;
    int age;
    int number_of_dose;
};
void record()
{
    FILE *fp;
    struct patient pnt;
    int i,n;
    printf("Kindly enter the number of patient to be recorded:");
    scanf("%d", &n);
    printf("Enter current year:.. ");
    scanf("%d",&pnt.cy);
    for(i=1; i<=n; i++){
        printf("Kindly enter ID of patient %d:.. ", i);
        scanf("%d",&pnt.id);
        printf("Kindly enter name of patient %d:.. ", i);
        scanf("%s",&pnt.name);
        printf("Kindly enter number of vaccine doses of patient %d:.. ", i);
        scanf("%d",&pnt.number_of_dose);
        printf("Kindly enter Date of birth of patient %d:.. ", i);
        scanf("%d",&pnt.dob);
        pnt.age=pnt.cy-pnt.dob;
        fp=fopen("patient.txt","a");
        fprintf(fp,"%d\t%s\t%d\t%d\n",pnt.id,pnt.name,pnt.age,pnt.number_of_dose);
        fclose(fp);
    }

}
void display()
{
    FILE *p;
    struct patient pnt;
    p=fopen("patient.txt","r");
    printf("\nID\tName\t\tAge\tNumber_of_dose\n==\t====\t\t===\t============\n");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\t%d\n",&pnt.id,&pnt.name,&pnt.age,&pnt.number_of_dose);
        printf("%d\t%s\t\t%d\t%d\n",pnt.id,pnt.name,pnt.age,pnt.number_of_dose);
    }
    fclose(p);
}
void search()
{
    int key;
    FILE *p;
    struct patient pnt;
    printf("Enter the ID you're searching:...");
    scanf("%d",&key);
    p=fopen("patient.txt","r");
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\t%d\n",&pnt.id,pnt.name,&pnt.age,&pnt.number_of_dose);
        if(pnt.id==key)
        {
            printf("\nHis/Her name is %s, He/She is %d Year(s) old and He/She has received %d doses \n\n",pnt.name,pnt.age,pnt.number_of_dose);
            fclose(p);
            return;
        }
    }
    printf("\npatient not found\n\n");
    fclose(p);
}
void sort()
{
    FILE *p;
    struct patient pnt[20],temp;
    int i,j,count,min,imin;
    p=fopen("patient.txt","r");
    count=0;
    while(!feof(p))
    {
        fscanf(p,"%d\t%s\t%d\t%d\n",&pnt[count].id,&pnt[count].name,&pnt[count].age, &pnt[count].number_of_dose);
        count++;
    }
    fclose(p);
    for(i=0;i<count-1;i++)
    {
        min=pnt[i].age;
        imin=i;
        for(j=i+1;j<count;j++)
        {
            if(pnt[j].age<min)
            {
                min=pnt[j].age;
                imin=j;
            }
        }
        temp=pnt[i];
        pnt[i]=pnt[imin];
        pnt[imin]=temp;
    }
    printf("\nSorted list:\n");
    printf("\nID\tName\tAge\tNumber_of_dose\n==\t====\t===\t============\n");
    for(i=0;i<count;i++)
    {
        printf("%d\t%s\t%d\t%d\n",pnt[i].id,pnt[i].name,pnt[i].age,pnt[i].number_of_dose);
    }
}

int main()
{
     int n;
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t                                           \n");
    printf("\t\t\t\t        PATIENT COVID REGISTRATION        \n");
    printf("\t\t\t\t                                      \n");
    printf("\t\t\t\t                                        \n");
    printf("\t\t\t\t                 ---                       \n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t press 1 to continue...");
    scanf("%d",&n);

    int c;
    do
    {
        printf("Main Menu\n=========\n");
        printf("1. Record\n2. Display\n3. Search\n4. Sort by age\n0. Exit\nMake a choice:...\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            record();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 0:
            printf("See you");
            break;
        default:
            printf("Invalid choice\n");
        }
    }while(c!=0);
}
