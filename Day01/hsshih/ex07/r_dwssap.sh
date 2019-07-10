at /etc/passwd | awk '!/#/' | cut -d : -f 1 | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | tr "\n" "," | sed 's/,/, /g' | rev | sed 's/ ,/./' | rev
