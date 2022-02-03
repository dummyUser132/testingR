for((i = 1; ; ++i)); do
   echo 'Passed'
   ./r.exe $i > in.txt
   ./p.exe < in.txt > out1.txt
   ./b.exe < in.txt > out2.txt 
   diff -w out1.txt out2.txt || break
done   