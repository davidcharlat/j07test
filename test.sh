let "n = 0"
nfile=$(find j07 -type f ! -regex '.*/\..*' -printf "0"|wc -c)

for file in 'ft_strdup' 'ft_range' 'ft_ultimate_range' 'ft_concat_params' 'ft_split_whitespaces' 'ft_print_words_tables' 'ft_convert_base' 'ft_split'
do	
	if [ -f j07/ex05/$file.c ] && [ -f j07/ex04/ft_split_whitespaces.c ]
	then 
		gcc -o test5 $file.test.c j07/ex0$n/$file.c j07/ex04/ft_split_whitespaces.c
		./test$n
		let "n = n + 1"
	elif [ -f j07/ex0$n/$file.c ]
	then 
		gcc -o test$n $file.test.c j07/ex0$n/$file.c
		./test$n firststring string2 "3rd str"
		let "n = n + 1"
	fi
done
if [ $n -eq $nfile ]
then
	echo "resultat = $n"
else
	echo "presence de fichiers autres que ceux specifies dans l'enonce -> resultat = 0"
fi
