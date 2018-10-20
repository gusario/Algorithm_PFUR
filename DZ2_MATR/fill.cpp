//
//  fill.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>

void fill(int n, int m, int **a)
{
    printf("Заполнение матрицы\n");
    
    for(int i=0;i<n;i++)
        
        for(int j=0;j<m;j++){
            
            printf("введите элемент %d %d ",i,j);
            
            scanf("%d",&a[i][j]);
            
        }
}
