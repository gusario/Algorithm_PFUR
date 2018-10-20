//
//  find_col.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 21/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>

int find_col(int n, int m, int **a)
{
    int i, j;
    int flag;
    
    for(j=m - 1;j>=0;j--){
        flag = 1;
        for(i=0;i<n;i++)
            if (a[i][j] < 0)
                flag = 0;
        if (flag)
            return (j);
    }
    return (0);
}
