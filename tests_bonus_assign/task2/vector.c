#include "vector.h"
#include "frame.h"
typedef struct vector {
   int size;
   frame_t ** data; //point to an array
} vector_t;

//size=1 and data points to one integer array on the heap
//bad new:// stack                 |    heap
//  ret--|               |
//       v               |
//  v: |size 1|          |
//     |data -|---+----> |[0]

// good new:
// stack                 |    heap
//  ret------------------+--> |size: 1|
//                       |    |data --]+------
//                       |                   |
//                       |    +---------------
//                       |    |
//                       |    --->[0]
vector_t * vector_new(){
	vector_t * ret = (vector_t*) malloc(sizeof(vector_t));
	if(ret == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}
	ret->size = 1;
	ret->data = (frame_t **) malloc(sizeof(frame_t *));
	if(ret->data == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}

	ret->data[0]=0;
	return ret;

}
void vector_delete(vector_t * v){
 free(v->data);
 free(v);
}

// before vector_set(5,99) 
// stack                 |        heap
//  ret------------------+------> |size: 3|
//                       |        |data --]+--
//                       |                   |
//                       |        ------------
//                       |        |
//                       |        ->[0|1|2]


void vector_set(vector_t* v,  int loc, frame_t* val){
	if(loc<v->size && loc>=0) {
   	    v->data[loc] = val;
   	} else {
 //what if vector_set(5, 99), then above diagram will transform into the 
 //following diagram:	
 	    v->data = (frame_t **) realloc(v->data, sizeof(frame_t*)*(loc+1));
	    for(int i= v->size; i<loc+1; i++)
		v->data[i] = 0;
 	    v->data[loc] = val;
	    v->size = loc+1; //what happens if we forget to update size?
	}	

}
// 
// stack                 |        heap
//  ret------------------+------> |size: 6|   //size should be updated to loc+1
//                       |        |data --]+--
//                       |                   |
//                       |        +-----------
//                       |        |
//                       |        ->[0|1|2|0|0|99]


int vector_get(vector_t *v, int loc){
   if(loc<v->size && loc>=0) {
   	return  (frame_t*)v->data[loc];
   } else {
  	perror("blahblah");
       return 0;	
   }
}


