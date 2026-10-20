#include <stdio.h>
#include "forme.h"
#include "svg.h"

static void svg_ecrire_transform(const Forme *f, FILE *out) {
    int sx = f->transform.flipX ? -1 : 1;
    int sy = f->transform.flipY ? -1 : 1;
    fprintf(out, " transform=\"translate(%d,%d) rotate(%d) scale(%d,%d)\"",
            f->transform.dx, f->transform.dy, f->transform.angle, sx, sy);
}

void svg_exporter_forme(const Forme *f, FILE *out) {
    if (f == NULL || out == NULL) {
        return;
    }

    switch (f->type) {
        case CERCLE:
            fprintf(out, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"%s\"",
                    f->data.cercle.middle.x, f->data.cercle.middle.y,
                    f->data.cercle.r, f->style.stroke, f->style.fill);
            svg_ecrire_transform(f, out);
            fprintf(out, "/>\n");
            break;

        case RECTANGLE:
            fprintf(out, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\"",
                    f->data.rectangle.corner.x, f->data.rectangle.corner.y,
                    f->data.rectangle.l, f->data.rectangle.h,
                    f->style.stroke, f->style.fill);
            svg_ecrire_transform(f, out);
            fprintf(out, "/>\n");
            break;

        case ELLIPSE:
            fprintf(out, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" stroke=\"%s\" fill=\"%s\"",
                    f->data.ellipse.middle.x, f->data.ellipse.middle.y,
                    f->data.ellipse.rx, f->data.ellipse.ry,
                    f->style.stroke, f->style.fill);
            svg_ecrire_transform(f, out);
            fprintf(out, "/>\n");
            break;

        case LIGNE:
            fprintf(out, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\"",
                    f->data.ligne.a.x, f->data.ligne.a.y,
                    f->data.ligne.b.x, f->data.ligne.b.y,
                    f->style.stroke);
            svg_ecrire_transform(f, out);
            fprintf(out, "/>\n");
            break;
    }
}

int svg_exporter(const Forme *racine, const char *chemin) {
    FILE *out = fopen(chemin, "w");
    if (out == NULL) {
        return 0;
    }

    fprintf(out, "<svg xmlns=\"http://www.w3.org/2000/svg\" "
                 "width=\"400\" height=\"400\" viewBox=\"-1000 -1000 2000 2000\">\n");
    for (const Forme *f = racine; f != NULL; f = f->suivant) {
        svg_exporter_forme(f, out);
    }
    fprintf(out, "</svg>\n");

    int success = ferror(out) == 0;
    if (fclose(out) != 0) {
        success = 0;
    }
    return success;
}
