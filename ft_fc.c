

int ft_putchar()
{
    return (write(1, &c, 1));
}

int ft_putstr()
{
    int i;

	if(!s)
		return  (write(1, "(null)", 6));

	i = 0;
	while (str[i] != '\0')
	{
		 write(1,&str[i],1);
		i++;
	}
	return i;
}

int ft_pointer()
{

}

int ft_putnbr(int n)
{
    long num;
    int len;
    char c;
    
    num = n;
    len = 0;
    if (num < 0)
    {
        len += write(1, "-", 1);
        num = -num;
    }
    
    if (num > 9)
        len += ft_putnbr(num / 10);
    
    c = (num % 10) + '0';
    len += write(1, &c, 1);
    
    return (len);
}

int ft_unbr()
{
	int len;

	len = 0;
    if (num > 9)
        len += ft_putnbr(num / 10);
    
    c = (num % 10) + '0';
    len += write(1, &c, 1);
    
    return (len);
}

int ft_hex(unsigned int n, char c)
{
	char	*use;
	int		len;

	if (c == 'x')
		use = "0123456789abcdef";
	else
		use = "0123456789ABCDEF";

	len = 0;
	if (n >= 16)
		len += ft_hex(n / 16, c);
	len += write(1, &use[n % 16], 1);
	return (len);
}

int ft_percent()
{
	return (write(1, "%", 1));
}