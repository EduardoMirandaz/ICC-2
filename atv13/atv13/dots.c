#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "dots.h"

struct Dot_ST {
    float x;
    float y;
};

float get_smallest_distance(float, DOT, DOT);
int get_inbound_dots(const DOT *, int, DOT *, float, DOT *);
float get_smallest(float, float);

DOT * create_dots(int n){
    DOT *dots = calloc(n, sizeof(DOT));

    if(dots != NULL){
        dots->x = 0;
        dots->y = 0;
    }
    return dots;
}

void insert_dots(DOT * dots, float x, float y, int i){

    if(dots != NULL){
        dots[i].x = x;
        dots[i].y = y;
    }
}

void manage_distances(DOT * dots, int n){
    do_quick_x(dots, SMALLEST, n);
    printf("%.6f", closest_pair(dots, n));
}

float closest_pair(DOT *dots, int n)
{
    //pega x do meio e o ponto que está no meio do plano
    int middle = n/2;
    float minimum_distance = distance(dots[n - 2], dots[n - 1]);
    DOT middle_dot = dots[middle];
    //esse array aponta pro meio do array original
    DOT *right_pairs = dots + middle;

    //busca manual pra minimo
    if (n <= MIN_NUMBER){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                get_smallest_distance(minimum_distance, dots[i], dots[j]);
            }
        }
    } else {
        DOT center_dots[n];

        /* essa função entra aqui recursivamente até pegar 2 ou 3 pontos */
        //pela esquerda
        float left_distance = closest_pair(dots, middle);
        //pela direita
        float right_distance = closest_pair(right_pairs, n - middle);
        //pega a menor entre as 2. será usada pra pegar a 3a distância, que será entre os pontos de um lado ee de outro
        float max_distance_limit = get_smallest(left_distance, right_distance);
        //pega os pontos da faixa central, e coloca eles no vetor acima. third_distance vai encontrar a menor distância nessa faixa
        int in_bound_position = get_inbound_dots(dots, n, &middle_dot, max_distance_limit, center_dots);
        float third_distance = dots_in_middle_given_limit_closest(center_dots, in_bound_position, max_distance_limit);

        //escolhe entre os dos extremos e o do meio
        minimum_distance = get_smallest(third_distance, max_distance_limit);
    }

    return minimum_distance;
}

float get_smallest(float left_distance, float right_distance)
{
    float max_distance_limit;
    max_distance_limit = left_distance <= right_distance ? left_distance : right_distance;
    return max_distance_limit;
}

int get_inbound_dots(const DOT *dots, int n, DOT *middle_dot, float max_distance_limit, DOT *dots_in_middle_given_limit) {
    int in_bound_position = 0;
    float range;
    for(int i = 0; i < n; i++) {

        range = abs(dots[i].x - (*middle_dot).x);
        if (range < max_distance_limit) {
            dots_in_middle_given_limit[in_bound_position] = dots[i];
            in_bound_position++;
        }
    }
    return in_bound_position;
}

float get_smallest_distance(float minimum_distance, DOT a, DOT b)
{
    float pair_distance = distance(a, b);
    if (pair_distance < minimum_distance) minimum_distance = distance(a, b);

    return minimum_distance;
}

float dots_in_middle_given_limit_closest(DOT *dots_in_middle, int number_of_dots_in_x_axis_bound, float distance_y_axis)
{
    //ordena com y dado os number_of_dots_in_x_axis_bound pontos
    do_quick_y(dots_in_middle, SMALLEST, number_of_dots_in_x_axis_bound - 1);
    //pra cada ponto verifica se esta tudo dentro do limite verticalmente
    float max_distace_in_y_axis = distance_y_axis;
    for(int i = 0; i < number_of_dots_in_x_axis_bound; ++i){

        //verifica se a distancia vertical está dentro do limite
        float y_dotA = dots_in_middle[i].y;
        float y_dotB = dots_in_middle[i + 1].y;
        boolean is_y_distance_in_bounds = is_y_distance_within_limit(y_dotA, y_dotB, max_distace_in_y_axis);

        for(int j = i + 1; j < number_of_dots_in_x_axis_bound && is_y_distance_in_bounds == TRUE; ++j){
            //se a distancia entre pontos for menor que o limite (que se renova), então essa distância é o novo limite
            boolean is_distance_in_y_bound = distance(dots_in_middle[i], dots_in_middle[j]) < max_distace_in_y_axis
                    ? TRUE : FALSE;
            if (is_distance_in_y_bound) {
                max_distace_in_y_axis = distance(dots_in_middle[i], dots_in_middle[j]);
            }
            //recalcula se a distancia entre o proximo par e o limite y é válido
            y_dotA = dots_in_middle[i].y;
            y_dotB = dots_in_middle[j].y;
            is_y_distance_in_bounds = is_y_distance_within_limit(y_dotA, y_dotB, max_distace_in_y_axis);
        }
    }
    return max_distace_in_y_axis;
}

boolean is_y_distance_within_limit(float yA, float yB, float distance_bounds)
{
    if((yA - yB) < distance_bounds)
        return TRUE;

    return FALSE;
}

float distance(DOT a, DOT b){
    float x = pow((a.x - b.x), 2);
    float y = pow((a.y - b.y), 2);

    return sqrt(x + y);
}


void do_quick_x(DOT *dots, int smallest, int greatest)
{
    int piv;
    if (smallest < greatest)
    {
        piv = quick_x(dots, smallest, greatest);
        do_quick_x(dots, smallest, piv - 1);
        do_quick_x(dots, piv + 1, greatest);
    }
}

int quick_x(DOT *dots, int smallest, int greatest)
{
    int i;
    int pivot = dots[greatest].x;
    int j = smallest - 1;
    for (i = smallest; i < greatest; i++)
    {
        if (dots[i].x < pivot)
        {
            j++;
            DOT temp = dots[i];
            dots[i] = dots[j];
            dots[j] = temp;
        }
    }

    DOT temp = dots[j + 1];
    dots[j + 1] = dots[greatest];
    dots[greatest] = temp;
    return ++j;
}


void do_quick_y(DOT *dots, int smallest, int greatest)
{
    int piv;
    if (smallest < greatest)
    {
        piv = quick_y(dots, smallest, greatest);
        do_quick_y(dots, smallest, piv - 1);
        do_quick_y(dots, piv + 1, greatest);
    }
}

int quick_y(DOT *dots, int smallest, int greatest)
{
    int i;
    int pivot = dots[greatest].y;
    int j = smallest - 1;
    for (i = smallest; i < greatest; i++)
    {
        if (dots[i].y < pivot)
        {
            j++;
            DOT temp = dots[i];
            dots[i] = dots[j];
            dots[j] = temp;
        }
    }

    DOT temp = dots[j + 1];
    dots[j + 1] = dots[greatest];
    dots[greatest] = temp;
    return ++j;
}

void print_dots(DOT * dots, int n)
{
    for(int i = 0; i < n; i++){
        printf("X: %f | Y: %f\n", dots[i].x, dots[i].y);
    }
}