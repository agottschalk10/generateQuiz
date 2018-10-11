#include <stdio.h>                                                                                            
#include <time.h>                                                               
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <ctype.h>                                                              
                                                                                
//int search(int, char (*)[(long unsigned int)(d)], char*, int, int, int, int, int);
                                                                                
int main()                                                                      
{                                                                               
    //fscan("%s");                                                              
    FILE* file_ptr = fopen("data1", "r");                                       
                                                                                
    int ch = getc(file_ptr);             // holds value of file                 
    int line_count = 0;     // number of lines                                  
    int char_count = 0;     // number of characters in a row, gives dimensions  
    // of wordsearch                                                            
                                                                                
    if(file_ptr == NULL)                                                        
    {                                                                           
        printf("can’t open the file\n");                                        
        return 1;                                                               
    }                                                                           
    while(ch != EOF)                                                            
    {                                                                           
        // get thenumber of characters in the first row to get dimensions of    
        // word search                                                          
        if (ch == '\n')                                                         
        {                                                                       
            line_count ++;                                                      
        }                                                                       
                                                                                
        if(line_count == 0)                                                     
        {                                                                       
            char_count ++;                                                      
        }                                                                       
        ch = getc(file_ptr);                                                    
    }                                                                           
    // number of chars per line after spaces taken out                          
    int d = char_count / 2;     // dimensions of puzzle                         
    printf("line_count: %d\n", line_count);                                     
    printf("char_count: %d\n", char_count);                                     
    int search(int, char[][d], char*, int, int, int, int, int);                 
    // create 2 empty 2-dimensional char arrays -1 for the word searh puzzle,   
    // and 1 for the output                                                     
    char puzzle[d][d];                                                          
    char output[d][d];                                                         
    
     // fill both with empty spaces                                              
    for(int i=0; i<d; i++)                                                      
    {                                                                           
        for(int x=0; x<d; x++)                                                  
        {                                                                       
            puzzle[i][x]=' ';                                                   
            output[i][x]=' ';                                                   
        }                                                                       
    }                                                                           
                                                                                
    // Start back at beggining of file                                          
    rewind(file_ptr);                                                           
                                                                                
    // 2 variables for the position of the puzzle                               
    int a = 0,                                                                  
        b = 0;                                                                  
    int numOfLines = 0;                                                         
                                                                                
    ch = getc(file_ptr);                                                        
    // File puzzle with values                                                  
    while (ch != EOF)                                                           
    {                                                                           
        if(ch == '\n')                                                          
        {                                                                       
            numOfLines++;                                                       
        }                                                                       
        else if(isalpha(ch))                                                    
        {                                                                       
            puzzle[a][b] = ch;                                                  
            b++;                                                                
        }                                                                       
        if(numOfLines == d)                                                     
        {                                                                       
            break;                                                              
        }                                                                       
        ch = getc(file_ptr);                                                    
    }                                                  
    
    printf("num of lines: %d\n", numOfLines);                                   
                                                                                
    // Print the puzzle                                                         
    /*                                                                          
       for(int j=0;j<d;j++)                                                     
       {                                                                        
       for(int c=0; c<d; c++)                                                   
       {                                                                        
       printf("%c", puzzle[j][c]);                                              
       }                                                                        
       printf("\n");                                                            
       }                                                                        
       */                                                                       
                                                                                
    int numOfWords = 0;     // number of words to search for                    
    numOfWords = line_count - d;                                                
                                                                                
    printf("numOfWords: %d\n", numOfWords);                                     
                                                                                
    char w[100];        // holds current word being searched for                
    char first = ' ';   // first char of word                                   
    int length = 0;     // length of word                                       
    int pos = 1;        // position in word                                     
    int r = 0;          // row position                                         
    int c = 0;          // column position                                      
    int dir = 0;        // direction that is being searched                     
    int found = 0;      // 0 if not found, 1 if found;                          
    int fr = 0;                                                                 
    int fc = 0;                                                                 
    int foundDir = -1;                                                          
    int comp = 0;                                                               
                                                                                
    for(int x=0; x < 2; x++)                                                    
    {                                                                           
        fgets(w, 100, file_ptr);                                                
        length = strlen(w);                                                     
        first = w[0];                                                           
        //printf("%s", *w);                                  
        for(r=0; r < d; r++)                                                    
        {                                                                       
            for(c=0; c < d; c++)                                                
            {                                                                   
                //printf("%c %c", first, puzzle[r][c]);                         
                if(first == puzzle[r][c])                                       
                {                                                               
                    fr = r;                                                     
                    fc = c;                                                     
                    for(dir=0; dir<8; dir++)                                    
                    {                                                           
                        while(found == 0)                                       
                        {                                                       
                            switch(dir)                                         
                            {                                                   
                                case 0: r+1;                                    
                                        c-1;                                    
                                        break;                                  
                                case 1: r+1;                                    
                                        break;                                  
                                case 2: r+1;                                    
                                        c+1;                                    
                                        break;                                  
                                case 3: c+1;                                    
                                        break;                                  
                                case 4: r-1;                                    
                                        c+1;                                    
                                        break;                                  
                                case 5: r-1;                                    
                                        break;                                  
                                case 6: r-1;                                    
                                        c-1;                                    
                                        break;                                  
                                case 7: c-1;                                    
                                        break;                                  
                            }                                                   
                                                                                
                            if(c>d || c<0 || r>d || r<0)                        
                            {                                                   
                                found = -1;                                     
                                pos =1;                                         
                            }                              
                             // if made it to last char of word                  
                            printf("%c %c", puzzle[r][c], w[length-1]);         
                            else if(length-1 == pos)                            
                            {                                                   
                                // if last char matches current index           
                                if(puzzle[r][c] == w[length-1])                 
                                {                                               
                                    found = 1;                                  
                                    pos = 1;                                    
                                    output[fr][fc] = first;                     
                                    r=fr;                                       
                                    c=fc;                                       
                                    int done =0;                                
                                    while(done ==0)                             
                                    {                                           
                                    switch(dir)                                 
                                    {                                           
                                        case 0: r+1;                            
                                                c-1;                            
                                                break;                          
                                        case 1: r+1;                            
                                                break;                          
                                        case 2: r+1;                            
                                                c+1;                            
                                                break;                          
                                        case 3: c+1;                            
                                                break;                          
                                        case 4: r-1;                            
                                                c+1;                            
                                                break;                          
                                        case 5: r-1;                            
                                                break;                          
                                        case 6: r-1;                            
                                                c-1;                            
                                                break;                          
                                        case 7: c-1;                            
                                                break;                          
                                    }                                           
                                                                                
                                    pos++;                                      
                                    output[r][c] = w[pos];                      
                                    if(length-1 == pos)                         
                                    {                                           
                                        done =1;                                
                                    }                                           
                                    }                      
                                    }                                               
                                pos = 1;                                        
                            }                                                   
                            else if(puzzle[r][c] != w[pos])                     
                            {                                                   
                                found = -1;                                     
                                pos =1;                                         
                            }                                                   
                            else                                                
                            {                                                   
                                pos++;                                          
                                found = 0;                                      
                            }                                                   
                        }                                                       
                                                                                
                        if(found == 1)                                          
                        {                                                       
                            //fillOutput(*w, r, c, dir);                        
                        }                                                       
                    }                                                           
                }                                                               
            }                                                                   
        }                                                                       
        //search(*puzzle, w, l, length);                                        
    }                                                                           
                                                                                
    for(int o=0; o<d; o++)                                                      
    {                                                                           
        printf("\n");                                                           
        for(int p=0; p<d; p++)                                                  
        {                                                                       
            printf("%c", output[o][p]);                                         
        }                                                                       
    }                                                                           
    printf("\n");                                                               
                                                                                
    fclose(file_ptr);                                                           
}                                                               
