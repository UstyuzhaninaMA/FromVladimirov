
#include <stdlib.h> 


struct sieve_t {
  int n;
  char *s;
};

void fill_sieve(struct sieve_t *sv){
    
}

int nth_prime(struct sieve_t *sv, int N);


/*struct sieve_t {
  int n;
  char *s;
};

int is_prime(unsigned n) 
{ 
    int j = 0; 
    if ((n == 2) || (n == 3)) 
        return 1; 
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0)) 
    return 0; 
    for (j = 5; j * j <= n; j += 6) 
    if (((n % j) == 0) || ((n % (j + 2)) == 0)) 
        return 0; 
    return 1; 
} 

void set_composite(struct sieve_t *sv, int j) 
{ 
    sv -> s[j] = 1; 
} 

void fill_sieve(struct sieve_t *sv) 
{ 
    int i = 0, j = 0; 

    unsigned r = (unsigned) sqrt(sv -> n) + 1; 
    sv -> s[0] = sv -> s[1] = 1; 
    for (i = 2; i < r; i++) 
        if (is_prime(i)) 
            for (j = i * i; j <= sv -> n; j += i) 
                set_composite(sv, j); 
} 

int nth_prime(struct sieve_t *sv, int N) 
{ 
    int i = 0; 
    int k = 0; 
    while (k != N) { 
    if (sv -> s[i] == 0) { 
        k++; 
    } 
    i++; 
    } 
    return i - 1; 
}*/