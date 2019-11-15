make
# ft_printf test
gcc -Wall -Wextra -Werror -D IS_FT -L. -I. test.c -o ft_printf -lftprintf && ./ft_printf > test_ft_printf
cat -e test_ft_printf > test_ft_printf.res
# printf test
gcc -Wall -Wextra -Werror test.c -o printf && ./printf > test_printf
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