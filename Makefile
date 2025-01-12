
TESTSRC := test_btree.cpp
CFLAGS := -g -std=c++11

all: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

clean:
	rm -f test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

check: test2 test9
	@/bin/echo -e  "\e[1;31m--- TEST 2 ---\e[0m"
	@-./test2 || true
	@/bin/echo -e  "\e[1;31m--- TEST 9 ---\e[0m"
	@-./test9 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 10 ---\e[0m"
# 	@-./test10 || true
# check: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10
# 	@/bin/echo -e "\e[1;31m--- TEST 1 ---\e[0m"
# 	@-./test1 || true # || true because we return non-zero for failing tests, which would halt make
# 	@/bin/echo -e  "\e[1;31m--- TEST 2 ---\e[0m"
# 	@-./test2 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 3 ---\e[0m"
# 	@-./test3 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 4 ---\e[0m"
# 	@-./test4 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 5 ---\e[0m"
# 	@-./test5 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 6 ---\e[0m"
# 	@-./test6 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 7 ---\e[0m"
# 	@-./test7 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 8 ---\e[0m"
# 	@-./test8 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 9 ---\e[0m"
# 	@-./test9 || true
# 	@/bin/echo -e  "\e[1;31m--- TEST 10 ---\e[0m"
# 	@-./test10 || true


test1: btree1.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree1.o -o test1

test2: btree2.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree2.o -o test2

test3: btree3.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree3.o -o test3

test4: btree4.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree4.o -o test4

test5: btree5.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree5.o -o test5

test6: btree6.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree6.o -o test6

test7: btree7.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree7.o -o test7

test8: btree8.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree8.o -o test8

test9: btree9.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree9.o -o test9

test10: btree10.o $(TESTSRC)
	g++ $(CFLAGS) $(TESTSRC) btree10.o -o test10
