# /bin/sh
trap "exit" QUIT
trap "return 44" INT

################################################################
### WARNING
### Dont forget to change the path to your project in the Makefile!
### Dont change things here, there is no config!
####################################################################

execmd="./copyed_project/checker####LEGACY"

diffttl=test_results

color_def="\e[36m"
color_det="\e[33m"
color_ok="\e[32m"
color_ko="\e[31m"
color_ok2="\e[92m"
color_ko2="\e[91m"



#########################
###    PREPARATION    ###
#########################

# Abort testing on problems
function abort_testing {
	printf $color_ko
	printf "You may abort testing for the folowing reason:\n\t%s\n" "$1"
	printf "\r${color_def} continue in 6 seconds..."
	sleep 1
	printf "\r${color_def} continue in 5 seconds..."
	sleep 1
	printf "\r${color_def} continue in 4 seconds..."
	sleep 1
	printf "\r${color_def} continue in 3 seconds..."
	sleep 1
	printf "\r${color_def} continue in 2 seconds..."
	sleep 1
	printf "\r${color_def} continue in 1 seconds..."
	sleep 1
	printf "\r${color_def} continue in 0 seconds...\n"
	return 1
}

# Argument 're' can re-build project
if [ "$1" = "re" ]
then
	printf $color_def
	make fclean
fi

# Importing the project (copy to copyed_project directory)
function try_import {
	make import
	if [ $? -ne 0 ]; then abort_testing "Failed to copy project. Please verify the path configured in the makefile."; fi
}
try_import

# Running norminette
function try_norminette {
	make norminette
	if [ $? -ne 0 ]; then abort_testing "Norm error possible, please verify."; fi
}
try_norminette

# Stressing the make a little
function try_makeproject {
	make makeproject
	if [ $? -ne 0 ]; then abort_testing "Error occured durring project making, please verify."; fi
}
try_makeproject


#########################
###       TOOLS       ###
#########################

# Make generator
printf $color_def
printf "making generator...\n"
make generator

# Beautifulllll message
printf $color_def
printf "\e[1mpush_swap_\e[34mt\e[35me\e[36ms\e[37mt\e[35m\e[31me\e[32mr\e[33mi\e[34mz\e[35me\e[36mr\e[35m\n\n\e[0m"

# Reset total diff file
printf "" > $diffttl

# SUCCESS/FAIL counters/incrementers
okttl=0
kottl=0
gotok() {
	okttl=`expr $okttl + 1`
}
gotko() {
	kottl=`expr $kottl + 1`
}

# DISPLAY TEST CATEGORY TITLE / END OF CATEGORY
begintests() { # $1 Title
	printf $color_def
	printf "\n$1\n"
}
endtests() {
	printf $color_def
	printf "\n"
}

# Timed test (NOT READY)
timeout() {
	time=$1
	command="/bin/sh -c \"$2\""
	expect -c "set echo \"-noechoi\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"
	if [ $? = 1 ] ; then
		return 1
	else
		return 0
	fi
}

# Check a test result
expect=tmp_expected_results
your=tmp_your_result
onediff() { # $1 expected_fname   # $2 rst_fname   # $3 fail_msg
	if [ "`diff $1.1 $2.1`" = "" ] && [ "`diff $1.2 $2.2`" = "" ]
	then
		printf $color_ok
		printf " ✓ "
		printf $color_ok2
		gotok
	else
		printf $color_ko
		printf " \e[5m✖\e[25m "
		diff $1.1 $2.1 > "tmp_diff" 2>&1
		diff $1.2 $2.2 >> "tmp_diff" 2>&1
		echo "Failed test: $3" >> $diffttl
		cat "tmp_diff" >> $diffttl
		printf $color_ko2
		gotko
	fi
}

# run a single test (CUSTOM DEPENDING ON TESTERIZER)
timedfiletest() { # $1 -> file_name
	#exetime=$(/usr/bin/time echo $($execmd $1 &> $your) 2>&1 | sed -E "/^$/d" | sed -E "s/^ *//g" | sed -E "s/ .*\$//g")
	timestart=$(./gettime)
	$execmd $1 &> $your
	timeend=$(./gettime)
	onediff "$1.expected" $your "TEST: $1"
	printf " ⏳ `echo \"scale = 1; $timeend - $timestart\" | bc -l` \t($1)\n"
}
filetest() { # $1 -> file_name
	printf $color_def
	printf "testing $1...\n"
	$execmd $1 &> $your
	onediff "$1.expected" $your "TEST: $1"
	printf "\n\n"
}
fasttest() { # $1 -> file_in   # $2 -> command   # $3 -> expected (.1 and .2 for both outputs will be append)
	printf $color_def
	cat "$1" | ./copyed_project/checker $2 1> "$your.1" 2> "$your.2"
	onediff "testfiles/$3" $your "TEST: cat $1 | checker $2 ($3)"
}
psfasttest() { # $1 -> command   # $2 -> expected (.1 and .2 for both outputs will be append)
	printf $color_def
	./copyed_project/push_swap $1 1> "$your.1" 2> "$your.2"
	onediff "testfiles/$2" $your "TEST: push_swap $2 (NOTHING)"
}
pssorttest() { # $1 -> command   # $2/$3 -> count/shuffle
	printf $color_def
	./copyed_project/push_swap $1 | ./copyed_project/checker $1 1> "$your.1" 2> "$your.2"
	onediff "testfiles/OK" $your "TEST: push_swap on $2 ints shuffled $3 times?"
}

# statistic tests
psstatstests() {
	N_MIN=$1
	N_COUNT=$2
	N_STEP=$3
	N_SHUFFLE=$4
	N_TEST=$5
	N_TITLE=$6
	begintests "$N_TITLE"
	rm -f tmp_stats
	tests=0
	min=2147483647
	max=-1
	for ((i = 0 ; i < $N_TEST ; i++ ))
	do
		./generator $N_MIN $N_COUNT $N_STEP $N_SHUFFLE > tmp_nums
		./copyed_project/push_swap $(cat tmp_nums) 1> tmp_inst.1 2> tmp_inst.2
		cat tmp_inst.1 | ./copyed_project/checker $(cat tmp_nums) 1> $your.1 2> $your.2
		onediff "testfiles/OK" $your "push_swap $$(./generator $N_MIN $N_COUNT $N_STEP $N_SHUFFLE)"
		if [[ "$(cat $your.1)" == OK* ]]; then
			tests=`expr $tests + 1`
			instrs=$(wc -l tmp_inst.1 | awk '{print $1}')
			echo "$instrs" >> tmp_stats
		fi
	done
	if [ $tests -gt 0 ]; then
		sort -n -o tmp_stats tmp_stats
		printf "\n"
		if [ $tests -ne $N_TEST ]; then
			printf $color_ko2
		fi
		printf "MIN: %-4d\t" $(sed '1q;d' tmp_stats)
		if [ $tests -gt 3 ]; then
			printf "|--- %d [=== %d ===] %d ---|\t" $(sed "`expr $tests / 4`q;d" tmp_stats) $(sed "`expr $tests / 2`q;d" tmp_stats) $(sed "`expr \( $tests \* 3 \) / 4`q;d" tmp_stats)
		fi
		printf "MAX: %-4d\t" $(sed "`expr $tests`q;d" tmp_stats)
		printf "MOY: %-4d\t" `expr $(awk '{ sum += $1 } END { print sum }' tmp_stats) / $tests`
	fi
	endtests
}

#########################################
###              TESTS                ###
#########################################

begintests "'checker': Minimum"
fasttest "testfiles/pbpapa" "1 2 3" "OK"
fasttest "testfiles/rarra" "$(cat testfiles/ordered10.in)" "OK"
fasttest "testfiles/pbpapa" "$(./generator 1 121 22)" "OK"
fasttest "testfiles/pbpapa" "1 3 2" "KO"
fasttest "testfiles/pbpapa" "r g #" "Error"
endtests

begintests "'checker': Advanced"
fasttest "testfiles/empty" "0" "OK"
fasttest "testfiles/empty" "0 1 2" "OK"
fasttest "testfiles/empty" "-5 -4 -3" "OK"
fasttest "testfiles/empty" "-7374 -4324 -33" "OK"
fasttest "testfiles/empty" "4 6 7" "OK"
fasttest "testfiles/pb" "4 6 7" "KO"
fasttest "testfiles/pbpbpb" "4 6 7" "KO"
fasttest "testfiles/empty" "0 3 2" "KO"
fasttest "testfiles/0_8_1.inst" "0" "OK"
fasttest "testfiles/0_8_1.inst" "1" "OK"
fasttest "testfiles/0_8_1.inst" "-1" "OK"
fasttest "testfiles/0_8_1.inst" "2147483647" "OK"
fasttest "testfiles/0_8_1.inst" "-2147483648" "OK"
fasttest "testfiles/rarra" "-2147483648 2147483647" "OK"
fasttest "testfiles/pbpapa" "2147483647 -2147483648" "KO"
fasttest "testfiles/example.inst" "$(cat testfiles/example.nums)" "OK"
fasttest "testfiles/0_8_1.inst" "0 1 2 3 4 5 6 7" "KO"
fasttest "testfiles/0_8_1.inst" "$(cat testfiles/0_8_1.nums)" "OK"
fasttest "testfiles/empty" "" "OK"
endtests

begintests "'checker': Error handling"
fasttest "testfiles/empty" "1 u 5" "Error"
fasttest "testfiles/rarra" "$(./generator 0 100 1 1) 1" "Error"
fasttest "testfiles/rarra" "$(./generator 0 100 1 1) 1 2" "Error"
fasttest "testfiles/rarra" "3 $(./generator 0 100 1 1) 3" "Error"
fasttest "testfiles/rarra" "$(./generator 0 100 1 1) 3 3 3" "Error"
fasttest "testfiles/rarra" "$(./generator 0 100 1 1) 99" "Error"
fasttest "testfiles/rarra" "$(./generator 0 100 1 1) 0" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 +-8 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -+8 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 ++8 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 --8 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -8+ 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 8+ 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -8- 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 +8- 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -8v 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 +- 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 + 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 - 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -+ 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 '' 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 ' ' 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 '-2 ' 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 873487357468265487265842562534 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 -873487357468265487265842562534 3 5" "Error"
fasttest "testfiles/rarra" "1 9 2 7 4 873487357468265487265842562534b 3 5" "Error"
fasttest "/dev/urandom" "$(./generator 0 8 35)" "Error"
fasttest "/dev/random" "$(./generator 0 128 44 2)" "Error"
fasttest "/dev/urandom" "$(./generator -3000 2048 16 3)" "Error"
fasttest "/dev/random" "$(./generator -3000 2048 44444 4)" "Error"
fasttest "/dev/zero" "$(./generator -3000 1024 15 5)" "Error"
fasttest "/dev/urandom" "$(./generator -3000 1024 -35 9)" "Error"
fasttest "testfiles/invalid1.inst" "1 9 2 5" "Error"
fasttest "testfiles/invalid2.inst" "1 9 2 7" "Error"
fasttest "testfiles/invalid2.inst" "0" "Error"
fasttest "testfiles/invalid3.inst" "2 7 4 6" "Error"
fasttest "testfiles/invalid4.inst" "2 7 4 6" "Error"
fasttest "testfiles/sa_nonl.inst" "1 0 2 3 4 5 6 7" "Error"
endtests

begintests "'checker': High Loads"
fasttest "testfiles/pbpapa" "$(./generator 1 10000 43)" "OK"
fasttest "testfiles/rarra" "$(./generator -3000 5000 35)" "OK"
fasttest "testfiles/pbpapa" "$(./generator -2 5000 -43)" "KO"
fasttest "testfiles/rarra" "$(./generator 5 10000 -1)" "KO"
fasttest "testfiles/rarra" "$(./generator 4783749 7000 -34455344)" "KO"
fasttest "testfiles/pbpapa" "$(./generator 5 3000 -1) A" "Error"
fasttest "testfiles/random1338.inst" "$(./generator -9999 5000 999)" "KO"
fasttest "testfiles/random1338.inst" "$(./generator 128 10000 2)" "KO"
fasttest "testfiles/random1338.inst" "$(./generator 128 10000 2) c" "Error"
fasttest "testfiles/lotsof_ra.inst" "1 2" "OK"
fasttest "testfiles/lotsof_ra.inst" "1 2 3 4" "OK"
fasttest "testfiles/lotsof_ra.inst" "-4 -3 -2 -1" "OK"
endtests

begintests "'push_swap': Already sorted"
psfasttest "" "NOTHING"
psfasttest "0" "NOTHING"
psfasttest "0 1" "NOTHING"
psfasttest "0 1 2" "NOTHING"
psfasttest "-1 0 1" "NOTHING"
psfasttest "-9 -8 -6" "NOTHING"
psfasttest "33 44 55" "NOTHING"
endtests

begintests "'push_swap': Error handling"
psfasttest "1 9 2 7 4 -+8 3 5" "Error"
psfasttest "1 9 2 7 4 ++8 3 5" "Error"
psfasttest "1 9 2 7 4 --8 3 5" "Error"
psfasttest "1 9 2 7 4 -8+ 3 5" "Error"
psfasttest "1 9 2 7 4 8+ 3 5" "Error"
psfasttest "1 9 2 7 4 -8- 3 5" "Error"
psfasttest "1 9 2 7 4 +8- 3 5" "Error"
psfasttest "1 9 2 7 4 -8v 3 5" "Error"
psfasttest "1 9 2 7 4 +- 3 5" "Error"
psfasttest "1 9 2 7 4 + 3 5" "Error"
psfasttest "1 9 2 7 4 - 3 5" "Error"
psfasttest "1 9 2 7 4 -+ 3 5" "Error"
psfasttest "1 9 2 7 4 '' 3 5" "Error"
psfasttest "1 9 2 7 4 ' ' 3 5" "Error"
psfasttest "1 9 2 7 4 '-2 ' 3 5" "Error"
psfasttest "1 9 2 7 4 873487357468265487265842562534 3 5" "Error"
psfasttest "1 9 2 7 4 -873487357468265487265842562534 3 5" "Error"
psfasttest "1 9 2 7 4 873487357468265487265842562534b 3 5" "Error"
psfasttest "1 9 2 7 4 8 3 2147483648" "Error"
psfasttest "1 9 2 7 4 8 3 -2147483649" "Error"
endtests

begintests "'push_swap': Regular sorting"
for ((i = 2 ; i < 1024 ; i *= 2 ))
do
	for ((j = 2 ; j < 1024 ; j *= 2 ))
	do
		pssorttest "$(./generator 0 $i 1 $j)" $i $j
	done
done
endtests

begintests "'push_swap': Regular sorting with negatives"
for ((i = 2 ; i < 1024 ; i *= 3 ))
do
	for ((j = 2 ; j < 1024 ; j *= 3 ))
	do
		pssorttest "$(./generator 0 $i -1 $j)" $i $j
	done
done
endtests

begintests "'push_swap': Inverted sorting"
for ((i = 2 ; i < 256 ; i *= 2 ))
do
	for ((j = 2 ; j < 256 ; j *= 2 ))
	do
		pssorttest "$(./generator 0 $i 1 $j)" $i $j
	done
done
endtests

begintests "'push_swap': Non-linear lists"
pssorttest "$(./generator 1 8 \*2 -1)" 8 -1
pssorttest "$(./generator 1 16 \*2 -1)" 16 -1
pssorttest "$(./generator 1 32 \*2 -1)" 32 -1
pssorttest "$(./generator 8000 8 /2 -1)" 8 -1
pssorttest "$(./generator 7777777 16 /2 -1)" 16 -1
pssorttest "$(./generator 40000 100 \*3 -1)" 100 -1
pssorttest "$(./generator 1 16 \*-3 -1)" 16 -1
pssorttest "$(./generator 1 32 \*-2 -1)" 32 -1
endtests

begintests "'push_swap': statistics"
N_TESTS=32
# small arrays
psstatstests 0 2 1 -1 8 "2 ints: FULLY SHUFFLED"
psstatstests 0 3 1 -1 8 "3 ints: FULLY SHUFFLED"
psstatstests 0 5 1 -1 $N_TESTS "5 ints: FULLY SHUFFLED"
psstatstests 4 5 -1 0 1 "5 ints: REVERSED"
psstatstests -4 5 3 -1 $N_TESTS "5 ints: FULLY SHUFFLED UNREGULAR"
psstatstests 0 12 1 -1 $N_TESTS "12 ints: FULLY SHUFFLED"
psstatstests 0 50 1 -1 $N_TESTS "50 ints: FULLY SHUFFLED"
psstatstests -4 50 3 -1 $N_TESTS "50 ints: FULLY SHUFFLED UNREGULAR"
psstatstests -4 50 3 1 $N_TESTS "50 ints: 1 SWAP UNREGULAR"
# medium arrays (interestings, so, with advanced tests)
psstatstests 0 100 1 -1 $N_TESTS "100 ints: FULLY SHUFFLED"
psstatstests 0 100 1 10 $N_TESTS "100 ints: ALMOST SORTED"
psstatstests 99 100 -1 0 1 "100 ints: REVERSED"
psstatstests 0 100 -1 0 1 "100 negative ints: REVERSED"
psstatstests 0 100 1 r20 1 "100 ints: 20 ROTATIONS"
psstatstests 0 100 1 r-20 1 "100 ints: 20 ROTATIONS INVERTED"
psstatstests 99 100 -1 r-20 1 "100 ints: 20 ROTATIONS INVERTED REVERSED"
psstatstests 99 100 -1 10 $N_TESTS "100 ints: ALMOST REVERSED"
psstatstests -4 100 3 -1 $N_TESTS "100 ints: FULLY SHUFFLED UNREGULAR"
psstatstests -4 100 3 10 $N_TESTS "100 ints: 10 SWAPS UNREGULAR"
psstatstests 0 500 1 -1 $N_TESTS "500 ints: FULLY SHUFFLED"
psstatstests 0 500 1 10 $N_TESTS "500 ints: ALMOST SORTED"
psstatstests 499 500 -1 0 1 "500 ints: REVERSED"
psstatstests 0 500 1 r20 1 "500 ints: 20 ROTATIONS"
psstatstests 0 500 1 r-20 1 "500 ints: 20 ROTATIONS INVERTED"
psstatstests 499 500 -1 r-20 1 "500 ints: 20 ROTATIONS INVERTED REVERSED"
psstatstests 499 500 -1 10 $N_TESTS "500 ints: ALMOST REVERSED"
psstatstests -4 500 3 -1 $N_TESTS "500 ints: FULLY SHUFFLED UNREGULAR"
# big arrays (innaccurate tests, just to see speed difference)
psstatstests 0 1000 1 4 4 "1000 ints: 1 SWAP"
psstatstests 0 1000 1 4 4 "1000 ints: 4 SWAPS"
psstatstests 0 1000 1 16 4 "1000 ints: 16 SWAPS"
psstatstests 0 1000 1 -1 4 "1000 ints: FULLY SHUFFLED"
endtests

printf $color_def
printf "ALL TESTS DONE!\n"
printf "$color_ok\tSUCCESS: $okttl / `expr $okttl + $kottl`\n"
printf "$color_ko\tFAILS: $kottl / `expr $okttl + $kottl`\n"
printf "\e[33m/!\\WARNING! A failing test do not mean you are wrong! Alway investigate!\n"
rm tmp_*
