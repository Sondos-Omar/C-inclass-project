#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<time.h>

int n;

struct dob
{
	int m, y, d;
};

struct add
{
    char country[50];
    char city[50];
    char district[50];
};

struct m
{
    float seventh, twelveth, year_work, final, total;
};

struct s_done{
    char name [100];
    char code [10];
    int ch;
    struct m mark;
    char g;
    int term;
    char lecturer[100];
    int done;
};


struct student
{
    char FN [50]; // First name
    char MN [50]; // Middle name
    char LN [50]; // Last name
	int id;
	struct dob date;
	int age;
	struct add address;
	float gpa;
	int nat; //national if
	int ch; //completed credit hour
	int uch; //credit hours to go
	int term;
	char phone[12];
	char email[100];
	char department[50];
	struct s_done subCurrent[50];
	struct s_done subdone[50];
	int NSub_done;
	int NSub_current;
};


student St[1000];
void subPrint ()
{
    int x;
	char str1[100], str2[100];

	FILE *f1;
	f1=fopen("c:\\DrHabrouk\\subjects.txt","r");

	while (fscanf(f1, "%s %s %d", str1, str2, &x)!= EOF)
	{
        printf ("%s\t\t%s\t%d\n", str1, str2, x);
	}

    fclose(f1);
    printf ("press any key to continue");
    getch ();
}


void regStudent ()
{
    int x;

    time_t t;

	student s;

	FILE *f1, *f2;
	f1=fopen("c:\\DrHabrouk\\studentData.txt", "a");
    f2=fopen("c:\\DrHabrouk\\subjects.txt", "r");
/*
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    printf("%d %d %d", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
*/
    // Student Name
    printf ("Student Name \"Fisrt Middle Last\": ");
    scanf("%s %s %s",s.FN, s.MN, s.LN);
    fprintf (f1,"%s %s %s ",s.FN, s.MN, s.LN);

    //Student ID
    printf ("Student ID: ");
    scanf("%d",&s.id );
    fprintf (f1,"%d ",s.id );

    //Student date of birth
    printf ("Student date of birth: ");

    //Year of birth
    printf ("Year: ");
    scanf("%d",&s.date.y);

    t = time(0);   // get time now
    struct tm * now = localtime( & t );

    while ( (s.date.y < 1980) || (s.date.y > now->tm_year + 1900) )
    {
            printf ("Error\nYear: ");
            scanf("%d ",&s.date.y);
    }
    fprintf (f1,"%d ",s.date.y);

    //Month of birth
    printf ("Month: ");
    scanf("%d",&s.date.m);

    while ( (s.date.m <= 1) || (s.date.m >= 12) )
    {
            printf ("Error\nMonth: ");
            scanf("%d",&s.date.m);
    }
    fprintf (f1,"%d ",s.date.m);

    //Day of birth
    printf ("Day: ");
    scanf("%d",&s.date.d);

    while ( 1 )
    {
        int l;
        if( (s.date.y%400==0 || s.date.y%100!=0) &&(s.date.y%4==0))
            l = 29;
        else
            l = 28;

        if ( ( (s.date.m == 1)
        || (s.date.m == 3)
        || (s.date.m == 5)
        || (s.date.m == 7)
        || (s.date.m == 8)
        || (s.date.m == 10)
        || (s.date.m == 12)
        ) && ( (s.date.d >= 1) && (s.date.d <= 31))
        )
            break;

        else if ( ( (s.date.m == 4)
        || (s.date.m == 6)
        || (s.date.m == 9)
        || (s.date.m == 11)
        ) && ( (s.date.d >= 1) && (s.date.d <= 30))
        )
            break;

        else if ( (s.date.m == 2) && ( (s.date.d >= 1) && (s.date.d <= l)) )
             break;

        else
            {
            printf ("Error\nDay: ");
            scanf("%d",&s.date.d);
            }
         }



    fprintf (f1,"%d ",s.date.d);

    //Calculate Age
    s.age = (now->tm_year + 1900) - s.date.y;
    printf ("Age = %d years old\n", s.age);
    fprintf (f1,"%d ", s.age);

    //Address
    printf ("Enter Student Address \n");
    printf ("Country: ");
    scanf("%s",s.address.country);
    fprintf (f1,"%s ",s.address.country);

    printf ("City: ");
    scanf("%s",s.address.city);
    fprintf (f1,"%s ",s.address.city);

    printf ("District: ");
    scanf("%s",s.address.district);
    fprintf (f1,"%s ",s.address.district);

    printf ("Enter Student National ID: ");
    scanf("%d",&s.nat);
    fprintf (f1,"%d ",s.nat);

    printf ("Enter Student email: ");
    scanf("%s",s.email);
    fprintf (f1,"%s ",s.email);

    printf ("Enter Student department: ");
    scanf("%s",s.department);
    fprintf (f1,"%s\n",s.department);

    fclose(f1);
    fclose(f2);
    printf ("press any key to continue");
    getch ();
}


void studentRecord ()
{
    char str[5000];

    FILE *f1;
	f1=fopen("c:\\DrHabrouk\\studentData.txt","r");

	while( fgets (str, 200, f1)!=NULL )
    {
        puts(str);
    }

    fclose(f1);
    printf ("\n\npress any key to continue");
    getch ();
}


void searchRecord ()
{
    char str[5000], FN[50], MN[50], LN[50], SN[50];
    int x, tempid;
    float tempgpa;

    //Selsct Menu
    printf ("Press\n\t");
    printf ("1. Search by Name\n\t");
    printf ("2. Search by ID\n\t");
    printf ("3. Search by GPA\n\t");

    //Selsct Menu
    printf ("\n\t> ");
    scanf ("%d",&x);
    if (x==1)
    {
        printf ("\n\n\tEnter Name: ");
        scanf ("%s", SN);

        for (int i=0; i<n; i++)
        {
            if ( (strcmp (strlwr(SN), strlwr(St[i].FN)) == 0)
               ||(strcmp (strlwr(SN), strlwr(St[i].MN)) == 0)
               ||(strcmp (strlwr(SN), strlwr(St[i].LN)) == 0)
                )
                {
                    printf ("%s %s %s", St[i].FN, St[i].MN, St[i].LN);
                    printf ("%d %d %d %d %d", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
                    printf ("%s %s %s", St[i].address.country, St[i].address.city, St[i].address.district);
                    printf ("%d", St[i].nat);
                    printf ("%s %s", St[i].email, St[i].department);
                    printf ("%f\n\n", St[i].gpa);
                }
        }

    }

    else if (x==2)
    {
        printf ("\n\n\tEnter ID number: ");
        scanf ("%d", &tempid);

        for (int i=0; i<n; i++)
        {
            if ( tempid == St[i].id)
            {
                printf ("%s %s %s", St[i].FN, St[i].MN, St[i].LN);
                printf ("%d %d %d %d %d", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
                printf ("%s %s %s", St[i].address.country, St[i].address.city, St[i].address.district);
                printf ("%d", St[i].nat);
                printf ("%s %s", St[i].email, St[i].department);
                printf ("%f\n\n", St[i].gpa);
            }
        }
    }

    else if (x==3)
    {
        printf ("\n\n\tEnter GPA: ");
        scanf ("%f", &tempgpa);

        for (int i=0; i<n; i++)
        {
            if ( tempgpa == St[i].gpa)
            {
                printf ("%s %s %s", St[i].FN, St[i].MN, St[i].LN);
                printf ("%d %d %d %d %d", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
                printf ("%s %s %s", St[i].address.country, St[i].address.city, St[i].address.district);
                printf ("%d", St[i].nat);
                printf ("%s %s", St[i].email, St[i].department);
                printf ("%f\n\n", St[i].gpa);
            }
        }
    }


    printf ("\n\npress any key to continue");
    getch ();
}


void editRecord ()
{
    int temp, j, i;
    printf ("Editing\nEnter Student ID> ");
    scanf ("%d",&temp);

    for (i=0; i<n; i++)
    {
        if ( temp == St[i].id)
        {
            printf ("%s %s %s ", St[i].FN, St[i].MN, St[i].LN);
            printf ("%d %d %d %d %d ", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
            printf ("%s %s %s ", St[i].address.country, St[i].address.city, St[i].address.district);
            printf ("%d ", St[i].nat);
            printf ("%s %s ", St[i].email, St[i].department);
            printf ("%f\n", St[i].gpa);
            break;
        }
    }

    j=i;

    if (j<n)
    {

    printf ("Press\n\t");
    printf ("1. Edit First Name\n\t");
    printf ("2. Edit Middle Name\n\t");
    printf ("3. Edit Last Name\n\t");
    printf ("4. Edit Date of Birth\n\t");
    printf ("5. Edit National ID\n\t");
    printf ("6. Edit email\n\t");
    printf ("7. Edit Department\n\t");
    printf ("8. Edit Subject\n\t");
    printf ("\n\t>");
    scanf ("%d", &temp);

    if (temp == 1)
    {
        scanf ("%s", St[j].FN);
    }

    else if (temp == 2)
    {
        scanf ("%s", St[j].MN);
    }

    else if (temp == 3)
    {
        scanf ("%s", St[j].LN);
    }

    else if (temp == 4)
    {
        time_t t;
        t = time(0);   // get time now
        struct tm * now = localtime( & t );

        //Year of birth
        printf ("Year: ");
        scanf("%d",&St[i].date.y);

        while ( (St[i].date.y < 1980) || (St[i].date.y > now->tm_year + 1900) )
        {
            printf ("Error\nYear: ");
            scanf("%d ",&St[i].date.y);
        }


        //Month of birth
        printf ("Month: ");
        scanf("%d",&St[i].date.m);

        while ( (St[i].date.m <= 1) || (St[i].date.m >= 12) )
        {
            printf ("Error\nMonth: ");
            scanf("%d",&St[i].date.m);
        }

        //Day of birth
        printf ("Day: ");
        scanf("%d",&St[i].date.d);

        while ( 1 )
        {
            if ( ( (St[i].date.m == 1)
                || (St[i].date.m == 3)
                || (St[i].date.m == 5)
                || (St[i].date.m == 7)
                || (St[i].date.m == 8)
                || (St[i].date.m == 10)
                || (St[i].date.m == 12)
                ) && ( (St[i].date.d >= 1) && (St[i].date.d <= 31))
                )
                    break;

            else if ( ( (St[i].date.m == 4)
                || (St[i].date.m == 6)
                || (St[i].date.m == 9)
                || (St[i].date.m == 11)
                ) && ( (St[i].date.d >= 1) && (St[i].date.d <= 30))
                )
                    break;

            else if ( (St[i].date.m == 2) && ( (St[i].date.d >= 1) && (St[i].date.d <= 28)) )
                break;

            else
            {
                printf ("Error\nDay: ");
                scanf("%d",&St[i].date.d);
            }
        }


        //Calculate Age
        St[i].age = (now->tm_year + 1900) - St[i].date.y;
        printf ("Age = %d years old\n", St[i].age);
    }

    else if (temp == 5)
    {
        scanf ("%d", &St[j].nat);
    }

    else if (temp == 6)
    {
        scanf ("%s", St[j].email);
    }

    else if (temp == 7)
    {
        scanf ("%s", St[j].department);
    }


    else if (temp == 8)
    {
        int a;
        for (int i=0; i<St[j].NSub_current; i++)
            printf ("%d. %s\t%f, %f, %f, %f\n", i+1, St[j].subCurrent[i].name, St[j].subCurrent[i].mark.seventh, St[j].subCurrent[i].mark.twelveth, St[j].subCurrent[i].mark.year_work, St[j].subCurrent[i].mark.final);

        printf ("\n\n\t Subject Select :");
        scanf ("%d", &a);

        printf ("\n\t Enter New Grades :");
        scanf ("%f %f %f %f", &St[j].subCurrent[i].mark.seventh, &St[j].subCurrent[i].mark.twelveth, &St[j].subCurrent[i].mark.year_work, &St[j].subCurrent[i].mark.final);

        getch();
    }

    FILE *f1;
    f1=fopen("c:\\DrHabrouk\\studentData.txt","w");
    printf ("done");
    for (i=0; i<n; i++)
    {
        fprintf (f1,"%s %s %s ", St[i].FN, St[i].MN, St[i].LN);
        fprintf (f1,"%d %d %d %d %d ", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
        fprintf (f1,"%s %s %s ", St[i].address.country, St[i].address.city, St[i].address.district);
        fprintf (f1,"%d ", St[i].nat);
        fprintf (f1,"%s %s ", St[i].email, St[i].department);


        FILE *f2;
        f2=fopen("c:\\DrHabrouk\\currentSubjects.txt","w");
        fprintf (f2, "%d %d ", St[i].id, St[i].NSub_current);
        for (int k=0; k<St[i].NSub_current; k++)
        {
            St[i].subCurrent[k].mark.total = St[i].subCurrent[k].mark.seventh + St[i].subCurrent[k].mark.twelveth + St[i].subCurrent[k].mark.year_work + St[i].subCurrent[k].mark.final;
            fprintf (f2, "%s ", St[i].subCurrent[k].name);
            fprintf (f2, "%d ", St[i].subCurrent[k].ch);
            fprintf (f2, "%f %f %f %f %f\n", St[i].subCurrent[k].mark.seventh, St[i].subCurrent[k].mark.twelveth, St[i].subCurrent[k].mark.year_work, St[i].subCurrent[k].mark.final);

        }

        fprintf (f1,"%f\n", St[i].gpa);
        fclose (f2);
    }

    fclose (f1);
    }

    else
    {
        printf ("Not Found");
        getch ();
    }
}


void delRecord ()
{
    int temp, j, i;
    printf ("Delete record\nEnter Student ID> ");
    scanf ("%d",&temp);

    for (i=0; i<n; i++)
    {
        printf ("%d\n",i);
        if ( temp == St[i].id)
        {
            j=i;
            printf ("\ttest %d\n",j);
        }
    }

    //j=i;
    printf ("j= %d   temp= %d", j, temp);
    if (j<n)
    {
        FILE *f1;
        f1=fopen("c:\\DrHabrouk\\studentData.txt","w");
        printf ("done");
        for (i=0; i<n; i++)
        {
            if (i!=j)
            {
                fprintf (f1,"%s %s %s ", St[i].FN, St[i].MN, St[i].LN);
                fprintf (f1,"%d %d %d %d %d ", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
                fprintf (f1,"%s %s %s ", St[i].address.country, St[i].address.city, St[i].address.district);
                fprintf (f1,"%d ", St[i].nat);
                fprintf (f1,"%s %s ", St[i].email, St[i].department);
                fprintf (f1,"%f\n", St[i].gpa);
            }
        }
        fclose (f1);
    }

    else
    {
        printf ("Not found");
        getch();
    }

}

int main( )
{
    int i=0, t, j;
    int inputData=-1;

    FILE *f, *f1, *f2;

    ///////////////////////////////////////
    ///////////////Read Data///////////////
    f=fopen("c:\\DrHabrouk\\studentData.txt","r");
    f1=fopen("c:\\DrHabrouk\\currentSubjects.txt","r");
    f2=fopen("c:\\DrHabrouk\\subjectsDone.txt","r");

    while (fscanf (f, "%s %s %s", St[i].FN, St[i].MN, St[i].LN) != EOF)
    {
        fscanf (f, "%d %d %d %d %d", &St[i].id, &St[i].date.y, &St[i].date.m, &St[i].date.d, &St[i].age);
        fscanf (f, "%s %s %s", St[i].address.country, St[i].address.city, St[i].address.district);
        fscanf (f, "%d", &St[i].nat);
        fscanf (f, "%s %s", St[i].email, St[i].department);
        fscanf (f, "%f", &St[i].gpa);

        fscanf (f1, "%d %d", &t, &St[i].NSub_current);
        for (int k=0; k<St[i].NSub_current; k++)
        {
            fscanf (f1, "%s", St[i].subCurrent[k].name);
            fscanf (f1, "%d", &St[i].subCurrent[k].ch);
            fscanf (f1, "%f %f %f %f", &St[i].subCurrent[k].mark.seventh, &St[i].subCurrent[k].mark.twelveth, &St[i].subCurrent[k].mark.year_work, &St[i].subCurrent[k].mark.final);
            St[i].subCurrent[k].mark.total = St[i].subCurrent[k].mark.seventh + St[i].subCurrent[k].mark.twelveth + St[i].subCurrent[k].mark.year_work + St[i].subCurrent[k].mark.final;
        }

        fscanf (f2, "%d %d", &t, &St[i].NSub_done);
        for (int k=0; k<St[i].NSub_done; k++)
        {
            fscanf (f2, "%s", St[i].subdone[k].name);
            fscanf (f2, "%d", &St[i].subdone[k].ch);
            fscanf (f2, "%f %f %f %f", &St[i].subdone[k].mark.seventh, &St[i].subdone[k].mark.twelveth, &St[i].subdone[k].mark.year_work, &St[i].subdone[k].mark.final);
            St[i].subdone[k].mark.total = St[i].subdone[k].mark.seventh + St[i].subdone[k].mark.twelveth + St[i].subdone[k].mark.year_work + St[i].subdone[k].mark.final;
        }

        i++;
    }
    n=i;
    fclose (f);
    fclose (f1);
    fclose (f2);


    while (inputData != 0)
    {

        // Menu Data
        system("cls");

        /* Some list of combinations
        0 = Black
        1 = Blue
        2 = Green
        3 = Aqua
        4 = Red
        5 = Purple
        6 = Yellow
        7 = White
        8 = Gray
        9 = Light Blue
        A = Light Green
        B = Light Aqua
        C = Light Red
        D = Light Purple
        E = Light Yellow
        F = Bright White */
        system("COLOR B0");/* This will change the bgcolor F - White and textcolor to 2- Green */

        printf ("Press\n\t");
        printf ("1. Print Subjects\n\t");
        printf ("2. Register new Student\n\t");
        printf ("3. Print Student Records\n\t");
        printf ("4. Search for Student Records\n\t");
        printf ("5. Edit Student Record\n\t");
        printf ("6. Delete Student Record\n\t");
        printf ("0. Exit\n\n\n");

        char fix[1000];
        gets(fix);
        int x=0;
        while(x==0){
        if(strlen(fix)!=1)
        {
         printf("Please ReEnter index:");
         gets(fix);
        }
        else
        x=1;
        }

        inputData=fix[0];



        ///////////////////////////////////////
        if (inputData == 1)
        {
            system("cls");
            subPrint ();
        }

        else if (inputData == 2)
        {
            system("cls");
            regStudent ();
        }

        else if (inputData == 3)
        {
            system("cls");
            studentRecord ();
        }

        else if (inputData == 4)
        {
            system("cls");
            searchRecord ();
        }

        else if (inputData == 5)
        {
            system("cls");
            editRecord ();
        }


        else if (inputData == 6)
        {
            system("cls");
            delRecord ();
        }


       else if (inputData == 9)
        {
            i=0;
            for (i=0; i<n; i++)
            {
                printf ("%s %s %s ", St[i].FN, St[i].MN, St[i].LN);
                printf ("%d %d %d %d %d ", St[i].id, St[i].date.y, St[i].date.m, St[i].date.d, St[i].age);
                printf ("%s %s %s ", St[i].address.country, St[i].address.city, St[i].address.district);
                printf ("%d ", St[i].nat);
                printf ("%s %s ", St[i].email, St[i].department);
                printf ("%f\n", St[i].gpa);

                printf ("Subjets Current\n");
                for (int k=0; k<St[i].NSub_current; k++)
                {
                    printf ("\t* %s ", St[i].subCurrent[k].name);
                    printf ("\t%d ", St[i].subCurrent[k].ch);
                    printf ("\t%f \n", St[i].subCurrent[k].mark.total);
                }

                printf ("Subjets done\n");
                for (int k=0; k<St[i].NSub_done; k++)
                {
                    printf ("\t* %s ", St[i].subdone[k].name);
                    printf ("\t%d ", St[i].subdone[k].ch);
                    printf ("\t%f \n", St[i].subdone[k].mark.total);
                }
                printf ("\n\n");
            }
            getch();
        }


    }

    return 0;
}
