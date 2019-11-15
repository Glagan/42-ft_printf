make
# ft_printf test
gcc -w -D IS_FT -L. -I. main_all.c -o ft_printf -lftprintf && ./ft_printf > test_ft_printf
cat -e test_ft_printf > test_ft_printf.res
# printf test
gcc -w main_all.c -o printf && ./printf > test_printf
cat -e test_printf > test_printf.res
# diff
if [[ $1 = "f" ]] || [[ $1 = "full" ]]; then
	diff -y --text test_printf.res test_ft_printf.res
else
	diff -y --suppress-common --text test_printf.res test_ft_printf.res
	rm -f test_printf.res test_ft_printf.res
fi
rm -f ft_printf printf
rm -f test_printf test_ft_printf