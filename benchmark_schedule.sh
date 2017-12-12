# Argument test
if [ -z "$1" ]
then
    echo "Argument needed: scheduling"
    exit 1
fi

# File used for benchmarking
file=data_files/model4/velocity_22ma.neu

# Number of computations
comps=100

# Output files creation
file1="results/bench_c_$1.dat"
file2="results/bench_m_$1.dat"

touch "$file1"
truncate -s 0 "$file1"

touch "$file2"
truncate -s 0 "$file2"

# Threads benchmark loop
for threads in $(seq 1 100)
do  
    echo -n "$threads " >> $file1
    echo -n "$threads " >> $file2
    
    bin/PAD -c $1 $file $threads 10 40 $comps 2>> $file1
    #bin/PAD -m $1 $file $threads 10 40 $comps 2>> $file2

    echo "$threads"
done
