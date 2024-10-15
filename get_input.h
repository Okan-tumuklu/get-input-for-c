#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char* string;

string get_string(string msg){
	printf("%s",msg);
	
	char ch;
	int length = 0;
	int size = 2;
	string str = (string) malloc(size);
	
	if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
	
	while((ch=getchar()) != EOF && ch != '\n'){
		if(length + 1 >= size){
			size+=1;
			str = (char*) realloc(str, size*sizeof(char));
			if (str == NULL) {
			free(str);
                printf("Memory allocation failed!\n");
                exit(1);
            }
			}
		str[length++] = ch;
		}
		
	str[length] = '\0';
	return str;
	}

int get_int(char* msg){
    int x;
    printf("%s",msg);
    scanf("%d",&x);
    return x;
}

float get_float(char* msg){
    float x;
    printf("%s",msg);
    scanf("%f",&x);
    return x;
}

double get_double(char* msg){
	double x;
	printf("%s",msg);
	scanf("%lf",&x);
	return x;
	}

char get_char(char* msg){
	char x;
	printf("%s",msg);
	scanf(" %c",&x);
	}

long get_long(char* msg){
    long x;
    printf("%s", msg);
    scanf("%ld", &x); 
    return x;
}

long long get_long_long(char* msg){
    long long x;
    printf("%s", msg);
    scanf("%lld", &x);  
    return x;
}


unsigned int get_unsigned_int(char* msg){
    unsigned int x;
    printf("%s", msg);
    scanf("%u", &x); 
    return x;
}

unsigned long get_unsigned_long(char* msg){
    unsigned long x;
    printf("%s", msg);
    scanf("%lu", &x); 
    return x;
}


long double get_long_double(char* msg){
    long double x;
    printf("%s", msg);
    scanf("%Lf", &x);
    return x;
}


#include <stdbool.h>

bool get_bool(char* msg){
    char response;
    printf("%s (y/n): ", msg);
    scanf(" %c", &response);
    return (response == 'y' || response == 'Y') ? true : false;
}


size_t get_size_t(char* msg){
    size_t x;
    printf("%s", msg);
    scanf("%zu", &x);
    return x;
}
