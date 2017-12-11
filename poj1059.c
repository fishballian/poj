#include<stdio.h>
#include<string.h>
int dice[1001];
int jump[101];
int turn[101];
int player[6][2];

int main()
{
#ifdef _POJ
    freopen("poj1059.txt", "r", stdin);
#endif
    int n = 0;
    int player_num, a, b, current_die, current_player, grid;
    while(scanf("%d", &dice[n]) && dice[n] > 0) {n++;}
    while(scanf("%d", &player_num) && player_num > 0)
    {
        memset(jump, 0, sizeof(jump));
        memset(turn, 0, sizeof(turn));
        memset(player, 0, sizeof(player));
        while(scanf("%d%d", &a, &b) && a > 0)
        {
            jump[a] = b;
        }
        while(scanf("%d", &a) && a != 0)
        {
            if(a < 0)
                turn[-a - 1] = -1;
            else
                turn[a - 1] = 1;
        }

        current_die = 0;
        current_player = 0;
        while(current_die < n)
        {
            if(player[current_player][1] == 1)
            {
                player[current_player][1] = 0;
                current_player = (current_player + 1) % player_num;
                continue;
            } // skip

            grid = player[current_player][0] + dice[current_die++];
            if(grid <= 100)
            {

                if(jump[grid] > 0)
                    player[current_player][0] = jump[grid]; 
                else
                    player[current_player][0] = grid;

                if(turn[grid] == 1)
                    continue; //more one round
                if(turn[grid] == -1)
                    player[current_player][1] = 1; // stop one round


                if(player[current_player][0] == 100)
                {
                    printf("%d\n", current_player + 1);
                    break;
                }
            }
            current_player = (current_player + 1) % player_num;
        }
    }

    return 0;
}

