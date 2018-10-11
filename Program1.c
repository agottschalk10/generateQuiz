#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int genQuestion(int, int);
int answerQuestion(int);
void response(int, int);
void scoreQuiz(int, int);

int main()
{
    int q = 0;  // number of questions
    int d = 0;  // quiz difficulty
    int a = 0;  // answer to the question
    int c = 0;  // if answer is correct, set to 1
                // if answer is incorrect, set to -1;
    int points = 0; // hold number of questions answered correctly
    
    // ask how many wuestions user wants, make sure answer is valid
    
    {
        printf("How many questions for this test(1 - 20)? ");
        scanf ("%d", &q);
    }
    while (q < 1 || q > 20);

    // ask user for desired dificulty, only procees when valid
    do
    {
        printf("Select dificulty(1 - 4): ");
        scanf ("%d", &d);
    }
    while(d < 1 || d > 4);

    // for the number of questions being asked, each time call each method
    for (int i = 1; i <= q; i++)
    {
        a = genQuestion(d, i);
        c = answerQuestion(a);
        // if question was answer correctly, add one to their points
        if( c == 1)
        {
            points++;
        }
        response(a, c);
    }
    scoreQuiz(points, q);
}

/*  Method Name : genQuestion
    Parameters  : d and i, both integers
    Return value(s) : The answer to question, int
    Partners        : None
    Description : This method generates and outputs a question based on the
    difficulty passed and returns the answer 
*/
int genQuestion(int d, int i)
{
    int h = 0, l = 1;   // high and low of range of integers based off the 
    //difficulty
    int num1 = 0, num2 = 0; // hold the randomly generated nunmbers
    int x = 0; // operation that is going to take place    
    char o = ' ';      // string version of operation
                        // 0 = +, 1 = -, 2 = *, 3 = /
    int answer = 0;     // answer to the create question

    // set high and low end of numbers allowed based on the difficulty
    switch(d)
    {
        case 1: h = 10;
                break;
        case 2: h = 50;
                break;
        case 3: h = 100;
                break;
        case 4: h = 100;
                l = -100;
                break;
    }

    // seeds random number generator
    srand(time(NULL));

    // get two numbers for the math problems
    if (l != -100)
    {
        num1 = rand() % h + 1;
        num2 = rand() % h + 1;
    }
    else
    {
        num1 = rand() % 201 - 100;
        num2 = rand() % 201 - 100;
    }

    // randomly choose an operation: +, -, *, or /
    x = (rand() % 4);
    
    if(x == 0)
    {
        o = '+';
        answer = num1 + num2;
    }
    else if(x == 1)
    {
        o = '-';
        answer = num1 - num2;
    }
    else if(x == 2)
    {
        o = '*';
        answer = num1 * num2;
    }
    else
    {
        o = '/';
        if (num2 == 0)
        {
            num2 = 1;
        }
        answer = num1 / num2;
    }
    // print the created math problem
    printf("Question %d: %d %c %d =", i, num1, o, num2);
    // return the asnwer to that problem
    return answer;
}

/*  Method Name : answerQuestion
    Parameters  : a, integer
    Return value(s) : If answer is correct or not, int
    Partners        : None
    Description : This method asks user to enter their answer to the problem, 
                  then comapares that to the right answer -returning -1 for a 
                  wrong answer, and 1 for a correct answer
*/
int answerQuestion(int a)
{
    int r; // response from user
    printf("\nEnter Answer: ");
    scanf ("%d", &r);
    // if answer is correct, else
    if (r == a)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/*  Method Name : response
    Parameters  : a and c, both integers
    Return value(s) : None
    Partners        : None
    Description : This method generates a response based on the users answer. 
*/
void response(int a, int c)
{
    // seeds random number generator
    srand(time(NULL));

    int r = (rand() % 3);     // randomly choose one of the responses

    // if the answer was correct
    if(c == 1)
    {
        if(r == 0) { 
            printf("Nice!\n");
        }
        else if(r == 1) {
            printf("Good Job!\n");
        }
        else {
            printf("You're Right!\n");
        }
    }
    // if the answer was incorrect
    else
    {
        if(r == 0) {
            printf("Sorry!\n");
        }
        else if(r == 1) {
            printf("Wrong!\n");
        }
        else {
            printf("Get it Next Time!\n");
        }
        
        // output the correct answer for user
        printf("The correct answer was %d\n", a);
    }
}

/*  Method Name : scoreQuiz
    Parameters  : points and q, integer
    Return value(s) : None
    Partners        : None
    Description : This method prints the users score
*/
void scoreQuiz(int points, int q)
{
    printf("Your score was %d/%d\n", points, q);
}
