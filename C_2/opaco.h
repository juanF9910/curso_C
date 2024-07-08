/*
en este archivo vamos a definir todos los tipeos de variables y también el prototipo de las funciones
*/

typedef struct foo foo_t; 

foo_t *nuevo_foo(); /* esta función devuelve un puntero a una estructura */
void set_foo( foo_t *foo, int a, int b);
void borrar_foo( foo_t *foo);
int suma_foo(foo_t *foo); 