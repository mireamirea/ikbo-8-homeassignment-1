#include <stdio.h>

typedef struct {
	float Re;
	float Im;
}Cnum_t;

Cnum_t* Cplus(Cnum_t* a, Cnum_t* b) {
	
	Cnum_t  *t = (Cnum_t*)malloc(sizeof(Cnum_t*));
	t->Re = a->Re + b->Re;
	t->Im = a->Im + b->Im;
	
	return t;
}

Cnum_t* Cminus(Cnum_t* a, Cnum_t* b) {
	Cnum_t  *t = (Cnum_t*)malloc(sizeof(Cnum_t*));
	t->Re = a->Re - b->Re;
	t->Im = a->Im - b->Im;
	
	return t;
} 

Cnum_t* Cmulti(Cnum_t* a, Cnum_t* b) {
	Cnum_t  *t = (Cnum_t*)malloc(sizeof(Cnum_t*));
	t->Re = a->Re * b->Re - a->Im * b->Im;
	t->Im = a->Im * b->Re + b->Im * a->Re;
	return t;
}

void Cprint(Cnum_t t) {
	if (t.Im < 0)
		printf("z = %f %f*i", t.Re, t.Im);
	else
		printf("z = %f + %f*i", t.Re, t.Im);
	if (t.Im == 0)
		print("z = %f", t.Re);
}

void Cdiv(Cnum_t* a, Cnum_t* b) {
	Cnum_t  *t = (Cnum_t*)malloc(sizeof(Cnum_t*));
	Cnum_t  *r = (Cnum_t*)malloc(sizeof(Cnum_t*));	
	Cnum_t  *k = (Cnum_t*)malloc(sizeof(Cnum_t*));
	Cnum_t  *v = (Cnum_t*)malloc(sizeof(Cnum_t*));
	r->Im = b->Im *(-1);
	t = Cmulti(*a, *r);
	k =	Cmulti(*b, *r);
	v = t->Re / k->Re + t->Im / k->Im;
}
