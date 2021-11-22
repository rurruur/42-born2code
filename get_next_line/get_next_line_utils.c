// check '\n', NULL, EOF
long long	find_end(char *buff)
{
	long long	index;

	index = -1;
	while (++index < BUFFER_SIZE)
		if (!buff[index]|| buff[index] == EOF || buff[index] == '\n')
			return (index + 1);
	return (-1);
}

// copy buffer to result
char    *create_result(char *result, char *buff, long long index)
{
    char                  *dest;
    unsigned long long   dest_size;
    unsigned long long   len_result;

    len_result = get_strlen(result);
    if (index < 0)
        dest_size = len_result + BUFFER_SIZE;
    else
        dest_size = len_result + index;
    dest = (char *)malloc(sizeof(char) * (dest_size + 1));
    if (dest)
    {
        str_cpy(dest, result, len_result);
        if (index < 0)
            str_cpy(dest + len_result, buff, BUFFER_SIZE);
        else
            str_cpy(dest + len_result, buff, index);
        dest[dest_size] = '\0';
    }
    free(result);
    return (dest);
}
