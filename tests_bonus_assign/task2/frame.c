/******************************************************
* File: frame.c
*
* This is the frame struct implementation
*
******************************************************/
#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static void load_frame(frame_t *f, char *path){
	FILE * fp;
  char * line = NULL;
  int len = 4096;
  int read = 0, test = 0;
	fp = fopen(path, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);
  f->content = (char*)malloc(sizeof(char));
  while ((read = getline(&line, &len, fp)) != -1) {
    if (test == 0) {
      f->rep_counter = atoi(line);
      test = 1;
    }
    else if (test == 1) {
      int size = strlen(line);
      f->content = realloc(f->content,size);
      strcpy(f->content,line);
      test = 2;
    }
    else {int size = strlen(f->content)+strlen(line)+1;
    f->content = realloc(f->content,size);
    strcat(f->content,line);
    	}
    }
  fclose(fp);
}

frame_t * frame_new(char *pathname, int id) {
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->id = id;
	load_frame(f, pathname);
	return f;
}

void frame_delete(frame_t * f) {
	free(f->content);
	free(f);
}

char* frame_get_content (frame_t *f){
	return f-> content;
}
int frame_get_rep_counter(frame_t * f){
	return f-> rep_counter;
}
int frame_get_id(frame_t *f){
	return f-> id;
}

