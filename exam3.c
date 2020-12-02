/* Thomas Krogh Lohse
 * tlohse20@student.aau.dk
 * Gruppe A.306
 * Datalogi
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TEAMS_COUNT 14


typedef struct team {
    int points, goals[2];
    char name[4];
} Team;

typedef struct match {
    char day[4], date[6], time[6], teams[2][4];
    int spectators, result[2];
} Match;


void scan_matches(FILE*, Match*, int);
void calculate_score(Match*, int);
void print_score(Team*);
int get_team(char*);
int cmp(const void*, const void*);

/* To-DO
 *  Comment
 *  COMMENT
 *  cmp
 *  get_team rename
 */

int main(void) {
    const int numOfMatches = 182;
    int n;
    FILE *file = fopen("./kampe-2019-2020.txt", "r");
    Match matches[numOfMatches];
    scan_matches(file, matches, numOfMatches);
    fclose(file);

    do {
        printf("Input the amount of matches you want to see the scoreboard for (Max is %d): ", numOfMatches); /* Re-formulate */
        scanf(" %d", &n);
    } while (n < 1 || n > numOfMatches);

    calculate_score(matches, n);

    return 0;
}

/* Scans 'n' matches, and saves it in an array */
void scan_matches(FILE *file, Match* matches, int n) {
    int i = 0;
    char *line = malloc(100); 
    while (i < n) {
        fgets(line, 100, file);
        sscanf(line, "%s %s %s %s %*c %s %d %*c %d %d", matches[i].day, matches[i].date, matches[i].time,
                                                        matches[i].teams[0], matches[i].teams[1], &(matches[i].result[0]),
                                                        &(matches[i].result[1]), &(matches[i].spectators));
        i++;
    } 
    free(line);
}

void calculate_score(Match* matches, int n) {
    Team teams[TEAMS_COUNT] = {0};
    int i = 0;
    
    /* Sets up the names for the teams */
    for (; i < TEAMS_COUNT/2; i++) {
        /* Uses 'get_team'-function to insert every name of every team into the array
         * Since every match has 2 teams, we can get every teams name after TEAMS_COUNT/2
         */
        int index1 = get_team(matches[i].teams[0]),
            index2 = get_team(matches[i].teams[1]); 
        strcpy(teams[index1].name, matches[i].teams[0]);
        strcpy(teams[index2].name, matches[i].teams[1]);
    }

    /* The loop that counts points, and goals for n number of matches */
    for (i = 0; i < n; i++) {
        int team1 = get_team(matches[i].teams[0]),
            team2 = get_team(matches[i].teams[1]); 

        /* Saves the amount of goals scored by each team */
        teams[team1].goals[0] += matches[i].result[0];
        teams[team2].goals[0] += matches[i].result[1];

        /* Saves the amount of goals scored against each team */
        teams[team1].goals[1] += matches[i].result[1];
        teams[team2].goals[1] += matches[i].result[0];

        /* Tied - Give both a point */
        if (matches[i].result[0] == matches[i].result[1]) {
            teams[team1].points += 1;
            teams[team2].points += 1; 
        }
        /* If team 1 won, they get 3 points */
        else if (matches[i].result[0] > matches[i].result[1])
            teams[team1].points += 3;
        /* If none of the other conditions were made, it means that team 2 won, and they get 3 points */
        else
            teams[team2].points += 3;

    }
    
    /* Sorts the array, and then prints it */
    qsort(teams, TEAMS_COUNT, sizeof(Team), cmp);
    print_score(teams);
}

void print_score(Team* teams) {
    int i = 0;
    for (; i < TEAMS_COUNT; i++) {
        printf("%-3s\t%d\t%d - %d\n", teams[i].name, teams[i].points, teams[i].goals[0], teams[i].goals[1]);
    }
}

/* Function that finds the index of a team based on their name
 * It goes through a static string-array 'count'-times, and if it doesn't find a matching name, it adds it and counts 'count' 1 up
 * An other way to to tis could have been with a dynamic array/list, where i still go through the whole array, but if I don't find it,
 * I add another element to the array/list. I chose not to, since a dynamic array/list is more useful when you don't know the size
 * of the array, but I do here, so I have deemed it not necessary.
 */
int get_team(char name[4]) {
    int i = 0;
    static int count = 0;
    static char names[TEAMS_COUNT][4];
    
    for (; i <= count; i++) {
        if (strcmp(name, names[i]) == 0)
            return i;
    }
    strcpy(names[count], name); 
    count++;
    return count-1;
}

/* My compare-function for qsort
 * It takes the parameters, and turns them into the right type.
 * Since it is supposed to sort by primarily points, secondarily goals, it stats with checking if the pointsof each team is the same.
 * If it is, it will return the goal-difference, and if not it will return the point-difference
 */
int cmp(const void* a, const void* b) {
    Team *TeamA = (Team*) a;
    Team *TeamB = (Team*) b;

    if (TeamB->points == TeamA->points)
        return (TeamB->goals[0]-TeamB->goals[1]) - (TeamA->goals[0]-TeamA->goals[1]);
 
    else
        return TeamB->points - TeamA->points;
}

