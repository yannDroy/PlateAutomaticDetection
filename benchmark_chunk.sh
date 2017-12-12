# Argument test
if [ -z "$1" ]
then
    echo "Argument needed: scheduling"
    exit 1
fi

# File used for benchmarking
data=data_files/model4/velocity_22ma.neu

# Number of computations
comps=200

# Output files creation
file1="results/bench_c_chunk_$1.dat"
file2="results/bench_m_chunk_$1.dat"

touch "$file1"
truncate -s 0 "$file1"

touch "$file2"
truncate -s 0 "$file2"

# Threads benchmark loop
for chunk in $(seq 1 100)
do  
    echo -n "$chunk " >> $file1
    echo -n "$chunk " >> $file2
    
    bin/PAD -c "$1,$chunk" $data 16 10 40 $comps 2>> $file1
    bin/PAD -c "$1,$chunk" $data 16 10 40 $comps 2>> $file2

    echo "$chunk"
done
