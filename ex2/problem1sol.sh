cp /share/ex_data/ex2/peter-pan.txt .
head -n22 peter-pan.txt | tr '.[:digit:]' '?' > pp2.txt
head -n15 peter-pan.txt| tail -n+11 | tr 'a-zA-Z' 'A-Za-z' > pp3.txt
head -n100 peter-pan.txt| tr '[:punct:]' ' ' | tr -s ' ' | tr '[:space:]' '\n' | sort -f |uniq -i |wc -l
