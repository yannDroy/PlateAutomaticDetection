#!/bin/bash

#########################
### author: Yann Droy ###
########### Fall 2017 ###
#########################

# This bash script computes the PAD executable to find plates limits
# on the given model.
#
# It requires 4 or 7 parameters:
# * the OpenMP scheduling option
# * the parallelization option
# * the input data file
# * the number of desired threads
# optional arguments:
# * the beginning cutoff for plate limits
# * the ending cutoff for plate limits
# * the number of computations
#
# After computing, it will write down in output files the different
# results (with the different cutoffs) and compute a visualization
# for each one.
#
# .out output files are in visualization/out/dat
# .jpg output images are in visualization/out/jpg
#
# WARNING :
# Make sure you have 'GMT' and 'convert' installed on the machine

# To run GMT (for visualization)
export PATH=$PATH:/usr/lib/gmt/bin

# Cleaning visualization input and output directories
echo -n "--- cleaning output directories... "
rm -rf visualization/in/*.out
rm -rf visualization/out/ps/*.ps
rm -rf visualization/out/jpg/*.jpg
echo "done."

# Running PAD
echo "--- running PAD with given parameters... "
bin/PAD $1 $2 $3 $4 $5 $6 $7 1> /dev/null

if (($? != 0))
then
    exit 1
fi
echo "done."

# Visualizations
cd visualization/

# Listing the generated output files
list=$(ls -A in/*.out)

# Computing the visualizations
echo -n "--- rendering .ps visualizations: "
for file in $list
do
    echo -n "."
    ./visualization.sh $file 3
done
echo " done."

# Converting .ps outputs to .jpg images
cd out/

echo -n "--- converting .ps files to .jpg files: "
for file in $(ls -A ps/*.ps)
do
    echo -n "."
    new=$(basename $file .ps)
    convert $file jpg/$new.jpg
done
echo " done."
