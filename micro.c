#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/utsname.h>
#include <math.h>
#include <signal.h>

#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"
#define BOLD_BLUE "\e[1;34m"

void ticboard(int table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d  ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            if (table[i][j] == 0)
            {
                printf("*   ");
            }
            else if (table[i][j] == 1)
            {
                printf("O   ");
            }
            else if (table[i][j] == 2)
            {
                printf("X   ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void tic_tac_toe()
{
    int board[3][3];
    char move[1000];
    int a = 1;
    int p = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
    }
    while (1)
    {
        printf("To stop playing tic-tac-toe, type: s\n");
        int draw = 9;
        draw = 9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] != 0)
                {
                    draw--;
                }
            }
        }
        if (draw == 0)
        {
            printf("\nIt's a draw!\n\n");
            break;
        }
        printf("\nAvailable moves:\n\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] == 0)
                {
                    if (i == 0)
                        printf("a%d\n", j + 1);
                    else if (i == 1)
                        printf("b%d\n", j + 1);
                    else if (i == 2)
                        printf("c%d\n", j + 1);
                }
            }
        }
        printf("\n");
        printf("   A   B   C\n");
        ticboard(board);
        if (a % 2 != 0)
            p = 1;
        else
            p = 2;
        printf("Player %d move\n", p);
        fgets(move, 1000, stdin);
        if (move[0] == 's')
        {
            break;
        }
        a++;
        switch (move[0])
        {
        case 'a':
        case 'A':
            if (move[1] == '1')
            {
                if (board[0][0] == 0)
                    board[0][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves. A\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][0] == 0)
                    board[1][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][0] == 0)
                    board[2][0] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        case 'b':
        case 'B':
            if (move[1] == '1')
            {
                if (board[0][1] == 0)
                    board[0][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][1] == 0)
                    board[1][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][1] == 0)
                    board[2][1] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        case 'c':
        case 'C':
            if (move[1] == '1')
            {
                if (board[0][2] == 0)
                    board[0][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '2')
            {
                if (board[1][2] == 0)
                    board[1][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else if (move[1] == '3')
            {
                if (board[2][2] == 0)
                    board[2][2] = p;
                else
                {
                    printf("Unavailable move, please choose one of available moves.\n");
                    a--;
                }
            }
            else
            {
                printf("Unavailable move, please choose one of available moves.\n");
                a--;
            }
            break;
        default:
            printf("Unavailable move, please choose one of available moves.\n");
            a--;
            break;
        }
        if ((draw != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][1] != 0) || (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][1] != 0) || (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][1] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
        else if ((draw != 0 && board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[1][0] != 0) || (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[1][1] != 0) || (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
        else if ((draw != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0) || (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != 0))
        {
            ticboard(board);
            printf("Player %d wins!\n", p);
            break;
        }
    }
}
void sysinfo()
{
    struct utsname uts;
    uname(&uts);
    printf("Operating system name: %s\n", uts.sysname);
    printf("Operating system distribution: %s\n", uts.nodename);
    printf("Current release of system: %s\n", uts.release);
    printf("Current version of system: %s\n", uts.version);
    printf("Machine version: %s\n", uts.machine);
    time_t current_time = time(NULL);
    printf("The current Unix time (in ms from 01-01-1970): %ld\n", current_time);
}

void calendar(int year) // inspired: https://www.codingunit.com/how-to-make-a-calendar-in-c
{
    if (year < 1000)
    {
        printf("Please select a year greater than 999\n");
        return;
    }
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {" ", "\nJanuary", "\n\nFebruary", "\n\nMarch", "\n\nApril", "\n\nMay", "\n\nJune", "\n\nJuly", "\n\nAugust", "\n\nSeptember", "\n\nOctober", "\n\nNovember", "\n\nDecember"};
    int first_day, par1, par2, par3;
    par1 = (year - 1.0) / 4.0;
    par2 = (year - 1.0) / 100.0;
    par3 = (year - 1.0) / 400.0;
    first_day = (year + par1 - par2 + par3) % 7;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        days_in_month[2] = 29;
    for (int i = 1; i <= 12; i++)
    {
        printf("%s", months[i]);
        printf("\n\nSun   Mon   Tue   Wed   Thu   Fri   Sat\n");
        if (first_day == 6)
            printf("      ");
        else if (first_day == 5)
            printf("     ");
        else if (first_day == 4)
            printf("    ");
        else if (first_day == 3)
            printf("   ");
        else if (first_day == 2)
            printf("  ");
        else if (first_day == 1)
            printf(" ");
        for (int j = 1; j <= 1 + first_day * 5; j++)
            printf(" ");
        for (int j = 1; j <= days_in_month[i]; j++)
        {
            printf("%2d", j);
            if ((j + first_day) % 7 > 0)
                printf("    ");
            else
                printf("\n ");
        }
        first_day = (first_day + days_in_month[i]) % 7;
    }
}

void morseInterpreter(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        switch (str[i])
        {
        case 'A':
        case 'a':
            printf(".- ");
            break;
        case 'B':
        case 'b':
            printf("-... ");
            break;
        case 'C':
        case 'c':
            printf("-.-. ");
            break;
        case 'D':
        case 'd':
            printf("-.. ");
            break;
        case 'E':
        case 'e':
            printf(". ");
            break;
        case 'F':
        case 'f':
            printf("..-. ");
            break;
        case 'G':
        case 'g':
            printf("--. ");
            break;
        case 'H':
        case 'h':
            printf(".... ");
            break;
        case 'I':
        case 'i':
            printf(".. ");
            break;
        case 'J':
        case 'j':
            printf(".--- ");
            break;
        case 'K':
        case 'k':
            printf("-.- ");
            break;
        case 'L':
        case 'l':
            printf(".-.. ");
            break;
        case 'M':
        case 'm':
            printf("-- ");
            break;
        case 'N':
        case 'n':
            printf("-. ");
            break;
        case 'O':
        case 'o':
            printf("--- ");
            break;
        case 'P':
        case 'p':
            printf(".--. ");
            break;
        case 'Q':
        case 'q':
            printf("--.- ");
            break;
        case 'R':
        case 'r':
            printf(".-. ");
            break;
        case 'S':
        case 's':
            printf("... ");
            break;
        case 'T':
        case 't':
            printf("- ");
            break;
        case 'U':
        case 'u':
            printf(" ..-");
            break;
        case 'V':
        case 'v':
            printf("...- ");
            break;
        case 'W':
        case 'w':
            printf(".-- ");
            break;
        case 'X':
        case 'x':
            printf("-..- ");
            break;
        case 'Y':
        case 'y':
            printf("-.-- ");
            break;
        case 'Z':
        case 'z':
            printf("--.. ");
            break;
        case '1':
            printf(".---- ");
            break;
        case '2':
            printf("..--- ");
            break;
        case '3':
            printf("...-- ");
            break;
        case '4':
            printf("....- ");
            break;
        case '5':
            printf("..... ");
            break;
        case '6':
            printf("-.... ");
            break;
        case '7':
            printf("--... ");
            break;
        case '8':
            printf("---.. ");
            break;
        case '9':
            printf("----. ");
            break;
        case '0':
            printf("----- ");
            break;
        default:
            printf("error - unknown sign. Please use only letters or numbers\n");
            break;
        }
    }
}

void basic_commands(char **str)
{
    switch (str[0][0])
    {
    case 'p':
        printf("%s\n", getcwd(NULL, 0));
        break;
    case 'e':
        exit(0);
    case 'c':
        if (strcmp(str[1], "~") == 0)
        {
            chdir(getenv("HOME"));
        }
        else{
        int new_path = chdir(str[1]);
	if(new_path == -1){
		printf("cd: no such file or directory: %s\n",str[1]);
		}
	}
        break;
    case 'h':
        printf("         ┌─┐┬ ┬┌┬┐┬ ┬┌─┐┬─┐\n");
        printf("         ├─┤│ │ │ ├─┤│ │├┬┘'\n");
        printf("         ┴ ┴└─┘ ┴ ┴ ┴└─┘┴└─'\n");
        printf("╔═╗┌─┐┬ ┬┌┬┐┌─┐┌┐┌   ╦┌─┐┌─┐┬ ┬┬┌─┐┬┌─\n");
        printf("╚═╗┌─┘└┬┘││││ ││││   ║│ │┌─┘││││├─┤├┴┐\n");
        printf("╚═╝└─┘ ┴ ┴ ┴└─┘┘└┘  ╚╝└─┘└─┘└┴┘┴┴ ┴┴ ┴\n");
        printf(">>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<\n\n");
        printf("AVAILABLE COMMANDS:\n1. ctc <color> - change text color (write \"ctc help\" - to show available ctc commands)\n");
        printf("2. cd <path> -change directory\n3. pwd - print working directory\n4. morse <text> - convert any text (only letters and numbers) to morse code\n");
        printf("5. history - show commands history\n6. calendar <year> - show input year callendar (year must be greater than 999)\n7. date - show current date\n8. sysinfo - show informations about your system\n");
        printf("9. tic-tac-toe - play tic tac toe game\n\nYou can also use commands that refer by name to programs located in directories described\nby the value of the PATH environment variable.\n\n");
        break;
    }
}

void text_color(char **str, char *ctc)
{
    if (strcmp(str[1], "reset") == 0)
    {
        for (int i = 0; i < strlen(WHITE); i++)
            ctc[i] = WHITE[i];
    }
    else if (strcmp(str[1], "black") == 0)
    {
        for (int i = 0; i < strlen(BLACK); i++)
            ctc[i] = BLACK[i];
    }
    else if (strcmp(str[1], "red") == 0)
    {
        for (int i = 0; i < strlen(RED); i++)
            ctc[i] = RED[i];
    }
    else if (strcmp(str[1], "yellow") == 0)
    {
        for (int i = 0; i < strlen(YELLOW); i++)
            ctc[i] = YELLOW[i];
    }
    else if (strcmp(str[1], "blue") == 0)
    {
        for (int i = 0; i < strlen(BLUE); i++)
            ctc[i] = BLUE[i];
    }
    else if (strcmp(str[1], "magenta") == 0)
    {
        for (int i = 0; i < strlen(MAGENTA); i++)
            ctc[i] = MAGENTA[i];
    }
    else if (strcmp(str[1], "cyan") == 0)
    {
        for (int i = 0; i < strlen(CYAN); i++)
            ctc[i] = CYAN[i];
    }
    else if (strcmp(str[1], "green") == 0)
    {
        for (int i = 0; i < strlen(GREEN); i++)
            ctc[i] = GREEN[i];
    }
    else if (strcmp(str[1], "help") == 0)
        printf("%sAvailable commands:\nctc reset - basic text\nctc black -%s basic text\n%sctc blue - %sbasic text\n%sctc red - %sbasic text\n%sctc yellow - %sbasic text\n%sctc green - %sbasic text\n%sctc cyan - %sbasic text\n%sctc magenta - %sbasic text\n%s", WHITE, BLACK, WHITE, BLUE, WHITE, RED, WHITE, YELLOW, WHITE, GREEN, WHITE, CYAN, WHITE, MAGENTA, ctc);
    else
        printf("error - unknown command. To look at available commands use \"ctc help\" \n");
}
void sigint_ctrl_c(int signumber) {
   signal(SIGINT, sigint_ctrl_c);
   fflush(stdout);
}
int main()
{
    printf("%s\n\n", WHITE);
    printf("UUUUUUUU          UUUUUUUU           AAA               MMMMMMMM               MMMMMMMM\n");
    printf("U::::::U          U::::::U          A:::A              M:::::::M             M:::::::M\n");
    printf("U::::::U          U::::::U         A:::::A             M::::::::M           M::::::::M\n");
    printf("UU:::::U          U:::::UU        A:::::::A            M:::::::::M         M:::::::::M\n");
    printf(" U:::::U          U:::::U        A:::::::::A           M::::::::::M       M::::::::::M\n");
    printf(" U:::::D          D:::::U       A:::::A:::::A          M:::::::::::M     M:::::::::::M\n");
    printf(" U:::::D          D:::::U      A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M\n");
    printf(" U:::::D          D:::::U     A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M\n");
    printf(" U:::::D          D:::::U    A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M\n");
    printf(" U:::::D          D:::::U   A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M\n");
    printf(" U:::::D          D:::::U  A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M\n");
    printf(" U::::::U        U::::::U A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M\n");
    printf(" U:::::::UUUUUUUU:::::::UA:::::A             A:::::A   M::::::M               M::::::M\n");
    printf("  UU::::::::::::::::::UUA:::::A               A:::::A  M::::::M               M::::::M\n");
    printf("    UU::::::::::::::UU A:::::A                 A:::::A M::::::M               M::::::M\n");
    printf("      UUUUUUUUUUUUUU  AAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMM\n\n%s", BLUE);
    printf("                       $$   $$   $$  $$$$$$ $$$$   $$\n");
    printf("                       $$   $$   $$  $$   $$   $$  $$\n");
    printf("                       $$   $$   $$  $$   $$   $$  $$\n");
    printf("                       $$   $$   $$  $$   $$   $$  $$\n");
    printf("                        $$$$$/$$$$   $$   $$   $$  $$\n%s", GREEN);
    printf("                $$                                         $$                  $$  $$\n");
    printf("                                                           $$                  $$  $$ \n");
    printf("  $$$$$$ $$$$   $$   $$$$$$$   $$$$$$   $$$$$$    $$$$$$$  $$$$$$$    $$$$$$   $$  $$ \n");
    printf("  $$   $$   $$  $$  $$        $$    $$ $$    $$  $$        $$    $$  $$    $$  $$  $$ \n");
    printf("  $$   $$   $$  $$  $$        $$       $$    $$   $$$$$$   $$    $$  $$$$$$$$  $$  $$ \n");
    printf("  $$   $$   $$  $$  $$        $$       $$    $$        $$  $$    $$  $$        $$  $$ \n");
    printf("  $$   $$   $$  $$   $$$$$$$  $$        $$$$$$   $$$$$$$   $$    $$   $$$$$$$  $$  $$\n%s", MAGENTA);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%s", WHITE);
    char ctc[15];
    for (int i = 0; i < strlen(WHITE); i++)
    {
        ctc[i] = WHITE[i];
        ctc[i + 1] = 0;
    }
    int his = 0;
    char history[1000][1000];
    char string[100];
    char date[1000][100];
    int dates = 0;
    char directories[1000][100];
    int dir = 0;
    while (true)
    {
        char *path = getcwd(NULL, 0);
        sprintf(directories[dir], "%s", path);
        dir++;
        printf("%s%s%s:~%s%s$ %s", MAGENTA, getlogin(), BOLD_BLUE, path, YELLOW, ctc);
        free(path);
        char str[1000];
        char dziel[] = " \n\t";
        char *schowek;
        char **arg = malloc(1000 * sizeof(char *));
        for (int i = 0; i < 1000; i++)
            arg[i] = malloc(1000 * sizeof(char));
        signal(SIGINT, sigint_ctrl_c);
        fgets(str, 1000, stdin);
        time_t actual_date = time(NULL);
        sprintf(string, "%s", ctime(&actual_date));
        sprintf(date[dates], "%s", string);
        dates++;
        for (int i = 0; i < strlen(str); i++)
        {
            history[his][i] = str[i];
        }
        his++;
        schowek = strtok(str, dziel);
        int z = 0;
        while (schowek != NULL)
        {
            for (int i = 0; i < strlen(schowek); i++)
            {
                arg[z][i] = schowek[i];
                arg[z][i + 1] = 0;
            }
            schowek = strtok(NULL, dziel);
            z++;
        }
        arg[z] = 0;
        if (z == 0)
        {
            wait(0);
        }
        else if (strcmp(arg[0], "morse") == 0)
        {
            for (int i = 1; i < z; i++)
            {
                morseInterpreter(arg[i]);
                printf("    ");
            }
            printf("\nEach letter is separated by a space, each word by a tabulator.\n");
        }
        else if (strcmp(arg[0], "sysinfo") == 0)
            sysinfo();
        else if (strcmp(arg[0], "calendar") == 0)
        {
            if (arg[1] == 0)
            {
                printf("Please write an argument. For example: year 2023\n");
            }
            else
            {
                printf("\nYear %s calendar\n\n", arg[1]);
                int year = atoi(arg[1]);
                calendar(year);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }
        else if (strcmp(arg[0], "pwd") == 0 || strcmp(arg[0], "cd") == 0 || strcmp(arg[0], "help") == 0 || strcmp(arg[0], "exit") == 0)
        {
            if (strcmp(arg[0], "cd") == 0 && strcmp(arg[1], "-") == 0 && dir > 1)
                chdir(directories[dir - 2]);
            basic_commands(arg);
        }
        else if (strcmp(arg[0], "ctc") == 0)
        {
            if (arg[1] == 0)
            {
                printf("Please write an argument. For example: ctc red\n");
            }
            else
                text_color(arg, ctc);
        }
        else if (strcmp(arg[0], "date") == 0)
        {
            time_t actual_date = time(NULL);
            printf("Current date is: %s\n", ctime(&actual_date));
        }
        else if (strcmp(arg[0], "history") == 0)
        {
            for (int i = 0; i < his; i++)
            {
                printf("%d. ", i + 1);
                for (int j = 0; j < strlen(history[i]); j++)
                    printf("%c", history[i][j]);
                printf("%s\n", date[i]);
            }
            printf("\n");
        }
        else if (strcmp(arg[0], "tic-tac-toe") == 0)
        {
            tic_tac_toe();
        }
        else
        {
            pid_t child_pid;
            child_pid = fork();
            if (child_pid == 0)
            {
                execvp(arg[0], arg);
                printf("error number: %d\nUnknown command. To look at available commands write \"help\". \n", errno);
                exit(0);
            }
            else
                wait(0);
        }
        for (int i = 0; i < 1000; i++)
            free(arg[i]);
        free(arg);
    }
    return 0;
}
