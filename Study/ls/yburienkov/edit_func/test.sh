clear
./uls -l ~/* > test2
ls -l ~/* > test
diff test test2
# for i in {1..12}; do
# 	touch ../test/file$i
# done
# make all
# ./uls ../test/* #> user
# echo
# echo "****"
# echo
# ls -aC ../test/* #> out
# diff user out
# for i in {1..11}; do
# 	rm -rf ../test/file$i
# done