# Projet d'éditeur de forme au format SVG avec interface par ligne de commande

Ce projet permet de créer, exporter ou modifier plusieurs types de formes que l utilisateur peut choisir

---

## Sommaire
- [Fonctionnalités](#-fonctionnalités)
- [Organisation fichiers](#-Organisation-fihiers)
  

---

##  Fonctionnalités

### 1. Différentes formes géométriques disponible
- SHAPE_CIRCLE => Cercle => caractéristiques :
- Centre, rayon, couleur de contour et de remplissage.


- SHAPE_ELLIPSE => Ellipse => caractéristiques :
- Centre, rayons horizontal et vertical, couleurs.


- SHAPE_RECTANLGE => Rectangle => caractéristiques :
-  Point supérieur gauche, largeur, hauteur, couleurs.


- SHAPE_LINE => Ligne => caractéristiques :
-  Points de départ et de fin, couleur de contour.


- SHAPE_POLYLINE => Polyligne => caractéristiques :
- Série de points reliés (sans remplissage).


- SHAPE_POLYGON => Polygone caractéristiques :
- Série de sommets fermés (avec contour et remplissage).

### 2. Styles et Transformations
- **Styles** : Personnalisation des couleurs de contour (*stroke*) et de remplissage (*fill*).
- **Transformations géométriques** :
  - **Translation** : Déplacement de la forme le long des axes X et Y (`dx`, `dy`).
  - **Rotation** : Rotation de la forme selon un angle en degrés (`angle`).
  - **Symétrie / Inversion** : Inversion horizontale (`flip_x`) ou verticale (`flip_y`).

### 3. Exportation SVG
- Exportation de 1 ou plusieurs formes au format svg avec svg_export

---

## Organisation des fichiers

Je les ai organisé d 'une certaine manière pour que je puisse me retrouver et aussi mieux organiser ce projet :
```
1 : main.c => permet d'afficher l interface graphique sur le terminal,
afin de proposer les différentes options de création, de modification ou d export
```
```text
shape.c et shape.h => contiennent le nécessaire pour modifier, créer les formes mais contiennent aussi
les structures visant a implanter les différentes formes ainsi que les points pour les cordonnées des formes.
```
```text
shape_list.h et shape_list.c contiennent les fonctions permettant l existence d une liste chaînée,
 afin de pouvoir créer plusieurs formes sans qu la suivant écrase celle d'avant.
```
```text
svg.c et svg.h contiennent les fonctions permettant l'écriture des formes au format SVG
( la création, les transformations ainsi que l'export de formes en svg)
```

```text
circle.c, rectangle.c etc => chauqe fichier.c correspond aux caractéristiques
 nécessaire pour créer une forme avec les caractéristiques associées.
```


