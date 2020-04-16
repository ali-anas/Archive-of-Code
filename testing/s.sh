for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    # ./sol < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./sol < int) <(./brute < int) || break
done
