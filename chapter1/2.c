#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define IS_SAMPLE_COORD(C1,C2) (C1.x == C2.x) && (C1.y == C2.y)? 1: 0

#define WORDLENS 10
#define LISTLENS 4


typedef struct
{
    char str[WORDLENS];
}Word;

typedef struct
{
    int x;
    int y;
}Coord;

typedef struct
{
    Coord start;
    Coord end;
    Word word;
}Result;


typedef enum direction {r, d, rd} Direction;

static const char WordMatrix[4][4] = {
    {'t', 'h', 'i', 's'},
    {'w', 'a', 't', 's'},
    {'o', 'a', 'h', 'g'},
    {'f', 'g', 'd', 't'}
};

static const Word WordList[LISTLENS] = {
    {"this"},
    {"two"},
    {"fat"},
    {"that"}
};

static Coord caul_next_coord(Coord c, Direction dire, int w, int h)
{
    w--;
    h--;
    switch (dire)
    {
        case r:
        {
            if (c.x < w)
                c.x++;
            return c;
        }
        case d:
        {
            if (c.y < h)
                c.y++;
            return c;
        }
        case rd:
        {
            if ((c.x < w) && (c.y < h))
            {
                c.x++;
                c.y++;
            }
            return c;
        }
    }
    
}




// bool is_same_coord(Coord c1, Coord c2)
// {
//     return (c1.x == c2.x) && (c1.y == c2.y) ? true: false;
// }

static int len_str(char * ps)
{
    int l = 0;
    while (*ps != '\0')
    {
        l++;
        ps++;
    }

    return l;
}

static bool is_str_contain_word(char * pstr)
{
    int len = len_str(pstr);
    char tmp_word[WORDLENS];
    for (int i=0; i<len; i++)
    {
        strncpy(tmp_word, pstr, i+1);
        for (int m=0; m<LISTLENS; m++)
        {
            if (strcmp(tmp_word, WordList[m].str) == 0)
                return true;
        }
    }
    
    return false;
}

void get_word(int sx, int sy, int w, int h, Direction direction, Result * pr)
{
    pr->start.x = sx;
    pr->start.y = sy;
    pr->word.str[0] = WordMatrix[sy][sx];
    
    Coord start_coord = {sx, sy};
    Coord pre_coord = start_coord;
    Coord coord;
    int i = 1;
    while (1)
    {
        coord = caul_next_coord(pre_coord, direction, w, h);
        if (IS_SAMPLE_COORD(pre_coord, coord))
            break;
        pre_coord = coord;
        pr->word.str[i] = WordMatrix[coord.y][coord.x];
        i++;
    }
    pr->word.str[i] = '\0';
    pr->end = coord;
}

int main(void)
{
    

    Result result;

    Direction dires[3] = {r, d, rd};

    // for (int i=0; i<3; i++)
    // {
    //     get_word(0, 0, 4, 4, dires[i], &result);

    //     printf("start: (%d, %d) end: (%d, %d) word: %s\n", result.start.x, result.start.y, result.end.x, result.end.y, result.word.str);
        
    // }

    get_word(0, 0, 4, 4, d, &result);

    bool rb = is_str_contain_word(result.word.str);

    printf("%u", rb);
    
    return 0;
}