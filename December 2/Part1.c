//
//  Advent of Code 2021
//  December 2 - Dive!
//
//  Part1.c
//
//  Created by Simon on 2021-12-02.
//

#include <stdlib.h>
#include <stdio.h>

char getMovement(FILE *fp){
    char c = fgetc(fp);
    if(c == EOF || c >= '0' && c <= '9')
        return c;
    else
        return getMovement(fp);
}

char getDirection(FILE *fp){
    char c = fgetc(fp);
    if(c == EOF || c >= 'a' && c <= 'z')
        return c;
    else
        return getDirection(fp);
}

int main(int argc, char **argv){
    FILE *fp = fopen("input.txt", "r");
    
    int horizontalPos = 0;
    int depth = 0;
    
    for(;;){
        char direction =  getDirection(fp);
        if(direction == EOF)
            break;
        
        char movement = getMovement(fp);
        if(movement == EOF)
            break;
        
        switch(direction){
            case 'u': depth -= atoi(&movement); break;
            case 'd': depth += atoi(&movement); break;
            case 'f': horizontalPos += atoi(&movement); break;
        }
    }
    fclose(fp);
    
    printf("Horizontal position = %d\n", horizontalPos);
    printf("Depth = %d\n", depth);
    printf("Answer: %d x %d = %d\n", horizontalPos, depth, horizontalPos*depth);
}
