rm *.txt
./spec_test tests.in >tests.result
cat tests.result | grep -v MR | grep -v MC | grep -v MW | grep -v PR | grep -v PC | grep -v PW>my.txt
cat tests.expected| grep -v MR | grep -v MC | grep -v MW |  grep -v PR |grep -v PC | grep -v PW>base.txt
diff -s my.txt base.txt