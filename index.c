#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user
{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phonenumber[50];
};

void takeInput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = '\0'; // remove '\n' from user
}

char generateUsername(char email[50], char username[50])
{
    // abc123@gmail.com
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            username[i] = email[i];
        }
    }
}

void takePassword(char pwd[50])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BCKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}

int main()
{
    system("color 0");
    int option, userfound = 0;
    struct user user;
    char password2[50];
    FILE *fp;
    char username[50], pword[50];
    struct user usr;

    printf("\n\t\t\t\t\t\t\t----------Welcome to Code with Bard-------------");
    printf("\n 1. Signup");
    printf("\n 2. Login");
    printf("\n 3. Exit");

    printf("\n Your choice: ");
    scanf("%d", &option);
    fflush(stdin);

    switch (option)
    {
    case 1:
        system("cls");
        printf("Enter your full name: ");
        takeInput(user.fullname);
        printf("Enter your email: ");
        takeInput(user.email);
        printf("Enter your contact number: ");
        takeInput(user.phonenumber);
        printf("\nEnter your password: ");
        takePassword(user.password);
        printf("\n\tConfirm your password");
        takePassword(password2);
        if (strcmp(user.password, password2))
        {
            printf("\nwrong password! sorry your account hasn't been created\t");
            Beep(750, 300);
        }
        else
        {
            generateUsername(user.email, user.username);
            fp = fopen("users.dat", "a+");
            fwrite(&user, sizeof(struct user), 1, fp);
            if (fwrite != 0)
            {
                system("cls");
                printf("\n\t\t\t\t ---------------------user registered----------------\n");
                printf("Your username is %s", user.username);
            }
            else
            {
                printf("something went wrong");
                fclose(fp);
            }
        }
        break;

    case 2:

        printf("Enter your username \n");
        takeInput(username);
        printf("Enter your password \n");
        takeInput(pword);
        system("cls");

        fp = fopen("users.dat", "rb");
        while (fread(&usr, sizeof(struct user), 1, fp))
        {
            if (!strcmp(usr.username, username))
            {
                if (!strcmp(usr.password, pword))
                {
                    printf("\t\t\t\t\t\t\t----------------welcome to the world of IT Mr. %s--------------", usr.fullname);
                    printf("\n Full name:%s", usr.fullname);
                    printf("\n Email address:%s", usr.email);
                    printf("\n Phone number:%s", usr.phonenumber);
                    printf("\n username:%s", usr.username);
                    printf("\n Full name:%s", usr.fullname);
                }
                else
                {
                    printf("can't find the user?");
                }
                userfound = 1;
            }
        }
    case 3:
        printf("\t\t\t\t --------------- Bye Bye-------------------------");
        return 0;
    default:
        break;
    }

    return 0;
}
