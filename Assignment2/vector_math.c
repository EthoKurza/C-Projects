#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector_math.h"

int main(int argc, char** argv) {
	//declare vectors
	Vec3d vector1;
	Vec3d vector2;
	Vec3d vector3;
	Vec3d vector4;

	//initilize vectors
	vec3dSet(&vector1, -2, 1, 11);
	vec3dSet(&vector2, 3.5, -7, 0.3);

	//calculate vectors
	vec3dAdd(&vector1, &vector2, &vector3);
	vec3dScalarMul(&vector3,0.5,&vector4);

	//print vectors
	vec3dPrint(&vector1);
	vec3dPrint(&vector2);
	vec3dPrint(&vector3);
	vec3dPrint(&vector4);

	//create a line
	Line newLine;

	lineSet(&newLine, &vector1, &vector4);
	linePrint(&newLine);

	//declare dynamic allocated vectors
	Vec3d* vecPtr1 = malloc(sizeof(Vec3d));
	Vec3d* vecPtr2 = malloc(sizeof(Vec3d));

	//initialize vector Pointers
	vec3dSet(vecPtr1, vector1.x, vector1.y, vector1.z);

	vec3dScalarMul(vecPtr1,-1.7,vecPtr2);

	//print vectors
	vec3dPrint(vecPtr1);
	vec3dPrint(vecPtr2);

	//free dynamic allocated vectors
	free(vecPtr1);
	free(vecPtr2);


}//end of main


//functions/methods
void vec3dSet(Vec3d* vec, double x, double y, double z) {
	vec->x = x;
	vec->y = y;
	vec->z = z;
}//end of vec3dSet

void vec3dPrint(const Vec3d* vec) {
	printf("(%g, %g, %g)\n",vec->x, vec->y, vec->z);
}//end of vec3dPrint

void vec3dAdd(const Vec3d* src1, const Vec3d* src2, Vec3d* dst) {
	dst->x = src1->x + src2->x;
	dst->y = src1->y + src2->y;
	dst->z = src1->z + src2->z;
}//end of vec3dAdd

void vec3dScalarMul(const Vec3d* src, double a, Vec3d* dst) {
	dst->x = a * src->x;
	dst->y = a * src->y;
	dst->z = a * src->z;
}//end of vec3dScalarMul

void lineSet(Line* line, const Point* start, const Point* end) {
	line->start = *start;
	line->end = *end;
}//end of lineSet

void linePrint(const Line* line) {
	printf("(%g, %g, %g) - (%g, %g, %g)\n", line->start.x,line->start.y, line->start.z, line->end.x, line->end.y, line->end.z);
}//end of linePrint


