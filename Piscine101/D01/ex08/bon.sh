ldapsearch -Q | grep -i "cn:" | rev | cut -d' ' -f1,3- | rev | grep -i bon | wc -l | bc
