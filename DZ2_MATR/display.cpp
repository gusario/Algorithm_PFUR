//
//  display.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>

void display(int n, int m, int **a)
{
    printf("Матрица а(n,m)\n");
    
    for(int i=0;i<n;i++){
        
        for(int j=0;j<m;j++)
            
            printf("%2d",a[i][j]);
        
        putchar('\n');
        
    }
}
