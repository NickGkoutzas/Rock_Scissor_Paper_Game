/*
            < Rock-Scissor-Paper >
                
                CPU vs PLAYER


Nick Gkoutzas (C language)
Greece, July 2020

If you use Linux, it is a good idea to turn off your blinking cursor: setterm -cursor off
You can turn it on again, using : setterm -cursor on


Have fun!

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* CPU_random_choice(char **cpu_array);
int player_input();
int check_hand_in_array(char **array , char *input);
int increase_score(int *score);
void result(int *for_CPU , int *for_player);
void win(char **array , char *player_hand , char *cpu_hand , int *CPU_score , int *player_score);
void delay(int number_of_seconds);
int play_again();

int main(void)
{
    int CPU_score = 0;
    int player_score = 0;

    char *Hands[4] = {"Rock" , "Scissors"  , "Paper"};
    result(&CPU_score , &player_score);

    char cpu_choice[20];
    int number;

    void run_program()
    {
        strcpy(cpu_choice , CPU_random_choice(Hands));  
        int player_hand = player_input();
                                                        

        win(Hands , Hands[player_hand - 1] , cpu_choice , &CPU_score , &player_score);
        printf("\n\n\x1B[33mWait...\x1B[0m\n");
        delay(2000);
        system("clear");
        result(&CPU_score , &player_score);
        printf("\x1B[36mCPU's previous hand:\x1B[0m \x1B[33m%s\x1B[0m\n" , cpu_choice);
        printf("\x1B[36mYour previous hand:\x1B[0m \x1B[33m%s\x1B[0m\n\n" , Hands[player_hand - 1]);
    }


    while(CPU_score <= 10 || player_score <= 10)
    {
        run_program();
        if(CPU_score == 10)
        {
            printf("\n\x1B[32mWinner:\x1B[0m CPU\n\n");
            number = play_again();
            if(number == 1)
            {
                CPU_score = 0;
                player_score = 0;
                delay(500);
                system("clear");
                result(&CPU_score , &player_score);
                run_program();
            }
            else
            {
                system("clear");
                break;
            }
        }
        else if(player_score == 10)
        {
            printf("\n\x1B[32mWinner:\x1B[0m Player\n\n");
            number = play_again();
            if(number == 1)
            {
                CPU_score = 0;
                player_score = 0;
                delay(500);
                system("clear");
                result(&CPU_score , &player_score);
                run_program();
            }
            else
            {
                system("clear");
                break;
            }
        }
    }   
}


int play_again()
{
    printf("==========================================================\n");
    printf("Do you want to play again?\n");
    printf("1: Yes\n2: No");
    printf("\nChoose a number: ");
    int number = 1;
    do
    {
        if(number != 1 && number != 2)
        {
            printf("\x1B[31mInvalid choice...\x1B[0m\nTry again: ");
        }
        scanf("%d" , &number);
    }

    while(number != 1 && number != 2);

    return number;
}




void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
} 





char* CPU_random_choice(char **cpu_array)
{
    srand(time(NULL));
    int i = rand() % 3;
    return cpu_array[i];
}


int player_input()
{
    printf("Choose a number\n");
    printf("---------------\n");
    printf("1:  Rock\n2:  Scissors\n3:  Paper\n\n");
    printf("==========================================================\n");
    printf("\n\nPlayer's turn: ");
    int player_hand = 1;

    do
    {
        if(player_hand < 1 || player_hand > 3)
        {
            printf("\x1B[31mInvalid choice...\x1B[0m\nTry again: ");
        }
        scanf("%d" , &player_hand);
    }

    while(player_hand < 1 || player_hand > 3);

    return player_hand;
}





void result(int *for_CPU , int *for_player)
{
    printf("The player who will reach 10 points first, win the game!!!\n");
    printf("==========================================================\n\n");
    printf("PLAYER  -  CPU\n==============\n");
    printf("   \x1B[33m%d\x1B[0m\t    \x1B[33m%d\x1B[0m\n"  , *for_player , *for_CPU);
    printf("\n");
    printf("==========================================================\n");
    printf("\x1B[32m[Ctrl+c]\x1B[0m \x1B[33mto exit game any time you want.\x1B[0m\n\n\n");
}




int increase_score(int *score)
{
    return (*score)++;
}

        


void win(char **array , char *player_hand , char *cpu_hand , int *CPU_score , int *player_score)
{

    if((strcmp(player_hand , cpu_hand)) == 0)
    {
        printf("\x1B[34mDraw!\x1B[0m");
    }

    else if(strcmp(player_hand , "Rock") == 0 && (strcmp(cpu_hand , "Scissors") == 0 ))
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }

    else if(strcmp(cpu_hand , "Rock") == 0 && (strcmp(player_hand , "Scissors") == 0 ))
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }

    else if(strcmp(player_hand , "Rock") == 0 && strcmp(cpu_hand , "Paper") == 0)
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }

    else if(strcmp(cpu_hand , "Rock") == 0 && strcmp(player_hand , "Paper") == 0)
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }

    else if(strcmp(player_hand , "Scissors") == 0 && strcmp(cpu_hand , "Rock") == 0)
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }

    else if(strcmp(cpu_hand , "Scissors") == 0 && strcmp(player_hand , "Rock") == 0)
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }

    else if(strcmp(player_hand , "Scissors") == 0 && strcmp(cpu_hand , "Paper") == 0)
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }

    else if(strcmp(cpu_hand , "Scissors") == 0 && strcmp(player_hand , "Paper") == 0)
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }

    else if(strcmp(player_hand , "Paper") == 0 && strcmp(cpu_hand , "Scissors") == 0)
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }

    else if(strcmp(cpu_hand , "Paper") == 0 && strcmp(player_hand , "Scissors") == 0)
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }
    
    else if(strcmp(player_hand , "Paper") == 0 && strcmp(cpu_hand , "Rock") == 0)
    {
        printf("\x1B[32mPlayer wins!\x1B[0m");
        increase_score(player_score);
    }

    else if(strcmp(cpu_hand , "Paper") == 0 && strcmp(player_hand , "Rock") == 0)
    {
        printf("\x1B[31mCPU wins!\x1B[0m");
        increase_score(CPU_score);
    }
}
