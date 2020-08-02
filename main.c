#include <stdio.h>
#include <string.h>
 
typedef struct Person {
    int  person_id;
    char name[50];
    int age;
    char gender[2];
    long int phone_number;
    char blood_group[5];
} Record;

Record persons[300];
int no_of_datas=0;

int search_person(int person_id);
void display_person(int person_id);
void add_person();
void edit_person(int person_id);
void delete_person(int person_id);
void display_all();
void display_message(char message[10]);
void run_system();

//Function to write all data in file at the end of the program

void write_to_file()
{
    FILE *fp;
    fp = fopen ("datas.txt", "w");
    for(int current_data=0;current_data<=no_of_datas;current_data++)
    {
        fprintf(fp, "ID\t\t: %d\n",persons[current_data].person_id);
        fprintf(fp, "Name\t\t: %s\n",persons[current_data].name);
        fprintf(fp, "Age\t\t: %d\n",persons[current_data].age);
        fprintf(fp, "Gender\t\t: %s\n",persons[current_data].gender);
        fprintf(fp, "Phone Number\t\t: %ld\n",persons[current_data].phone_number);
        fprintf(fp, "Blood Group\t\t: %s\n",persons[current_data].blood_group);
        fprintf(fp, "-----------------------------------------------\n");
    }
    fclose (fp);
}

//Function to check credentials , default username= admin and default password = admin123

int check_credentials(char username[10],char password[10])
{
    int check=0;
    if(strcmp(username,"admin")==0)
    { 
        if(strcmp(password,"admin123")==0)
        { 
             check=1;
        }
        else
        { 
            printf("\nwrong password"); 
        } 
    }
    else
    { 
        printf("\nUser doesn't exist"); 
    } 

    return check;
}

//Main Function

int main()
{
    char password[10], username[10], ch;
    int i;
    printf("Enter User name: ");
    gets(username);
    printf("Enter the password < any 8 characters>: ");
    for (i = 0; i < 8; i++)
    {
        ch = getchar();
        password[i] = ch;
        ch = '*' ;
        printf("%c", ch);
    }
    password[i] = '\0';

    if(check_credentials(username,password)==1)
    {
        run_system();    
    }
    return 0;
}

//Main system after user is authenticated

void run_system()
{
    int choice;
    int givenPersonId;
    do
    {
        printf("-----------Please choose the option-----------\n\n");
        printf("1 to Add Person\n");
        printf("2 to Edit Person\n");
        printf("3 to Display Person Data\n");
        printf("4 to Delete Person\n");
        printf("5 to Display All Data\n");
        printf("6 to Exit\n");
        printf("-----------------------------------------------\n==>");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                add_person();
                break;

            case 2:
                printf("Enter Person ID of person to edit\n");
                scanf("%d",&givenPersonId);
                edit_person(givenPersonId);
                break;

            case 3:
                printf("Enter Person ID of person to search\n");
                scanf("%d",&givenPersonId);
                display_person(givenPersonId);
                break;

            case 4:
                printf("Enter Person ID of person to delete\n");
                scanf("%d",&givenPersonId);
                delete_person(givenPersonId);
                break;

            case 5:
                display_all();
                choice=6;
                break;

            default:
                break;
        }

    } while (choice!=6);

    write_to_file();
}

//Simple function to display message such as added , edited data 

void display_message(char message[10])
{
    printf("------------------------------\n");
    printf("Data %s Successfully\n",message);
    printf("------------------------------\n");
}

//Search the person with id and returns the person position in array

int search_person(int person_id)
{
    int selected_person_id;
    for(int j=0;j<=no_of_datas;j++)
    {
        if(persons[j].person_id==person_id)
        {
            selected_person_id=j;
        }
    }
    return selected_person_id;
}

// CURD Operations

void display_all() {
    printf("------------------------------\n");
    for(int current_data=0;current_data<no_of_datas;current_data++)
    {
        Record selected_person=persons[current_data];
        printf( "Person Name : %s\n", selected_person.name);
        printf( "%s's Age : %d\n",selected_person.name,selected_person.age);
        printf( "%s's Gender : %s\n",selected_person.name,selected_person.gender);
        printf( "%s's Phone Number : %ld\n",selected_person.name,selected_person.phone_number);
        printf( "%s's Blood Group : %s\n",selected_person.name,selected_person.blood_group);
        printf("------------------------------\n");
    }
}

void display_person(int person_id ) {
    Record selected_person=persons[search_person(person_id)];
    printf("------------------------------\n");
    printf( "Person Name : %s\n", selected_person.name);
    printf( "%s's Age : %d\n",selected_person.name,selected_person.age);
    printf( "%s's Gender : %s\n",selected_person.name,selected_person.gender);
    printf( "%s's Phone Number : %ld\n",selected_person.name,selected_person.phone_number);
    printf( "%s's Blood Group : %s\n",selected_person.name,selected_person.blood_group);
    printf("------------------------------\n");
}

void add_person()
{
    printf("Enter person id:\n");
    scanf("%d", &persons[no_of_datas].person_id);    

    printf("Enter the name of the person:\n");     
    scanf("%s", persons[no_of_datas].name);

    printf("Gender (M/F/O) :\n");
    scanf("%s", persons[no_of_datas].gender);
    
    printf("Enter age of %s :\n",persons[no_of_datas].name);
    scanf("%d", &persons[no_of_datas].age);

    printf("Enter contact number of %s :\n",persons[no_of_datas].name);
    scanf("%ld", &persons[no_of_datas].phone_number);

    printf("Enter blood group of %s :\n",persons[no_of_datas].name);
    scanf("%s", persons[no_of_datas].blood_group);

    no_of_datas++;
    display_message("Added");
}

void edit_person(int person_id)
{
    Record selected_person=persons[search_person(person_id)];

    printf("You are editing %s\n",selected_person.name );
    printf("------------------------------\n");
    printf("Enter the name of the person:\n");     
    scanf("%s", selected_person.name);

    printf("Enter age of %s :\n",selected_person.name);
    scanf("%d", &selected_person.age);

    printf("Enter contact number of %s :\n",selected_person.name);
    scanf("%ld", &selected_person.phone_number);

    printf("Enter blood group of %s :\n",selected_person.name);
    scanf("%s", selected_person.blood_group);

    persons[search_person(person_id)]=selected_person;
    display_message("Edited");
}

void delete_person(int person_id)
{
    Record selected_person=persons[0];
    int i=0;
    for(int j=0;j<=no_of_datas;j++)
    {
        if(persons[j].person_id==person_id)
        {
            i=j+1;
        }
    }
    while (i<=no_of_datas){
        persons[i-1]=persons[i];
        i++;
    }
    no_of_datas--;
    display_message("Deleted");
}