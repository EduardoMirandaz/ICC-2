#ifndef TAD_DOT_H
#define TAD_DOT_H

    typedef struct Dot_ST DOT;
    typedef int boolean;

    #define SMALLEST 0
    #define MIN_NUMBER 3
    #define FALSE 0 
    #define TRUE 1

    void manage_distances(DOT *, int);
    float closest_pair(DOT *dots, int n);
    float dots_in_middle_given_limit_closest(DOT *, int, float);
    float distance(DOT, DOT);
    DOT * create_dots(int);
    void insert_dots(DOT *dots, float x, float y, int i);
    void print_dots(DOT * dots, int n);
    boolean is_y_distance_within_limit(float, float, float);
    int quick_x(DOT *, int, int);
    void do_quick_x(DOT *, int, int);

    int quick_y(DOT *, int, int);
    void do_quick_y(DOT *, int, int);
#endif //TAD_DOT_H