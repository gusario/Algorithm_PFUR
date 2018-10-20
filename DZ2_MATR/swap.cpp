//
//  swap.cpp
//  DZ1_MATR
//
//  Created by David Nurdinov on 21/09/2018.
//  Copyright © 2018 David Nurdinov. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b)
{
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
    
}
