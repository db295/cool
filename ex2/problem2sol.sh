cp /share/ex_data/ex2/phone_dir.txt .
sort -rnk3 phone_dir.txt > phone_dir2.txt
cut -f2 -d' ' phone_dir.txt | tr 'A-Z' 'a-z' | sort -f | uniq -i >> phone_dir2.txt
tail -n8 phone_dir.txt| tr '67' '76' > modified.txt
cut -d' ' -f2  phone_dir.txt | cut -c1 | paste -d' ' - phone_dir.txt | cut -c1-3 > initials.txt
