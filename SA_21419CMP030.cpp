// C++ Program to maximise Benchmark Functions using Simulated Annealing
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164

long double sphere(long double x)
{
    return x*x;
}

/*
//Function to implement Schwefel 2.22
long double schwefel_222(long double x)
{
    static long double sum = 0, mul = 1;
    sum += x;
    mul *= x;
    return sum + mul;
}  

//Function to implement Schwefel 1.2
long double schwefel_12(long double x)
{
    static long double sum = 0;
    
    sum += x;
}

//Function to implement Schwefel 2.21
long double schwefel_221(long double x)
{
    return x;
}

//Function to implement Rosenbrock
long double rosenbrock(long double x)
{
    return 100*((x-(x*x))*(x-(x*x))) + (x*x);
}

//Function to implement step
long double step(long double x)
{
    return (x+0.5)*(x+0.5);
}

//Function to implement Quartic Functiom
long double quartic(long double x)
{
    static int j = 0;
    long double rand_value;
    srand(time(0));
    rand_value = (rand() % (1 - 0 + 1))+1;
    return (j++)*pow(x,4) + rand_value;
}

//Function to implement Schwefel
long double schwefel(long double x)
{
    long double sqr_x;
    sqr_x = sqrt(abs(x));
    return -x*sin(sqr_x);
}

//Function to implement Rastrigin function
long double rastrigin(long double x)
{
    return (x*x)-10*cos(2*PI*x) + 10;
}
*/

void simulated_annealing(int x_min, int x_max, int max_iters, double step_size, double T)
{
    srand(time(0));
    double temp, prob, r;
    long double best, best_eval, curr, curr_eval, candidate, candidate_eval;
    // Generate initial point
    best = x_min + (rand() % (x_max - x_min + 1));

    //Evaluate the initial point
    best_eval = sphere(best);

    curr = best;
    curr_eval = best_eval;

    for(int i=0; i<max_iters; i++)
    {
        candidate = curr + (rand() % (x_max - x_min + 1)) * step_size;
        
        // Evaluate candidate point
        candidate_eval = sphere(candidate);

        // Check for best solution 
        if (candidate_eval < best_eval)
        {
            best = candidate;
            best_eval = candidate_eval;
            cout<< i<<"th iteration : "<<best<<" - "<<best_eval<<endl;
        }

        // Calculate temperature for the current epoch
        temp = T / (double)(i+1);
        prob = exp(-(candidate_eval - curr_eval)/temp);

        r = ((double) rand() / (RAND_MAX));

        if ((candidate_eval - curr_eval)<0 || r < prob)
        {
            curr = candidate;
            curr_eval = candidate_eval;
        }

    }

    cout << "Final Solution : "<<endl;
    cout << "Best Candidate : "<< best <<endl;
    cout << "Best Solution : " << best_eval;
}

int main()
{
    int x_min = -100;
    int x_max = +100;

    int max_iters = 100;

    double step_size = 0.1;

    // Initial Temperature
    double T = 10.0;

    simulated_annealing(x_min, x_max, max_iters, step_size, T);
}