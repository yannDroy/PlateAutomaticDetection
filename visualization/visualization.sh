#!/bin/bash

# gmt bin directory
export PATH=$PATH:/usr/lib/gmt/bin

gmtset COLOR_MODEL RGB LABEL_FONT_SIZE 10p ANNOT_FONT_SIZE 8p MEASURE_UNIT cm BASEMAP_TYPE plain PLOT_DEGREE_FORMAT dddF

central_meridian=0

# Mollweide projection
frame=-179.99/179.99/-89.99/89.99
width=20
proj=W0/$width
scale_1=${width}
scalepar="-D7.5/-0.4/15.0/0.5h"
maxplate=500

# Input grid file located on Ebyte4
xyzfile=$1
grdfile=surface.grd
cpt=plates_scale.cpt

# ---- Input parameters dependant on the $age variable
surface -T0.25 $xyzfile -R$frame -G$grdfile -I0.5/0.5

#Build color palette
grd2cpt $grdfile -Crainbow -E$maxplate > $cpt

# Output filenames
string=$(basename $1 .dat)
output=out/ps/$string.ps

# Plots point outlines
psxy -R$frame -J$proj $xyzfile -Sg0.1 -C$cpt -P -K -Y5 -X0.5 > $output
