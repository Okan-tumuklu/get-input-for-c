# get-input-for-c

---

## User Input Functions for C Programming

In the C programming language, obtaining user input is crucial, especially in large projects or situations that require dynamic data entry. Below, you will find simple functions written for the most commonly used data types. You can use these functions in your projects to provide more flexible and user-friendly input methods.

### 1. `get_string`: Dynamic String Input from the User

This function allows you to dynamically read a string from the user while managing memory.

```c
string get_string(string msg){
    printf("%s", msg);
    
    char ch;
    int length = 0;
    int size = 2;
    string str = (string) malloc(size);

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    while((ch = getchar()) != EOF && ch != '\n'){
        if(length + 1 >= size){
            size += 1;
            str = (char*) realloc(str, size * sizeof(char));
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
```

**Usage:**
```c
int main() {
    string name = get_string("Enter your name: ");
    printf("Hello, %s!\n", name);
    free(name); // Don't forget to free the memory!
    return 0;
}
```

### 2. `get_int`, `get_float`, `get_double`: Numerical Input Functions

These functions accept input from the user for different data types like integers (`int`), floats (`float`), and doubles (`double`).

```c
int get_int(char* msg){
    int x;
    printf("%s", msg);
    scanf("%d", &x);
    return x;
}

float get_float(char* msg){
    float x;
    printf("%s", msg);
    scanf("%f", &x);
    return x;
}

double get_double(char* msg){
    double x;
    printf("%s", msg);
    scanf("%lf", &x);
    return x;
}
```

**Usage:**
```c
int main() {
    int age = get_int("Enter your age: ");
    float height = get_float("Enter your height (in meters): ");
    double weight = get_double("Enter your weight (in kg): ");
    
    printf("Age: %d, Height: %.2f m, Weight: %.2f kg\n", age, height, weight);
    return 0;
}
```

### 3. `get_char`: Single Character Input

This function allows you to read a single character from the user.

```c
char get_char(char* msg){
    char x;
    printf("%s", msg);
    scanf(" %c", &x);  // The leading space clears any previous newline characters
    return x;
}
```

**Usage:**
```c
int main() {
    char gender = get_char("Enter your gender (M/F): ");
    printf("Gender: %c\n", gender);
    return 0;
}
```

### 4. `get_bool`: Yes/No (Boolean) Input

This function prompts the user for a `y/n` (yes/no) response and returns a boolean (`true/false`) value.

```c
#include <stdbool.h>

bool get_bool(char* msg){
    char response;
    printf("%s (y/n): ", msg);
    scanf(" %c", &response);
    return (response == 'y' || response == 'Y') ? true : false;
}
```

**Usage:**
```c
int main() {
    bool proceed = get_bool("Do you want to continue?");
    
    if (proceed) {
        printf("Continuing...\n");
    } else {
        printf("Cancelled.\n");
    }
    
    return 0;
}
```

### 5. Other Data Type Input Functions

You can also get input for other important data types in C:

```c
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

size_t get_size_t(char* msg){
    size_t x;
    printf("%s", msg);
    scanf("%zu", &x);
    return x;
}
```

**Usage:**
```c
int main() {
    long long largeNum = get_long_long("Enter a large integer: ");
    unsigned int positiveNum = get_unsigned_int("Enter a positive integer: ");
    unsigned long bigPositiveNum = get_unsigned_long("Enter a large positive integer: ");
    long double preciseNum = get_long_double("Enter a fractional number: ");
    size_t size = get_size_t("Enter a memory size (size_t): ");
    
    printf("Entered values:\nLong Long: %lld\nUnsigned Int: %u\nUnsigned Long: %lu\nLong Double: %Lf\nSize_t: %zu\n", largeNum, positiveNum, bigPositiveNum, preciseNum, size);
    
    return 0;
}
```
