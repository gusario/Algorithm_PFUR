//
//  get_sizeM.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 26/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>
#define LIM 30

int get_sizeM()
{
    int m;
    do{
        
        printf("Введите 0<m<=%d ",LIM);
        
        scanf("%d",&m);
        
    }while(m<=0 || m>LIM);
    return m;
}
