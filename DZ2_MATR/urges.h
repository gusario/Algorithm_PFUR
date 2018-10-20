//
//  urges.h
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#ifndef urges_h
#define urges_h

#define LIM 30

void swap(int *a, int *b); //меняет местами
int find_col(int n, int m, int **a); //ищет последний столбец со всеми положительными элементами
void maxrow(int n, int m, int **a); //находит строку с наибольшей суммой элементов
void fill(int n, int m, int **a); // заполнение матрицы
void display(int n, int m, int **a); // показ матрицы
int get_sizeN(); // скан N
int get_sizeM(); // скан М

#endif /* urges_h */
