//
//  maxrow.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>

void maxrow(int n, int m, int **a){
    int max, row;
    int sum;
    
    sum = 0;
    max = 0;
    row = 0;
    for (int j = 0; j < m; j++)
        max += a[0][j];
    
    for(int i=0;i<n;i++){
        
        sum=0;
        
        for(int j=0;j<m;j++)
            sum=sum+a[i][j];
        if (sum > max){
            max = sum;
            row = i;
        }
    }
    printf("строка %d имеет максимальную сумму, равную %d\n", row, max);
}
