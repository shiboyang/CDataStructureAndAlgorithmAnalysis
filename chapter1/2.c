#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define IS_SAMPLE_COORD(C1,C2) (C1.x == C2.x) && (C1.y == C2.y)? 1: 0
#define WORDLENS 10
#define LISTLENS 5
#define W 4
#define H 5


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

typedef struct 
{
    Coord list[W*H];
    int count;
}CoordSet;

typedef enum direction {r, d, rd, ru} Direction;

static const char WordMatrix[H][W] = {
    {'t', 'h', 'i', 's'},
    {'w', 'a', 't', 's'},
    {'o', 'a', 'h', 'g'},
    {'f', 'g', 'd', 't'},
    {'a', 'b', 'c', 'd'},
};

static const Word WordList[LISTLENS] = {
    {"this"},
    {"two"},
    {"fat"},
    {"that"},
    {"at"}
};

static int len_str(char * ps);
static Result reverse_coord(Result r);
static Coord caul_next_coord(Coord c, Direction dire, int w, int h);
static bool is_str_contain_word(char * pstr, char * pret_str);
void get_content(int sx, int sy, int w, int h, Direction direction, Result * pr);
static void show_result(Result r);
static void can_down_direction_coord(CoordSet * p_coord_set, int h, int w);

static void can_right_direction_coord(CoordSet * p_coord_set, int h, int w);
static void can_rd_direction_coord(CoordSet * p_coord_set, int h, int w);
static void can_ru_direction_coord(CoordSet * p_coord_set, int h, int w);
static void show_corrd_set(CoordSet coord_set);

static void show_finded_result(Result r);
static void find_word(CoordSet * pcoord_set, Direction dircetion);



int main(void)
{
    Result result;

    CoordSet 
    down_coord_set,
    right_coord_set,
    rd_coord_set,
    ru_coord_set;
    down_coord_set.count = 0;
    right_coord_set.count = 0;
    rd_coord_set.count = 0;
    ru_coord_set.count = 0;

    char tmp_word[WORDLENS];

    can_down_direction_coord(&down_coord_set, H, W);
    puts("The could down direction coord set: ");
    show_corrd_set(down_coord_set);
    find_word(&down_coord_set, d);

    
    can_right_direction_coord(&right_coord_set, H, W);
    puts("The could right direction coord set: ");
    show_corrd_set(right_coord_set);
    find_word(&right_coord_set, r);


    can_rd_direction_coord(&rd_coord_set, H, W);
    puts("Right down");
    show_corrd_set(rd_coord_set);
    find_word(&rd_coord_set, rd);

    can_ru_direction_coord(&ru_coord_set, H, W);
    puts("Right up");
    show_corrd_set(ru_coord_set);
    find_word(&ru_coord_set, ru);
    return 0;
}


static void find_word(CoordSet * pcoord_set, Direction dircetion)
{
    Result result;
    char tmp_str[WORDLENS];

    for (int i=0; i<pcoord_set->count; i++)
    {
        get_content(
            pcoord_set->list[i].x,
            pcoord_set->list[i].y,
            W,
            H,
            dircetion,
            &result
        );
        // printf("%s\n", result.word.str);
        if (is_str_contain_word(result.word.str, tmp_str))
        {
            printf("Fined word %s\n", tmp_str);
            show_finded_result(result);
        }
        result = reverse_coord(result);
        if (is_str_contain_word(result.word.str, tmp_str))
        {
            printf("Fined word %s\n", tmp_str);
            show_finded_result(result);
        }
    }
}


static bool is_str_contain_word(char * pstr, char * pret_str)
{
    char tmp_word[WORDLENS];
    char * find_char;
    char word[WORDLENS];

    for (int i=0; i<LISTLENS; i++)
    {
        strcpy(word, WordList[i].str);
        find_char = strchr(pstr, word[0]);
        if (find_char == NULL)
            continue;
        if (strncmp(find_char, word, len_str(word))==0)
        {
            strcpy(pret_str, word);
            return true;
        }
    }

    return false;
}

void get_content(int sx, int sy, int w, int h, Direction direction, Result * pr)
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

static Result reverse_coord(Result r)
{
    Result ret;
    ret.start = r.end;
    ret.end = r.start;
    Word nw;
    int len = len_str(r.word.str);
    for(int i=len-1; i>=0; i--)
    {
        nw.str[len-1-i] = r.word.str[i];
    }
    nw.str[len] = '\0';
    ret.word = nw;

    return ret;
}


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
        case ru:
        {
            if ((c.x < w) && (c.y>0))
            {
                c.x++;
                c.y--;
            }
            return c;
        }
    }
    
}


static void show_result(Result r)
{
    printf("%s, (%d, %d), (%d, %d)\n", r.word.str, r.start.x, r.start.y, r.end.x, r.end.y);
}


static void can_down_direction_coord(CoordSet * p_coord_set, int h, int w)
{
    for (int i=0; i<w; i++)
    {
        p_coord_set->list[p_coord_set->count].x = i;
        p_coord_set->list[p_coord_set->count].y = 0;
        p_coord_set->count++;
    }
}

static void can_right_direction_coord(CoordSet * p_coord_set, int h, int w)
{
    for (int i=0; i<h; i++)
    {
        p_coord_set->list[p_coord_set->count].x = 0;
        p_coord_set->list[p_coord_set->count].y = i;
        p_coord_set->count++;
    }
}

static void can_rd_direction_coord(CoordSet * p_coord_set, int h, int w)
{
    for (int i=0; i<w; i++)
    {
        p_coord_set->list[p_coord_set->count].x = i;
        p_coord_set->list[p_coord_set->count].y = 0;
        p_coord_set->count++;
    }
    for (int i=1; i<h; i++)
    {
        p_coord_set->list[p_coord_set->count].x = 0;
        p_coord_set->list[p_coord_set->count].y = i;
        p_coord_set->count++;
    }
}

static void can_ru_direction_coord(CoordSet * p_coord_set, int h, int w)
{
    can_right_direction_coord(p_coord_set, h, w);
    for (int i=1; i<w; i++)
    {
        p_coord_set->list[p_coord_set->count].x = i;
        p_coord_set->list[p_coord_set->count].y = h-1;
        p_coord_set->count++;
    }
}

static void show_corrd_set(CoordSet coord_set)
{
    for (int i=0; i<coord_set.count; i++)
    {
        printf("(%d, %d)\t", coord_set.list[i].x, coord_set.list[i].y);
        if (i+1 % 10 == 0)
            printf("\n");
    }
    putchar('\n');
}

static void show_finded_result(Result r)
{
    printf("start (%d, %d), end (%d, %d), content: %s\n", r.start.x, r.start.y, r.end.x, r.end.y, r.word.str);
}