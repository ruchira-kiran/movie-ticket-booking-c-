#include <stdio.h>

struct movie
{
    int movie_id;
    char movie_name[50];
    char language[50];
    int duration;
    char genre[50];
    int available_seats;
    int booked_seats;
    int total_seats;
    char seatlayout[5][5];
    int isActive;
};

struct movie mov[10];
int moviecount = 0;

void mainmenu();
void ownermenu();
void customermenu();
void addmovie();
void initializeseats(int index);

int main()
{
    mainmenu();
    return 0;
}

void mainmenu()
{
    int choice = 0;

    while (choice != 3)
    {
        printf("\n=====================================\n");
        printf("             MAIN MENU\n");
        printf("=====================================\n");
        printf("1. Theatre Owner\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                ownermenu();
                break;

            case 2:
                customermenu();
                break;

            case 3:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}

void ownermenu()
{
    int choice = 0;

    while (choice != 2)
    {
        printf("\n=====================================\n");
        printf("             OWNER PANEL\n");
        printf("=====================================\n");
        printf("1. Add Movie\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addmovie();
                break;

            case 2:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}

void customermenu()
{
    printf("\nCustomer menu coming soon...\n");
}

void addmovie()
{
    if (moviecount >= 10)
    {
        printf("Movie list is full\n");
        return;
    }

    mov[moviecount].movie_id = moviecount + 1;

    printf("Enter movie name: ");
    scanf(" %49[^\n]", mov[moviecount].movie_name);

    printf("Enter movie language: ");
    scanf(" %49[^\n]", mov[moviecount].language);

    printf("Enter duration of movie (in minutes): ");
    scanf("%d", &mov[moviecount].duration);

    printf("Enter genre: ");
    scanf(" %49[^\n]", mov[moviecount].genre);

    mov[moviecount].isActive = 1;

    mov[moviecount].total_seats = 25;
    mov[moviecount].booked_seats = 0;
    mov[moviecount].available_seats = 25;

    initializeseats(moviecount);

    moviecount++;

    printf("Movie added successfully!\n");
}

void initializeseats(int index)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mov[index].seatlayout[i][j] = 'O';
        }
    }
}