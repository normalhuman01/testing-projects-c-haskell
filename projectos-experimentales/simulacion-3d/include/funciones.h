#pragma once
#include "clases.h"

// Requerimiento 1
bool verificarMesh(MallaDeTriangulos* malla);

// Requerimiento 2
void pintarTriangulo(MallaDeTriangulos* malla);

// Requerimiento 3
MallaDeTriangulos* crearRectangulo(float ancho, float alto, Vector3 centro);

// Requerimiento 4
MallaDeTriangulos* crearCubo(float ancho, float alto, float profundidad, Vector3 centro);

// Requerimiento 5
void pintarRectangulo(MallaDeTriangulos* malla);

// Requerimiento 6
void moverMesh(MallaDeTriangulos* malla, Vector3 destino);

// Requerimiento 7
void animar(MallaDeTriangulos* malla);