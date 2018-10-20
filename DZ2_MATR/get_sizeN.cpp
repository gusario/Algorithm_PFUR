//
//  get_sizeN.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>
#define LIM 30

int get_sizeN()
{
    int n;
    
    do{
        
        printf("Введите 0<n<=%d ",LIM);
        
        scanf("%d",&n);
        
    }while(n<=0 || n>LIM);
    return n;
}
