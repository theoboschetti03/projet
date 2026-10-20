#ifndef SVG_H
#define SVG_H
#include "forme.h"
#include <stdio.h>

void svg_exporter_forme(const Forme *f, FILE *out);
int  svg_exporter(const Forme *racine, const char *chemin);

#endif
